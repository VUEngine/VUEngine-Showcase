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
#include <BgmapTextureManager.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <CharSet.h>
#include <Mem.h>
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
		/*
		 * Non affine sprites cannot be rotated, but can be mirrored vertically and horizontally through a Rotation.
		 */

		static Rotation rotation = {0, 0, 0};

		if(K_RU & userInput->releasedKey)
		{
			rotation.x = __I_TO_FIXED(255);
		}
		else if(K_RD & userInput->releasedKey)
		{
			rotation.x = 0;
		}
		else if(K_RL & userInput->releasedKey)
		{
			rotation.y = __I_TO_FIXED(255);
		}
		else if(K_RR & userInput->releasedKey)
		{
			rotation.y = 0;
		}

		Sprite animatedSprite = Sprite::safeCast(VirtualList::getObjectAtPosition(this->animatedSprites, 1));
			
		if(!isDeleted(animatedSprite))
		{
			Sprite::rotate(animatedSprite, &rotation);
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
		int16 y = 3;
		Printing::text(Printing::getInstance(), "                      ", 1, y, NULL);
		Printing::text(Printing::getInstance(), "Animation schene: ", 1, y, NULL);

		switch(this->animationScheme)
		{
			case kAnimationsNotSharedTexture:

				Printing::text(Printing::getInstance(), "Not shared   ", 19, y, NULL);

				if(this->showDetails)
				{
					Printing::text(Printing::getInstance(), "Char memory:", 1, 16, NULL);
					Printing::text(Printing::getInstance(), "Each sprite has its own set of tiles", 1, y + 2, NULL);
				}
				else
				{
					Printing::text(Printing::getInstance(), "Bgmap memory: ", 1, 16, NULL);
					Printing::text(Printing::getInstance(), "Each sprite has its own texture", 1, y + 2, NULL);
				}
				break;

			case kAnimationsSharedTexture:

				Printing::text(Printing::getInstance(), "Shared   ", 19, y, NULL);

				if(this->showDetails)
				{
					Printing::text(Printing::getInstance(), "Char memory:", 1, 16, NULL);
					Printing::text(Printing::getInstance(), "All sprites share the same tiles set", 1, y + 2, NULL);
				}
				else
				{
					Printing::text(Printing::getInstance(), "Bgmap memory: ", 1, 16, NULL);
					Printing::text(Printing::getInstance(), "All sprites share the same texture", 1, y + 2, NULL);
				}
				break;

			case kAnimationsMultiframeTexture:

				Printing::text(Printing::getInstance(), "Multiframe   ", 19, y, NULL);

				if(this->showDetails)
				{
					Printing::text(Printing::getInstance(), "Char memory:", 1, 16, NULL);
					Printing::text(Printing::getInstance(), "All sprites share the same tiles set", 1, y + 2, NULL);
				}
				else
				{
					Printing::text(Printing::getInstance(), "Bgmap memory: ", 1, 16, NULL);
					Printing::text(Printing::getInstance(), "Each sprite shows a frame from the same texture", 1, y + 2, NULL);
				}
				break;
		}
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
			// I will need to access the sprites later on
			VirtualList::pushBack(this->animatedSprites, animatedSprite);

			extern AnimationFunctionROMSpec* PunkAnimations[];
			
			PixelVector spritePosition = {__SCREEN_WIDTH / 2 + 64 * (i - 1), __SCREEN_HEIGHT / 2 - 24, 1, 2};
			Sprite::setPosition(animatedSprite, &spritePosition);
			
			Sprite::play(animatedSprite, PunkAnimations, "Move", NULL);

			// Try to get the sprite's animation out of sync from the others'
			Sprite::setActualFrame(animatedSprite, i * 12 / 3);
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

	// Clean manually graphics memory (the engine takes care of this when swapping states)
	BgmapTextureManager::reset(BgmapTextureManager::getInstance());
	VIPManager::clearBgmapSegment(VIPManager::getInstance(), 0, 64 * 64);
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

	if(this->showDetails)
	{
		AnimationSchemesState::showCharMemoryForNotSharedTextures(this);
	}
	else
	{
		AnimationSchemesState::showBgmapMemory(this);
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

	if(this->showDetails)
	{
		AnimationSchemesState::showCharMemoryForSharedTextures(this);
	}
	else
	{
		AnimationSchemesState::showBgmapMemory(this);
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

	if(this->showDetails)
	{
		AnimationSchemesState::showCharMemoryForMultiframeTextures(this);
	}
	else
	{
		AnimationSchemesState::showBgmapMemory(this);
	}
}

void AnimationSchemesState::showBgmapMemory()
{
	uint32 printingBgmap = BgmapTextureManager::getPrintingBgmapSegment(BgmapTextureManager::getInstance());
	int32 topBorder = 19;
	int32 bottomBorder = 0;
	int32 leftBorder = 1;
	int32 rightBorder = 0;
	int32 mxDisplacement = 0;
	int32 myDisplacement = 0;

	uint32 numberOfHWORDS = __SCREEN_WIDTH_IN_CHARS - leftBorder - rightBorder;
	uint32 xOffset = leftBorder;

	uint16* const bgmapSpaceBaseAddress = (uint16*)__BGMAP_SPACE_BASE_ADDRESS;

	for(int32 row = 0; row < __SCREEN_HEIGHT_IN_CHARS - topBorder - bottomBorder; row++)
	{
		Mem::copyHWORD
		(
			(HWORD*)(&bgmapSpaceBaseAddress[(0x1000 * (printingBgmap + 1) - __PRINTABLE_BGMAP_AREA) + ((row + topBorder) << 6) + xOffset]),
			(const HWORD*)(&bgmapSpaceBaseAddress[(0x1000 * (0)) + ((row + myDisplacement) << 6) + mxDisplacement]), 
			numberOfHWORDS
		);
	}
}

void AnimationSchemesState::showCharMemoryForNotSharedTextures()
{
	uint32 printingBgmap = BgmapTextureManager::getPrintingBgmapSegment(BgmapTextureManager::getInstance());
	int32 topBorder = 18;
	int32 leftBorder = 1;

	uint16* const bgmapSpaceBaseAddress = (uint16*)__BGMAP_SPACE_BASE_ADDRESS;

	const HWORD charMemoryMap[] =
	{
		0,	1,	2,	3,	4,	5,	6,	7,
		8,	9,	10,	11,	12,	13,	14,	15,
		16,	17,	18,	19,	20,	21,	22,	23,
		24,	25,	26,	27,	28,	29,	30,	31
	};

	int16 row = 0;
	uint32 xOffset = leftBorder;

	for(VirtualNode node = VirtualList::begin(this->animatedSprites); NULL != node; node = VirtualNode::getNext(node), row += 2)
	{
		Sprite animatedSprite = Sprite::safeCast(VirtualNode::getData(node));
		
		if(isDeleted(animatedSprite))
		{
			continue;
		}

		Texture texture = Sprite::getTexture(animatedSprite);

		if(isDeleted(texture))
		{
			continue;
		}

		CharSet charSet = Texture::getCharSet(texture, false);

		if(isDeleted(charSet))
		{
			continue;
		}

		Mem::addHWORD
		(
			(HWORD*)(&bgmapSpaceBaseAddress[(0x1000 * (printingBgmap + 1) - __PRINTABLE_BGMAP_AREA) + ((row + topBorder) << 6) + xOffset]),
			(HWORD*)charMemoryMap,
			CharSet::getNumberOfChars(charSet),
			CharSet::getOffset(charSet)
		);
	}
}

void AnimationSchemesState::showCharMemoryForSharedTextures()
{
	uint32 printingBgmap = BgmapTextureManager::getPrintingBgmapSegment(BgmapTextureManager::getInstance());
	int32 topBorder = 18;
	int32 leftBorder = 1;

	uint16* const bgmapSpaceBaseAddress = (uint16*)__BGMAP_SPACE_BASE_ADDRESS;

	const HWORD charMemoryMap[] =
	{
		0,	1,	2,	3,	4,	5,	6,	7,
		8,	9,	10,	11,	12,	13,	14,	15,
		16,	17,	18,	19,	20,	21,	22,	23,
		24,	25,	26,	27,	28,	29,	30,	31
	};

	Sprite animatedSprite = Sprite::safeCast(VirtualList::front(this->animatedSprites));
	Texture texture = NULL;
	CharSet charSet = NULL;
	
	if(!isDeleted(animatedSprite))
	{
		texture = Sprite::getTexture(animatedSprite);
	}

	if(!isDeleted(texture))
	{
		charSet = Texture::getCharSet(texture, false);
	}

	uint32 xOffset = leftBorder;

	Mem::addHWORD
	(
		(HWORD*)(&bgmapSpaceBaseAddress[(0x1000 * (printingBgmap + 1) - __PRINTABLE_BGMAP_AREA) + ((topBorder) << 6) + xOffset]),
		(HWORD*)charMemoryMap,
		CharSet::getNumberOfChars(charSet),
		CharSet::getOffset(charSet)
	);
}

void AnimationSchemesState::showCharMemoryForMultiframeTextures()
{
	uint32 printingBgmap = BgmapTextureManager::getPrintingBgmapSegment(BgmapTextureManager::getInstance());
	int32 topBorder = 18;
	int32 leftBorder = 0;

	uint16* const bgmapSpaceBaseAddress = (uint16*)__BGMAP_SPACE_BASE_ADDRESS;

	const HWORD charMemoryMap[] =
	{
		0,	1,	2,	3,	4,	5,	6,	7,
		8,	9,	10,	11,	12,	13,	14,	15,
		16,	17,	18,	19,	20,	21,	22,	23,
		24,	25,	26,	27,	28,	29,	30,	31
	};

	Sprite animatedSprite = Sprite::safeCast(VirtualList::front(this->animatedSprites));
	Texture texture = NULL;
	CharSet charSet = NULL;
	
	if(!isDeleted(animatedSprite))
	{
		texture = Sprite::getTexture(animatedSprite);
	}

	if(!isDeleted(texture))
	{
		charSet = Texture::getCharSet(texture, false);
	}

	int16 charsPerFrame = CharSet::getNumberOfChars(charSet) / Texture::getNumberOfFrames(texture);
	int32 xOffset = leftBorder;
	int16 yOffset = topBorder;

	// put the map into memory calculating the number of char for each reference
	for(uint16 frame = 0; frame <= Texture::getNumberOfFrames(texture); frame++, yOffset += 2)
	{
		if(__SCREEN_HEIGHT_IN_CHARS <= yOffset)
		{
			xOffset += charsPerFrame;

			if(__SCREEN_WIDTH_IN_CHARS <= xOffset)
			{
				break;
			}

			yOffset = topBorder;
		}

		Mem::addHWORD
		(
			(HWORD*)(&bgmapSpaceBaseAddress[(0x1000 * (printingBgmap + 1) - __PRINTABLE_BGMAP_AREA) + ((yOffset) << 6) + xOffset]),
			(HWORD*)charMemoryMap,
			charsPerFrame,
			CharSet::getOffset(charSet) + frame * charsPerFrame
		);
	}
}