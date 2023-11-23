/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef SPRITES_SCREEN_STATE_H_
#define SPRITES_SCREEN_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>
#include <Sprite.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class SpritesState : ShowcaseState
{
	Sprite sprite;
	uint32 spriteType;
	bool showSpriteDetails;

	static SpritesState getInstance();

	void constructor();

	override void execute(void* owner);
	override void processUserInput(const UserInput* userInput);
	override void printHeader();
	override void showStuff();
}


#endif
