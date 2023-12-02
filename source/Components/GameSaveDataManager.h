/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef GAME_SAVE_DATA_MANAGER_H_
#define GAME_SAVE_DATA_MANAGER_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <SaveDataManager.h>


//---------------------------------------------------------------------------------------------------------
// 											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// this struct is never instantiated, its sole purpose is to determine offsets of its members.
// therefore it acts as kind of like a map of sram content.
typedef struct GameSaveData
{
	// save data handled by base class
	SaveData baseSaveData;

	// some custom value
	uint8 someCustomValue;

} GameSaveData;


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class GameSaveDataManager : SaveDataManager
{
	static GameSaveDataManager getInstance();
	override void restoreSettings();
	uint8 getCustomValue();
	void setCustomValue(uint8 customValue);
}


#endif
