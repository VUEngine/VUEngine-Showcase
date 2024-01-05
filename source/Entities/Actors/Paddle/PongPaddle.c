/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Box.h>
#include <InGameTypes.h>
#include <Messages.h>
#include <Optics.h>
#include <Pong.h>
#include <VUEngine.h>

#include "PongPaddle.h"


//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define HORIZONTAL_FORCE		80
#define VERTICAL_FORCE			80


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void PongPaddle::constructor(PongPaddleSpec* pongPaddleSpec, int16 internalId, const char* const name)
{
	// construct base
	Base::constructor((ActorSpec*)&pongPaddleSpec->actorSpec, internalId, name);

	// save spec
	this->pongPaddleSpec = pongPaddleSpec;
}

void PongPaddle::destructor()
{
	// delete the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

bool PongPaddle::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kMessagePongResetPositions:

			if(!Pong::isVersusMode(Pong::getInstance()))
			{
				PongPaddle::stopMovement(this, __ALL_AXIS);
				Vector3D localPosition = this->transformation.localPosition;
				localPosition.y = 0;
				PongPaddle::setLocalPosition(this, &localPosition);
			}

			break;
	}

	return false;
}

void PongPaddle::moveTowards(NormalizedDirection direction)
{
	Vector3D force =
	{
		__FIX10_6_MULT(this->pongPaddleSpec->force.x, __I_TO_FIX10_6(direction.x)),
		__FIX10_6_MULT(this->pongPaddleSpec->force.y, __I_TO_FIX10_6(direction.y)),
		0
	};

	PongPaddle::applyForce(this, &force, true);
}

bool PongPaddle::mustBounce()
{
	return false;
}
