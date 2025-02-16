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

#include "PunkWalking.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

mutation class PunkWalking;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PunkWalking::collisionStarts(const CollisionInformation* collisionInformation)
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

			PunkWalking::freeze(this);

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
			PunkWalking::checkCollisions(this, false);

			PunkWalking::die(this);
			return true;
			break;
	}

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PunkWalking::handleMessage(Telegram telegram)
{
	Vector3D force = Vector3D::zero();

	switch(Telegram::getMessage(telegram))
	{
		case kMessageShowcaseStateReleasedLeft:
		case kMessageShowcaseStateReleasedRight:

			/*
			 * Start to check if the punk stopped only when there is no input.
			 */
			PunkWalking::stop(this);
			return true;
			break;

		case kMessageShowcaseStateHoldLeft:

			force.x = -(Body::getMass(PunkWalking::getBody(this)) << 1);
			break;

		case kMessageShowcaseStateHoldRight:

			force.x = Body::getMass(PunkWalking::getBody(this)) << 1;
			break;
	}

	if(0 == force.x)
	{
		return false;
	}

	PunkWalking::applyForce(this, &force, true);

	return Base::handleMessage(this, telegram);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
