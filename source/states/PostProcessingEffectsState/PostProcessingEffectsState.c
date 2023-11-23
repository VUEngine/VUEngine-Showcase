/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <PostProcessingEffectsState.h>

#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <PostProcessingDwarfPlanet.h>
#include <PostProcessingRain.h>
#include <PostProcessingTilt.h>
#include <PostProcessingWobble.h>
#include <Printing.h>
#include <VIPManager.h>

#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec PostProcessingEffectsStage;

//---------------------------------------------------------------------------------------------------------
// 											CLASS'S ATTRIBUTES
//---------------------------------------------------------------------------------------------------------

/*
 * The effects are implemented as plugins.
 * Check source/pluginsConfigh.h for configuration of each effect.
 */
static const PostProcessingEffect _postProcessingEffect[] =
{
	PostProcessingWobble::wobble,
	PostProcessingTilt::tiltScreen,
	PostProcessingDwarfPlanet::dwarfPlanet,
	PostProcessingRain::waterFall,
};

//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void PostProcessingEffectsState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&PostProcessingEffectsStage;
	this->selectedPostProcessingEffect = 0;
}

// class's destructor
void PostProcessingEffectsState::destructor()
{
	// destroy base
	Base::destructor();
}

void PostProcessingEffectsState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(!(K_PWR & userInput->releasedKey))
	{
		if(K_LL & userInput->releasedKey)
		{
			VIPManager::removePostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);

			if(0 > --this->selectedPostProcessingEffect)
			{
				this->selectedPostProcessingEffect = sizeof(_postProcessingEffect) / sizeof(PostProcessingEffect) - 1;
			}

			VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);
			PostProcessingEffectsState::printHeader(this);
			PostProcessingEffectsState::printMessage(this);
		}
		else if(K_LR & userInput->releasedKey)
		{
			VIPManager::removePostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);

			if((signed)(sizeof(_postProcessingEffect) / sizeof(PostProcessingEffect) - 1) < ++this->selectedPostProcessingEffect)
			{
				this->selectedPostProcessingEffect = 0;
			}

			VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);
			PostProcessingEffectsState::printHeader(this);
			PostProcessingEffectsState::printMessage(this);
		}
	}

	Base::processUserInput(this, userInput);
}

void PostProcessingEffectsState::showStuff()
{
	PostProcessingEffectsState::printMessage(this);

	// add wobble effect
	VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);
	
}

void PostProcessingEffectsState::printHeader()
{
	Base::printHeader(this);

	int16 y = 3;

	if(PostProcessingWobble::wobble == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Effect: Wobble      ", 1, y, NULL);
	}
	else if(PostProcessingTilt::tiltScreen == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Effect: Tilt        ", 1, y, NULL);
	}
	else if(PostProcessingDwarfPlanet::dwarfPlanet == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Effect: Dwarf planet ", 1, y, NULL);
	}
	else if(PostProcessingRain::waterFall == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Effect: Rain         ", 1, y, NULL);
	}
}

void PostProcessingEffectsState::showDetails()
{
	PostProcessingEffectsState::printHeader(this);

	if(this->showDetails)
	{
		VIPManager::removePostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);

		Printing::printSprite(Printing::getInstance(), 1, 3);
	}
	else
	{
		PostProcessingEffectsState::printMessage(this);

		PostProcessingEffectsState::showStuff(this);
	}	

	PostProcessingEffectsState::setupBrightness(this, this->showDetails);
}

void PostProcessingEffectsState::printMessage()
{
	const char* strPostProcessingEffects = I18n::getText(I18n::getInstance(), kStringPostProcessingEffects);

	FontSize textSize = Printing::getTextSize(Printing::getInstance(), strPostProcessingEffects, "VirtualBoyExt");

	Printing::text(
		Printing::getInstance(),
		strPostProcessingEffects,
		(__SCREEN_WIDTH >> 4) - (textSize.x >> 1),
		12,
		"VirtualBoyExt"
	);
}