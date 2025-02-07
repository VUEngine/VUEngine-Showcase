////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <BgmapSprite.h>
#include <InGameTypes.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 VideoActorVideoL064LTiles[];
extern uint16 VideoActorVideoL064LMap[];
extern uint32 VideoActorVideoL064LTilesFrameOffsets[];
extern uint32 VideoActorVideoR064RTiles[];
extern uint16 VideoActorVideoR064RMap[];
extern uint32 VideoActorVideoR064RTilesFrameOffsets[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec VideoAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	114,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
		30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
		40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 
		50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 
		60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 
		70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 
		80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 
		90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 
		100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 
		110, 111, 112, 113, 
	},

	// Number of cycles a frame of animation is displayed
	1,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"FrameBlend",
};

AnimationFunctionROMSpec VideoAnimation2AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	114,

	// Frames to play in animation
	{
		0, 0, 2, 2, 4, 4, 6, 6, 8, 8, 
		10, 10, 12, 12, 14, 14, 16, 16, 18, 18, 
		20, 20, 22, 22, 24, 24, 26, 26, 28, 28, 
		30, 30, 32, 32, 34, 34, 36, 36, 38, 38, 
		40, 40, 42, 42, 44, 44, 46, 46, 48, 48, 
		50, 50, 52, 52, 54, 54, 56, 56, 58, 58, 
		60, 60, 62, 62, 64, 64, 66, 66, 68, 68, 
		70, 70, 72, 72, 74, 74, 76, 76, 78, 78, 
		80, 80, 82, 82, 84, 84, 86, 86, 88, 88, 
		90, 90, 92, 92, 94, 94, 96, 96, 98, 98, 
		100, 100, 102, 102, 104, 104, 106, 106, 108, 108, 
		110, 110, 112, 112, 
	},

	// Number of cycles a frame of animation is displayed
	1,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"4Color",
};

AnimationFunctionROMSpec* VideoAnimationSpecs[] =
{
	(AnimationFunction*)&VideoAnimation1AnimationSpec,
	(AnimationFunction*)&VideoAnimation2AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec VideoSprite1LCharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	632,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	VideoActorVideoL064LTiles,

	// Frame offsets array
	VideoActorVideoL064LTilesFrameOffsets
};

TextureROMSpec VideoSprite1LTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&VideoSprite1LCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	VideoActorVideoL064LMap,

	// Horizontal size in tiles of the texture (max. 64)
	48,

	// Vertical size in tiles of the texture (max. 64)
	28,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec VideoSprite1LSpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)VideoAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&VideoSprite1LTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_LON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec VideoSprite1RCharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	647,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	VideoActorVideoR064RTiles,

	// Frame offsets array
	VideoActorVideoR064RTilesFrameOffsets
};

TextureROMSpec VideoSprite1RTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&VideoSprite1RCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	VideoActorVideoR064RMap,

	// Horizontal size in tiles of the texture (max. 64)
	48,

	// Vertical size in tiles of the texture (max. 64)
	28,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec VideoSprite1RSpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)VideoAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&VideoSprite1RTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_RON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const VideoComponentSpecs[] = 
{
	(ComponentSpec*)&VideoSprite1LSpriteSpec,
	(ComponentSpec*)&VideoSprite1RSpriteSpec,
	NULL
};

ActorROMSpec VideoActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)VideoComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Animation to play automatically
	"FrameBlend"
	
};
