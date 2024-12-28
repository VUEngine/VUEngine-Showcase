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

#include <CommunicationManager.h>
#include <GameEvents.h>
#include <InGameTypes.h>
#include <MessageDispatcher.h>
#include <Messages.h>
#include <Optics.h>
#include <Pong.h>
#include <ParticleSystem.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <SoundManager.h>
#include <Sounds.h>
#include <Telegram.h>
#include <Utilities.h>
#include <VUEngine.h>

#include "PongBall.h"


//=========================================================================================================
// CLASS' MACROS
//=========================================================================================================

#define START_X_FORCE 									__I_TO_FIX10_6(Math::random(seed, 150))
#define START_Y_FORCE 									__I_TO_FIX10_6(Math::random(seed, 150))
#define START_Z_FORCE										0

#define MINIMUM_HORIZONTAL_SPEED						__F_TO_FIX10_6(7.5f)
#define MINIMUM_VERTICAL_SPEED							__F_TO_FIX10_6(4.0f)
#define MINIMUM_DEPTH_SPEED								__I_TO_FIX10_6(9)
#define FORCE_TO_APPLY_WHEN_VERTICAL_SPEED_IS_ZERO		__I_TO_FIX10_6(-60)
#define FORCE_DECREASE_PER_CYCLE						__I_TO_FIX10_6(1)
#define SPEED_X_MULTIPLIER								__I_TO_FIX10_6(2)
#define SPEED_Y_MULTIPLIER								__I_TO_FIX10_6(2)


//=========================================================================================================
// CLASS' ATTRIBUTES
//=========================================================================================================

/*
 * This is used to generate a new angle each time that the ball starts to move.
 * For this to work, this has to be kept in sync between both VBs and is has to
 * persist between calls to startMovement.
 */
static uint32 _randomSeed = 0;


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void PongBall::constructor(PongBallSpec* pongBallSpec, int16 internalId, const char* const name)
{
	// Always explicitly call the base's constructor 
	Base::constructor((ActorSpec*)&pongBallSpec->actorSpec, internalId, name);
}
//---------------------------------------------------------------------------------------------------------
void PongBall::destructor()
{
	if(!PongBall::isInCameraRange(this, 0, false))
	{
		Pong::fireEvent(Pong::getInstance(), kEventPongBallStreamedOut);
	}

	// Always explicitly call the base's destructor 
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
bool PongBall::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kMessagePongBallStartMoving:

			PongBall::startMovement(this);
			return true;		
	}

	return Base::handleMessage(this, telegram);	
}
//---------------------------------------------------------------------------------------------------------
bool PongBall::collisionStarts(const CollisionInformation* collisionInformation)
{
	ASSERT(collisionInformation->otherCollider, "Actor::collisionStarts: otherColliders");

	bool returnValue = Base::collisionStarts(this, collisionInformation);

	if(NULL == collisionInformation->otherCollider)
	{
		return returnValue;
	}	

	SpatialObject collidingObject = Collider::getOwner(collisionInformation->otherCollider);

	switch(SpatialObject::getInGameType(collidingObject))
	{
		case kTypePongPaddle:

			{
				Vector3D velocity = *Body::getVelocity(this->body);

				fixed_t yDisplacement = this->transformation.position.y - SpatialObject::getPosition(collidingObject)->y;

//				velocity.x -= yDisplacement;
				velocity.y += yDisplacement;

				Body::setVelocity(this->body, &velocity);
			}
			break;
	}

	RumbleManager::startEffect(&HitPaddleRumbleEffectSpec);

	SoundManager::playSound
	(
		SoundManager::getInstance(), 
		&HitPaddle1SoundSpec, 
		NULL, 
		kSoundPlaybackNormal,
		NULL, 
		NULL
	);

	return returnValue;
}
//---------------------------------------------------------------------------------------------------------
bool PongBall::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kMessagePongResetPositions:

			PongBall::prepareToMove(this);
			break;
	}

	return false;
}
//---------------------------------------------------------------------------------------------------------
void PongBall::ready(bool recursive)
{
	// call base
	Base::ready(this, recursive);

	Pong::fireEvent(Pong::getInstance(), kEventPongBallSpawned);

	PongBall::prepareToMove(this);
}
//---------------------------------------------------------------------------------------------------------

//=========================================================================================================
// CLASS' PRIVATE METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void PongBall::prepareToMove()
{
	PongPaddle::stopMovement(this, __ALL_AXIS);
	Vector3D localPosition = Vector3D::zero();
	localPosition.z = __PIXELS_TO_METERS(128);
	PongBall::setLocalPosition(this, &localPosition);

	Body::setMaximumVelocity(this->body, ((PongBallSpec*)this->entitySpec)->maximumVelocity);

	PongBall::discardMessages(this, kMessagePongBallStartMoving);
	PongBall::sendMessageToSelf(this, kMessagePongBallStartMoving, 1500, 0);
}
//---------------------------------------------------------------------------------------------------------
void PongBall::startMovement()
{
	int16 angle = 0;

	if(Pong::isVersusMode(Pong::getInstance()))
	{
		if(0 == _randomSeed)
		{
			_randomSeed = 7;
		}

		_randomSeed ^= _randomSeed << 13;
		_randomSeed ^= _randomSeed >> 17;
		_randomSeed ^= _randomSeed << 5;

		angle = Math::random(Math::randomSeed() + _randomSeed, 64) - 32;
	}

	Vector3D velocity =
	{
		__FIXED_MULT(((PongBallSpec*)this->entitySpec)->maximumVelocity.x, __FIX7_9_TO_FIXED(__COS(angle))),
		__FIXED_MULT(((PongBallSpec*)this->entitySpec)->maximumVelocity.y, __FIX7_9_TO_FIXED(__SIN(angle))),
		0
	};

	if(50 > Math::random(Math::randomSeed() + _randomSeed, 100))
	{
		velocity.x = -velocity.x;
	}

	PongBall::setVelocity(this, &velocity, false);
}
//---------------------------------------------------------------------------------------------------------
