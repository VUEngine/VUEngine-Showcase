/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SpritesState.h>

#include <BgmapSprite.h>
#include <CameraEffectManager.h>
#include <Printing.h>
#include <SpriteManager.h>

#include <debugUtilities.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec SpritesStage;

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


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void SpritesState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&SpritesStage;
	this->sprite = NULL;
	this->spriteType = kSpriteNoTypeStart + 1;
	this->validSuboptionKeys = K_LL | K_LR;
}

// class's destructor
void SpritesState::destructor()
{
	SpritesState::destroySprite(this);

	// destroy base
	Base::destructor();
}

/*
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Look for SpritesState::mutateMethod below in SpritesState::createSprite.
 */
void SpritesState::execute(void* owner __attribute__((unused)))
{
	// Don't print stuff every game cycle, it is a heavy process. This is just an example!
	if(this->showAdditionalDetails)
	{
		SpritesState::showAdditionalDetails(this);
	}
}

void SpritesState::processUserInput(const UserInput* userInput)
{
	SpritesState::playSoundEffects(this, userInput, false);

	// Check for UserInput and key definitions in KeypadManager.h
	if(!(K_PWR & userInput->releasedKey))
	{
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
	}

	Base::processUserInput(this, userInput);
}

void SpritesState::showControls()
{
	Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

void SpritesState::showStuff()
{
	SpritesState::destroySprite(this);
	SpritesState::createSprite(this);
}

void SpritesState::showExplanation()
{
	if(!isDeleted(this->sprite))
	{
		int16 y = 3;
		Printing::text(Printing::getInstance(), "CONCEPTS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "Game states", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "Sprites", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "Specs", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "User input", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "OTHER CONCEPTS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "Class extensions", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "Class mutation", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "CLASSES", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "CharSet", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "*Sprite      ", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "Texture", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "METHODS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "SpritesState", 1, y++, NULL);
		Printing::text(Printing::getInstance(), " createSprite", 1, y++, NULL);
		Printing::text(Printing::getInstance(), " destroySprite", 1, y++, NULL);
		Printing::text(Printing::getInstance(), " processUserInput", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "SPECS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "CogWheel*Sprite*", 1, y++, NULL);

		y = 3;
		Printing::text(Printing::getInstance(), __GET_CLASS_NAME(this->sprite), 28, y++, NULL);

		if(Sprite::isObject(this->sprite))
		{
			Printing::text(Printing::getInstance(), "Mode: N/A", 28, y, NULL);
		}
		else if(Sprite::isAffine(this->sprite))
		{
			Printing::text(Printing::getInstance(), "Mode: Affine", 28, y, NULL);
		}
		else if(Sprite::isHBias(this->sprite))
		{
			Printing::text(Printing::getInstance(), "Mode: HBias", 28, y, NULL);
		}
		else if(Sprite::isBgmap(this->sprite))
		{
			Printing::text(Printing::getInstance(), "Mode: Bgmap", 28, y, NULL);
		}
	}	
}

void SpritesState::showAdditionalDetails()
{
	SpritesState::showSpriteDetails(this);
}

void SpritesState::showSpriteDetails()
{
	if(!isDeleted(this->sprite))
	{
		Sprite::print(this->sprite, 1, 3);
	}
}

void SpritesState::createSprite()
{
	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	SpritesState::restoreMethods();

	// Check these specifications in assets/images/CogWheel/Spec/CogWheelSpec.c		
	extern SpriteSpec CogWheelObjectSprite;
	extern SpriteSpec CogWheelBgmapSpriteNormal;
	extern SpriteSpec CogWheelBgmapSpriteAffine;
	extern SpriteSpec CogWheelBgmapSpriteHBias;
	extern SpriteSpec CogWheelMBgmapSpriteNormal;

	SpriteSpec* spriteSpec = NULL;

	switch(this->spriteType)
	{
		case kSpriteObject:

			spriteSpec = &CogWheelObjectSprite;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteHorizontalTranslation);
			break;

		case kSpriteBgmapNormal:

			spriteSpec = &CogWheelBgmapSpriteNormal;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteVerticalTranslation);
			break;

		case kSpriteBgmapAffine:

			spriteSpec = &CogWheelBgmapSpriteAffine;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteRotation);
			break;

		case kSpriteBgmapHBias:

			// Check BgmapSprite::waveEffect in source/components/graphics/Sprites/BgmapSpriteExtensions.c
			spriteSpec = &CogWheelBgmapSpriteHBias;
			break;

		case kSpriteMBgmap:

			spriteSpec = &CogWheelMBgmapSpriteNormal;
			SpritesState::mutateMethod(execute, SpritesState::executeSpriteFullTranslation);
	}

	// Don't create Sprites directly
	this->sprite = SpriteManager::createSprite(SpriteManager::getInstance(), spriteSpec, NULL);

	if(!isDeleted(this->sprite))
	{
		PixelVector spritePosition = {__SCREEN_WIDTH / 2 + __SCREEN_WIDTH / 4, __SCREEN_HEIGHT / 2 +__HALF_SCREEN_HEIGHT / 4, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		Scale scale = {__F_TO_FIX7_9(0.5f), __F_TO_FIX7_9(0.5f), __F_TO_FIX7_9(0.5f)};
		Sprite::resize(this->sprite, scale, __PIXELS_TO_METERS(0));
	}

	SpritesState::showHeader(this);
}

void SpritesState::destroySprite()
{
	if(!isDeleted(this->sprite))
	{
		// Don't destroy the sprite directly		
		SpriteManager::destroySprite(SpriteManager::getInstance(), this->sprite);

		this->sprite = NULL;
	}
}

/*
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Runtime overrides for SpritesState::execute.
 */
void SpritesState::executeSpriteVerticalTranslation(void* owner __attribute__((unused)))
{
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

void SpritesState::executeSpriteHorizontalTranslation(void* owner __attribute__((unused)))
{
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

void SpritesState::executeSpriteRotation(void* owner __attribute__((unused)))
{
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
		zAngle += __I_TO_FIXED(delta);

		Rotation rotation = {0, 0, zAngle};
		Sprite::rotate(this->sprite, &rotation);

		if(this->showAdditionalDetails)
		{
			SpritesState::showAdditionalDetails(this);
		}
	}
}

void SpritesState::executeSpriteFullTranslation(void* owner __attribute__((unused)))
{
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

