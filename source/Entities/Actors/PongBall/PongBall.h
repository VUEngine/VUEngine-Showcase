/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_BALL_H_
#define PONG_BALL_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Actor.h>

#include <PongPaddle.h>
#include <ParticleSystem.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define PONG_BALL_NAME				"PongBL"


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------


typedef struct PongBallSpec
{
	// the base animated entity
	ActorSpec actorSpec;

	// minimum velocity when moving
	Vector3D minimumVelocity;

	// maximum velocity when moving
	Vector3D maximumVelocity;

} PongBallSpec;

typedef const PongBallSpec PongBallROMSpec;


class PongBall : Actor
{
	/* spec pointer */
	ParticleSystem particles;
	PongBallSpec* pongBallSpec;
	int paddleEnum;

	void constructor(PongBallSpec* pongBallSpec, int16 internalId, const char* const name);
	void startMovement();
	int getPaddleEnum();
	override void ready(bool recursive);
	override fix10_6 getFrictionOnCollision(SpatialObject collidingObject, const Vector3D* collidingObjectNormal);
	override fix10_6 getSurroundingFrictionCoefficient();
	override void syncRotationWithBody();
}


#endif
