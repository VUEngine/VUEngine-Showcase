/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © Stage by Julian Leucht (JnL)
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Stage.h>
#include <Printing.h>
#include <CharSet.h>
#include <Fonts.h>
#include <Sound.h>
#include <DebugConfig.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern EntitySpec LowPowerIndicatorEntitySpec;
extern EntitySpec PyramidEntitySpec;
extern EntitySpec StreetEntitySpec;
extern EntitySpec HouseEntitySpec;
extern EntitySpec HouseBigEntitySpec;
extern EntitySpec TunnelEntitySpec;
extern EntitySpec BusStopEntitySpec;
extern EntitySpec BillboardEntitySpec;
extern EntitySpec LampEntitySpec;
extern EntitySpec CurveLeftEntitySpec;


//=========================================================================================================
// ENTITY LISTS
//=========================================================================================================

PositionedEntityROMSpec WireframesStageEntitySpecs[] =
{
	{&HouseBigEntitySpec, {-192, -8, 896}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&TunnelEntitySpec, {0, 56, 1728}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&HouseEntitySpec, {192,-8, 896}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetEntitySpec, {0, 56, 832}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&HouseEntitySpec, {-192, -8, 640}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&BusStopEntitySpec, {192, -8, 640}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&BillboardEntitySpec, {-160, -8, 450}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&LampEntitySpec, {192, -8, 512}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&LampEntitySpec, {192, -8, 1152}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&CurveLeftEntitySpec, {0, 56, 2112}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},

	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

PositionedEntityROMSpec WireframesStageUiEntitySpecs[] =
{
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};


//=========================================================================================================
// ASSETS LISTS
//=========================================================================================================

FontROMSpec* const WireframesStageFontSpecs[] =
{
	NULL
};

SoundROMSpec* WireframesStageSoundSpecs[] =
{
	NULL
};


//=========================================================================================================
// STAGE DEFINITION
//=========================================================================================================

StageROMSpec WireframesStageSpec =
{
	// allocator
	__TYPE(Stage),

	// Timer config
	{
		__TIMER_100US,
		20,
		kMS
	},

	// Sound config
	{
		6000,
		false
	},

	// level
	{
		// Size
		{
			// x
			8191,
			// y
			__SCREEN_HEIGHT,
			// z
			8191,
		},

		// camera's initial position inside the game world
		{
			// x
			0,
			// y
			0,
			// z
			0,
			// p
			0,
		},

		// camera's frustum
		{
			// x0
			0,
			// y0
			0,
			// z0
			0,
			// x1
			__SCREEN_WIDTH,
			// y1
			__SCREEN_HEIGHT,
			// z1
			2048,
		}
	},

	// streaming
	{
		// load padding
		128,
		// unload padding
		64,
		// streaming amplitude
		24,
		// particle removal delay cycles
		0,
		// deferred
		false,
	},

	// rendering
	{
		// maximum number of texture's rows to write each time the texture writing is active
		12,

		// maximum number of rows to compute on each call to the affine functions
		112,

		// colors config
		{
			// background color
			__COLOR_BLACK,

			// brightness
			// these values times the repeat values specified in the column table (max. 16) make the final
			// brightness values on the respective regions of the screen. maximum brightness is 128.
			{
				// dark red
				8,
				// medium red
				__BRIGHTNESS_MEDIUM_RED,
				// bright red
				__BRIGHTNESS_BRIGHT_RED,
			},

			// brightness repeat
			(BrightnessRepeatSpec*)NULL,
		},

		// palettes' config
		{
			{
				// bgmap palette 0
				__BGMAP_PALETTE_0,
				// bgmap palette 1
				__BGMAP_PALETTE_1,
				// bgmap palette 2
				__BGMAP_PALETTE_2,
				// bgmap palette 3
				__BGMAP_PALETTE_3,
			},
			{
				// object palette 0
				__OBJECT_PALETTE_0,
				// object palette 1
				__OBJECT_PALETTE_1,
				// object palette 2
				__OBJECT_PALETTE_2,
				// object palette 3
				__OBJECT_PALETTE_3,
			},
		},

		// bgmap segments configuration
		// number of segments reserved for the param table
		1,

		// object segments sizes (up to 1024 in total)
		// can impact performance, make sure to configure only as large as maximally needed
		{
			// __spt0
			0,
			// __spt1
			0,
			// __spt2
			0,
			// __spt3
			0,
		},

		// object segments z coordinates
		// note that each spt's z coordinate much be larger than or equal to the previous one's,
		// since the vip renders obj worlds in reverse order (__spt3 to __spt0)
		{
			// __spt0
			0,
			// __spt1
			0,
			// __spt2
			0,
			// __spt3
			0,
		},

		// optical configuration values
		{
			// maximum view distance's power into the horizon
			__MAXIMUM_X_VIEW_DISTANCE, __MAXIMUM_Y_VIEW_DISTANCE,
			// distance of the eyes to the screen
			__CAMERA_NEAR_PLANE,
			// distance from left to right eye (depth sensation)
			__BASE_FACTOR,
			// horizontal view point center
			__HORIZONTAL_VIEW_POINT_CENTER,
			// vertical view point center
			__VERTICAL_VIEW_POINT_CENTER,
			// scaling factor
			__SCALING_MODIFIER_FACTOR
		},
	},

	// physics
	{
		// gravity
		{
			__I_TO_FIX10_6(0),
			__F_TO_FIX10_6(0),
			__I_TO_FIX10_6(0),
		},

		// friction
		__F_TO_FIX10_6(0.1f),
	},

	// assets
	{
		// fonts to preload
		(FontSpec**)WireframesStageFontSpecs,

		// char sets to preload
		(CharSetSpec**)NULL,

		// textures to preload
		(TextureSpec**)NULL,

		// background music
		(SoundSpec**)WireframesStageSoundSpecs,
	},

	// entities
	{
		// ui
		{
			(PositionedEntity*)WireframesStageUiEntitySpecs,
			__TYPE(UIContainer),
		},

		// Children specs
		(PositionedEntity*)WireframesStageEntitySpecs,
	},

	// post processing effects
	(PostProcessingEffect*)NULL,
};
