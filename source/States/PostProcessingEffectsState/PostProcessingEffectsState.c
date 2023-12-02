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

void PostProcessingEffectsState::exit(void* owner __attribute__((unused)))
{
	VIPManager::removePostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);
	
	Base::exit(this, owner);	
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

			PostProcessingEffectsState::show(this, true);
		}
		else if(K_LR & userInput->releasedKey)
		{
			VIPManager::removePostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);

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
	}

	Base::processUserInput(this, userInput);
}

void PostProcessingEffectsState::showControls()
{
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 2, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

void PostProcessingEffectsState::showStuff()
{
	VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), _postProcessingEffect[this->selectedPostProcessingEffect], NULL);
}

void PostProcessingEffectsState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), "CONCEPTS", 1, y++, "Debug");
	Printing::text(Printing::getInstance(), "Frame buffers", 1, y++, NULL);
	Printing::text(Printing::getInstance(), "Post processing effects", 1, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "METHODS", 1, y++, "Debug");
	Printing::text(Printing::getInstance(), "PostProcessingEffectsState", 1, y++, NULL);
	Printing::text(Printing::getInstance(), " processUserInput", 1, y++, NULL);
	
	y = 3;
	Printing::text(Printing::getInstance(), "CLASSES", 32, y++, "Debug");
	Printing::text(Printing::getInstance(), "VIPManager", 32, y++, NULL);
	y++;

	Printing::text(Printing::getInstance(), "EFFECT", 32, y++, "Debug");

	if(PostProcessingWobble::wobble == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Wobble      ", 32, y, NULL);
	}
	else if(PostProcessingTilt::tiltScreen == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Tilt        ", 32, y, NULL);
	}
	else if(PostProcessingDwarfPlanet::dwarfPlanet == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Dwarf planet ", 32, y, NULL);
	}
	else if(PostProcessingRain::waterFall == _postProcessingEffect[this->selectedPostProcessingEffect])
	{
		Printing::text(Printing::getInstance(), "Rain         ", 32, y, NULL);
	}
}
