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

#include <BgmapSprite.h>
#include <Box.h>
#include <ColliderLayers.h>
#include <Entity.h>
#include <InGameTypes.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 BoxTiles[];
extern uint16 BoxMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

CharSetROMSpec BoxCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	42,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	BoxTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec BoxTextureSpec =
{
	// charset spec
	(CharSetSpec*)&BoxCharsetSpec,

	// bgmap spec
	BoxMap,

	// cols (max 64)
	7,

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

BgmapSpriteROMSpec BoxSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// texture spec
		(TextureSpec*)&BoxTextureSpec,

		// transparency (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
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



	// floor
ColliderROMSpec BoxColliderSpecsCollider1 =
	{
		// Component
		{
			// Allocator
			__TYPE(Box),

			// Component type
			kColliderComponent
		},

		// size (x, y, z)
		{7 * 8, 6 * 8, 4 * 8},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{0, 0, 0},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerSolid,

		// layers to ignore when checking for collisions
		kLayerNone,
	};



const ComponentSpec* BoxEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)BoxSpriteSpec,
    (ComponentSpec*)BoxColliderSpecsCollider1,
	NULL
};

EntityROMSpec BoxEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpecs**)BoxEntitySpecComponentSpecs,

	// children
	NULL,

	

	// extra
	NULL,

	

	// use z displacement in projection
	false,
			
	
	
	

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeSolidObject,

	
};
