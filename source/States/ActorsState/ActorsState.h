/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef ACTORS_STATE_H_
#define ACTORS_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <ShowcaseState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class ActorsState
///
/// Inherits from ShowcaseState
///
/// Implements a game state to showcase how actor parenting works.
dynamic_singleton class ActorsState : ShowcaseState
{
	/// Main actor
	Actor leaderPunk;
	

	/// Updates the object in this state.
	/// @param owner: Object that is in this state
	override void execute(void* owner);

	/// Process the provided user input.
	/// @param userInput: Struct with the current user input information
	override void processUserInput(const UserInput* userInput);

	/// Show the state's controls.
	override void showControls();

	/// Show the state's revelant stuff.
	override void showStuff();

	/// Show the state's explanation.
	override void showExplanation();

	/// Show the state's additional details.
	override void showAdditionalDetails();
}

#endif
