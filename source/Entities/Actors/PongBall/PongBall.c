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
#include <PongState.h>
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
		PongState::fireEvent(PongState::getInstance(), kEventPongBallStreamedOut);
	}

	// delete the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

void PongBall::ready(bool recursive)
{
	// call base
	Base::ready(this, recursive);

	if(!PongState::isVersusMode(PongState::getInstance()))
	{
		this->particles = ParticleSystem::safeCast(Container::getChildByName(Container::safeCast(this), "Partcls", true));
//		ParticleSystem::setLoop(this->particles, true);
	}

	PongState::fireEvent(PongState::getInstance(), kEventPongBallSpawned);

	PongBall::startMovement(this);
}

void PongBall::onPositionTransmitted(ListenerObject eventFirer __attribute__((unused)))
{
	if(kPlayerTwo == Pong::getPlayerNumber(Pong::getInstance()))
	{
		const Vector3D* otherWorldPosition = (Vector3D*)CommunicationManager::getReceivedData(CommunicationManager::getInstance());
		Entity::setLocalPosition(this, otherWorldPosition);
	}
}

// start moving
void PongBall::startMovement()
{
	Vector3D localPosition = Vector3D::zero();
	Entity::setLocalPosition(this, &localPosition);

	// Force uniform movement along the X and Y axis, while Z is accelerated and handled by gravity
	Body::setMaximumVelocity(this->body, this->pongBallSpec->maximumVelocity);

	int16 angle = Utilities::random(Utilities::randomSeed(), 511);

	angle = 0;

	Vector3D velocity =
	{
		__FIXED_MULT(this->pongBallSpec->maximumVelocity.x, __FIX7_9_TO_FIXED(__COS(angle))),
		__FIXED_MULT(this->pongBallSpec->maximumVelocity.y, __FIX7_9_TO_FIXED(__SIN(angle))),
		0
	};

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