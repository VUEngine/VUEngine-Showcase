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

#include <PongPaddle.h>

#include <Box.h>
#include <GameConfig.h>
#include <Optics.h>
#include <VUEngine.h>


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
	this->mustBounce = false;
}

void PongPaddle::destructor()
{
	// delete the super object
	// must always be called at the end of the destructor
	Base::destructor();
}

void PongPaddle::ready(bool recursive)
{
	// call base
	Base::ready(this, recursive);

	// optimization
	Body::sendMessages(this->body, false);
}

bool PongPaddle::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kPongMessageResetPositions:
			{
				PongPaddle::stopAllMovement(this);
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

	PongPaddle::applyForce(this, &force, false);
}

bool PongPaddle::mustBounce()
{
	return this->mustBounce;
}

bool PongPaddle::enterCollision(const CollisionInformation* collisionInformation)
{
	ASSERT(collisionInformation->collidingShape, "Hero::enterCollision: null collidingObjects");

	Shape collidingShape = collisionInformation->collidingShape;
	SpatialObject collidingObject = Shape::getOwner(collidingShape);

	switch(SpatialObject::getInGameType(collidingObject))
	{
		case kTypePongWall:

			Base::enterCollision(this, collisionInformation);
			PongPaddle::stopAllMovement(this);
			return true;
			break;
	}

	return Base::enterCollision(this, collisionInformation);
}

void PongPaddle::exitCollision(Shape shape  __attribute__ ((unused)), Shape shapeNotCollidingAnymore, bool isShapeImpenetrable)
{
	if(!this->body)
	{
		return;
	}

	Body::setSurroundingFrictionCoefficient(this->body,  PongPaddle::getSurroundingFrictionCoefficient(this));

	SpatialObject collidingObject = Shape::getOwner(shapeNotCollidingAnymore);

	if(kTypePongWall != SpatialObject::getInGameType(collidingObject))
	{
		if(isShapeImpenetrable)
		{
			Body::clearNormal(this->body, ListenerObject::safeCast(shapeNotCollidingAnymore));
		}
	}
}

bool PongPaddle::isSubjectToGravity(Vector3D gravity __attribute__((unused)))
{
	return false;
}
