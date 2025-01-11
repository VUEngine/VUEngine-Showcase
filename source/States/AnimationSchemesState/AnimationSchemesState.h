/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef ANIMATION_SCHEMES_STATE_H_
#define ANIMATION_SCHEMES_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <ShowcaseState.h>
#include <Sprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class AnimationSchemesState
///
/// Inherits from ShowcaseState
///
/// Implements a game state to showcase how animations work.
dynamic_singleton class AnimationSchemesState : ShowcaseState
{
	/// Rotation to apply to the animated sprites
	Rotation spriteRotation;

	/// Linked list of animated sprites
	VirtualList animatedSprites;

	/// Type of animation scheme to showcase
	uint32 animationScheme;

	/// Method to retrieve the singleton instance
	/// @return AnimationSchemesState singleton
	static AnimationSchemesState getInstance(ClassPointer requesterClass);

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

	/// Show the CHAR memory's state.
	virtual void showCharMemory();
}

#endif
