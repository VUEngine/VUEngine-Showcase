/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef POST_PROCESSING_EFFECTS_STATE_H_
#define POST_PROCESSING_EFFECTS_STATE_H_


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <ShowcaseState.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

///
/// Class PostProcessingEffectsState
///
/// Inherits from ShowcaseState
///
/// Implements a game state to showcase post processing effects.
dynamic_singleton class PostProcessingEffectsState : ShowcaseState
{
	/// Index of the post processing effect to show
	int8 selectedPostProcessingEffect;

	/// Method to retrieve the singleton instance
	/// @return PostProcessingEffectsState singleton
	static PostProcessingEffectsState getInstance();

	/// Prepares the object to exit this state.
	/// @param owner: Object that is exiting this state
	override void exit(void* owner);

	/// Process the provided user input.
	/// @param userInput: Struct with the current user input information
	override void processUserInput(const UserInput* userInput);

	/// Show the state's controls.
	override void showControls();

	/// Show the state's revelant stuff.
	override void showStuff();

	/// Show the state's explanation.
	override void showExplanation();
}


#endif
