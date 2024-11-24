/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PUNK_DIE_H_
#define PUNK_DIE_H_


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <State.h>


//=========================================================================================================
// CLASS' DECLARATION
//=========================================================================================================

///
/// Class PunkDie
///
/// Inherits from State
///
/// Controls the logic for the Punk when it dies.
singleton class PunkDie : State
{
	/// Method to retrieve the singleton instance
	/// @return PunkDie singleton
	static PunkDie getInstance();

	/// Class' constructor
	void constructor();

	/// Prepares the object to enter this state.
	/// @param owner: Object that is entering in this state
	override void enter(void* owner);

	/// Prepares the object to exit this state.
	/// @param owner: Object that is exiting this state
	override void exit(void* owner);
}


#endif
