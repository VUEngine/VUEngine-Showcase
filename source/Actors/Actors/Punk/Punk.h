/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PUNK_H_
#define PUNK_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// A Punk Spec
/// @memberof Punk
typedef struct PunkSpec
{
	/// Actor spec
	ActorSpec actorSpec;

} PunkSpec;

/// A Punk spec that is stored in ROM
/// @memberof Punk
typedef const PunkSpec PunkROMSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class Punk
///
/// Inherits from Actor
///
/// Implements a controllable actor.
class Punk : Actor
{
	/// @param punkSpec: Specification that determines how to configure the paddle
	/// @param internalId: ID to keep track internally of the new instance
	/// @param name: Name to assign to the new instance
	void constructor(const PunkSpec* punkSpec, int16 internalId, const char* const name);

	/// Process an event that the instance is listen for.
	/// @param eventFirer: ListenerObject that signals the event
	/// @param eventCode: Code of the firing event
	/// @return False if the listener has to be removed; true to keep it
	override bool onEvent(ListenerObject eventFirer __attribute__((unused)), uint32 eventCode);

	/// Default interger message handler for propagateMessage
	/// @param message: Propagated integer message
	/// @return True if the propagation must stop; false if the propagation must reach other containers
	override bool handlePropagatedMessage(int32 message);

	/// Make the animated actor ready to starts operating once it has been completely intialized.
	/// @param recursive: If true, the ready call is propagated to its children, grand children, etc.
	override void ready(bool recursive);

	/// Freeze the punk.
	void freeze();

	/// Make the punk walk.
	void walk();

	/// Make the punk stop.
	void stop();

	/// Make the punk to die.
	void die();

	/// Resucitate the punk.
	void resuscitate();

	/// Callback for die animation when completed.
	/// @param eventFirer: Animation controller
	bool onDieAnimationComplete(ListenerObject eventFirer);
}

#endif
