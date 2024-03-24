///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <Ball.h>
#include <BgmapSprite.h>
#include <CogWheel.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Texture.h>


//---------------------------------------------------------------------------------------------------------
//                                              DECLARATIONS                                               
//---------------------------------------------------------------------------------------------------------

extern uint32 CogWheelBgmapNormalEntityCogWheelTiles[];
extern uint16 CogWheelBgmapNormalEntityCogWheelMap[];


//---------------------------------------------------------------------------------------------------------
//                                                 SPRITES                                                 
//---------------------------------------------------------------------------------------------------------


CharSetROMSpec CogWheelBgmapNormalSprite1CharsetSpec =
{
	// number of chars in function or the number of frames to load at the same time
	26,

	// whether it is shared or not
	true,

	// whether the tiles are optimized or not
	true,

	// char spec
	CogWheelBgmapNormalEntityCogWheelTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec CogWheelBgmapNormalSprite1TextureSpec =
{
	// charset spec
	(CharSetSpec*)&CogWheelBgmapNormalSprite1CharsetSpec,

	// bgmap spec
	CogWheelBgmapNormalEntityCogWheelMap,

	// cols (max 64)
	16,

	// rows (max 64)
	16,

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

BgmapSpriteROMSpec CogWheelBgmapNormalSprite1SpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&CogWheelBgmapNormalSprite1TextureSpec,

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
};

BgmapSpriteROMSpec* const CogWheelBgmapNormalSpriteSpecs[] =
{
	(BgmapSpriteSpec*)&CogWheelBgmapNormalSprite1SpriteSpec,
	NULL
};

//---------------------------------------------------------------------------------------------------------
//                                                COLLIDERS                                                
//---------------------------------------------------------------------------------------------------------

ColliderROMSpec CogWheelBgmapNormalColliderSpecs[] =
{
	{
		// collider
		__TYPE(Ball),

		// size (x, y, z)
		{ 128, 0, 0 },

		// displacement (x, y, z, p)
		{ 0, 0, 0, 0 },

		// rotation (x, y, z)
		{ __F_TO_FIX7_9(0), __F_TO_FIX7_9(0), __F_TO_FIX7_9(0) },

		// scale (x, y, z)
		{ __F_TO_FIX7_9(1), __F_TO_FIX7_9(1), __F_TO_FIX7_9(1) },

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerDangers,

		// layers to ignore when checking for collisions
		kLayerAll,
	},
	
	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};


//---------------------------------------------------------------------------------------------------------
//                                                 ENTITY                                                  
//---------------------------------------------------------------------------------------------------------

CogWheelROMSpec CogWheelBgmapNormalEntitySpec =
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
			(SpriteSpec**)CogWheelBgmapNormalSpriteSpecs,

			// use z displacement in projection
			false,

			// wireframes
			NULL,

			// collider colliders
			(ColliderSpec*)CogWheelBgmapNormalColliderSpecs,

			// size
			// if 0, width and height will be inferred from the first sprite's texture's size
			{ 0, 0, 0 },

			// gameworld's character's type
			kTypeCogWheel,

			// physical specification
			(PhysicalProperties*)NULL,
	}
};
