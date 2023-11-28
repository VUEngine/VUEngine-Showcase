/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef ANIMATION_SCHEMES_SCREEN_STATE_H_
#define ANIMATION_SCHEMES_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>
#include <Sprite.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class AnimationSchemesState : ShowcaseState
{
	Rotation rotation;
	VirtualList animatedSprites;
	uint32 animationScheme;

	static AnimationSchemesState getInstance();

	void constructor();
	void setupBrightness(bool dimm);

	override void processUserInput(const UserInput* userInput);
	override void printHeader();
	override void showStuff();
	override void showDetails();
}


#endif
