/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PARTICLES_STATE_H_
#define PARTICLES_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>
#include <ParticleSystem.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class ParticlesState : ShowcaseState
{
	ParticleSystem particleSystem;
	uint32 particlesType;

	static ParticlesState getInstance();

	void constructor();
	void setupBrightness(bool dimm);

	override void execute(void* owner);
	override void processUserInput(const UserInput* userInput);
	override void showControls();
	override void showStuff();
	override void showExplanation();
	override void showAdditionalDetails();
}


#endif
