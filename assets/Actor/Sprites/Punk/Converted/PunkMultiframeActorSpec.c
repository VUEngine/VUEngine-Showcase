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

extern uint32 PunkMultiframeActorPunkTiles[];
extern uint16 PunkMultiframeActorPunkMap[];

extern uint32 PunkMultiframeActorPunkBlackTiles[];
extern uint16 PunkMultiframeActorPunkBlackMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec PunkMultiframeAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	12,

	// Frames to play in animation
	{
		9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 
		7, 8, 
	},

	// Number of cycles a frame of animation is displayed
	4,

	// Whether to play it in loop or not
	true,

	// Animation's name
	"Move",
};

AnimationFunctionROMSpec* PunkMultiframeAnimationSpecs[] =
{
	(AnimationFunction*)&PunkMultiframeAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec PunkMultiframeSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	288,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkMultiframeActorPunkTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkMultiframeSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkMultiframeSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkMultiframeActorPunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	12,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recycle the texture with a different map
	true,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec PunkMultiframeSprite1SpriteSpec =
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
			(const AnimationFunction**)PunkMultiframeAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkMultiframeSprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec PunkMultiframeSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	288,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkMultiframeActorPunkBlackTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkMultiframeSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkMultiframeSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkMultiframeActorPunkBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	12,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recycle the texture with a different map
	true,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec PunkMultiframeSprite2SpriteSpec =
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
			(const AnimationFunction**)PunkMultiframeAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkMultiframeSprite2TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 1, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PunkMultiframeComponentSpecs[] = 
{
	(ComponentSpec*)&PunkMultiframeSprite1SpriteSpec,
	(ComponentSpec*)&PunkMultiframeSprite2SpriteSpec,
	NULL
};

ActorROMSpec PunkMultiframeActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PunkMultiframeComponentSpecs,

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
	"Move"
	
};
