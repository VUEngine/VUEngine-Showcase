///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <BgmapSprite.h>
#include <Box.h>
#include <ColliderLayers.h>
#include <Entity.h>
#include <InGameTypes.h>
#include <Texture.h>


//---------------------------------------------------------------------------------------------------------
//                                              DECLARATIONS                                               
//---------------------------------------------------------------------------------------------------------

extern uint32 BoxEntityBoxTiles[];
extern uint16 BoxEntityBoxMap[];


//---------------------------------------------------------------------------------------------------------
//                                                 SPRITES                                                 
//---------------------------------------------------------------------------------------------------------


CharSetROMSpec BoxSprite1CharsetSpec =
{
	// number of chars in function or the number of frames to load at the same time
	42,

	// whether it is shared or not
	true,

	// whether the tiles are optimized or not
	true,

	// char spec
	BoxEntityBoxTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec BoxSprite1TextureSpec =
{
	// charset spec
	(CharSetSpec*)&BoxSprite1CharsetSpec,

	// bgmap spec
	BoxEntityBoxMap,

	// cols (max 64)
	7,

	// rows (max 64)
	6,

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

BgmapSpriteROMSpec BoxSprite1SpriteSpec =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&BoxSprite1TextureSpec,

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

BgmapSpriteROMSpec* const BoxSpriteSpecs[] =
{
	(BgmapSpriteSpec*)&BoxSprite1SpriteSpec,
	NULL
};

//---------------------------------------------------------------------------------------------------------
//                                                COLLIDERS                                                
//---------------------------------------------------------------------------------------------------------

ColliderROMSpec BoxColliderSpecs[] =
{
	{
		// collider
		__TYPE(Box),

		// size (x, y, z)
		{ 56, 48, 32 },

		// displacement (x, y, z, p)
		{ 0, 0, 0, 0 },

		// rotation (x, y, z)
		{ __F_TO_FIX7_9(0), __F_TO_FIX7_9(0), __F_TO_FIX7_9(0) },

		// scale (x, y, z)
		{ __F_TO_FIX7_9(1), __F_TO_FIX7_9(1), __F_TO_FIX7_9(1) },

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerSolid,

		// layers to ignore when checking for collisions
		kLayerAll,
	},
	
	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};


//---------------------------------------------------------------------------------------------------------
//                                                 ENTITY                                                  
//---------------------------------------------------------------------------------------------------------

EntityROMSpec BoxEntitySpec =
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
			(SpriteSpec**)BoxSpriteSpecs,

			// use z displacement in projection
			false,

			// wireframes
			NULL,

			// collider colliders
			(ColliderSpec*)BoxColliderSpecs,

			// size
			// if 0, width and height will be inferred from the first sprite's texture's size
			{ 0, 0, 0 },

			// gameworld's character's type
			kTypeSolidObject,

			// physical specification
			(PhysicalProperties*)NULL,
};
