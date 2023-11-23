/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef SHOWCASE_STATE_H_
#define SHOWCASE_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <GameState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

class ShowcaseState;

typedef ShowcaseState(*ShowcaseStateGetInstance)();

abstract class ShowcaseState : GameState
{
	StageSpec* stageSpec;

	static ShowcaseStateGetInstance getFirstShowcase();

	void constructor();

	virtual void printHeader();
	virtual void showStuff();
	
	override void enter(void* owner);
	override void suspend(void* owner);
	override void resume(void* owner);
	override void processUserInput(const UserInput* userInput);
}


#endif
