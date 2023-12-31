/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef WIREFRAMES_STATE_H_
#define WIREFRAMES_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class WireframesState : ShowcaseState
{
	static WireframesState getInstance();

	void constructor();

	override void enter(void* owner);
	override void execute(void* owner);
	override void processUserInput(const UserInput* userInput);
	override void showControls();
	override void showExplanation();
	override void showAdditionalDetails();
}


#endif
