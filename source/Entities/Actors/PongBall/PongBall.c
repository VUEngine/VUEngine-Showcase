/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <PongBall.h>

#include <CommunicationManager.h>
#include <GameEvents.h>
#include <GameConfig.h>
#include <MessageDispatcher.h>
#include <Optics.h>
#include <Pong.h>
#include <ParticleSystem.h>
#include <Telegram.h>
#include <Utilities.h>
#include <VUEngine.h>

#include <debugUtilities.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define START_X_FORCE 									__I_TO_FIX10_6(Utilities::random(seed, 150))
#define START_Y_FORCE 									__I_TO_FIX10_6(Utilities::random(seed, 150))
#define START_Z_FORCE										0

#define MINIMUM_HORIZONTAL_SPEED						__F_TO_FIX10_6(7.5f)
#define MINIMUM_VERTICAL_SPEED							__F_TO_FIX10_6(4.0f)
#define MINIMUM_DEPTH_SPEED								__I_TO_FIX10_6(9)
#define FORCE_TO_APPLY_WHEN_VERTICAL_SPEED_IS_ZERO		__I_TO_FIX10_6(-60)
#define FORCE_DECREASE_PER_CYCLE						__I_TO_FIX10_6(1)
#define SPEED_X_MULTIPLIER								__I_TO_FIX10_6(2)
#define SPEED_Y_MULTIPLIER								__I_TO_FIX10_6(2)


//---------------------------------------------------------------------------------------------------------
//												CLASS'S ATTRIBUTES
//---------------------------------------------------------------------------------------------------------

/*
 * This is used to generate a new angle each time that the ball starts to move.
 * For this to work, this has to be kept in sync between both VBs and is has to
 * persist between calls to startMovement.
 */
static uint32 _randomSeed = 0;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void PongBall::constructor(PongBallSpec* pongBallSpec, int16 internalId, const char* const name)
{
	// construct base
	Base::constructor((ActorSpec*)&pongBallSpec->actorSpec, internalId, name);

	// save spec
	this->pongBallSpec = pongBallSpec;
	this->paddleEnum = kNoPongPaddle;
	this->particles = NULL;
}

void PongBall::destructor()
{
	if(!this->inCameraRange)
	{
		Pong::fireEvent(Pong::getInstance(), kEventPongBallStreamedOut);
	}

	// delete the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

void PongBall::ready(bool recursive)
{
	// call base
	Base::ready(this, recursive);

//	this->particles = ParticleSystem::safeCast(Container::getChildByName(Container::safeCast(this), "Partcls", true));
//	ParticleSystem::setLoop(this->particles, true);

	Pong::fireEvent(Pong::getInstance(), kEventPongBallSpawned);

	PongBall::prepareToMove(this);
}

bool PongBall::handleMessage(Telegram telegram)
{
	switch(Telegram::getMessage(telegram))
	{
		case kPongBallMessageStartMoving:

			PongBall::startMovement(this);
			return true;		
	}

	return Base::handleMessage(this, telegram);	
}

bool PongBall::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kPongMessageResetPositions:

			PongBall::prepareToMove(this);
			break;
	}

	return false;
}

bool PongBall::enterCollision(const CollisionInformation* collisionInformation)
{
	ASSERT(collisionInformation->collidingShape, "Actor::enterCollision: collidingShapes");

	bool returnValue = Base::enterCollision(this, collisionInformation);

	if(NULL == collisionInformation->collidingShape)
	{
		return returnValue;
	}	

	SpatialObject collidingObject = Shape::getOwner(collisionInformation->collidingShape);

	switch(SpatialObject::getInGameType(collidingObject))
	{
		case kTypePongPaddle:

			{
				Vector3D velocity = *Body::getVelocity(this->body);

				fixed_t yDisplacement = this->transformation.globalPosition.y - SpatialObject::getPosition(collidingObject)->y;

//				velocity.x -= yDisplacement;
				velocity.y += yDisplacement;

				Body::setVelocity(this->body, &velocity);
			}
			break;
	}


	return returnValue;
}


void PongBall::prepareToMove()
{
	PongPaddle::stopMovement(this, __ALL_AXIS);
	Body::setMaximumVelocity(this->body, this->pongBallSpec->maximumVelocity);
	Vector3D localPosition = Vector3D::zero();
	localPosition.z = __PIXELS_TO_METERS(128);
	Entity::setLocalPosition(this, &localPosition);
	PongBall::discardMessages(this, kPongBallMessageStartMoving);
	PongBall::sendMessageToSelf(this, kPongBallMessageStartMoving, 1500, 0);
}

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

		angle = Utilities::random(Utilities::randomSeed() + _randomSeed, 64) - 32;
	}

	Vector3D velocity =
	{
		__FIXED_MULT(this->pongBallSpec->maximumVelocity.x, __FIX7_9_TO_FIXED(__COS(angle))),
		__FIXED_MULT(this->pongBallSpec->maximumVelocity.y, __FIX7_9_TO_FIXED(__SIN(angle))),
		0
	};

	if(50 > Utilities::random(Utilities::randomSeed() + _randomSeed, 100))
	{
		velocity.x = -velocity.x;
	}

	Body::moveUniformly(this->body, velocity);
}

fix10_6 PongBall::getFrictionOnCollision(SpatialObject collidingObject __attribute__ ((unused)), const Vector3D* collidingObjectNormal __attribute__ ((unused)))
{
	return 0;
}

fix10_6 PongBall::getSurroundingFrictionCoefficient()
{
	return 0;
}

int PongBall::getPaddleEnum()
{
	return this->paddleEnum;
}

void PongBall::syncRotationWithBody()
{
}