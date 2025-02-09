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

#include <I18n.h>
#include <Languages.h>
#include <PostProcessingDwarfPlanet.h>
#include <PostProcessingRain.h>
#include <PostProcessingTilt.h>
#include <PostProcessingWobble.h>
#include <Printer.h>
#include <Singleton.h>
#include <VUEngine.h>

#include "PostProcessingEffectsState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' ATTRIBUTES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * The effects are implemented as plugins. Check source/pluginsConfigh.h for configuration of each effect.
 */
static const PostProcessingEffect _postProcessingEffect[] =
{
	PostProcessingWobble::wobble,
	PostProcessingTilt::tiltScreen,
	PostProcessingDwarfPlanet::dwarfPlanet,
	PostProcessingRain::thinRain,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::exit(void* owner __attribute__((unused)))
{
	VIPManager::removePostProcessingEffect(_postProcessingEffect[this->selectedPostProcessingEffect], NULL);
	
	Base::exit(this, owner);	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::processUserInput(const UserInput* userInput)
{
	if(0 == (K_SEL & userInput->releasedKey))
	{
		PostProcessingEffectsState::playSoundEffects(this, userInput);
	}

	if(K_LL & userInput->releasedKey)
	{
		VIPManager::removePostProcessingEffect(_postProcessingEffect[this->selectedPostProcessingEffect], NULL);

		if(0 > --this->selectedPostProcessingEffect)
		{
			this->selectedPostProcessingEffect = sizeof(_postProcessingEffect) / sizeof(PostProcessingEffect) - 1;
		}

		PostProcessingEffectsState::show(this, true);
	}
	else if(K_LR & userInput->releasedKey)
	{
		VIPManager::removePostProcessingEffect(_postProcessingEffect[this->selectedPostProcessingEffect], NULL);

		if((signed)(sizeof(_postProcessingEffect) / sizeof(PostProcessingEffect) - 1) < ++this->selectedPostProcessingEffect)
		{
			this->selectedPostProcessingEffect = 0;
		}

		PostProcessingEffectsState::show(this, true);
	}
	else if(K_SEL & userInput->releasedKey)
	{
		return;
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::showControls()
{
	Printer::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 2, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printer::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::showStuff()
{
	VIPManager::pushBackPostProcessingEffect(_postProcessingEffect[this->selectedPostProcessingEffect], NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::showExplanation()
{
	int16 y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printer::text(I18n::getText(I18n::getInstance(), kStringFrameBuffersLabel), 2, y++, NULL);
	Printer::text(I18n::getText(I18n::getInstance(), kStringPostProcessingEffectsLabel), 2, y++, NULL);
	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "DefaultBold");
	Printer::text("PostProcessingEffectsState", 2, y++, NULL);
	Printer::text("::processUserInput", 2, y++, NULL);
	
	y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 32, y++, "DefaultBold");
	Printer::text("VUEngine", 32, y++, NULL);
	y++;

	Printer::text(I18n::getText(I18n::getInstance(), kStringEffectSubtitle), 32, y++, "DefaultBold");
	Printer::text("            ", 32, y, NULL);

	if(PostProcessingWobble::wobble == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printer::text(I18n::getText(I18n::getInstance(), kStringWobbleLabel), 32, y, NULL);
	}
	else if(PostProcessingTilt::tiltScreen == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printer::text(I18n::getText(I18n::getInstance(), kStringTiltELabel), 32, y, NULL);
	}
	else if(PostProcessingDwarfPlanet::dwarfPlanet == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printer::text(I18n::getText(I18n::getInstance(), kStringDwarfPlanetLabel), 32, y, NULL);
	}
	else if(PostProcessingRain::thinRain == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printer::text(I18n::getText(I18n::getInstance(), kStringRainLabel), 32, y, NULL);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	// Check assets/stage/PostProcessingEffectsStageSpec.c
	extern StageROMSpec PostProcessingEffectsStageSpec;
	this->stageSpec = (StageSpec*)&PostProcessingEffectsStageSpec;
	this->selectedPostProcessingEffect = 0;
	this->validSuboptionKeys = K_LL | K_LR;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PostProcessingEffectsState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
