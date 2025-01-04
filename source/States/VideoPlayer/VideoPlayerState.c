/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <string.h>

#include <AnimatedEntity.h>
#include <DebugConfig.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>

#include "VideoPlayerState.h"


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::processUserInput(const UserInput* userInput)
{
	VideoPlayerState::playSoundEffects(this, userInput, false);

	AnimatedEntity videoEntity = AnimatedEntity::safeCast(VideoPlayerState::getEntityByName(this, "Video"));

	if(!isDeleted(videoEntity))
	{
		if(K_A & userInput->releasedKey)
		{
			AnimatedEntity::pauseAnimation(videoEntity, AnimatedEntity::isPlaying(videoEntity));
		}
		else if((K_LL | K_LR) & userInput->releasedKey)
		{
			if(AnimatedEntity::isPlayingAnimation(videoEntity, "HiColor"))
			{					
				AnimatedEntity::playAnimation(videoEntity, "4Color");
			}
			else
			{					
				AnimatedEntity::playAnimation(videoEntity, "HiColor");
			}

			VideoPlayerState::show(this, false);
		}
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::showControls()
{
	Printing::text(this->printing, __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

	Printing::text(this->printing, __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::showExplanation()
{
	int16 y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringAnimationsLabel), 2, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringHiColorLabel), 2, y++, NULL);

	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printing::text(this->printing, "AnimatedEntity", 2, y++, NULL);
	Printing::text(this->printing, "Sprite", 2, y++, NULL);

	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "DefaultBold");
	Printing::text(this->printing, "VideoEntitySpec", 2, y++, NULL);

	y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOptimizedCharSetsLabel), 26, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOptimizedBgmapsLabel), 26, y++, NULL);

	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "DefaultBold");
	Printing::text(this->printing, "VideoPlayerState", 26, y++, NULL);
	Printing::text(this->printing, "::processUserInput", 26, y++, NULL);

	VideoPlayerState::showAdditionalDetails(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::showAdditionalDetails()
{
	int16 y = 25;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringAnimationSubtitle), 2, y++, "DefaultBold");

	AnimatedEntity videoEntity = AnimatedEntity::safeCast(VideoPlayerState::getEntityByName(this, "Video"));

	if(!isDeleted(videoEntity))
	{
		Printing::text(this->printing, AnimatedEntity::getPlayingAnimationName(videoEntity), 2, y++, NULL);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/VideoPlayerStageSpec.c
	 */
	extern StageROMSpec VideoPlayerStageSpec;
	this->stageSpec = (StageSpec*)&VideoPlayerStageSpec;
	this->validSuboptionKeys = K_LL | K_LR;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

