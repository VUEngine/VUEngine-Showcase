/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <ActorsState.h>
#include <Body.h>
#include <Messages.h>
#include <Punk.h>
#include <Telegram.h>

#include "PunkWalking.h"


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void PunkWalking::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}
//---------------------------------------------------------------------------------------------------------
void PunkWalking::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
void PunkWalking::enter(void* owner)
{
	PunkWalking::restoreMethods();

	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return;
	}

	Punk::playAnimation(punk, "Move");
}
//---------------------------------------------------------------------------------------------------------
bool PunkWalking::processMessage(void* owner, Telegram telegram)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk) || isDeleted(Punk::getBody(punk)))
	{
		return false;
	}
	
	Vector3D force = Vector3D::zero();

	switch(Telegram::getMessage(telegram))
	{
		case kMessageActorsStateReleasedLeft:
		case kMessageActorsStateReleasedRight:

			/*
			 * Start to check if the punk stopped only when there is no input.
			 */
			PunkWalking::mutateMethod(execute, PunkWalking::executeCheckIfMoving);
			return true;
			break;

		case kMessageActorsStateHoldLeft:
			
			force.x = -(Body::getMass(Punk::getBody(punk)) << 1);
			break;

		case kMessageActorsStateHoldRight:

			force.x = Body::getMass(Punk::getBody(punk)) << 1;
			break;
	}

	if(0 == force.x)
	{
		return false;
	}

	Punk::applyForce(punk, &force, true);

	/*
	 * Don't check if not moving while there is a force applied to the punk.
	 */
	PunkWalking::restoreMethods();

	return true;
}
//---------------------------------------------------------------------------------------------------------

//=========================================================================================================
// CLASS' PRIVATE METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void PunkWalking::executeCheckIfMoving(void* owner __attribute__ ((unused)))
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return;
	}

	if(!Punk::isMoving(punk))
	{
		Punk::freeze(punk);
	}
}
//---------------------------------------------------------------------------------------------------------
