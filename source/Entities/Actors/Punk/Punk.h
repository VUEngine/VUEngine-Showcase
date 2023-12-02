/*
 * Capitán Sevilla 3D, an adventure platforming game demo for Nintendo Virtual Boy
 *
 * (c) Christian Radke, Jorge Eremiev and Rubén Garcerá Soto
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
	/// Actor spec
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

	override void ready(bool recursive);
	override bool handlePropagatedMessage(int32 message);
	override bool enterCollision(const CollisionInformation* collisionInformation);
}


#endif
