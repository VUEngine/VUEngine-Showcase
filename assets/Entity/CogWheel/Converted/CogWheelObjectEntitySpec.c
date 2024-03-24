///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <Ball.h>
#include <CogWheel.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <ObjectSprite.h>
#include <Texture.h>


//---------------------------------------------------------------------------------------------------------
//                                              DECLARATIONS                                               
//---------------------------------------------------------------------------------------------------------

extern uint32 CogWheelObjectEntityCogWheelTiles[];
extern uint16 CogWheelObjectEntityCogWheelMap[];


//---------------------------------------------------------------------------------------------------------
//                                                 SPRITES                                                 
//---------------------------------------------------------------------------------------------------------


CharSetROMSpec CogWheelObjectSprite1CharsetSpec =
{
	// number of chars in function or the number of frames to load at the same time
	26,

	// whether it is shared or not
	true,

	// whether the tiles are optimized or not
	true,

	// char spec
	CogWheelObjectEntityCogWheelTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec CogWheelObjectSprite1TextureSpec =
{
	// charset spec
	(CharSetSpec*)&CogWheelObjectSprite1CharsetSpec,

	// bgmap spec
	CogWheelObjectEntityCogWheelMap,

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

ObjectSpriteROMSpec CogWheelObjectSprite1SpriteSpec =
{
	{
		// sprite's type
		__TYPE(ObjectSprite),

		// texture spec
		(TextureSpec*)&CogWheelObjectSprite1TextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{ 0, 0, 0, 0 },
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_OBJECT,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ObjectSpriteROMSpec* const CogWheelObjectSpriteSpecs[] =
{
	(ObjectSpriteSpec*)&CogWheelObjectSprite1SpriteSpec,
	NULL
};

//---------------------------------------------------------------------------------------------------------
//                                                COLLIDERS                                                
//---------------------------------------------------------------------------------------------------------

ColliderROMSpec CogWheelObjectColliderSpecs[] =
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

CogWheelROMSpec CogWheelObjectEntitySpec =
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
			(SpriteSpec**)CogWheelObjectSpriteSpecs,

			// use z displacement in projection
			false,

			// wireframes
			NULL,

			// collider colliders
			(ColliderSpec*)CogWheelObjectColliderSpecs,

			// size
			// if 0, width and height will be inferred from the first sprite's texture's size
			{ 0, 0, 0 },

			// gameworld's character's type
			kTypeCogWheel,

			// physical specification
			(PhysicalProperties*)NULL,
	}
};
