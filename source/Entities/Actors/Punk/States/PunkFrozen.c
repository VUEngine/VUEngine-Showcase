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

#include <ActorsState.h>
#include <Messages.h>
#include <Punk.h>
#include <Telegram.h>

#include "PunkFrozen.h"


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————


//——————————————————————————————————————————————————————————————————————————————————————————————————————————

void PunkFrozen::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————

void PunkFrozen::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————

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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————

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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————

