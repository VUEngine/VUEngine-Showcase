/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PUNK_H_
#define PUNK_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Actor.h>


//---------------------------------------------------------------------------------------------------------
//											SPEC DEFINITION
//---------------------------------------------------------------------------------------------------------

typedef struct PunkSpec
{
	// Actor spec
	ActorSpec actorSpec;

} PunkSpec;

typedef const PunkSpec PunkROMSpec;

//---------------------------------------------------------------------------------------------------------
//										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

class Punk : Actor
{
	void constructor(PunkSpec* punkSpec, int16 internalId, const char* const name);

	void freeze();
	void walk();
	bool onDieAnimationComplete(ListenerObject eventFirer);

	override void ready(bool recursive);
	override bool handleMessage(Telegram telegram);
	override bool handlePropagatedMessage(int32 message);
	override bool enterCollision(const CollisionInformation* collisionInformation);
}


#endif
