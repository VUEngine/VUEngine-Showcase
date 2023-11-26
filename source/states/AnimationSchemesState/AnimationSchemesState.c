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

#include <AnimationSchemesState.h>

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

extern StageROMSpec AnimationSchemesStage;


enum AnimationSchemes
{
	kAnimationNoneStart = 0,
	kAnimationNotShared,
	kAnimationShared,
	kAnimationMulti,

	kAnimationNoneEnd
};


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void AnimationSchemesState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&AnimationSchemesStage;
	this->animatedSprite = NULL;
	this->animationScheme = kAnimationNoneStart + 1;
}

// class's destructor
void AnimationSchemesState::destructor()
{
	AnimationSchemesState::destroySprite(this);

	// destroy base
	Base::destructor();
}

/*
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Look for AnimationSchemesState::mutateMethod below in AnimationSchemesState::createSprite.
 */
void AnimationSchemesState::execute(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->animatedSprite))
	{
		Sprite::updateAnimation(this->animatedSprite);
	}
}

/*
 *	The StateMachine calls State::exit when popping the State from its stack.
 */
void AnimationSchemesState::exit(void* owner __attribute__((unused)))
{
	Base::exit(this, owner);

	// Since I'm a dynamic_singleton, I must delete myself upon exit
	delete this;
}

void AnimationSchemesState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(!(K_PWR & userInput->releasedKey))
	{
		if(K_LL & userInput->releasedKey)
		{
			if(kAnimationNoneStart >= --this->animationScheme)
			{
				this->animationScheme = kAnimationNoneEnd - 1;
			}

			AnimationSchemesState::printHeader(this);
			AnimationSchemesState::showStuff(this);
			
			return;
		}
		else if(K_LR & userInput->releasedKey)
		{
			if(kAnimationNoneEnd <= ++this->animationScheme)
			{
				this->animationScheme = kAnimationNoneStart + 1;
			}

			AnimationSchemesState::printHeader(this);
			AnimationSchemesState::showStuff(this);

			return;
		}
	}

	Base::processUserInput(this, userInput);
}

void AnimationSchemesState::showStuff()
{
	this->showDetails = false;
	AnimationSchemesState::setupBrightness(this, this->showDetails);
	AnimationSchemesState::createSprite(this);
}

void AnimationSchemesState::showDetails()
{
	AnimationSchemesState::setupBrightness(this, this->showDetails);
	AnimationSchemesState::printHeader(this);
}

void AnimationSchemesState::printHeader()
{
	Base::printHeader(this);

	if(!isDeleted(this->animatedSprite))
	{
		if(!this->showDetails)
		{
			int16 y = 3;
			Printing::text(Printing::getInstance(), "                      ", 1, y, NULL);
			Printing::text(Printing::getInstance(), __GET_CLASS_NAME(this->animatedSprite), 1, y, NULL);
			Printing::text(Printing::getInstance(), "                 ", 9, ++y, NULL);

			if(!Sprite::isObject(this->animatedSprite))
			{
				Printing::text(Printing::getInstance(), "Mode: ", 1, y, NULL);

				if(Sprite::isAffine(this->animatedSprite))
				{
					Printing::text(Printing::getInstance(), "Affine   ", 7, y, NULL);
				}
				else if(Sprite::isHBias(this->animatedSprite))
				{
					Printing::text(Printing::getInstance(), "HBias   ", 7, y, NULL);
				}
				else if(Sprite::isBgmap(this->animatedSprite))
				{
					Printing::text(Printing::getInstance(), "Bgmap    ", 7, y, NULL);
				}
			}
		}
	}	
}

void AnimationSchemesState::printSpriteDetails()
{
	if(this->showDetails && !isDeleted(this->animatedSprite))
	{
		Sprite::print(this->animatedSprite, 1, 3);
	}
}

void AnimationSchemesState::createSprite()
{
	AnimationSchemesState::destroySprite(this);

	// Check these specifications in assets/images/CogWheel/Spec/CogWheelSpec.c		
	extern SpriteSpec PunkSprite;

	SpriteSpec* spriteSpec = &PunkSprite;
/*
	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::execute);

	switch(this->animationScheme)
	{
		case kAnimationObject:

			spriteSpec = &CogWheelObjectSprite;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeSpriteHorizontalTranslation);
			break;

		case kAnimationBgmapNormal:

			spriteSpec = &CogWheelBgmapSpriteNormal;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeSpriteVerticalTranslation);
			break;

		case kAnimationBgmapAffine:

			spriteSpec = &CogWheelBgmapSpriteAffine;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeSpriteRotation);
			break;

		case kAnimationBgmapHBias:

			// Check BgmapSprite::waveEffect in source/components/graphics/Sprites/BgmapSpriteExtensions.c
			spriteSpec = &CogWheelBgmapSpriteHBias;
			break;

		case kAnimationMBgmap:

			spriteSpec = &CogWheelMBgmapSpriteNormal;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeSpriteFullTranslation);
	}
*/
	// Don't create Sprites directly
	this->animatedSprite = SpriteManager::createSprite(SpriteManager::getInstance(), spriteSpec, NULL);

	if(!isDeleted(this->animatedSprite))
	{
		extern AnimationFunctionROMSpec* PunkAnimations[];
		
		Sprite::play(this->animatedSprite, PunkAnimations, "Move", NULL);
		
		PixelVector spritePosition = {__SCREEN_WIDTH / 2, __SCREEN_HEIGHT / 2, 1, 2};
		Sprite::setPosition(this->animatedSprite, &spritePosition);
	}

	AnimationSchemesState::printHeader(this);
}

void AnimationSchemesState::destroySprite()
{
	if(!isDeleted(this->animatedSprite))
	{
		// Don't destroy the sprite directly		
		SpriteManager::destroySprite(SpriteManager::getInstance(), this->animatedSprite);

		this->animatedSprite = NULL;
	}
}

/*
 * Runtime overrides for AnimationSchemesState::execute
 */
void AnimationSchemesState::executeSpriteVerticalTranslation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->animatedSprite))
	{
		static int16 yPosition = __SCREEN_HEIGHT / 2;
		static int16 delta = 1;

		yPosition += delta;

		if(__SCREEN_HEIGHT <= (unsigned)yPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {__SCREEN_WIDTH / 2, yPosition, 1, 2};
		Sprite::setPosition(this->animatedSprite, &spritePosition);

		AnimationSchemesState::printSpriteDetails(this);
	}
}

void AnimationSchemesState::executeSpriteHorizontalTranslation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->animatedSprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 delta = 1;

		xPosition += delta;

		if(__SCREEN_WIDTH <= (unsigned)xPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {xPosition, __SCREEN_HEIGHT / 2, 1, 2};
		Sprite::setPosition(this->animatedSprite, &spritePosition);

		AnimationSchemesState::printSpriteDetails(this);
	}
}

void AnimationSchemesState::executeSpriteRotation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->animatedSprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 delta = 1;

		xPosition += delta;

		if(__SCREEN_WIDTH <= (unsigned)xPosition)
		{
			delta = -delta;
		}

		PixelVector spritePosition = {xPosition, __SCREEN_HEIGHT / 2, 1, 2};
		Sprite::setPosition(this->animatedSprite, &spritePosition);

		static fixed_t zAngle = 0;
		zAngle += __I_TO_FIXED(delta);

		Rotation rotation = {0, 0, zAngle};
		Sprite::rotate(this->animatedSprite, &rotation);

		AnimationSchemesState::printSpriteDetails(this);
	}
}

void AnimationSchemesState::executeSpriteFullTranslation(void* owner __attribute__((unused)))
{
	if(!isDeleted(this->animatedSprite))
	{
		static int16 xPosition = __SCREEN_WIDTH / 2;
		static int16 yPosition = __SCREEN_HEIGHT / 2;

		xPosition++;
		yPosition++;

		PixelVector spritePosition = {xPosition, yPosition, 1, 2};
		Sprite::setPosition(this->animatedSprite, &spritePosition);

		AnimationSchemesState::printSpriteDetails(this);
	}
}

