/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Box.h>
#include <InGameTypes.h>
#include <Messages.h>
#include <Optics.h>
#include <Pong.h>
#include <VUEngine.h>

#include "PongPaddle.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' MACROS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define HORIZONTAL_FORCE		80
#define VERTICAL_FORCE			80

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongPaddle::constructor(PongPaddleSpec* pongPaddleSpec, int16 internalId, const char* const name)
{
	// Always explicitly call the base's constructor 
	Base::constructor((ActorSpec*)&pongPaddleSpec->actorSpec, internalId, name);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongPaddle::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongPaddle::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kMessagePongResetPositions:

			if(!Pong::isVersusMode(Pong::getInstance()))
			{
				PongPaddle::stopMovement(this, __ALL_AXIS);
				Vector3D localPosition = this->localTransformation.position;
				localPosition.y = 0;
				PongPaddle::setLocalPosition(this, &localPosition);
			}

			break;
	}

	/* Returning false allows any other entity interested in the message to process it,
	 * returning true will make that the propagation stops here
	 */ 

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongPaddle::moveTowards(NormalizedDirection direction)
{
	Vector3D force =
	{
		__FIX10_6_MULT(((PongPaddleSpec*)this->entitySpec)->force.x, __I_TO_FIX10_6(direction.x)),
		__FIX10_6_MULT(((PongPaddleSpec*)this->entitySpec)->force.y, __I_TO_FIX10_6(direction.y)),
		0
	};

	PongPaddle::applyForce(this, &force, true);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

