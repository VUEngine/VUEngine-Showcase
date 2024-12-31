/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <AnimatedEntity.h>
#include <BgmapAnimatedSprite.h>
#include <Body.h>
#include <Box.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Punk.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 PunkTiles[];
extern uint32 PunkBlackTiles[];
extern uint16 PunkMap[];
extern uint16 PunkBlackMap[];

extern uint32 PunkDyingTiles[];
extern uint32 PunkDyingBlackTiles[];
extern uint16 PunkDyingMap[];
extern uint16 PunkDyingBlackMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec PunkMoveAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	12,

	// Frames to play in animation
	{9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8},

	// Number of cycles a frame of animation is displayed
	4,

	// Whether to play it in loop or not
	true,

	// Callback on animation completion
	NULL,

	// Animation's name
	"Move",
};

AnimationFunctionROMSpec PunkDieAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	11,

	// Frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	},

	// Number of cycles a frame of animation is displayed
	4,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	(EventListener)&Punk_onDieAnimationComplete,

	// Animation's name
	"Die",
};

AnimationFunctionROMSpec* PunkAnimationSpecs[] =
{
	(AnimationFunctionROMSpec*)&PunkMoveAnimationSpec,
	(AnimationFunctionROMSpec*)&PunkDieAnimationSpec,
	NULL,
};

CharSetROMSpec PunkCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4 * 6,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkTiles,

	// Frame offsets array
	NULL,
};

CharSetROMSpec PunkCharsetNotSharedSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4 * 6,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkTiles,

	// Frame offsets array
	NULL,
};

CharSetROMSpec PunkCharsetSharedSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4 * 6,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkTiles,

	// Frame offsets array
	NULL,
};

CharSetROMSpec PunkCharsetMultiframeSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4 * 6 * 12,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkTiles,

	// Frame offsets array
	NULL,
};

CharSetROMSpec PunkBlackCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	4 * 6,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkBlackTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec PunkTextureSpec =
{
	(CharSetSpec*)&PunkCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{1, 1},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

TextureROMSpec PunkTextureNotSharedSpec =
{
	(CharSetSpec*)&PunkCharsetNotSharedSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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
	false,
};

TextureROMSpec PunkTextureSharedSpec =
{
	(CharSetSpec*)&PunkCharsetSharedSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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
	false,
};

TextureROMSpec PunkTextureMultiframeSpec =
{
	(CharSetSpec*)&PunkCharsetMultiframeSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	12,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

TextureROMSpec PunkBlackTextureSpec =
{
	(CharSetSpec*)&PunkBlackCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	4,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{1, 1},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

BgmapSpriteROMSpec PunkSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec PunkAffineSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
		__WORLD_AFFINE,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec PunkSpriteNotSharedSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkTextureNotSharedSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec PunkSpriteSharedSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkTextureSharedSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec PunkSpriteMultiframeSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkTextureMultiframeSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec PunkBlackSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkBlackTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 3, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec PunkAffineBlackSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkBlackTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 3, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_AFFINE,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};



CharSetROMSpec PunkDyingCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	8*6,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkDyingTiles,

	// Frame offsets array
	NULL,
};

CharSetROMSpec PunkDyingBlackCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	8*6,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	PunkDyingBlackTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec PunkDyingTextureSpec =
{
	(CharSetSpec*)&PunkDyingCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkDyingMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
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
	false,
};

TextureROMSpec PunkDyingBlackTextureSpec =
{
	(CharSetSpec*)&PunkDyingBlackCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	PunkDyingBlackMap,

	// Horizontal size in tiles of the texture (max. 64)
	8,

	// Vertical size in tiles of the texture (max. 64)
	6,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	1,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,
};

BgmapSpriteROMSpec PunkDyingSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkDyingTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 2, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};


BgmapSpriteROMSpec PunkDyingBlackSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&PunkDyingBlackTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 3, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ColliderROMSpec PunkColliderSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Box),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{16, 38, 24},

	// Displacement (x, y, z, p)
	{0, 1, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{0, 0, 0},

	// If true this collider checks for collisions against other colliders
	true,

	// Layers in which I live
	kLayerPunk,

	// Layers to ignore when checking for collisions
	~(kLayerSolid | kLayerDangers),
};

ComponentSpec* const PunkEntityComponentSpecs[] = 
{
	(ComponentSpec*)&PunkAffineSpriteSpec,
	(ComponentSpec*)&PunkAffineBlackSpriteSpec,
	(ComponentSpec*)&PunkColliderSpec,
	NULL
};

AnimatedEntityROMSpec PunkEntitySpec =
{
	{
		// Class allocator		
		__TYPE(AnimatedEntity),

		// Component specs
		(ComponentSpec**)PunkEntityComponentSpecs,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		kTypeNone
	},

	// Pointer to animation functions array
	(const AnimationFunction**)&PunkAnimationSpecs,

	// Animation to play automatically
	"Move"
};

BodyROMSpec PunkBodySpec =
{
	// Component
	{
		// Allocator
		__TYPE(Body),

		// Component type
		kPhysicsComponent
	},

	// Create body
	true,

	// Mass
	__F_TO_FIXED(0.5f),

	// Friction
	__F_TO_FIXED(0.1f),

	// Bounciness
	__F_TO_FIXED(0),

	// Maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// Maximum speed
	__F_TO_FIXED(3),

	// Axises on which the body is subject to gravity
	__NO_AXIS
};

ComponentSpec* const PunkActorComponentSpecs[] = 
{
	(ComponentSpec*)&PunkSpriteSpec,
	(ComponentSpec*)&PunkBlackSpriteSpec,
	(ComponentSpec*)&PunkBodySpec,
	(ComponentSpec*)&PunkColliderSpec,
	NULL
};

ComponentSpec* const PunkActorDyingComponentSpecs[] = 
{
	(ComponentSpec*)&PunkDyingSpriteSpec,
	(ComponentSpec*)&PunkDyingBlackSpriteSpec,
	NULL
};

PunkROMSpec PunkActorSpec =
{
	{	
		{
			{
				// Class allocator				
				__TYPE(Punk),

				// Component specs
				(ComponentSpec**)PunkActorComponentSpecs,

				// Children specs
				NULL,

				// Extra info
				NULL,

				// Size
				// If 0, it is computed from the visual components if any
				{0, 0, 0},

				// Entity's in-game type
				kTypePunk
			},

			// Pointer to animation functions array
			(const AnimationFunction**)&PunkAnimationSpecs,

			// Animation to play automatically
			"Move"
		},

		// Axises around which to rotate the entity when syncronizing with bodyate the entity when syncronizing with body
		__Y_AXIS,
	}
};