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

#include <BgmapTextureManager.h>
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
	this->rotation = (Rotation){0, 0, 0};
}

// class's destructor
void AnimationSchemesState::destructor()
{
	AnimationSchemesState::destroySprites(this);

	// destroy base
	Base::destructor();
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

			AnimationSchemesState::show(this, true);
			
			return;
		}
		else if(K_LR & userInput->releasedKey)
		{
			if(kAnimationsNoneEnd <= ++this->animationScheme)
			{
				this->animationScheme = kAnimationsNoneStart + 1;
			}

			AnimationSchemesState::show(this, true);

			return;
		}
		/*
		 * Non affine sprites cannot be rotated, but can be mirrored vertically and horizontally through a this->rotation.
		 */
		if(K_RU & userInput->releasedKey)
		{
			this->rotation.x = __I_TO_FIXED(255);
		}
		else if(K_RD & userInput->releasedKey)
		{
			this->rotation.x = 0;
		}
		else if(K_RL & userInput->releasedKey)
		{
			this->rotation.y = __I_TO_FIXED(255);
		}
		else if(K_RR & userInput->releasedKey)
		{
			this->rotation.y = 0;
		}

		Sprite animatedSprite = Sprite::safeCast(VirtualList::getObjectAtPosition(this->animatedSprites, 1));
			
		if(!isDeleted(animatedSprite))
		{
			Sprite::rotate(animatedSprite, &this->rotation);
		}
	}

	Base::processUserInput(this, userInput);
}

void AnimationSchemesState::showStuff()
{
	this->rotation = (Rotation){0, 0, 0};

	AnimationSchemesState::destroySprites(this);
	AnimationSchemesState::createSprites(this);
}

void AnimationSchemesState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), "CONCEPTS ", 1, y++, "Debug");
	Printing::text(Printing::getInstance(), "  Animations", 1, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "OTHER CONCEPTS: ", 1, y++, "Debug");
	Printing::text(Printing::getInstance(), "  Lists", 1, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "CLASSES: ", 1, y++, "Debug");
	Printing::text(Printing::getInstance(), "  *AnimatedSprite", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "  VirtualList", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "  VirtualNode", 1, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "METHODS: ", 1, y++, "Debug");
	Printing::text(Printing::getInstance(), "  AnimationSchemesState", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "    execute*", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "    createSprites", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "    destroySprites", 1, y++, NULL);
	y++;

	if(kAnimationsMultiframeTexture != this->animationScheme)
	{
		Printing::text(Printing::getInstance(), "SPECS: ", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "  PunkSprite*", 1, y++, NULL);
	}

	y = 3;
	
	switch(this->animationScheme)
	{
		case kAnimationsNotSharedTexture:

			Printing::text(Printing::getInstance(), "Not shared", 28, y++, NULL);
			Printing::text(Printing::getInstance(), "animation", 28, y++, NULL);
			break;

		case kAnimationsSharedTexture:

			Printing::text(Printing::getInstance(), "Shared animation", 28, y++, NULL);
			break;

		case kAnimationsMultiframeTexture:

			Printing::text(Printing::getInstance(), "Multiframe", 28, y++, NULL);
			Printing::text(Printing::getInstance(), "animation", 28, y++, NULL);
			break;
	}


	Printing::text(Printing::getInstance(), "BGMAP memory: ", 28, 18, NULL);
}


void AnimationSchemesState::showAdditionalDetails()
{
	AnimationSchemesState::showAnimationDetails(this);
}

void AnimationSchemesState::showAnimationDetails()
{
	if(!isDeleted(this->animatedSprites))
	{
		int16 y = 3;

		switch(this->animationScheme)
		{
			case kAnimationsNotSharedTexture:

				Printing::text(Printing::getInstance(), "Not shared", 28, y++, NULL);
				Printing::text(Printing::getInstance(), "animation", 28, y++, NULL);
				break;

			case kAnimationsSharedTexture:

				Printing::text(Printing::getInstance(), "Shared animation", 28, y++, NULL);
				break;

			case kAnimationsMultiframeTexture:

				Printing::text(Printing::getInstance(), "Multiframe", 28, y++, NULL);
				Printing::text(Printing::getInstance(), "animation", 28, y++, NULL);
				break;
		}

		switch(this->animationScheme)
		{
			case kAnimationsNotSharedTexture:

				y = 7;
				Printing::text(Printing::getInstance(), " Each sprite has its ", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " own set of tiles and", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " its own texture", 1, ++y, NULL);
				y++;
				Printing::text(Printing::getInstance(), " Each one has to be", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " animated individually", 1, ++y, NULL);
				break;

			case kAnimationsSharedTexture:
	
				y = 7;
				Printing::text(Printing::getInstance(), " All sprites share ", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " the same tiles set", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " and the same texture", 1, ++y, NULL);
				y++;
				Printing::text(Printing::getInstance(), " Animations only need", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " to run in one of the", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " sprites", 1, ++y, NULL);

				break;

			case kAnimationsMultiframeTexture:

				y = 2;
				Printing::text(Printing::getInstance(), " The sprites share the", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " graphis but each can", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " show a different frame", 1, ++y, NULL);
				Printing::text(Printing::getInstance(), " from the same texture", 1, ++y, NULL);
				break;
		}

		y++;

		if(kAnimationsMultiframeTexture == this->animationScheme)
		{
			y++;
		}
		else
		{
			y = 17;
		}

		Printing::text(Printing::getInstance(), "CHAR memory: ", 1, ++y, NULL);

		Printing::text(Printing::getInstance(), "BGMAP memory: ", 28, 18, NULL);
	}
}

void AnimationSchemesState::createSprites()
{
	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	AnimationSchemesState::restoreMethods();

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
			
			PixelVector spritePosition = {__SCREEN_WIDTH / 2 + __SCREEN_WIDTH / 4 + 48 * (i - 1), __SCREEN_HEIGHT / 2 - 24, 1, 2};
			Sprite::setPosition(animatedSprite, &spritePosition);
			
			Sprite::play(animatedSprite, PunkAnimations, "Move", NULL);

			// Try to get the sprite's animation out of sync from the others'
			Sprite::setActualFrame(animatedSprite, i * 12 / 3);
		}
	}
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
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Runtime overrides for AnimationSchemesState::execute.
 */
void AnimationSchemesState::executeAnimateSpritesWithNotSharedTextures(void* owner __attribute__((unused)))
{
	/* When Sprites use non shared Textures they all have to be
	 * update their graphics when animated. Each will reserve its
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

	if(this->showAdditionalDetails)
	{
		AnimationSchemesState::showCharMemoryForNotSharedTextures(this);
	}
	AnimationSchemesState::showBgmapMemory(this);
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

	if(this->showAdditionalDetails)
	{
		AnimationSchemesState::showCharMemoryForSharedTextures(this);
	}
	AnimationSchemesState::showBgmapMemory(this);
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

	if(this->showAdditionalDetails)
	{
		AnimationSchemesState::showCharMemoryForMultiframeTextures(this);
	}

	AnimationSchemesState::showBgmapMemory(this);
}

void AnimationSchemesState::showBgmapMemory()
{
	uint32 printingBgmap = BgmapTextureManager::getPrintingBgmapSegment(BgmapTextureManager::getInstance());
	int32 topBorder = 20;
	int32 bottomBorder = 0;
	int32 leftBorder = kAnimationsMultiframeTexture != this->animationScheme ? 28 : 1;
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
	int32 topBorder = 21;
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
	int32 topBorder = 21;
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
	
	if(isDeleted(animatedSprite))
	{
		return;
	}

	texture = Sprite::getTexture(animatedSprite);

	if(isDeleted(texture))
	{
		return;
	}

	charSet = Texture::getCharSet(texture, false);

	if(isDeleted(charSet))
	{
		return;
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
	int32 topBorder = 11;
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
	
	if(isDeleted(animatedSprite))
	{
		return;
	}

	texture = Sprite::getTexture(animatedSprite);

	if(isDeleted(texture))
	{
		return;
	}

	charSet = Texture::getCharSet(texture, false);

	if(isDeleted(charSet))
	{
		return;
	}

	int16 charsPerFrame = CharSet::getNumberOfChars(charSet) / Texture::getNumberOfFrames(texture);
	int32 xOffset = leftBorder;
	int16 yOffset = topBorder;

	// put the map into memory calculating the number of char for each reference
	for(uint16 frame = 0; frame <= Texture::getNumberOfFrames(texture); frame++, yOffset += 1)
	{
		if(18 <= yOffset)
		{
			break;
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