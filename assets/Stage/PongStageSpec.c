/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

//#include <Collision.h>
#include <Fonts.h>
#include <PongPaddle.h>
#include <PongBall.h>
#include <Stage.h>



//——————————————————————————————————————————————————————————————————————————————————————————————————————————

//											DECLARATIONS

//——————————————————————————————————————————————————————————————————————————————————————————————————————————


extern EntitySpec LowPowerIndicatorEntitySpec;
extern EntitySpec PongBallEntitySpec;
extern EntitySpec PongPaddleEntitySpec;
extern EntitySpec PongWallsEntitySpec;


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// ENTITY LISTS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

PositionedEntityROMSpec PongStageEntitySpecs[] =
{
	{&PongBallEntitySpec, 		{  0, 0, 128}, {0, 0, 0}, {1, 1, 1},  	0, PONG_BALL_NAME, NULL, NULL, false},
	{&PongPaddleEntitySpec, 	{-96, 0, 128}, {0, 0, 0}, {1, 1, 1},  	0, PADDLE_LEFT_NAME, NULL, NULL, true},
	{&PongPaddleEntitySpec,	 	{+96, 0, 128}, {0, 0, 0}, {1, 1, 1},  	0, PADDLE_RIGHT_NAME, NULL, NULL, true},
	{&PongWallsEntitySpec,		{ 0,  0, 128}, {0, 0, 0}, {1, 1, 1}, 		0, NULL, NULL, NULL, true}, // bottom border

	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};

PositionedEntityROMSpec PongStageUiEntitySpecs[] =
{
	{&LowPowerIndicatorEntitySpec, 	{__PLUGIN_LOW_POWER_ENTITY_X_POSITION, __PLUGIN_LOW_POWER_ENTITY_Y_POSITION, __PLUGIN_LOW_POWER_ENTITY_Z_POSITION}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
	{NULL, {0, 0, 0}, {0, 0, 0}, {1, 1, 1}, 0, NULL, NULL, NULL, false},
};


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// ASSETS LISTS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

FontROMSpec* const PongStageFontSpecs[] =
{
	NULL
};

CharSetROMSpec* const PongStageCharsets[] =
{
	NULL
};

TextureSpec* const PongStageTextures[] =
{
	NULL
};


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// STAGE DEFINITION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

StageROMSpec PongStageSpec =
{
	// Class allocator
	__TYPE(Stage),

	// Timer config
	{
		__TIMER_100US,
		10,
		kMS
	},

	// Sound config
	{
		__DEFAULT_PCM_HZ,
		0
	},

	// General stage's attributes
	{
		// Stage's size in pixels
		{
			// x
			__SCREEN_WIDTH,
			// y
			__SCREEN_HEIGHT,
			// z
			__SCREEN_DEPTH,
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
			0
		},

		// Camera's frustum
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
			__SCREEN_DEPTH
		}
	},

	// Streaming
	{
		// Padding to be added to camera's frustum when checking if a entity spec
		// describes an entity that is within the camera's range
		0,
		// Padding to be added to camera's frustum when checking if a entity is
		// out of the camera's range
		0,
		// Amount of entity descriptions to check for streaming in entities
		10,
		// If true, entity instantiation is done over time
		false,
	},

	// Rendering
	{
		// Maximum number of texture's rows to write each time the texture writing is active
		64,

		// Maximum number of rows to compute on each call to the affine functions
		64,

		// Color configuration
		{
			// Background color
			__COLOR_BLACK,

			// Brightness
			// These values times the repeat values specified in the column table (max. 16) make the final
			// brightness values on the respective regions of the screen. maximum brightness is 128.
			{
				// Dark red
				__BRIGHTNESS_DARK_RED,
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
		2,

		// obj segments sizes (must total 1024)
		{
			// __spt0
			1024,
			// __spt1
			0,
			// __spt2
			0,
			// __spt3
			0
		},

		// OBJECT segments z coordinates
		// Note that each spt's z coordinate much be larger than or equal to the previous one's,
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

		// Struct defining the optical settings for the stage
		{
			// Maximum view distance's power into the horizon
			__MAXIMUM_X_VIEW_DISTANCE, __MAXIMUM_X_VIEW_DISTANCE,
			// Distance of the eyes to the screen
			__CAMERA_NEAR_PLANE * 3,
			// Distance from left to right eye (depth sensation)
			__BASE_FACTOR,
			// Horizontal view point center
			__HORIZONTAL_VIEW_POINT_CENTER,
			// Vertical view point center
			__VERTICAL_VIEW_POINT_CENTER,
			// Scaling factor
			__SCALING_MODIFIER_FACTOR,
		},
	},

	// Physical world's properties
	{
		// Gravity
		{
			__F_TO_FIX10_6(__GRAVITY),
			__F_TO_FIX10_6(__GRAVITY),
			__F_TO_FIX10_6(__GRAVITY)
		},

		// Friction coefficient
		__F_TO_FIX10_6(0.0f),
	},

	// Assets
	{
		// Fonts to preload
		(FontSpec**)PongStageFontSpecs,

		// CharSets to preload
		(CharSetSpec**)PongStageCharsets,

		// Textures to preload
		(TextureSpec**)PongStageTextures,

		// Sounds to load
		(SoundSpec**)NULL,
	},

	// Entities
	{
		// UI configuration
		{
			(PositionedEntity*)PongStageUiEntitySpecs,
			__TYPE(UIContainer),
		},

		// Stage's children entities
		(PositionedEntity*)PongStageEntitySpecs,
	},

	// Post processing effects
	(PostProcessingEffect*)NULL,
};
