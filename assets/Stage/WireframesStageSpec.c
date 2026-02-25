/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © Stage by Julian Leucht (JnL)
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Stage.h>
#include <Printer.h>
#include <CharSet.h>
#include <Fonts.h>
#include <Sound.h>
#include <DebugConfig.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern ActorSpec LowPowerIndicatorActorSpec;
extern ActorSpec StreetActorSpec;
extern ActorSpec StreetEndActorSpec;
extern ActorSpec StreetInclinedActorSpec;
extern ActorSpec HouseActorSpec;
extern ActorSpec HouseBigActorSpec;
extern ActorSpec TunnelActorSpec;
extern ActorSpec BusStopActorSpec;
extern ActorSpec BillboardActorSpec;
extern ActorSpec LampActorSpec;
extern ActorSpec CurveLeftActorSpec;
extern ActorSpec PowerPoleActorSpec;
extern ActorSpec PowerCableActorSpec;
extern ActorSpec WaterTowerActorSpec;
extern ActorSpec TreeActorSpec;
extern ActorSpec ProductionSiteActorSpec;
extern ActorSpec ViewpointActorSpec;
extern ActorSpec ChurchActorSpec;
extern ActorSpec LeftCurveInclinedActorSpec;
extern ActorSpec RoadClosedActorSpec;
extern ActorSpec AirplaneActorSpec;
extern ActorSpec WindTurbineActorSpec;

//---------------------------------------------------------------------------------------------------------
// 											Actor LISTS
//---------------------------------------------------------------------------------------------------------

PositionedActorROMSpec WireframesStageActorSpecs[] =
{
	{&StreetEndActorSpec, 			{0, 56, 832}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&HouseActorSpec,				{256,-8, 1024}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&HouseActorSpec,				{-256, -8, 1280}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&HouseBigActorSpec,			{-256, -8, 1536}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{0, 56, 1728}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&BusStopActorSpec,				{192, -8, 768}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&BillboardActorSpec,			{-160, -8, 546}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&LampActorSpec,				{192, -8, 640}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&LampActorSpec,				{192, -8, 1280}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{0, 56, 2624}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&TunnelActorSpec,				{0, 56, 2368}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&WindTurbineActorSpec, 		{128, 56, 3552}, {0, 48, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&CurveLeftActorSpec,			{0, 56, 3008}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},

	{&StreetActorSpec,				{-896, 56, 3392}, {0, -128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{-1792, 56, 3392}, {0, -128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&PowerPoleActorSpec,			{-848, 56, 3072}, {0, 128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&PowerPoleActorSpec,			{-1104, 56, 3072}, {0, 128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&PowerCableActorSpec,			{-848, -76, 3156}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&ProductionSiteActorSpec,		{-2032, 56, 3584}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{-2688, 56, 3392}, {0, -128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&CurveLeftActorSpec,			{-3072, 56, 3392}, {0, -128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	
	{&StreetInclinedActorSpec,		{-3456, 56, 2624}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{-3456, -40, 2112}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&TreeActorSpec,				{-3256, -40, 1952}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&ViewpointActorSpec,			{-3328, -40, 2368}, {0, 128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{-3456, -40, 1216}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&WaterTowerActorSpec,			{-3820, -192, 400}, {0, 32, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&LeftCurveInclinedActorSpec, 	{-3456, -40, 832}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},

	{&StreetActorSpec, 				{-2560, 56, 448}, {0, 128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec, 				{-1664, 56, 448}, {0, 128, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&ChurchActorSpec,				{-1888, 56, 256}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&LampActorSpec,				{-1832, -8, 336}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&CurveLeftActorSpec, 			{-896, 56, 64}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},

	{&StreetActorSpec,				{-896, 56, -320}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&StreetActorSpec,				{-896, 56, -1216}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&RoadClosedActorSpec,			{-896, 56, -1728}, {0, 256, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{&AirplaneActorSpec, 			{-488, -128, -1024}, {-32, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},

	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

PositionedActorROMSpec WireframesStageUiActorSpecs[] =
{
	{&LowPowerIndicatorActorSpec, {__PLUGIN_LOW_POWER_ACTOR_X_POSITION, __PLUGIN_LOW_POWER_ACTOR_Y_POSITION, __PLUGIN_LOW_POWER_ACTOR_Z_POSITION}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ASSETS LISTS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

FontROMSpec* const WireframesStageFontSpecs[] =
{
	NULL
};

SoundROMSpec* const WireframesStageSoundSpecs[] =
{
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// STAGE DEFINITION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

StageROMSpec WireframesStageSpec =
{
	// Class allocator
	__TYPE(Stage),

	// Timer config
	{
		// Timer's resolution (__TIMER_100US or __TIMER_20US)
		__TIMER_100US,
		// Target elapsed time between timer interrupts
		40,
		// Timer interrupt's target time units
		kMS
	},

	// General stage's attributes
	{
		// Stage's size in pixels
		{
			// x
			8191,
			// y
			__SCREEN_HEIGHT,
			// z
			8191,
		},

		// Camera's initial position inside the stage
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

		// Camera's frustum
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
			1024 + 1024 + 512,
		}
	},

	// Streaming
	{
		// Padding to be added to camera's frustum when checking if a actor spec
		// describes an actor that is within the camera's range
		160,
		// Padding to be added to camera's frustum when checking if a actor is
		// out of the camera's range
		64,
		// Amount of actor descriptions to check for streaming in actors
		24,
		// If true, actor instantiation is done over time
		false,
	},

	// Rendering
	{
		// Maximum number of texture's rows to write each time the texture writing is active
		12,

		// Maximum number of rows to compute on each call to the affine functions
		112,

		// Color configuration
		{
			// Background color
			__COLOR_BLACK,

			// Brightness
			// These values times the repeat values specified in the column table (max. 16) make the final
			// brightness values on the respective regions of the screen. maximum brightness is 128.
			{
				// Dark red
				8,
				// Medium red
				__BRIGHTNESS_MEDIUM_RED,
				// Bright red
				__BRIGHTNESS_BRIGHT_RED,
			},

			// Brightness repeat
			(BrightnessRepeatSpec*)NULL,
		},

		// Palettes' configuration
		{
			{
				// Bgmap palette 0
				__BGMAP_PALETTE_0,
				// Bgmap palette 1
				__BGMAP_PALETTE_1,
				// Bgmap palette 2
				__BGMAP_PALETTE_2,
				// Bgmap palette 3
				__BGMAP_PALETTE_3,
			},
			{
				// Object palette 0
				__OBJECT_PALETTE_0,
				// Object palette 1
				__OBJECT_PALETTE_1,
				// Object palette 2
				__OBJECT_PALETTE_2,
				// Object palette 3
				__OBJECT_PALETTE_3,
			},
		},

		// Bgmap segments configuration
		// Number of BGMAP segments reserved for the param
		1,

		// Object Sprite Containers configuration
		// true to instantiate, z for z sorting
		{
			// SPT0
			{false, 0},
			// SPT1
			{false, 0},
			// SPT2
			{false, 0},
			// SPT3
			{false, 0}
		},
		// Struct defining the optical settings for the stage
		{
			// Maximum view distance's power into the horizon
			__MAXIMUM_X_VIEW_DISTANCE, __MAXIMUM_Y_VIEW_DISTANCE,
			// Distance of the eyes to the screen
			__CAMERA_NEAR_PLANE,
			// Distance from left to right eye (depth sensation)
			__BASE_FACTOR,
			// Horizontal view point center
			__HORIZONTAL_VIEW_POINT_CENTER,
			// Vertical view point center
			__VERTICAL_VIEW_POINT_CENTER,
			// Scaling factor
			__SCALING_MODIFIER_FACTOR
		},
	},

	// Physical world's properties
	{
		// Gravity
		{
			__I_TO_FIX10_6(0),
			__F_TO_FIX10_6(0),
			__I_TO_FIX10_6(0),
		},

		// Friction coefficient
		__F_TO_FIX10_6(0.1f),
	},

	// Assets
	{
		// Fonts to preload
		(FontSpec**)WireframesStageFontSpecs,

		// CharSets to preload
		(CharSetSpec**)NULL,

		// Textures to preload
		(TextureSpec**)NULL,

		// Sounds to load
		(SoundSpec**)WireframesStageSoundSpecs,
	},

	// Actors
	{
		// UI configuration
		{
			(PositionedActor*)WireframesStageUiActorSpecs,
			__TYPE(UIContainer),
		},

		// Stage's children actors
		(PositionedActor*)WireframesStageActorSpecs,
	},

	// Post processing effects
	(PostProcessingEffect*)NULL,
};
