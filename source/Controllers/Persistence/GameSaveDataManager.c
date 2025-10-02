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

#include <stddef.h>

#include <SRAMManager.h>
#include <Singleton.h>
#include <VirtualList.h>

#include "GameSaveDataManager.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void GameSaveDataManager::constructor()
{
	// Always explicitly call the base's constructor
	Base::constructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void GameSaveDataManager::destructor()
{
	// Always explicitly call the base's destructor
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void GameSaveDataManager::setCustomValue(uint8 customValue)
{
	if(this->sramAvailable)
	{
		// Write language
		SRAMManager::save((uint8*)&customValue, offsetof(struct GameSaveData, someCustomValue), sizeof(customValue));

		// Write checksum
		SaveDataManager::writeChecksum(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint8 GameSaveDataManager::getCustomValue()
{
	uint8 customValue = 0;
	if(this->sramAvailable)
	{
		SRAMManager::read((uint8*)&customValue, offsetof(struct GameSaveData, someCustomValue), sizeof(customValue));
	}

	return customValue;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
