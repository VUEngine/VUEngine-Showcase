/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <VideoPlayerState.h>

#include <AnimatedEntity.h>
#include <Printing.h>

#include <debugConfig.h>
#include <string.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

/*
 * Check assets/stage/VideoPlayerStageSpec.c
 */
extern StageROMSpec VideoPlayerStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void VideoPlayerState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&VideoPlayerStage;
}

// class's destructor
void VideoPlayerState::destructor()
{
	// destroy base
	Base::destructor();
}

void VideoPlayerState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);

	AnimatedEntity videoEntity = AnimatedEntity::safeCast(VideoPlayerState::getEntityByName(this, "Video"));

	AnimatedEntity::pauseAnimation(videoEntity, true);
}

void VideoPlayerState::processUserInput(const UserInput* userInput)
{
	AnimatedEntity videoEntity = AnimatedEntity::safeCast(VideoPlayerState::getEntityByName(this, "Video"));

	if(!isDeleted(videoEntity))
	{
		if(!(K_PWR & userInput->releasedKey))
		{
			if(K_A & userInput->releasedKey)
			{
				AnimatedEntity::pauseAnimation(videoEntity, AnimatedEntity::isPlayingAnimation(videoEntity));
			}
			else if((K_LL | K_LR) & userInput->releasedKey)
			{
				if(AnimatedEntity::isAnimationLoaded(videoEntity, "HiColor"))
				{					
					AnimatedEntity::playAnimation(videoEntity, "4Color");
				}
				else
				{					
					AnimatedEntity::playAnimation(videoEntity, "HiColor");
				}

				AnimatedEntity::pauseAnimation(videoEntity, true);

				VideoPlayerState::show(this, false);
			}
		}
	}

	return Base::processUserInput(this, userInput);
}

void VideoPlayerState::showControls()
{
	Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

void VideoPlayerState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), "CONCEPTS", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Animations", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "HiColor", 2, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), "CLASSES", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "AnimatedEntity", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Sprite", 2, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), "SPECS", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "VideoEntity", 2, y++, NULL);

	y = 3;
	Printing::text(Printing::getInstance(), "OTHER CONCEPTS", 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "Optimized charsets", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "Optimized textures", 26, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), "METHODS", 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "VideoPlayerState", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " processUserInput", 26, y++, NULL);

	VideoPlayerState::showAnimationDetails(this);
}

void VideoPlayerState::showAnimationDetails()
{
	int16 y = 26;
	Printing::text(Printing::getInstance(), "Animation", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "Name: ", 1, y, NULL);

	AnimatedEntity videoEntity = AnimatedEntity::safeCast(VideoPlayerState::getEntityByName(this, "Video"));

	if(!isDeleted(videoEntity))
	{
		Printing::text(Printing::getInstance(), AnimatedEntity::getPlayingAnimationName(videoEntity), 1 + 5, y++, NULL);
	}
}

void VideoPlayerState::showAdditionalDetails()
{
	VideoPlayerState::showAnimationDetails(this);
}