/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef WIREFRAMES_STATE_H_
#define WIREFRAMES_STATE_H_


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <ShowcaseState.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

///
/// Class WireframesState
///
/// Inherits from ShowcaseState
///
/// Implements a game state to showcase how wireframes work.
dynamic_singleton class WireframesState : ShowcaseState
{
	/// Method to retrieve the singleton instance
	/// @return AnimationSchemesState singleton
	static WireframesState getInstance();

	/// Prepares the object to enter this state.
	/// @param owner: Object that is entering in this state
	override void enter(void* owner);

	/// Updates the object in this state.
	/// @param owner: Object that is in this state
	override void execute(void* owner);

	/// Process the provided user input.
	/// @param userInput: Struct with the current user input information
	override void processUserInput(const UserInput* userInput);

	/// Show the state's controls.
	override void showControls();

	/// Show the state's explanation.
	override void showExplanation();

	/// Show the state's additional details.
	override void showAdditionalDetails();
}


#endif
