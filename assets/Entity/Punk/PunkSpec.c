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
	// number of frames of this animation function
	12,

	// frames to play in animation
	{9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8},

	// number of cycles a frame of animation is displayed
	4,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Move",
};

AnimationFunctionROMSpec PunkDieAnimationSpec =
{
	// number of frames of this animation function
	11,

	// frames to play in animation
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	},

	// number of cycles a frame of animation is displayed
	4,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	(EventListener)&Punk_onDieAnimationComplete,

	// function's name
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
	// number of chars in function of the number of frames to load at the same time
	4*6,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkTiles,

	// pointer to the frames offsets
	NULL,
};

CharSetROMSpec PunkCharsetNotSharedSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4*6,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkTiles,

	// pointer to the frames offsets
	NULL,
};

CharSetROMSpec PunkCharsetSharedSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4*6,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkTiles,

	// pointer to the frames offsets
	NULL,
};

CharSetROMSpec PunkCharsetMultiframeSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4*6 * 12,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkTiles,

	// pointer to the frames offsets
	NULL,
};

CharSetROMSpec PunkBlackCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	4*6,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkBlackTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec PunkTextureSpec =
{
	(CharSetSpec*)&PunkCharsetSpec,

	// bgmap spec
	PunkMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{1, 1},

	// number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

TextureROMSpec PunkTextureNotSharedSpec =
{
	(CharSetSpec*)&PunkCharsetNotSharedSpec,

	// bgmap spec
	PunkMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

TextureROMSpec PunkTextureSharedSpec =
{
	(CharSetSpec*)&PunkCharsetSharedSpec,

	// bgmap spec
	PunkMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

TextureROMSpec PunkTextureMultiframeSpec =
{
	(CharSetSpec*)&PunkCharsetMultiframeSpec,

	// bgmap spec
	PunkMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	12,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

TextureROMSpec PunkBlackTextureSpec =
{
	(CharSetSpec*)&PunkBlackCharsetSpec,

	// bgmap spec
	PunkBlackMap,

	// cols (max 64)
	4,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{1, 1},

	// number of frames
	1,

	// palette number (0-3)
	1,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
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

		// texture spec
		(TextureSpec*)&PunkTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_AFFINE,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkTextureNotSharedSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkTextureSharedSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkTextureMultiframeSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 3, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 3, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_AFFINE,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};



CharSetROMSpec PunkDyingCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	8*6,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkDyingTiles,

	// pointer to the frames offsets
	NULL,
};

CharSetROMSpec PunkDyingBlackCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	8*6,

	// whether it is shared or not
	false,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PunkDyingBlackTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec PunkDyingTextureSpec =
{
	(CharSetSpec*)&PunkDyingCharsetSpec,

	// bgmap spec
	PunkDyingMap,

	// cols (max 64)
	8,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

TextureROMSpec PunkDyingBlackTextureSpec =
{
	(CharSetSpec*)&PunkDyingBlackCharsetSpec,

	// bgmap spec
	PunkDyingBlackMap,

	// cols (max 64)
	8,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	1,

	// palette number (0-3)
	1,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
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

		// texture spec
		(TextureSpec*)&PunkDyingTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 2, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

		// texture spec
		(TextureSpec*)&PunkDyingBlackTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 3, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or BgmapSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
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

	// displacement (x, y, z, p)
	{0, 1, 0, 0},

	// rotation (x, y, z)
	{0, 0, 0},

	// scale (x, y, z)
	{0, 0, 0},

	// if true this collider checks for collisions against other colliders
	true,

	// layers in which I live
	kLayerPunk,

	// layers to ignore when checking for collisions
	~(kLayerSolid | kLayerDangers),
};

const ComponentSpec* PunkEntityComponentSpecs[] = 
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

		// In-game entity's type
		kTypeNone
	},

	// pointer to the animation spec for the character
	(const AnimationFunction**)&PunkAnimationSpecs,

	// initial animation
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

	// mass
	__F_TO_FIXED(0.5f),

	// friction
	__F_TO_FIXED(0.1f),

	// bounciness
	__F_TO_FIXED(0),

	// maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// maximum speed
	__F_TO_FIXED(3)
};

const ComponentSpec* PunkActorComponentSpecs[] = 
{
	(ComponentSpec*)&PunkSpriteSpec,
	(ComponentSpec*)&PunkBlackSpriteSpec,
	(ComponentSpec*)&PunkBodySpec,
	(ComponentSpec*)&PunkColliderSpec,
	NULL
};

const ComponentSpec* PunkActorDyingComponentSpecs[] = 
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

				// In-game entity's type
				kTypePunk
			},

			// pointer to the animation spec for the character
			(const AnimationFunction**)&PunkAnimationSpecs,

			// initial animation
			"Move"
		},

		// true to create a body
		true,

		// axis subject to gravity
		__NO_AXIS,

		// axis around which to rotate the entity when syncronizing with body
		__Y_AXIS,
	}
};