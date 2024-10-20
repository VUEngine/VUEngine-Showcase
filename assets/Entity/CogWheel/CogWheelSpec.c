/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Ball.h>
#include <BgmapSprite.h>
#include <BgmapSpriteExtensions.h>
#include <CogWheel.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <MBgmapSprite.h>
#include <ObjectSprite.h>
#include <Texture.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 CogWheelTiles[];
extern uint16 CogWheelMap[];

extern uint32 CogWheelBackgroundTiles[];
extern uint16 CogWheelBackgroundMap[];



//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------


CharSetROMSpec CogWheelCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	26,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	CogWheelTiles,

	// pointer to the frames offsets
	NULL,
};

CharSetROMSpec CogWheelBackgroundCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	26,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	CogWheelBackgroundTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec CogWheelTextureSpec =
{
	// charset spec
	(CharSetSpec*)&CogWheelCharsetSpec,

	// bgmap spec
	CogWheelMap,

	// cols (max 64)
	16,

	// rows (max 64)
	16,

	// padding for affine/hbias transformations (cols, rows)
	{10, 10},

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

TextureROMSpec CogWheelBackgroundTexture =
{
	// charset spec
	(CharSetSpec*)&CogWheelBackgroundCharsetSpec,

	// bgmap spec
	CogWheelBackgroundMap,

	// cols (max 64)
	64,

	// rows (max 64)
	64,

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

TextureROMSpec* const CogWheelBackgroundTextureSpecs[] =
{
	(TextureSpec*)&CogWheelBackgroundTexture,
	NULL
};

ObjectSpriteROMSpec CogWheelObjectSpriteSpec =
{
	{
		// sprite's type
		__TYPE(ObjectSprite),

		// texture spec
		(TextureSpec*)&CogWheelTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_OBJECT,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec CogWheelBgmapSpriteNormalSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&CogWheelTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec CogWheelBgmapSpriteAffineSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&CogWheelTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 1, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_AFFINE,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec CogWheelBgmapSpriteHBiasSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&CogWheelTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_HBIAS,

	// pointer to affine/hbias manipulation function
	BgmapSprite_waveEffect,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

MBgmapSpriteROMSpec CogWheelMBgmapSpriteNormalSpec =
{
	{
		{
			// sprite's type
			__TYPE(MBgmapSprite),

			// texture spec
			NULL,

			// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
			__TRANSPARENCY_NONE,

			// displacement
			{0, 0, 0, 0},
		},

		// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
		// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
		__WORLD_BGMAP,

		// pointer to affine/hbias manipulation function
		NULL,

		// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
		__WORLD_ON,
	},

	// texture to use with the sprite
	(TextureSpec**)CogWheelBackgroundTextureSpecs,

	// SCX/SCY value
	__WORLD_1x1,

	// flag to loop the x axis
	true,

	// flag to loop the y axis
	true,

	// Bounds the sprite's size to provide culling; if 0, the value is inferred from the texture
	0,

	// Bounds the sprite's size to provide culling; if 0, the value is inferred from the texture
	0,
};


BgmapSpriteROMSpec* const CogWheelSpriteSpecs[] =
{
	&CogWheelBgmapSpriteAffineSpec,
	NULL
};

ColliderROMSpec CogWheelColliderSpecs[] =
{
	// floor
	{
		// collider
		__TYPE(Ball),

		// size (x, y, z)
		{64 * 2, 64 * 2, 32},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{0, 0, 0},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerDangers,

		// layers to ignore when checking for collisions
		kLayerNone,
	},

	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};

CogWheelROMSpec CogWheelEntitySpec =
{
	{
		// class allocator
		__TYPE(CogWheel),

		// children
		NULL,

		// behaviors
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)CogWheelSpriteSpecs,

		// use z displacement in projection
		false,
				
		// wireframes
		(WireframeSpec**)NULL,

		// collision colliders
		(ColliderSpec*)CogWheelColliderSpecs,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kTypeCogWheel,

		// physical specification
		(PhysicalProperties*)NULL,
	}
};
