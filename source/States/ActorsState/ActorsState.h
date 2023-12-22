/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef ACTORS_STATE_H_
#define ACTORS_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S MESSAGES
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class ActorsState : ShowcaseState
{
	static ActorsState getInstance();

	void constructor();

	override void enter(void* owner);
	override void execute(void* owner);
	override void exit(void* owner);
	override void processUserInput(const UserInput* userInput);
	override void showControls();
	override void showStuff();
	override void showExplanation();
	override void showAdditionalDetails();
}


#endif
