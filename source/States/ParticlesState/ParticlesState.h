/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PARTICLES_STATE_H_
#define PARTICLES_STATE_H_


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <ShowcaseState.h>
#include <ParticleSystem.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

///
/// Class ParticlesState
///
/// Inherits from ShowcaseState
///
/// Implements a game state to showcase particle systems.
dynamic_singleton class ParticlesState : ShowcaseState
{
	/// State's particle system
	ParticleSystem particleSystem;

	/// Index of the particle type to showcase
	uint32 particlesType;

	/// Method to retrieve the singleton instance
	/// @return AnimationSchemesState singleton
	static ParticlesState getInstance();

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
