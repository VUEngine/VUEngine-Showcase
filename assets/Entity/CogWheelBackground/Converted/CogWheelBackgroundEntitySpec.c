///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <Entity.h>
#include <MBgmapSprite.h>
#include <Texture.h>


//---------------------------------------------------------------------------------------------------------
//                                              DECLARATIONS                                               
//---------------------------------------------------------------------------------------------------------

extern uint32 CogWheelBackgroundEntityCogWheelBackgroundTiles[];
extern uint16 CogWheelBackgroundEntityCogWheelBackgroundMap[];


//---------------------------------------------------------------------------------------------------------
//                                                 SPRITES                                                 
//---------------------------------------------------------------------------------------------------------


CharSetROMSpec CogWheelBackgroundSprite1CharsetSpec =
{
	// number of chars in function or the number of frames to load at the same time
	26,

	// whether it is shared or not
	true,

	// whether the tiles are optimized or not
	true,

	// char spec
	CogWheelBackgroundEntityCogWheelBackgroundTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec CogWheelBackgroundSprite1TextureSpec =
{
	// charset spec
	(CharSetSpec*)&CogWheelBackgroundSprite1CharsetSpec,

	// bgmap spec
	CogWheelBackgroundEntityCogWheelBackgroundMap,

	// cols (max 64)
	64,

	// rows (max 64)
	64,

	// padding for affine/hbias transformations
	{ 0, 0 },

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

TextureROMSpec* const CogWheelBackgroundSprite1TextureSpecs[] =
{
	(TextureSpec*)&CogWheelBackgroundSprite1TextureSpec,
	NULL
};

MBgmapSpriteROMSpec CogWheelBackgroundSprite1SpriteSpec =
{
	{
	{
		// sprite's type
		__TYPE(MBgmapSprite),

		// texture spec
		NULL,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{ 0, 0, 0, 0 },
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
	(TextureSpec**)CogWheelBackgroundSprite1TextureSpecs,

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

BgmapSpriteROMSpec* const CogWheelBackgroundSpriteSpecs[] =
{
	(BgmapSpriteSpec*)&CogWheelBackgroundSprite1SpriteSpec,
	NULL
};

//---------------------------------------------------------------------------------------------------------
//                                                 ENTITY                                                  
//---------------------------------------------------------------------------------------------------------

EntityROMSpec CogWheelBackgroundEntitySpec =
{
			// class allocator
			__TYPE(Entity),

			// children
			NULL,

			// behaviors
			NULL,

			// extra
			NULL,

			// sprites
			(SpriteSpec**)CogWheelBackgroundSpriteSpecs,

			// use z displacement in projection
			false,

			// wireframes
			NULL,

			// collider colliders
			NULL,

			// size
			// if 0, width and height will be inferred from the first sprite's texture's size
			{ 0, 0, 0 },

			// gameworld's character's type
			kTypeNone,

			// physical specification
			(PhysicalProperties*)NULL,
};
