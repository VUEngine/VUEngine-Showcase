/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef GAME_SAVE_DATA_MANAGER_H_
#define GAME_SAVE_DATA_MANAGER_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <SaveDataManager.h>


//=========================================================================================================
// CLASS' DATA
//=========================================================================================================

typedef struct GameSaveData
{
	// save data handled by base class
	SaveData baseSaveData;

	// some custom value
	uint8 someCustomValue;

} GameSaveData;


//=========================================================================================================
// CLASS' DECLARATION
//=========================================================================================================

///
/// Class GameSaveDataManager
///
/// Inherits from SaveDataManager
///
/// Implements a custom save data manager.
singleton class GameSaveDataManager : SaveDataManager
{
	/// Method to GameSaveDataManager the singleton instance
	/// @return AnimationSchemesState singleton
	static GameSaveDataManager getInstance();

	/// Save a custom value to SRAM.
	/// @param customValue: Value to save
	void setCustomValue(uint8 customValue);

	/// Retriev the custom value from SRAM.
	/// @return Value from SRAM
	uint8 getCustomValue();
}

#endif
