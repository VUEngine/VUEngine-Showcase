/*
 * Capitán Sevilla 3D, an adventure platforming game demo for Nintendo Virtual Boy
 *
 * (c) Christian Radke, Jorge Eremiev and Rubén Garcerá Soto
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Punk.h>

#include <ActorsState.h>
#include <GameConfig.h>
#include <MessageDispatcher.h>
#include <PunkDie.h>
#include <PunkFrozen.h>
#include <PunkWalking.h>
#include <Telegram.h>
#include <ShowcaseState.h>
#include <StateMachine.h>

#include <debugUtilities.h>


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void Punk::constructor(PunkSpec* punkSpec, int16 internalId, const char* const name)
{
	// construct base
	Base::constructor((ActorSpec*)&punkSpec->actorSpec, internalId, name);
}

void Punk::destructor()
{
	// destroy the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

/*
 * This method is called when the entity has been fully initialized
 */
void Punk::ready(bool recursive)
{
	Base::ready(this, recursive);

	this->stateMachine = new StateMachine(this);

	Punk::freeze(this);
}

/*
 * Messaging serves the purpose of communicating classes decoupling their interfaces
 * (ie; not having to implement specific methods). These messages can be delayed too.
*/
bool Punk::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kActorsStateResucitate:

			Punk::resucitate(this);
			return true;
			break;
	}

	Base::handleMessage(this, telegram);	
}

/*
 * Returning true stops the propagation
 */
bool Punk::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kActorsStateHoldLeft:
		case kActorsStateHoldRight:
		case kActorsStateReleasedLeft:
		case kActorsStateReleasedRight:

			/*
			 * My state machine will process this Telegram. This is not very performant, but it is certainly, 
			 * more elegant than calling directly a specific method in the current state, and this showcases
			 * how to send messages to the current state in the state machine
			 */ 
			MessageDispatcher::dispatchMessage(0, ListenerObject::safeCast(this), ListenerObject::safeCast(this), message, NULL);
			return true;
			break;

		case kActorsStatePrintActorStatus:

			Body::print(this->body, 1, 3);
			return true;
			break;
	}

	return false;
}

// process collisions
bool Punk::enterCollision(const CollisionInformation* collisionInformation)
{
	if(NULL == collisionInformation || isDeleted(collisionInformation->collidingShape))
	{
		return false;
	}

	Shape collidingShape = collisionInformation->collidingShape;
	SpatialObject collidingObject = Shape::getOwner(collidingShape);

	if(isDeleted(collidingObject))
	{
		return false;
	}

	uint32 collidingObjectInGameType = SpatialObject::getInGameType(collidingObject);

	switch(collidingObjectInGameType)
	{
		case kTypeSolidObject:

			Punk::freeze(this);

			/*
			 * The Actor class can resolve collisions against solid objects by itself
			 */
			return Base::enterCollision(this, collisionInformation);
			break;

		case kTypeCogWheel:

			/*
			* Disable collision checks so this doesn't fire multiple times. 
			* They are enabled by the Actor when starting to move.
			*/
			Punk::activeCollisionChecks(this, false);

			Punk::die(this);
			return true;
			break;
	}

	return false;
}

void Punk::freeze()
{
	StateMachine::swapState(this->stateMachine, State::safeCast(PunkFrozen::getInstance()));	
}

void Punk::walk()
{
	StateMachine::swapState(this->stateMachine, State::safeCast(PunkWalking::getInstance()));	
}

void Punk::die()
{
	StateMachine::swapState(this->stateMachine, State::safeCast(PunkDie::getInstance()));	
}

void Punk::resucitate()
{
	Vector3D position = Vector3D::getFromPixelVector((PixelVector){0, 64, 0, 0});
	Punk::setLocalPosition(this, &position);

	Rotation rotation = Rotation::zero();
	Punk::setLocalRotation(this, &rotation);

	Punk::freeze(this);
}

void Punk::onDieAnimationComplete(ListenerObject eventFirer __attribute__((unused)))
{
	/*
	 * Restore myself after 1 second
	 */
	Punk::sendMessageToSelf(this, kActorsStateResucitate, 1000, 0);
}