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

extern uint16 PunkAffineActorPunkBlackMap[];
extern uint16 PunkAffineActorPunkMap[];
extern uint32 PunkAffineActorPunkBlackTiles[];
extern uint32 PunkAffineActorPunkTiles[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ANIMATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec PunkAffineAnimation1AnimationSpec =
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
	true
	"Move",
};

AnimationFunctionROMSpec* PunkAffineAnimationSpecs[] =
{
	(AnimationFunction*)&PunkAffineAnimation1AnimationSpec,
	NULL,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec PunkAffineSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	24,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkAffineActorPunkTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkAffineSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkAffineSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkAffineActorPunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// padding for affine/hbias transformations
	{1, 1},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recycle the texture with a different map
	true,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec PunkAffineSprite1SpriteSpec =
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
			(const AnimationFunction**)PunkAffineAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkAffineSprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_AFFINE,
	
	// Pointer to affine/hbias manipulation function
	NULL
};


CharSetROMSpec PunkAffineSprite2CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	24,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkAffineActorPunkBlackTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec PunkAffineSprite2TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&PunkAffineSprite2CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkAffineActorPunkBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// padding for affine/hbias transformations
	{1, 1},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recycle the texture with a different map
	true,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec PunkAffineSprite2SpriteSpec =
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
			(const AnimationFunction**)PunkAffineAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkAffineSprite2TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 3, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_AFFINE,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PunkAffineComponentSpecs[] = 
{
	(ComponentSpec*)&PunkAffineSprite1SpriteSpec,
	(ComponentSpec*)&PunkAffineSprite2SpriteSpec,
	NULL
};

ActorROMSpec PunkAffineActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PunkAffineComponentSpecs,

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
