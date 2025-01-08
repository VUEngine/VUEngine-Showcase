/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <string.h>

#include <BgmapSprite.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <SpriteManager.h>

#include "SpritesState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum SpriteTypes
{
	kSpriteNoTypeStart = 0,
	kSpriteObject,
	kSpriteBgmapNormal,
	kSpriteBgmapAffine,
	kSpriteBgmapHBias,
	kSpriteMBgmap,

	kSpriteNoTypeEnd
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Look for SpritesState::mutateMethod below in SpritesState::createSprite.
 */
void SpritesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	// Don't print stuff every game cycle, it is a heavy process. This is just an example!
	if(this->showAdditionalDetails)
	{
		SpritesState::showAdditionalDetails(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::processUserInput(const UserInput* userInput)
{
	SpritesState::playSoundEffects(this, userInput, false);

	if(K_LL & userInput->releasedKey)
	{
		if(kSpriteNoTypeStart >= --this->spriteType)
		{
			this->spriteType = kSpriteNoTypeEnd - 1;
		}

		SpritesState::show(this, true);
	}
	else if(K_LR & userInput->releasedKey)
	{
		if(kSpriteNoTypeEnd <= ++this->spriteType)
		{
			this->spriteType = kSpriteNoTypeStart + 1;
		}

		SpritesState::show(this, true);
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::showControls()
{
	Printing::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::showStuff()
{
	SpritesState::destroySprite(this);
	SpritesState::createSprite(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::showExplanation()
{
	if(!isDeleted(this->sprite))
	{
		int16 y = 3;
		Printing::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
		Printing::text(I18n::getText(I18n::getInstance(), kStringGameStatesLabel), 2, y++, NULL);
		Printing::text(I18n::getText(I18n::getInstance(), kStringSpritesLabel), 2, y++, NULL);
		Printing::text(I18n::getText(I18n::getInstance(), kStringSpecsLabel), 2, y++, NULL);
		Printing::text(I18n::getText(I18n::getInstance(), kStringUserInputLabel), 2, y++, NULL);
		y++;
		Printing::text(I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 2, y++, "DefaultBold");
		Printing::text(I18n::getText(I18n::getInstance(), kStringClassExtensionLabel), 2, y++, NULL);
		Printing::text(I18n::getText(I18n::getInstance(), kStringClassMutationLabel), 2, y++, NULL);
		y++;
		Printing::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
		Printing::text("CharSet", 2, y++, NULL);
		Printing::text("*Sprite      ", 2, y++, NULL);
		Printing::text("Texture", 2, y++, NULL);
		y++;
		Printing::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "DefaultBold");
		Printing::text("SpritesState", 2, y++, NULL);
		Printing::text("::createSprite", 2, y++, NULL);
		Printing::text("::destroySprite", 2, y++, NULL);
		Printing::text("::processUserInput", 2, y++, NULL);
		y++;
		Printing::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "DefaultBold");
		Printing::text("CogWheel*Sprite*Spec", 2, y++, NULL);

		y = 3;
		Printing::text(I18n::getText(I18n::getInstance(), kStringSpriteSubtitle), 28, y++, "DefaultBold");
		Printing::text(__GET_CLASS_NAME(this->sprite), 28, y++, NULL);
		const char* strMode = I18n::getText(I18n::getInstance(), kStringModeLabel);
		Printing::text(strMode, 28, y, NULL);
		FontSize strModeTextSize = Printing::getTextSize(strMode, NULL);

		if(Sprite::isObject(this->sprite))
		{
			Printing::text("N/A", 28 + strModeTextSize.x, y, NULL);
		}
		else if(Sprite::isAffine(this->sprite))
		{
			Printing::text("Affine", 28 + strModeTextSize.x, y, NULL);
		}
		else if(Sprite::isHBias(this->sprite))
		{
			Printing::text("HBias", 28 + strModeTextSize.x, y, NULL);
		}
		else if(Sprite::isBgmap(this->sprite))
		{
			Printing::text("BGMAP", 28 + strModeTextSize.x, y, NULL);
		}
	}	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::showAdditionalDetails()
{
	if(!isDeleted(this->sprite))
	{
		Sprite::print(this->sprite, 1, 3);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/SpritesStageSpec.c
	 */
	extern StageROMSpec SpritesStageSpec;
	this->stageSpec = (StageSpec*)&SpritesStageSpec;
	this->sprite = NULL;
	this->spriteType = kSpriteNoTypeStart + 1;
	this->validSuboptionKeys = K_LL | K_LR;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::destructor()
{
	SpritesState::destroySprite(this);

	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::createSprite()
{
	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	SpritesState::restoreMethods();

	// Check these specifications in assets/images/CogWheel/Spec/CogWheelSpec.c		
	extern SpriteSpec CogWheelObjectSpriteSpec;
	extern SpriteSpec CogWheelBgmapSpriteNormalSpec;
	extern SpriteSpec CogWheelBgmapSpriteAffineSpec;
	extern SpriteSpec CogWheelBgmapSpriteHBiasSpec;
	extern SpriteSpec CogWheelMBgmapSpriteNormalSpec;

	SpriteSpec* spriteSpec = NULL;

	switch(this->spriteType)
	{
		case kSpriteObject:

			spriteSpec = &CogWheelObjectSpriteSpec;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteHorizontalTranslation);
			break;

		case kSpriteBgmapNormal:

			spriteSpec = &CogWheelBgmapSpriteNormalSpec;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteVerticalTranslation);
			break;

		case kSpriteBgmapAffine:

			spriteSpec = &CogWheelBgmapSpriteAffineSpec;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteRotation);
			break;

		case kSpriteBgmapHBias:

			// Check BgmapSprite::waveEffect in source/components/graphics/Sprites/BgmapSpriteExtensions.c
			spriteSpec = &CogWheelBgmapSpriteHBiasSpec;
			break;

		case kSpriteMBgmap:

			spriteSpec = &CogWheelMBgmapSpriteNormalSpec;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteFullTranslation);
	}

	// Don't create Sprites directly
	this->sprite = Sprite::safeCast(ComponentManager::createComponent(NULL, (ComponentSpec*)&spriteSpec));

	if(!isDeleted(this->sprite))
	{
		PixelVector spritePosition = {__SCREEN_WIDTH / 2 + __SCREEN_WIDTH / 4, __SCREEN_HEIGHT / 2 +__HALF_SCREEN_HEIGHT / 4, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		PixelScale spriteScale = {__F_TO_FIX7_9(0.5f), __F_TO_FIX7_9(0.5f)};
		Sprite::setScale(this->sprite, &spriteScale);
	}

	SpritesState::showHeader(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::destroySprite()
{
	if(!isDeleted(this->sprite))
	{
		// Don't destroy the sprite directly		
		ComponentManager::destroyComponent(NULL, Component::safeCast(this->sprite));

		this->sprite = NULL;
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Runtime overrides for SpritesState::execute.
 */
void SpritesState::executeSpriteVerticalTranslation(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->sprite))
	{
		static int16 yPosition = __SCREEN_HEIGHT / 2 +__HALF_SCREEN_HEIGHT / 4;
		static int16 delta = 1;

		yPosition += delta;

		if(__HALF_SCREEN_HEIGHT / 2 >= yPosition || __SCREEN_HEIGHT <= yPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {__SCREEN_WIDTH / 2 + __SCREEN_WIDTH / 4, yPosition, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		if(this->showAdditionalDetails)
		{
			SpritesState::showAdditionalDetails(this);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::executeSpriteHorizontalTranslation(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->sprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 delta = 1;

		xPosition += delta;

		if(__HALF_SCREEN_WIDTH >= xPosition || __SCREEN_WIDTH <= xPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {xPosition, __SCREEN_HEIGHT / 2 +__HALF_SCREEN_HEIGHT / 4, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		if(this->showAdditionalDetails)
		{
			SpritesState::showAdditionalDetails(this);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::executeSpriteRotation(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->sprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 delta = 1;

		xPosition += delta;

		if(__HALF_SCREEN_WIDTH >= xPosition || __SCREEN_WIDTH <= xPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {xPosition, __SCREEN_HEIGHT / 2 +__HALF_SCREEN_HEIGHT / 4, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		static fixed_t zAngle = 0;
		zAngle += __I_TO_FIXED(delta * 2);

		Rotation rotation = {0, 0, zAngle};
		Sprite::setRotation(this->sprite, &rotation);

		fix7_9 scaleMagnitude = __FIXED_TO_FIX7_9(__FIXED_DIV(__I_TO_FIXED(__HALF_SCREEN_HEIGHT), __I_TO_FIXED(xPosition)));

		PixelScale spriteScale = {scaleMagnitude, scaleMagnitude};
		Sprite::setScale(this->sprite, &spriteScale);

		if(this->showAdditionalDetails)
		{
			SpritesState::showAdditionalDetails(this);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SpritesState::executeSpriteFullTranslation(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->sprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 yPosition = __SCREEN_HEIGHT / 2;

		xPosition++;
		yPosition++;

		PixelVector spritePosition = {xPosition, yPosition, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		if(this->showAdditionalDetails)
		{
			SpritesState::showAdditionalDetails(this);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
