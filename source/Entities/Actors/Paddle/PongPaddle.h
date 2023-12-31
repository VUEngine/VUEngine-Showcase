/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_PADDLE_H_
#define PONG_PADDLE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Actor.h>
#include <Collider.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define PADDLE_LEFT_NAME			"LeftPD"
#define PADDLE_RIGHT_NAME			"RightPD"


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------


typedef struct PongPaddleSpec
{
	// the base animated entity
	ActorSpec actorSpec;

	// force to apply
	Vector3D force;

} PongPaddleSpec;

typedef const PongPaddleSpec PongPaddleROMSpec;


enum PlayerPongPaddles
{
	kLeftPongPaddle = 0,
	kRightPongPaddle,
	kNoPongPaddle
};


class PongPaddle : Actor
{
	void constructor(PongPaddleSpec* pongPaddleSpec, int16 internalId, const char* const name);
	void moveTowards(NormalizedDirection direction);
	override bool handlePropagatedMessage(int32 message);
	override bool mustBounce();
}


#endif
