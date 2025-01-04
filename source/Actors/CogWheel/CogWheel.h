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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// A CogWheel Spec
/// @memberof CogWheel
typedef struct CogWheelSpec
{
	/// Actor spec
	ActorSpec actorSpec;

} CogWheelSpec;

/// A PongBall spec that is stored in ROM
/// @memberof CogWheel
typedef const CogWheelSpec CogWheelROMSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class CogWheel
///
/// Inherits from Actor
///
/// Implements a simple rotating actor.
class CogWheel : Actor
{
	/// @param cogWheelSpec: Specification that determines how to configure the paddle
	/// @param internalId: ID to keep track internally of the new instance
	/// @param name: Name to assign to the new instance
	void constructor(CogWheelSpec* cogWheelSpec, int16 internalId, const char* const name);

	/// Update this instance's logic.
	override void update();
}

#endif
