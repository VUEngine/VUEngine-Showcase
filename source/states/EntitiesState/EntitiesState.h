/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef ENTITIES_STATE_H_
#define ENTITIES_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class EntitiesState : ShowcaseState
{
	static EntitiesState getInstance();

	void constructor();

	override void enter(void* owner);
	override void execute(void* owner);
	override void processUserInput(const UserInput* userInput);
	override void showDetails();
}


#endif