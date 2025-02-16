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

#include <Body.h>
#include <InGameTypes.h>
#include <Messages.h>
#include <Optics.h>
#include <VUEngine.h>

#include "PongPaddle.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' MACROS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define HORIZONTAL_FORCE 80
#define VERTICAL_FORCE	 80

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongPaddle::constructor(const PongPaddleSpec* pongPaddleSpec, int16 internalId, const char* const name)
{
	// Always explicitly call the base's constructor
	Base::constructor((ActorSpec*)&pongPaddleSpec->actorSpec, internalId, name);

	this->type = kPaddleNone;
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
		{
			PongPaddle::stopMovement(this, __ALL_AXIS);
			Vector3D localPosition = this->localTransformation.position;
			localPosition.y = 0;
			PongPaddle::setLocalPosition(this, &localPosition);
			break;
		}

		case kMessageShowcaseStateHoldUp:
		{
			if(kPaddleLocal == this->type)
			{
				PongPaddle::move(this, __UP);
				return true;
			}

			break;
		}

		case kMessageShowcaseStateHoldDown:
		{
			if(kPaddleLocal == this->type)
			{
				PongPaddle::move(this, __DOWN);
				return true;
			}

			break;
		}

		case kMessageShowcaseStateRemoteHoldUp:
		{
			if(kPaddleRemote == this->type)
			{
				PongPaddle::move(this, __UP);
				return true;
			}

			break;
		}

		case kMessageShowcaseStateRemoteHoldDown:
		{
			if(kPaddleRemote == this->type)
			{
				PongPaddle::move(this, __DOWN);
				return true;
			}

			break;
		}
	}

	/* Returning false allows any other actor interested in the message to process it,
	 * returning true will make that the propagation stops here
	 */

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongPaddle::setType(uint32 type)
{
	this->type = type;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongPaddle::move(int32 direction)
{
	if(!isDeleted(this->body))
	{
		fixed_t forceMagnitude = __FIXED_MULT(Body::getMass(this->body), Body::getMaximumSpeed(this->body));

		Vector3D force = {0, forceMagnitude * direction, 0};

		PongPaddle::applyForce(this, &force, true);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
