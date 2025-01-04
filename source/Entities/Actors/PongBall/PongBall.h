/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_BALL_H_
#define PONG_BALL_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <StatefulActor.h>
#include <PongPaddle.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// A PongPaddle Spec
/// @memberof PongBall
typedef struct PongBallSpec
{
	/// StatefulActor spec
	StatefulActorSpec statefulActorSpec;

	/// minimum velocity when moving
	Vector3D minimumVelocity;

	/// maximum velocity when moving
	Vector3D maximumVelocity;

} PongBallSpec;

/// A PongBall spec that is stored in ROM
/// @memberof PongBall
typedef const PongBallSpec PongBallROMSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class PongBall
///
/// Inherits from StatefulActor
///
/// Implements a Pong ball.
class PongBall : StatefulActor
{
	/// @param pongBallSpec: Specification that determines how to configure the paddle
	/// @param internalId: ID to keep track internally of the new instance
	/// @param name: Name to assign to the new instance
	void constructor(PongBallSpec* pongBallSpec, int16 internalId, const char* const name);

	/// Process a Telegram.
	/// @param telegram: Telegram to process
	/// @return True if the Telegram was processed
	override bool handleMessage(Telegram telegram);

	/// Process a newly detected collision by one of the component colliders.
	/// @param collisionInformation: Information struct about the collision to resolve
	/// @return True if the collider must keep track of the collision to detect if it persists and when it
	/// ends; false otherwise
	override bool collisionStarts(const CollisionInformation* collisionInformation);

	/// Default interger message handler for propagateMessage
	/// @param message: Propagated integer message
	/// @return True if the propagation must stop; false if the propagation must reach other containers
	override bool handlePropagatedMessage(int32 message);

	/// Make the animated entity ready to starts operating once it has been completely intialized.
	/// @param recursive: If true, the ready call is propagated to its children, grand children, etc.
	override void ready(bool recursive);
}

#endif
