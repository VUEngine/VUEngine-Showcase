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

#include <CharSet.h>
#include <Fonts.h>
#include <Printing.h>
#include <Stage.h>
#include <Sound.h>

#include <DebugConfig.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern EntitySpec BoxEntitySpec;
extern EntitySpec CogWheelEntitySpec;
extern EntitySpec PunkActorSpec;
extern EntitySpec LowPowerIndicatorEntitySpec;


//---------------------------------------------------------------------------------------------------------
// 											ENTITY LISTS
//---------------------------------------------------------------------------------------------------------

PositionedEntityROMSpec ActorsStageEntitySpecs[] =
{
	{&PunkActorSpec, {0, 64, 0}, {0, 0, 0}, {1, 1, 1},  0, NULL, NULL, NULL, false},
	{&BoxEntitySpec, {150, 64, 0}, {0, 0, 0}, {1, 1, 1},  0, NULL, NULL, NULL, false},
	{&CogWheelEntitySpec, {-150, 64, 0}, {0, 0, 0}, {1, 1, 1},  0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

PositionedEntityROMSpec ActorsStageUiEntitySpecs[] =
{
	{&LowPowerIndicatorEntitySpec, 	{__PLUGIN_LOW_POWER_ENTITY_X_POSITION, __PLUGIN_LOW_POWER_ENTITY_Y_POSITION, __PLUGIN_LOW_POWER_ENTITY_Z_POSITION}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};


//---------------------------------------------------------------------------------------------------------
// 											PRELOAD LISTS
//---------------------------------------------------------------------------------------------------------

FontROMSpec* const ActorsStageFontSpecs [] =
{
	NULL
};

SoundROMSpec* ActorsStageSoundSpecs[] =
{
	NULL
};


//---------------------------------------------------------------------------------------------------------
//											STAGE DEFINITION
//---------------------------------------------------------------------------------------------------------

StageROMSpec ActorsStageSpec =
{
	// allocator
	__TYPE(Stage),

	// Timer config
	{
		__TIMER_100US,
		10,
		kMS
	},

	// Sound config
	{
		6000,
		false
	},

	// level
	{
		// size
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
			-10,
			// x1
			__SCREEN_WIDTH,
			// y1
			__SCREEN_HEIGHT,
			// z1
			8191 / 2,
		}
	},

	// streaming
	{
		// load padding
		192,
		// unload padding
		256,
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
		64 * 8,

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
			__MAXIMUM_X_VIEW_DISTANCE >> 1, __MAXIMUM_Y_VIEW_DISTANCE,
			// distance of the eyes to the screen
			0,
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
		__F_TO_FIX10_6(0.01f),
	},

	// assets
	{
		// fonts to preload
		(FontSpec**)ActorsStageFontSpecs ,

		// char sets to preload
		(CharSetSpec**)NULL,

		// textures to preload
		(TextureSpec**)NULL,

		// background music
		(SoundSpec**)ActorsStageSoundSpecs,
	},

	// entities
	{
		// ui
		{
			(PositionedEntity*)ActorsStageUiEntitySpecs,
			__TYPE(UIContainer),
		},

		// children
		(PositionedEntity*)ActorsStageEntitySpecs,
	},

	// post processing effects
	(PostProcessingEffect*)NULL,
};

