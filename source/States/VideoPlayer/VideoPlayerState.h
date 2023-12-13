/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef VIDEO_PLAYER_STATE_H_
#define VIDEO_PLAYER_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

dynamic_singleton class VideoPlayerState : ShowcaseState
{
	static VideoPlayerState getInstance();

	void constructor();

	override void enter(void* owner);
	override void processUserInput(const UserInput* userInput);
	override void showControls();
	override void showExplanation();
	override void showAdditionalDetails();
}


#endif
