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

#include <PunkWalking.h>

#include <ActorsState.h>
#include <Punk.h>
#include <Telegram.h>

#include <debugUtilities.h>

//---------------------------------------------------------------------------------------------------------
//												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void PunkWalking::constructor()
{
	// construct base
	Base::constructor();
}

// class's destructor
void PunkWalking::destructor()
{
	// destroy base
	Base::destructor();
}

// state's enter
void PunkWalking::enter(void* owner)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return;
	}

	Punk::playAnimation(punk, "Move");
}

// state's execute
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

void PunkWalking::exit(void* owner __attribute__ ((unused)))
{
	Base::exit(this, owner);

	PunkWalking::restoreMethods();
}

// state's handle message
bool PunkWalking::processMessage(void* owner, Telegram telegram)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return false;
	}
	
	Vector3D force = Vector3D::zero();

	switch(Telegram::getMessage(telegram))
	{
		case kActorsStateReleasedLeft:
		case kActorsStateReleasedRight:

			PunkWalking::mutateMethod(execute, PunkWalking::executeCheckIfMoving);
			return true;
			break;

		case kActorsStateHoldLeft:
			
			force.x = -(Body::getMass(Punk::getBody(punk)) << 1);
			break;

		case kActorsStateHoldRight:

			force.x = Body::getMass(Punk::getBody(punk)) << 1;
			break;
	}

	if(0 == force.x)
	{
		return false;
	}

	Punk::applyForce(punk, &force, true);

	return true;
}

