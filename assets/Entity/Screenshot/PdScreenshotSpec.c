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

#include <Entity.h>
#include <BgmapSprite.h>
#include <Texture.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 PdScreenshotTiles[];
extern uint16 PdScreenshotLMap[];
extern uint16 PdScreenshotRMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

CharSetROMSpec PdScreenshotCharsetSpec =
{
	// number of chars in function of the number of frames to load at the same time
	460,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	PdScreenshotTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec PdScreenshotLTextureSpec =
{
	// charset spec
	(CharSetSpec*)&PdScreenshotCharsetSpec,

	// bgmap spec
	PdScreenshotLMap,

	// cols (max 64)
	44,

	// rows (max 64)
	16,

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

TextureROMSpec PdScreenshotRTextureSpec =
{
	// charset spec
	(CharSetSpec*)&PdScreenshotCharsetSpec,

	// bgmap spec
	PdScreenshotRMap,

	// cols (max 64)
	44,

	// rows (max 64)
	16,

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

BgmapSpriteROMSpec PdScreenshotLSpriteSpec =
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
		(TextureSpec*)&PdScreenshotLTextureSpec,

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
	__WORLD_LON,
};

BgmapSpriteROMSpec PdScreenshotRSpriteSpec =
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
		(TextureSpec*)&PdScreenshotRTextureSpec,

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
	__WORLD_RON,
};

const ComponentSpec* PdScreenshotEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)&PdScreenshotLSpriteSpec,
    (ComponentSpec*)&PdScreenshotRSpriteSpec,
	NULL
};

EntityROMSpec PdScreenshotEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpec**)PdScreenshotEntitySpecComponentSpecs,

	// children
	NULL,

	// extra
	NULL,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	

};