/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <stddef.h>

#include <SRAMManager.h>
#include <VirtualList.h>

#include "GameSaveDataManager.h"


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void GameSaveDataManager::constructor()
{
	// construct base object
	Base::constructor();
}

// class's destructor
void GameSaveDataManager::destructor()
{
	// destroy base
	Base::destructor();
}

uint8 GameSaveDataManager::getCustomValue()
{
	uint8 customValue = 0;
	if(this->sramAvailable)
	{
		SRAMManager::read(SRAMManager::getInstance(), (BYTE*)&customValue, offsetof(struct GameSaveData, someCustomValue), sizeof(customValue));
	}

	return customValue;
}

void GameSaveDataManager::setCustomValue(uint8 customValue)
{
	if(this->sramAvailable)
	{
		// write language
		SRAMManager::save(SRAMManager::getInstance(), (BYTE*)&customValue, offsetof(struct GameSaveData, someCustomValue), sizeof(customValue));

		// write checksum
		SaveDataManager::writeChecksum(this);
	}
}
