/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_STATE_H_
#define PONG_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class PongState : ShowcaseState
{
	bool isVersusMode;

	static PongState getInstance();

	void setVersusMode(bool value);
	bool getVersusMode();
	void remoteWentAway();

	override bool isVersusMode();
	override void enter(void* owner);
	override void exit(void* owner);
	override void processUserInput(const UserInput* userInput);
	override bool processUserInputRegardlessOfInput();
	override void showControls();
	override void showStuff();
	override void showExplanation();
	override void showAdditionalDetails();
}



#endif
