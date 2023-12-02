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
#include <MessageDispatcher.h>
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
			 * My state machine will process this Telegram.
			 * This is kind of convoluted, but this showcases
			 * how to send messages to the current state in 
			 * the state machine
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
	/*
	Shape collidingShape = collisionInformation->collidingShape;
	SpatialObject collidingObject = Shape::getOwner(collidingShape);
	uint32 collidingObjectInGameType = SpatialObject::getInGameType(collidingObject);

	Velocity velocity = (Velocity){-this->speed, 0, 0};

	switch(collidingObjectInGameType)
	{
		// speed things up by breaking early
		case kEnemyWall:

			this->speed = -this->speed;
			Punk::moveUniformly(this, &velocity);
			break;
	}
	*/

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
