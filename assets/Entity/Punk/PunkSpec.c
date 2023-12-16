/*
 * Capitán Sevilla 3D, an adventure platforming game demo for Nintendo Virtual Boy
 *
 * (c) Christian Radke, Jorge Eremiev and Rubén Garcerá Soto
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <BgmapAnimatedSprite.h>
#include <Box.h>
#include <GameConfig.h>
#include <Punk.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 PunkTiles[];
extern uint32 PunkBlackTiles[];
extern uint16 PunkMap[];
extern uint16 PunkBlackMap[];

extern uint32 PunkDyingTiles[];
extern uint32 PunkDyingBlackTiles[];
extern uint16 PunkDyingMap[];
extern uint16 PunkDyingBlackMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec PunkMoveAnimation =
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

AnimationFunctionROMSpec PunkDieAnimation =
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

AnimationFunctionROMSpec* PunkAnimations[] =
{
	(AnimationFunctionROMSpec*)&PunkMoveAnimation,
	(AnimationFunctionROMSpec*)&PunkDieAnimation,
	NULL,
};

CharSetROMSpec PunkCharset =
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

CharSetROMSpec PunkCharsetNotShared =
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

CharSetROMSpec PunkCharsetShared =
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

CharSetROMSpec PunkCharsetMultiframe =
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

CharSetROMSpec PunkBlackCharset =
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

TextureROMSpec PunkTexture =
{
	(CharSetSpec*)&PunkCharset,

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

TextureROMSpec PunkTextureNotShared =
{
	(CharSetSpec*)&PunkCharsetNotShared,

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

TextureROMSpec PunkTextureShared =
{
	(CharSetSpec*)&PunkCharsetShared,

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

TextureROMSpec PunkTextureMultiframe =
{
	(CharSetSpec*)&PunkCharsetMultiframe,

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

TextureROMSpec PunkBlackTexture =
{
	(CharSetSpec*)&PunkBlackCharset,

	// bgmap spec
	PunkBlackMap,

	// cols (max 64)
	4,

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

BgmapSpriteROMSpec PunkSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec PunkSpriteNotShared =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkTextureNotShared,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec PunkSpriteShared =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkTextureShared,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec PunkSpriteMultiframe =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkTextureMultiframe,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec PunkBlackSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkBlackTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec* const PunkSprites[] =
{
	&PunkSprite,
	&PunkBlackSprite,
	NULL
};

CharSetROMSpec PunkDyingCharset =
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

CharSetROMSpec PunkDyingBlackCharset =
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

TextureROMSpec PunkDyingTexture =
{
	(CharSetSpec*)&PunkDyingCharset,

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

TextureROMSpec PunkDyingBlackTexture =
{
	(CharSetSpec*)&PunkDyingBlackCharset,

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

BgmapSpriteROMSpec PunkDyingSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkDyingTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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


BgmapSpriteROMSpec PunkDyingBlackSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PunkDyingBlackTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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

BgmapSpriteROMSpec* const PunkDyingSprites[] =
{
	&PunkDyingSprite,
	&PunkDyingBlackSprite,
	NULL
};


ColliderROMSpec PunkColliders[] =
{
	{
		// collider
		__TYPE(Box),

		// size (x, y, z)
		{16, 38, 24},

		// displacement (x, y, z, p)
		{0, 1, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{0, 0, 0},

		// if true this collider checks for collisions against other shapes
		true,

		// layers in which I live
		kLayerPunk,

		// layers to ignore when checking for collisions
		~(kLayerSolid | kLayerDangers),
	},

	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};

AnimatedEntityROMSpec PunkEntity =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		NULL,

		// behaviors
		NULL,

		// extra
		NULL,
		
		// sprites
		(SpriteSpec**)PunkSprites,

		// use z displacement in projection
		false,

		// wireframes
		NULL,

		// collision shapes
		(ColliderSpec*)PunkColliders,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kTypeNone,

		// physical specification
		(PhysicalSpecification*)NULL,
	},

	// pointer to the animation spec for the character
	(const AnimationFunction**)&PunkAnimations,

	// initial animation
	"Move"
};

PhysicalSpecificationROMSpec PunkActorPhysicalProperties =
{
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

PunkROMSpec PunkActor =
{
	{	
		{
			{
				// class allocator
				__TYPE(Punk),

				// children
				NULL,

				// behaviors
				NULL,

				// extra
				NULL,
				
				// sprites
				(SpriteSpec**)PunkSprites,

				// use z displacement in projection
				false,

				// wireframes
				NULL,

				// collision shapes
				(ColliderSpec*)PunkColliders,

				// size
				// if 0, width and height will be inferred from the first sprite's texture's size
				{0, 0, 0},

				// gameworld's character's type
				kTypePunk,

				// physical specification
				(PhysicalSpecification*)&PunkActorPhysicalProperties,
			},

			// pointer to the animation spec for the character
			(const AnimationFunction**)&PunkAnimations,

			// initial animation
			"Move"
		},

		// true to create a body
		true,

		// axis subject to gravity
		__NO_AXIS,

		/// axis around which to rotate the entity when syncronizing with body
		__Y_AXIS
	}
};