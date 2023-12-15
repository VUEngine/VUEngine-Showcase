/**
 * VUEngine Video Player
 *
 * © Christian Radke and Marten Reiß
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Stage.h>
#include <Fonts.h>
#include <VIPManager.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern EntitySpec VideoEntity;


//---------------------------------------------------------------------------------------------------------
// 												ASSETS
//---------------------------------------------------------------------------------------------------------

PositionedEntityROMSpec VideoPlayerStageChildren[] =
{
	{&VideoEntity,			{0, 0, 1, 0}, 1, "Video", NULL, NULL, true},

	{NULL,{0,0,0,0}, 0, NULL, NULL, NULL, false},
};

PositionedEntityROMSpec VideoPlayerStageUiEntities[] =
{
	{NULL, {0,0,0,0}, 0, NULL, NULL, NULL, false},
};

//---------------------------------------------------------------------------------------------------------
// 											PRELOAD LISTS
//---------------------------------------------------------------------------------------------------------

FontROMSpec* const VideoPlayerStageFonts[] =
{
	NULL
};


//---------------------------------------------------------------------------------------------------------
// 											STAGE DEFINITION
//---------------------------------------------------------------------------------------------------------

StageROMSpec VideoPlayerStage =
{
	// allocator
	__TYPE(Stage),

    // Timer config
    {
        __TIMER_100US,
        20,
        kMS,
    },

    // Sound config
    {
        __DEFAULT_PCM_HZ,
        0
    },

	// level
	{
        // size
        {
            // x
            __SCREEN_WIDTH,
            // y
            __SCREEN_HEIGHT,
            // z
            __SCREEN_DEPTH,
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
			__SCREEN_WIDTH,
		}
	},

    // streaming
	{
		// load padding
		0,
		// unload padding
		0,
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
		64,

		// maximum number of rows to compute on each call to the affine functions
		16,

        // colors config
        {
            // background color
            __COLOR_BLACK,

            // brightness
            // these values times the repeat values specified in the column table (max. 16) make the final
            // brightness values on the respective regions of the screen. maximum brightness is 128.
            {
                // dark red
                __BRIGHTNESS_DARK_RED,
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
        0,

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
        // Note that each SPT's z coordinate much be larger than or equal to the previous one's,
        // since the VIP renders OBJ Worlds in reverse order (__SPT3 to __SPT0)
        {
            // __spt0
        	__F_TO_FIX10_6(0),
    		__F_TO_FIX10_6(0),
    		__F_TO_FIX10_6(0),
    		__F_TO_FIX10_6(0),
        },

        // optical configuration values
        {
			// maximum view distance's power into the horizon
			__MAXIMUM_X_VIEW_DISTANCE, __MAXIMUM_Y_VIEW_DISTANCE,
			// distance of the eyes to the screen
			0,
			// distance from left to right eye (depth sensation)
			__BASE_FACTOR,
			// horizontal view point center
			__HORIZONTAL_VIEW_POINT_CENTER,
			// vertical view point center
			__VERTICAL_VIEW_POINT_CENTER,
			// scaling factor
			__SCALING_MODIFIER_FACTOR,

        },
	},

    // physics
    {
        // gravity
        {
    	    __F_TO_FIX10_6(0),
    	    __F_TO_FIX10_6(0),
    	    __F_TO_FIX10_6(0),
        },

        // friction
        __F_TO_FIX10_6(0),
    },

    // assets
    {
        // fonts to preload
        (FontSpec**)VideoPlayerStageFonts,

        // char sets to preload
        (CharSetSpec**)NULL,

        // textures to preload
		(TextureSpec**)NULL,

        // background music
        NULL,
    },

    // entities
    {
        // ui
        {
        	NULL,
            NULL,
        },

        // children
        (PositionedEntity*)VideoPlayerStageChildren,
    },

	// post processing effects
	(PostProcessingEffect*)NULL,
};
