/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_PADDLE_H_
#define PONG_PADDLE_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Actor.h>
#include <Collider.h>


//=========================================================================================================
// CLASS' MACROS
//=========================================================================================================

#define PADDLE_LEFT_NAME			"LeftPD"
#define PADDLE_RIGHT_NAME			"RightPD"


//=========================================================================================================
// CLASS' DATA
//=========================================================================================================

/// A PongPaddle Spec
typedef struct PongPaddleSpec
{
	ActorSpec actorSpec;

	/// Force to apply to the paddle
	Vector3D force;

} PongPaddleSpec;

/// A PongPaddle spec that is stored in ROM
typedef const PongPaddleSpec PongPaddleROMSpec;

/// Enums to identify the paddles
enum PlayerPongPaddles
{
	kLeftPongPaddle = 0,
	kRightPongPaddle,
	kNoPongPaddle
};


//=========================================================================================================
// CLASS' DECLARATION
//=========================================================================================================

///
/// Class PongPaddle
///
/// Inherits from Actor
///
/// Implements a Pong paddle.
class PongPaddle : Actor
{
	/// @param actorSpec: Specification that determines how to configure the paddle
	/// @param internalId: ID to keep track internally of the new instance
	/// @param name: Name to assign to the new instance
	void constructor(PongPaddleSpec* pongPaddleSpec, int16 internalId, const char* const name);

	/// Default interger message handler for propagateMessage
	/// @param message: Propagated integer message
	/// @return True if the propagation must stop; false if the propagation must reach other containers
	override bool handlePropagatedMessage(int32 message);

	/// Check if the padle bounces when it collides with another object.
	/// @return True if the paddle bounces when it collides with another object
	override bool isBouncy();

	/// Move the paddle towards the provided direction.
	/// @param direction: Direction towards which to move the paddle
	void moveTowards(NormalizedDirection direction);
}


#endif
