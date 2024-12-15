/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef COG_WHEEL_H_
#define COG_WHEEL_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Entity.h>


//=========================================================================================================
// CLASS' DATA
//=========================================================================================================

/// A CogWheel Spec
typedef struct CogWheelSpec
{
	EntitySpec entitySpec;

} CogWheelSpec;

/// A PongBall spec that is stored in ROM
typedef const CogWheelSpec CogWheelROMSpec;


//=========================================================================================================
// CLASS' DECLARATION
//=========================================================================================================

///
/// Class CogWheel
///
/// Inherits from Entity
///
/// Implements a simple rotating entity.
class CogWheel : Entity
{
	/// @param cogWheelSpec: Specification that determines how to configure the paddle
	/// @param internalId: ID to keep track internally of the new instance
	/// @param name: Name to assign to the new instance
	void constructor(CogWheelSpec* cogWheelSpec, int16 internalId, const char* const name);

	/// Update this instance's logic.
	override void update();
}


#endif
