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

#include <ActorsState.h>
#include <Body.h>
#include <InGameTypes.h>
#include <MessageDispatcher.h>
#include <Messages.h>
#include <PunkDie.h>
#include <PunkFrozen.h>
#include <PunkWalking.h>
#include <Telegram.h>
#include <ShowcaseState.h>
#include <StateMachine.h>

#include "Punk.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::constructor(PunkSpec* punkSpec, int16 internalId, const char* const name)
{
	// Always explicitly call the base's constructor 
	Base::constructor((ActorSpec*)&punkSpec->actorSpec, internalId, name);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * Messaging serves the purpose of communicating classes decoupling their interfaces
 * (ie; not having to implement specific methods). These messages can be delayed too.
*/
bool Punk::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kMessageActorsStateResuscitate:

			Punk::resuscitate(this);
			return true;
			break;
	}

	return Base::handleMessage(this, telegram);	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool Punk::collisionStarts(const CollisionInformation* collisionInformation)
{
	if(NULL == collisionInformation || isDeleted(collisionInformation->otherCollider))
	{
		return false;
	}

	Collider otherCollider = collisionInformation->otherCollider;
	GameObject collidingObject = Collider::getOwner(otherCollider);

	if(isDeleted(collidingObject))
	{
		return false;
	}

	uint32 collidingObjectInGameType = GameObject::getInGameType(collidingObject);

	switch(collidingObjectInGameType)
	{
		case kTypeSolidObject:

			Punk::freeze(this);

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
			Punk::checkCollisions(this, false);

			Punk::die(this);
			return true;
			break;
	}

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * Returning true stops the propagation
 */
bool Punk::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kMessageActorsStateHoldLeft:
		case kMessageActorsStateHoldRight:
		case kMessageActorsStateReleasedLeft:
		case kMessageActorsStateReleasedRight:

			/*
			 * My state machine will process this Telegram. This is not very performant, but it is certainly, 
			 * more elegant than calling directly a specific method in the current state, and this showcases
			 * how to send messages to the current state in the state machine
			 */ 
			MessageDispatcher::dispatchMessage(0, ListenerObject::safeCast(this), ListenerObject::safeCast(this), message, NULL);
			return true;
			break;

		case kMessageActorsStatePrintActorStatus:

			if(!isDeleted(this->body))
			{
				Body::print(this->body, 1, 3);
			}
			return true;
			break;
	}

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * This method is called when the entity has been fully initialized
 */
void Punk::ready(bool recursive)
{
	Base::ready(this, recursive);

	this->stateMachine = new StateMachine(this);

	Punk::freeze(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::freeze()
{
	StateMachine::swapState(this->stateMachine, State::safeCast(PunkFrozen::getInstance()));	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::walk()
{
	StateMachine::swapState(this->stateMachine, State::safeCast(PunkWalking::getInstance()));	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::die()
{
	StateMachine::swapState(this->stateMachine, State::safeCast(PunkDie::getInstance()));	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::resuscitate()
{
	Vector3D position = Vector3D::getFromPixelVector((PixelVector){0, 64, 0, 0});
	Punk::setLocalPosition(this, &position);

	Rotation rotation = Rotation::zero();
	Punk::setLocalRotation(this, &rotation);

	Punk::freeze(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * This is an EventListener added by the engine because the PunkDieAnimation
 * defines it as the callback for when its playback finishes.
 */
bool Punk::onDieAnimationComplete(ListenerObject eventFirer __attribute__((unused)))
{
	/*
	 * Restore myself after 1 second
	 */
	Punk::sendMessageToSelf(this, kMessageActorsStateResuscitate, 1000, 0);

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
