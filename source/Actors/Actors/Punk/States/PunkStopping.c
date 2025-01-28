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

#include <Body.h>
#include <CollisionsState.h>
#include <InGameTypes.h>
#include <Messages.h>
#include <Printer.h>
#include <Telegram.h>

#include "PunkStopping.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PunkStopping::collisionStarts(const CollisionInformation* collisionInformation)
{
	if(NULL == collisionInformation || isDeleted(collisionInformation->otherCollider))
	{
		return false;
	}

	Collider otherCollider = collisionInformation->otherCollider;
	Entity collidingEntity = Collider::getOwner(otherCollider);

	if(isDeleted(collidingEntity))
	{
		return false;
	}

	uint32 collidingEntityInGameType = Entity::getInGameType(collidingEntity);

	switch(collidingEntityInGameType)
	{
		case kTypeSolidObject:

			PunkStopping::freeze(this);

			/*
			 * The Actor class can resolve collisions against solid objects by itself
			 */
			return Base::collisionStarts(this, collisionInformation);
			break;

		case kTypeCogWheel:

			/*
			 * Disable collision checks so this doesn't fire multiple times.
			 * They are enabled by the Actor when starting to move.
			 */
			PunkStopping::checkCollisions(this, false);

			PunkStopping::die(this);
			return true;
			break;
	}

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PunkStopping::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kMessageCollisionsStateHoldLeft:
		case kMessageCollisionsStateHoldRight:

			PunkStopping::walk(this);
			return true;
			break;
	}

	return Base::handleMessage(this, telegram);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PunkStopping::update()
{
	if(!PunkStopping::isMoving(this))
	{
		PunkStopping::freeze(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PunkStopping::destructor()
{
	// Always explicitly call the base's destructor
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
