/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Ball.h>
#include <BgmapSprite.h>
#include <BgmapSpriteExtensions.h>
#include <CogWheel.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <MBgmapSprite.h>
#include <ObjectSprite.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 CogWheelTiles[];
extern uint16 CogWheelMap[];

extern uint32 CogWheelBackgroundTiles[];
extern uint16 CogWheelBackgroundMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec CogWheelCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	26,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	CogWheelTiles,

	// Frame offsets array
	NULL,
};

CharSetROMSpec CogWheelBackgroundCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	26,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	CogWheelBackgroundTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec CogWheelTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&CogWheelCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	CogWheelMap,

	// Horizontal size in tiles of the texture (max. 64)
	16,

	// Vertical size in tiles of the texture (max. 64)
	16,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{10, 10},

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

TextureROMSpec CogWheelBackgroundTexture =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&CogWheelBackgroundCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	CogWheelBackgroundMap,

	// Horizontal size in tiles of the texture (max. 64)
	64,

	// Vertical size in tiles of the texture (max. 64)
	64,

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

TextureROMSpec* const CogWheelBackgroundTextureSpecs[] =
{
	(TextureSpec*)&CogWheelBackgroundTexture,
	NULL
};

ObjectSpriteROMSpec CogWheelObjectSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(ObjectSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&CogWheelTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_OBJECT,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec CogWheelBgmapSpriteNormalSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&CogWheelTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec CogWheelBgmapSpriteAffineSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&CogWheelTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 1, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_AFFINE,

	// Pointer to affine/hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec CogWheelBgmapSpriteHBiasSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&CogWheelTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_HBIAS,

	// Pointer to affine/hbias manipulation function
	BgmapSprite_waveEffect,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

MBgmapSpriteROMSpec CogWheelMBgmapSpriteNormalSpec =
{
	{
		{
			// Component
			{
				// Allocator
				__TYPE(MBgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Spec for the texture to display
			NULL,

			// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
			__TRANSPARENCY_NONE,

			// Displacement added to the sprite's position
			{0, 0, 0, 0},
		},

		// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
		// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
		__WORLD_BGMAP,

		// Pointer to affine/hbias manipulation function
		NULL,

		// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
		__WORLD_ON,
	},

	// Texture to use with the sprite
	(TextureSpec**)CogWheelBackgroundTextureSpecs,

	// SCX/SCY value
	__WORLD_1x1,

	// Flag to loop the x axis
	true,

	// Flag to loop the y axis
	true,

	// Bounds the sprite's width to provide culling; if 0, the value is inferred from the texture
	0,

	// Bounds the sprite's width to provide culling; if 0, the value is inferred from the texture
	0,
};

ColliderROMSpec CogWheelColliderSpec1 =
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{64 * 2, 64 * 2, 32},

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{0, 0, 0},

	// If true this collider checks for collisions against other colliders
	false,

	// Layers in which I live
	kLayerDangers,

	// Layers to ignore when checking for collisions
	kLayerNone,
};

ComponentSpec* const CogWheelEntityComponentSpecs[] = 
{
	(ComponentSpec*)&CogWheelBgmapSpriteAffineSpec,
	(ComponentSpec*)&CogWheelColliderSpec1,
	NULL
};

CogWheelROMSpec CogWheelEntitySpec =
{
	{
		// Class allocator
		__TYPE(CogWheel),

		// Component specs
		(ComponentSpec**)CogWheelEntityComponentSpecs,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		kTypeCogWheel,

		// Pointer to animation functions array
		NULL,

		// Animation to play automatically
		NULL
	}
};
