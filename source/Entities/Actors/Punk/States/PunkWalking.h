/**
 * Virtual WarZone
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PUNK_WALKING_H_
#define PUNK_WALKING_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <State.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
//										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

singleton class PunkWalking : State
{
	static PunkWalking getInstance();

	void constructor();

	override void enter(void* owner);
	override bool processMessage(void* owner, Telegram telegram);
}


#endif
