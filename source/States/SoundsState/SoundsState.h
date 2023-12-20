/**
 * VUEngine Core
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


#ifndef SOUNDS_STATE_H_
#define SOUNDS_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>

#include <Sound.h>


//---------------------------------------------------------------------------------------------------------
//											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class SoundsState : ShowcaseState
{
	Sound sound;
	uint16 selectedSound;
	
	static SoundsState getInstance();

	override void enter(void* owner);
	override void execute(void* owner);
	override void exit(void* owner);
	override void processUserInput(const UserInput*  userInput);
	override bool stream();
	override void showControls();
	override void showStuff();
	override void showExplanation();
	override void showAdditionalDetails();
}

#endif
