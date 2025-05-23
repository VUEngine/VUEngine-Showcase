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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <Collider.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// A PongPaddle Spec
/// @memberof PongPaddle
typedef struct PongPaddleSpec
{
	/// Actor spec
	ActorSpec actorSpec;

	/// Force to apply to the paddle
	Vector3D force;

} PongPaddleSpec;

/// A PongPaddle spec that is stored in ROM
/// @memberof PongPaddle
typedef const PongPaddleSpec PongPaddleROMSpec;

/// Enum to identify the paddles
/// @memberof PongPaddle
enum PongPaddleType
{
	kPaddleNone = 0,
	kPaddleLocal,
	kPaddleRemote
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class PongPaddle
///
/// Inherits from Actor
///
/// Implements a Pong paddle.
class PongPaddle : Actor
{
	/// @protectedsection
	uint32 type;

	/// @param pongPaddleSpec: Specification that determines how to configure the paddle
	/// @param internalId: ID to keep track internally of the new instance
	/// @param name: Name to assign to the new instance
	void constructor(const PongPaddleSpec* pongPaddleSpec, int16 internalId, const char* const name);

	/// Default interger message handler for propagateMessage
	/// @param message: Propagated integer message
	/// @return True if the propagation must stop; false if the propagation must reach other containers
	override bool handlePropagatedMessage(int32 message);

	/// Set whether the paddle is locally controlled or not.
	/// @param type: kPaddleLocal/kPaddleRemote
	void setType(uint32 type);
}

#endif
