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
#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <ObjectSprite.h>
#include <Printing.h>
#include <SpriteManager.h>
#include <Texture.h>
#include <VIPManager.h>

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
	this->showDetails = true;
}

// class's destructor
void SpritesState::destructor()
{
	SpritesState::destroySprite(this);

	// destroy base
	Base::destructor();
}

/*
 *	The StateMachine calls State::execute when updated.
 *  It is called once per game frame.
 */
void SpritesState::execute(void* owner __attribute__((unused)))
{
	SpritesState::printSpriteDetails(this);
}

/*
 *	The StateMachine calls State::exit when popping the State from its stack.
 */
void SpritesState::exit(void* owner __attribute__((unused)))
{
	Base::exit(this, owner);

	// Since I'm a dynamic_singleton, I must delete myself upon exit
	delete this;
}

void SpritesState::executeSpriteVerticalTranslation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->sprite))
	{
		static int16 yPosition = __SCREEN_HEIGHT / 2;
		static int16 delta = 1;

		yPosition += delta;

		if(__SCREEN_HEIGHT <= (unsigned)yPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {__SCREEN_WIDTH / 2, yPosition, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		SpritesState::printSpriteDetails(this);
	}
}

void SpritesState::executeSpriteHorizontalTranslation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->sprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 delta = 1;

		xPosition += delta;

		if(__SCREEN_WIDTH <= (unsigned)xPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {xPosition, __SCREEN_HEIGHT / 2, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		SpritesState::printSpriteDetails(this);
	}
}

void SpritesState::executeSpriteRotation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->sprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 delta = 1;

		xPosition += delta;

		if(__SCREEN_WIDTH <= (unsigned)xPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {xPosition, __SCREEN_HEIGHT / 2, 1, 2};
		Sprite::setPosition(this->sprite, &spritePosition);

		static fixed_t zAngle = 0;
		zAngle += __I_TO_FIXED(delta);

		Rotation rotation = {0, 0, zAngle};
		Sprite::rotate(this->sprite, &rotation);

		SpritesState::printSpriteDetails(this);
	}
}

void SpritesState::printSpriteDetails()
{
	if(this->showDetails && !isDeleted(this->sprite))
	{
		Sprite::print(this->sprite, 1, 3);
	}
}

void SpritesState::showStuff()
{
	this->showDetails = true;
	SpritesState::setupBrightness(this, this->showDetails);
	SpritesState::createSprite(this);
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

void SpritesState::createSprite()
{
	SpritesState::destroySprite(this);

	// Look for the specifications in assets/images/CogWheel/Spec/CogWheelSpec.c		
	extern SpriteSpec CogWheelObjectSprite;
	extern SpriteSpec CogWheelBgmapSpriteNormal;
	extern SpriteSpec CogWheelBgmapSpriteAffine;
	extern SpriteSpec CogWheelBgmapSpriteHBias;

	SpriteSpec* spriteSpec = NULL;

	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	SpritesState::mutateMethod(execute, SpritesState::execute);

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
	}

	// Don't create Sprites directly
	this->sprite = SpriteManager::createSprite(SpriteManager::getInstance(), spriteSpec, NULL);

	SpritesState::printHeader(this);
}

void SpritesState::printHeader()
{
	Base::printHeader(this);

	if(!isDeleted(this->sprite))
	{
		PixelVector spritePosition = {__SCREEN_WIDTH / 2, __SCREEN_HEIGHT / 2, 1, 2};

		Sprite::setPosition(this->sprite, &spritePosition);

		Scale scale = {__F_TO_FIX7_9(0.5f), __F_TO_FIX7_9(0.5f), __F_TO_FIX7_9(0.5f)};
		Sprite::resize(this->sprite, scale, __PIXELS_TO_METERS(0));

		if(!this->showDetails)
		{
			int16 y = 3;
			Printing::text(Printing::getInstance(), "                      ", 1, y, NULL);
			Printing::text(Printing::getInstance(), __GET_CLASS_NAME(this->sprite), 1, y, NULL);
			Printing::text(Printing::getInstance(), "                 ", 9, ++y, NULL);

			if(!Sprite::isObject(this->sprite))
			{
				Printing::text(Printing::getInstance(), "Mode: ", 1, y, NULL);

				if(Sprite::isAffine(this->sprite))
				{
					Printing::text(Printing::getInstance(), "Affine   ", 7, y, NULL);
				}
				else if(Sprite::isHBias(this->sprite))
				{
					Printing::text(Printing::getInstance(), "HBias   ", 7, y, NULL);
				}
				else if(Sprite::isBgmap(this->sprite))
				{
					Printing::text(Printing::getInstance(), "Bgmap    ", 7, y, NULL);
				}
			}
		}
	}	
}

void SpritesState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(!(K_PWR & userInput->releasedKey))
	{
		if(K_LL & userInput->releasedKey)
		{
			if(kSpriteNoTypeStart >= --this->spriteType)
			{
				this->spriteType = kSpriteNoTypeEnd - 1;
			}

			SpritesState::printHeader(this);
			SpritesState::showStuff(this);
			
			return;
		}
		else if(K_LR & userInput->releasedKey)
		{
			if(kSpriteNoTypeEnd <= ++this->spriteType)
			{
				this->spriteType = kSpriteNoTypeStart + 1;
			}

			SpritesState::printHeader(this);
			SpritesState::showStuff(this);

			return;
		}
	}

	Base::processUserInput(this, userInput);
}

void SpritesState::showDetails()
{
	SpritesState::setupBrightness(this, this->showDetails);
	SpritesState::printHeader(this);
}
