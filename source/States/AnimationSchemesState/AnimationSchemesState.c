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

#include <string.h>

#include <BgmapTextureManager.h>
#include <CharSet.h>
#include <DebugUtilities.h>
#include <I18n.h>
#include <Languages.h>
#include <Mem.h>
#include <Printing.h>
#include <SpriteManager.h>
#include <Texture.h>
#include <VIPManager.h>
#include <VirtualList.h>
#include <VirtualNode.h>

#include "AnimationSchemesState.h"


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------


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

	/*
	 * Check assets/stage/AnimationSchemesStageSpec.c
	 */
	extern StageROMSpec AnimationSchemesStageSpec;
	this->stageSpec = (StageSpec*)&AnimationSchemesStageSpec;
	this->animatedSprites = new VirtualList();
	this->animationScheme = kAnimationsNoneStart + 1;
	this->rotation = (Rotation){0, 0, 0};
	this->validSuboptionKeys = K_LL | K_LR | K_RU | K_RD | K_RL | K_RR;
}

// class's destructor
void AnimationSchemesState::destructor()
{
	AnimationSchemesState::destroySprites(this);

	// destroy base
	Base::destructor();
}

void AnimationSchemesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);


	if(this->showAdditionalDetails)
	{
		AnimationSchemesState::showCharMemory(this);
	}

	AnimationSchemesState::showBgmapMemory(this);
}

void AnimationSchemesState::processUserInput(const UserInput* userInput)
{
	AnimationSchemesState::playSoundEffects(this, userInput, false);

	if(K_LL & userInput->releasedKey)
	{
		if(kAnimationsNoneStart >= --this->animationScheme)
		{
			this->animationScheme = kAnimationsNoneEnd - 1;
		}

		AnimationSchemesState::show(this, true);
	}
	else if(K_LR & userInput->releasedKey)
	{
		if(kAnimationsNoneEnd <= ++this->animationScheme)
		{
			this->animationScheme = kAnimationsNoneStart + 1;
		}

		AnimationSchemesState::show(this, true);
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
		Sprite::setRotation(animatedSprite, &this->rotation);
	}

	Base::processUserInput(this, userInput);
}

void AnimationSchemesState::showControls()
{
	Printing::text(this->printing, __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_R_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_R_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_R_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_R_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

	Printing::text(this->printing, __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 10, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 11, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
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
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringAnimationsLabel), 2, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringLinkedListsLabel), 2, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, "*AnimatedSprite", 2, y++, NULL);
	Printing::text(this->printing, "VirtualList", 2, y++, NULL);
	Printing::text(this->printing, "VirtualNode", 2, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, "AnimationSchemesState", 2, y++, NULL);
	Printing::text(this->printing, " execute*", 2, y++, NULL);
	Printing::text(this->printing, " createSprites", 2, y++, NULL);
	Printing::text(this->printing, " destroySprites", 2, y++, NULL);
	y++;

	if(kAnimationsMultiframeTexture != this->animationScheme)
	{
		Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "Debug");
		Printing::text(this->printing, "PunkSprite*Spec", 2, y++, NULL);
	}

	y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringAnimationSubtitle), 28, y++, "Debug");
	
	switch(this->animationScheme)
	{
		case kAnimationsNotSharedTexture:

			Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringNotSharedLabel), 28, y++, NULL);
			break;

		case kAnimationsSharedTexture:

			Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSharedLabel), 28, y++, NULL);
			break;

		case kAnimationsMultiframeTexture:

			Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMultiframeLabel), 28, y++, NULL);
			break;
	}

	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringBgmapMemoryLabel), 28, 18, NULL);
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

		Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringAnimationSubtitle), 28, y++, "Debug");
		
		switch(this->animationScheme)
		{
			case kAnimationsNotSharedTexture:

				Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringNotSharedLabel), 28, y++, NULL);
				break;

			case kAnimationsSharedTexture:

				Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSharedLabel), 28, y++, NULL);
				break;

			case kAnimationsMultiframeTexture:

				Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMultiframeLabel), 28, y++, NULL);
				break;
		}

		switch(this->animationScheme)
		{
			case kAnimationsNotSharedTexture:

				y = 8;
				Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringNotSharedTextureLabel), 2, y, NULL);
				y += 6;
				break;

			case kAnimationsSharedTexture:
	
				y = 8;
				Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSharedTextureLabel), 2, y, NULL);
				y += 6;
				break;

			case kAnimationsMultiframeTexture:

				y = 3;
				Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMultiframeTextureLabel), 2, y, NULL);
				y += 3;
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

		Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringCharMemoryLabel), 2, ++y, NULL);
		Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringBgmapMemoryLabel), 28, 18, NULL);
	}
}

void AnimationSchemesState::createSprites()
{
	// Virtual methods can be changed in real time (the change affects all the class instances, but this is a singleton)
	AnimationSchemesState::restoreMethods();

	// Check these specifications in assets/images/Punk/Spec/PunkSpec.c		
	extern SpriteSpec PunkSpriteNotSharedSpec;
	extern SpriteSpec PunkSpriteSharedSpec;
	extern SpriteSpec PunkSpriteMultiframeSpec;

	SpriteSpec* spriteSpec = &PunkSpriteNotSharedSpec;

	switch(this->animationScheme)
	{
		case kAnimationsNotSharedTexture:

			/* When Sprites use non shared Textures they all have to
			* update their graphics when animated. Each will reserve its
			* own chunk of graphics memory and updating all of them
			* will require more processing resources.	 
			*/
			spriteSpec = &PunkSpriteNotSharedSpec;
			AnimationSchemesState::mutateMethod(showCharMemory, AnimationSchemesState::showCharMemoryForNotSharedTextures);
			break;

		case kAnimationsSharedTexture:

			/* When Sprites share a Texture (and the underlying CharSet)
			* animating one of them will animate the others because the
			* underlying graphics are shared by all of them.
			* This saves on performance too because the graphics memory
			* is only updated once.
			*/
			spriteSpec = &PunkSpriteSharedSpec;
			AnimationSchemesState::mutateMethod(showCharMemory, AnimationSchemesState::showCharMemoryForSharedTextures);
			break;

		case kAnimationsMultiframeTexture:

			/* Multiframe Textures write all the frames of animation in graphics memory.
			* They should always be shared, otherwise processing power would be wasted
			* by writing multiple times the same spreadsheet.
			* The animations of the Sprites that use these Textures are not constrained 
			* to be in sync.
			*/
			spriteSpec = &PunkSpriteMultiframeSpec;
			AnimationSchemesState::mutateMethod(showCharMemory, AnimationSchemesState::showCharMemoryForMultiframeTextures);
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

			extern AnimationFunctionROMSpec* PunkAnimationSpecs[];
			
			PixelVector spritePosition = {__SCREEN_WIDTH / 2 + __SCREEN_WIDTH / 4 + 48 * (i - 1), __SCREEN_HEIGHT / 2 - 24, 1, 2};
			Sprite::setPosition(animatedSprite, &spritePosition);
			
			Sprite::play(animatedSprite, PunkAnimationSpecs, "Move", NULL);

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

	/*
	 * Cleaning graphics memory explicitly should not be done in general, the engine takes 
	 * care of this when swapping states. We do it here becuase BGMAP memory cannot be 
	 * defragmented and loading non shared textures would quickly deplete it.
	 */ 
	BgmapTextureManager::reset(BgmapTextureManager::getInstance());
	VIPManager::clearBgmapSegment(VIPManager::getInstance(), 0, 64 * 64);
}

/*
 * Virtual methods can be changed in runtime to alter a class' behavior in real time.
 * Mutating the methods affects all the instances of the class.
 * Runtime overrides for AnimationSchemesState::showCharMemory.
 */
void AnimationSchemesState::showCharMemory()
{
}

void AnimationSchemesState::showBgmapMemory()
{
	uint32 printingBgmap = BgmapTextureManager::getPrintingBgmapSegment(BgmapTextureManager::getInstance());
	int32 topBorder = 20;
	int32 bottomBorder = 1;
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