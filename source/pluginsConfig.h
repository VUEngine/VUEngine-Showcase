/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PLUGINS_CONFIG_H_
#define PLUGINS_CONFIG_H_


//---------------------------------------------------------------------------------------------------------
//												PLUGINS
//---------------------------------------------------------------------------------------------------------

#define __SAVE_DATA_MANAGER_SAVE_STAMP						"VUEngine"
#define __SAVE_DATA_MANAGER_SAVE_STAMP_LENGTH				8

#define __ADJUSTMENT_SCREEN_USE_LOW_POWER_ENTITY			true
#define __LANGUAGE_SELECTION_SCREEN_VARIANT					1

#define __AUTOMATIC_PAUSE_SCREEN_TITLE_TEXT_FONT			"AstonishExt"
#define __AUTOMATIC_PAUSE_SELECTION_SCREEN_TITLE_TEXT_FONT	"AstonishExt"
#define __LANGUAGE_SELECTION_SCREEN_TITLE_TEXT_FONT 		"AstonishExt"
#define __PRECAUTION_SCREEN_TEXT_FONT						"AstonishExt"


#define __DWARF_PLANET_STARTING_ROW							(64)
#define __DWARF_PLANET_ENDING_ROW							(__SCREEN_HEIGHT)
#define __DWARF_PLANET_STARTING_COLUMN						84
#define __DWARF_PLANET_ENDING_COLUMN						300

#define __WOBBLE_STARTING_ROW								(64)
#define __WOBBLE_ENDING_ROW									(__SCREEN_HEIGHT)

#define __TILT_STARTING_ROW									(64)
#define __TILT_ENDING_ROW									(__SCREEN_HEIGHT)

#define __WATERFALL_X_POSITION								(__HALF_SCREEN_WIDTH_METERS)
#define __WATERFALL_Y_POSITION								(__HALF_SCREEN_HEIGHT_METERS + __PIXELS_TO_METERS(44))
#define __WATERFALL_WIDTH									(140)
#define __WATERFALL_HEIGHT									(64)

#endif
