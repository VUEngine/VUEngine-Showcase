/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PUNK_FROZEN_H_
#define PUNK_FROZEN_H_


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <State.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

///
/// Class PunkWalking
///
/// Inherits from State
///
/// Controls the logic for the Punk when it doesn't move.
singleton class PunkFrozen : State
{
	/// Method to retrieve the singleton instance
	/// @return PunkFrozen singleton
	static PunkFrozen getInstance();

	/// Class' constructor
	void constructor();

	/// Prepares the object to enter this state.
	/// @param owner: Object that is entering in this state
	override void enter(void* owner);

	/// Process a Telegram sent to an object that is in this state.
	/// @param owner: Object that is in this state
	/// @param telegram: Telegram to process
	override bool processMessage(void* owner, Telegram telegram);
}

#endif
