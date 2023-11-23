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

#include <HelloWorldState.h>

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

extern StageROMSpec HelloWorldStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void HelloWorldState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&HelloWorldStage;
}

// class's destructor
void HelloWorldState::destructor()
{
	// destroy base
	Base::destructor();
}

void HelloWorldState::showStuff()
{
	HelloWorldState::print(this);

	// add wobble effect
	VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), PostProcessingWobble::wobble, NULL);
}

void HelloWorldState::print()
{
	const char* strHelloWorld = I18n::getText(I18n::getInstance(), kStringHelloWorld);

	FontSize textSize = Printing::getTextSize(Printing::getInstance(), strHelloWorld, "VirtualBoyExt");

	Printing::text(
		Printing::getInstance(),
		strHelloWorld,
		(__SCREEN_WIDTH >> 4) - (textSize.x >> 1),
		12,
		"VirtualBoyExt"
	);
}

void HelloWorldState::showDetails()
{
	if(this->showDetails)
	{
		VIPManager::removePostProcessingEffect(VIPManager::getInstance(), PostProcessingWobble::wobble, NULL);

		Printing::printSprite(Printing::getInstance(), 1, 3);
	}
	else
	{
		HelloWorldState::printHeader(this);

		HelloWorldState::showStuff(this);
	}	

	HelloWorldState::setupBrightness(this, this->showDetails);
}
