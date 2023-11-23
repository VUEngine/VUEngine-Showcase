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
#include <PostProcessingWobble.h>
#include <Printing.h>
#include <VIPManager.h>

#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec PostProcessingEffectsStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void PostProcessingEffectsState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&PostProcessingEffectsStage;
}

// class's destructor
void PostProcessingEffectsState::destructor()
{
	// destroy base
	Base::destructor();
}

void PostProcessingEffectsState::showStuff()
{
	PostProcessingEffectsState::print(this);

	// add wobble effect
	VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), PostProcessingWobble::wobble, NULL);
}

void PostProcessingEffectsState::print()
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

void PostProcessingEffectsState::showDetails()
{
	if(this->showDetails)
	{
		VIPManager::removePostProcessingEffect(VIPManager::getInstance(), PostProcessingWobble::wobble, NULL);

		Printing::printSprite(Printing::getInstance(), 1, 3);
	}
	else
	{
		PostProcessingEffectsState::printHeader(this);

		PostProcessingEffectsState::showStuff(this);
	}	

	PostProcessingEffectsState::setupBrightness(this, this->showDetails);
}
