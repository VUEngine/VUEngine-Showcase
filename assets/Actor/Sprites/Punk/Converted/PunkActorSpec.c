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

extern uint32 PunkActorPunkTiles[];
extern uint16 PunkActorPunkMap[];

extern uint32 PunkActorPunkBlackTiles[];
extern uint16 PunkActorPunkBlackMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec PunkAnimation1AnimationSpec =
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

AnimationFunctionROMSpec* PunkAnimationSpecs[] =
{
	(AnimationFunction*)&PunkAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec PunkSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	24,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkActorPunkTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkActorPunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

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

BgmapSpriteROMSpec PunkSprite1SpriteSpec =
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
			(const AnimationFunction**)PunkAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkSprite1TextureSpec,

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


CharSetROMSpec PunkSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	24,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkActorPunkBlackTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkActorPunkBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

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

BgmapSpriteROMSpec PunkSprite2SpriteSpec =
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
			(const AnimationFunction**)PunkAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkSprite2TextureSpec,

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

ComponentSpec* const PunkComponentSpecs[] = 
{
	(ComponentSpec*)&PunkSprite1SpriteSpec,
	(ComponentSpec*)&PunkSprite2SpriteSpec,
	NULL
};

ActorROMSpec PunkActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PunkComponentSpecs,

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
