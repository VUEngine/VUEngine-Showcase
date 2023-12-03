/*
 * Capitán Sevilla 3D, an adventure platforming game demo for Nintendo Virtual Boy
 *
 * (c) Christian Radke, Jorge Eremiev and Rubén Garcerá Soto
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef COG_WHEEL_H_
#define COG_WHEEL_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Entity.h>


//---------------------------------------------------------------------------------------------------------
//											SPEC DEFINITION
//---------------------------------------------------------------------------------------------------------

typedef struct CogWheelSpec
{
	/// Entity spec
	EntitySpec entitySpec;

} CogWheelSpec;

typedef const CogWheelSpec CogWheelROMSpec;

//---------------------------------------------------------------------------------------------------------
//										PUBLIC INTERFACE
//---------------------------------------------------------------------------------------------------------

class CogWheel : Entity
{
	void constructor(CogWheelSpec* cogWheelSpec, int16 internalId, const char* const name);

	override void update();
}


#endif
