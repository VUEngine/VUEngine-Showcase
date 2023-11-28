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
#include <VirtualList.h>
#include <VirtualNode.h>

#include <debugUtilities.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec AnimationSchemesStage;


enum AnimationSchemes
{
	kAnimationsNoneStart = 0,
	kAnimationsNotSharedTexture,
	kAnimationsSharedTexture,
	kAnimationsMultiframeTexture,

	kAnimationsNoneEnd
};


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void AnimationSchemesState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&AnimationSchemesStage;
	this->animatedSprites = new VirtualList();
	this->animationScheme = kAnimationsNoneStart + 1;
}

// class's destructor
void AnimationSchemesState::destructor()
{
	AnimationSchemesState::destroySprites(this);

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
			if(kAnimationsNoneStart >= --this->animationScheme)
			{
				this->animationScheme = kAnimationsNoneEnd - 1;
			}

			AnimationSchemesState::printHeader(this);
			AnimationSchemesState::showStuff(this);
			
			return;
		}
		else if(K_LR & userInput->releasedKey)
		{
			if(kAnimationsNoneEnd <= ++this->animationScheme)
			{
				this->animationScheme = kAnimationsNoneStart + 1;
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
	AnimationSchemesState::createSprites(this);
}

void AnimationSchemesState::showDetails()
{
	AnimationSchemesState::setupBrightness(this, this->showDetails);
	AnimationSchemesState::printHeader(this);
}

void AnimationSchemesState::printHeader()
{
	Base::printHeader(this);

	if(!isDeleted(this->animatedSprites))
	{
		if(!this->showDetails)
		{
			int16 y = 3;
			Printing::text(Printing::getInstance(), "                      ", 1, y, NULL);
			Printing::text(Printing::getInstance(), "Mode: ", 1, y, NULL);

			switch(this->animationScheme)
			{
				case kAnimationsNotSharedTexture:

					Printing::text(Printing::getInstance(), "Not shared animations   ", 7, y, NULL);
					break;

				case kAnimationsSharedTexture:

					Printing::text(Printing::getInstance(), "Shared animations   ", 7, y, NULL);
					break;

				case kAnimationsMultiframeTexture:

					Printing::text(Printing::getInstance(), "Multiframe animations   ", 7, y, NULL);
					break;
			}
		}
	}	
}

void AnimationSchemesState::printSpriteDetails()
{
	if(this->showDetails && !isDeleted(this->animatedSprites))
	{
	}
}

void AnimationSchemesState::createSprites()
{
	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::execute);

	AnimationSchemesState::destroySprites(this);

	// Check these specifications in assets/images/Punk/Spec/PunkSpec.c		
	extern SpriteSpec PunkSpriteNotShared;
	extern SpriteSpec PunkSpriteShared;
	extern SpriteSpec PunkSpriteMultiframe;

	SpriteSpec* spriteSpec = &PunkSpriteNotShared;

	switch(this->animationScheme)
	{
		case kAnimationsNotSharedTexture:

			spriteSpec = &PunkSpriteNotShared;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeAnimateSpritesWithNotSharedTextures);
			break;

		case kAnimationsSharedTexture:

			spriteSpec = &PunkSpriteShared;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeAnimateSpritesWithSharedTextures);
			break;

		case kAnimationsMultiframeTexture:

			spriteSpec = &PunkSpriteMultiframe;
			AnimationSchemesState::mutateMethod(execute, AnimationSchemesState::executeAnimateSpritesWithMultiframeTextures);
			break;
	}

    for(int16 i = 0; i < 3; i++)
    {
		// Don't create Sprites directly
        Sprite animatedSprite = SpriteManager::createSprite(SpriteManager::getInstance(), spriteSpec, NULL);

		if(!isDeleted(animatedSprite))
		{
			extern AnimationFunctionROMSpec* PunkAnimations[];
			
			Sprite::play(animatedSprite, PunkAnimations, "Move", NULL);

			// Try to get the sprite's animation out of sync from the others'
			Sprite::setActualFrame(animatedSprite, i * 12 / 3);			
			
			PixelVector spritePosition = {__SCREEN_WIDTH / 2 - 64 * (i - 1), __SCREEN_HEIGHT / 2, 1, 2};
			Sprite::setPosition(animatedSprite, &spritePosition);

			VirtualList::pushBack(this->animatedSprites, animatedSprite);
		}
	}

	AnimationSchemesState::printHeader(this);
}

void AnimationSchemesState::destroySprites()
{
	if(!isDeleted(this->animatedSprites))
	{
		for(VirtualNode node = VirtualList::begin(this->animatedSprites); NULL != node; node = VirtualNode::getNext(node))
		{
			Sprite animatedSprite = Sprite::safeCast(VirtualNode::getData(node));
			
			if(!isDeleted(animatedSprite))
			{
				// Don't destroy the sprite directly		
				SpriteManager::destroySprite(SpriteManager::getInstance(), animatedSprite);				
			}
		}

		VirtualList::clear(this->animatedSprites);
	}
}

/*
 * Runtime overrides for AnimationSchemesState::execute
 */
void AnimationSchemesState::executeAnimateSpritesWithNotSharedTextures(void* owner __attribute__((unused)))
{
	/* When Sprites use non shared Textures they all have to be
	 * update their graphics when animated. Each will reserver its
	 * own chunk of graphics memory and updating all of them
	 * will be heavier.	 
	 */
	for(VirtualNode node = VirtualList::begin(this->animatedSprites); NULL != node; node = VirtualNode::getNext(node))
	{
		Sprite animatedSprite = Sprite::safeCast(VirtualNode::getData(node));
		
		if(!isDeleted(animatedSprite))
		{
			Sprite::updateAnimation(animatedSprite);
		}
	}
}

void AnimationSchemesState::executeAnimateSpritesWithSharedTextures(void* owner __attribute__((unused)))
{
	/* When Sprites share a Texture (and the underlying CharSet)
	 * animating one of them will animate the other because the
	 * underlying graphics are shared by all of them.
	 * This saves on performance too because the graphics memory
	 * is only updated once.
	 */	 

	Sprite animatedSprite = Sprite::safeCast(VirtualList::front(this->animatedSprites));
	
	if(!isDeleted(animatedSprite))
	{
		Sprite::updateAnimation(animatedSprite);
	}
}

void AnimationSchemesState::executeAnimateSpritesWithMultiframeTextures(void* owner __attribute__((unused)))
{
	/* Multiframe Textures write all the frames of animation in graphics memory.
	 * They should always be shared Texture, otherwise graphics memory would be
	 * wasted by writing multiple times the same spreadsheet.
	 * The animations of the Sprites that use these Textures are not constrained 
	 * to be in sync.
	 */
	for(VirtualNode node = VirtualList::begin(this->animatedSprites); NULL != node; node = VirtualNode::getNext(node))
	{
		Sprite animatedSprite = Sprite::safeCast(VirtualNode::getData(node));
		
		if(!isDeleted(animatedSprite))
		{
			Sprite::updateAnimation(animatedSprite);
		}
	}
}