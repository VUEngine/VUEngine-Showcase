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

#include <SoundWrapper.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S MISC
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

class ShowcaseState;

typedef ShowcaseState(*ShowcaseStateGetInstance)();

abstract class ShowcaseState : GameState
{
	StageSpec* stageSpec;
	Sound* playingSoundEffect;
	bool showAdditionalDetails;
	uint16 validSuboptionKeys;
	int8 selectedPostProcessingEffect;

	static ShowcaseStateGetInstance getFirstShowcase();

	void constructor();
	void setupBrightness(bool dimm);
	void show(bool reloadStuff);
	void playSoundEffects(const UserInput* userInput, bool lock);

	virtual void showHeader();
	virtual void showControls();
	virtual void showStuff();
	virtual void showExplanation();
	virtual void showAdditionalDetails();
	
	override void enter(void* owner);
	override void exit(void* owner);
	override void suspend(void* owner);
	override void resume(void* owner);
	override void processUserInput(const UserInput* userInput);
}


#endif
