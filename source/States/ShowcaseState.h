/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef SHOWCASE_STATE_H_
#define SHOWCASE_STATE_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Printing.h>
#include <Sound.h>

#include <GameState.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// FORWARD DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

class ShowcaseState;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

typedef ShowcaseState(*ShowcaseStateGetInstance)();

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class ShowcaseState
///
/// Inherits from GameState
///
/// Implements the base class for game states that showcase some engine's capabilities.
abstract class ShowcaseState : GameState
{
	/// Pointer to the spec that defines how to initialize the stage 
	StageSpec* stageSpec;

	/// Pointer to the printing manager to reduce the calls to ::getInstance
	Printing printing;

	/// Sound spec for the playing sound
	SoundSpec* playingSoundEffect;

	/// Flag to enable/prevent the printing of additional details
	bool showAdditionalDetails;

	/// Flag to ignore some user inputs depending on the specific showcase
	uint16 validSuboptionKeys;

	/// Method to retrieve the singleton instance of the first show case state
	/// @return ShowcaseState singleton
	static ShowcaseStateGetInstance getFirstShowcase();

	/// Class' constructor
	void constructor();

	/// Prepares the object to enter this state.
	/// @param owner: Object that is entering in this state
	override void enter(void* owner);

	/// Prepares the object to exit this state.
	/// @param owner: Object that is exiting this state
	override void exit(void* owner);

	/// Prepares the object to become inactive in this state.
	/// @param owner: Object that is in this state
	override void suspend(void* owner);

	/// Prepares the object to become active in this state.
	/// @param owner: Object that is in this state
	override void resume(void* owner);

	/// Process the provided user input.
	/// @param userInput: Struct with the current user input information
	override void processUserInput(const UserInput* userInput);

	/// Play the user input related sound effects.
	/// @param userInput: Struct with the current user input information
	/// @param lock: If true, the program halts until the playback is completed
	void playSoundEffects(const UserInput* userInput, bool lock);

	/// Configure the color palettes.
	/// @param dimm: If true, the brightness is dimmed
	void configurePalettes(bool dimm);

	/// Make visible all the relevant actors and information.
	/// @param reloadStuff: If true, ::showStuff is called
	void show(bool reloadStuff);

	/// Show the state's header.
	virtual void showHeader();

	/// Show the state's controls.
	virtual void showControls();

	/// Show the state's revelant stuff.
	virtual void showStuff();

	/// Show the state's explanation.
	virtual void showExplanation();

	/// Show the state's additional details.
	virtual void showAdditionalDetails();	
}

#endif
