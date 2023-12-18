/**
 * Virtual WarZone
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <PunkFrozen.h>

#include <ActorsState.h>
#include <Messages.h>
#include <Punk.h>
#include <Telegram.h>

#include <DebugUtilities.h>


//---------------------------------------------------------------------------------------------------------
//												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void PunkFrozen::constructor()
{
	// construct base
	Base::constructor();
}

// class's destructor
void PunkFrozen::destructor()
{
	// destroy base
	Base::destructor();
}

// state's enter
void PunkFrozen::enter(void* owner)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return;
	}
	
	Punk::pauseAnimation(punk, true);
	Punk::setActualFrame(punk, 0);
}

// state's handle message
bool PunkFrozen::processMessage(void* owner, Telegram telegram)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return false;
	}

	switch(Telegram::getMessage(telegram))
	{
		case kMessageActorsStateHoldLeft:
		case kMessageActorsStateHoldRight:

			Punk::walk(punk);
			return true;
	}

	return false;
}

