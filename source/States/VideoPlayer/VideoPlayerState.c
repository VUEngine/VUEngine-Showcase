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

#include <Actor.h>
#include <DebugConfig.h>
#include <I18n.h>
#include <Languages.h>
#include <Printer.h>
#include <Singleton.h>

#include "VideoPlayerState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::processUserInput(const UserInput* userInput)
{
	VideoPlayerState::playSoundEffects(this, userInput, false);

	Actor videoActor = Actor::safeCast(VideoPlayerState::getActorByName(this, "Video"));

	if(!isDeleted(videoActor))
	{
		if(K_A & userInput->releasedKey)
		{
			Actor::pauseAnimation(videoActor, Actor::isPlaying(videoActor));
		}
		else if((K_LL | K_LR) & userInput->releasedKey)
		{
			if(Actor::isPlayingAnimation(videoActor, "FrameBlend"))
			{					
				Actor::playAnimation(videoActor, "4Color");
			}
			else
			{					
				Actor::playAnimation(videoActor, "FrameBlend");
			}

			VideoPlayerState::show(this, false);
		}
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::showControls()
{
	Printer::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printer::text(__CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

	Printer::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printer::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::showExplanation()
{
	int16 y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printer::text(I18n::getText(I18n::getInstance(), kStringAnimationsLabel), 2, y++, NULL);
	Printer::text(I18n::getText(I18n::getInstance(), kStringFrameBlendingLabel), 2, y++, NULL);

	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printer::text("Actor", 2, y++, NULL);
	Printer::text("Sprite", 2, y++, NULL);

	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "DefaultBold");
	Printer::text("VideoActorSpec", 2, y++, NULL);

	y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printer::text(I18n::getText(I18n::getInstance(), kStringOptimizedCharSetsLabel), 26, y++, NULL);
	Printer::text(I18n::getText(I18n::getInstance(), kStringOptimizedBgmapsLabel), 26, y++, NULL);

	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "DefaultBold");
	Printer::text("VideoPlayerState", 26, y++, NULL);
	Printer::text("::processUserInput", 26, y++, NULL);

	VideoPlayerState::showAdditionalDetails(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void VideoPlayerState::showAdditionalDetails()
{
	int16 y = 25;
	Printer::text(I18n::getText(I18n::getInstance(), kStringAnimationSubtitle), 2, y++, "DefaultBold");

	Actor videoActor = Actor::safeCast(VideoPlayerState::getActorByName(this, "Video"));

	if(!isDeleted(videoActor))
	{
		Printer::text(Actor::getPlayingAnimationName(videoActor), 2, y++, NULL);
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
