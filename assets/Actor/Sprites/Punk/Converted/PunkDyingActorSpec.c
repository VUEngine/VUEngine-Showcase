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

extern uint32 PunkDyingActorPunkDyingTiles[];
extern uint16 PunkDyingActorPunkDyingMap[];

extern uint32 PunkDyingActorPunkDyingBlackTiles[];
extern uint16 PunkDyingActorPunkDyingBlackMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec PunkDyingAnimation1AnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	20,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
		10, 11, 12, 13, 14, 15, 16, 17, 18, 10, 
	},

	// Number of cycles a frame of animation is displayed
	4,

	// Whether to play it in loop or not
	false,

	// Animation's name
	"Die",
};

AnimationFunctionROMSpec* PunkDyingAnimationSpecs[] =
{
	(AnimationFunction*)&PunkDyingAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec PunkDyingSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	48,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkDyingActorPunkDyingTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkDyingSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkDyingSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkDyingActorPunkDyingMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recycle the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec PunkDyingSprite1SpriteSpec =
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
			(const AnimationFunction**)PunkDyingAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkDyingSprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 1, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec PunkDyingSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	48,

	// Whether it is shared or not
	false,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkDyingActorPunkDyingBlackTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkDyingSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkDyingSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkDyingActorPunkDyingBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// padding for affine/hbias transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recycle the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec PunkDyingSprite2SpriteSpec =
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
			(const AnimationFunction**)PunkDyingAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkDyingSprite2TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PunkDyingComponentSpecs[] = 
{
	(ComponentSpec*)&PunkDyingSprite1SpriteSpec,
	(ComponentSpec*)&PunkDyingSprite2SpriteSpec,
	NULL
};

ActorROMSpec PunkDyingActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PunkDyingComponentSpecs,

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
	"Die"
	
};
