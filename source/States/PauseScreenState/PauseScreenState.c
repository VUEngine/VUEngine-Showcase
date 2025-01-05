/*
 * VUEngine Plugins Library
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

#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <MessageDispatcher.h>
#include <Printing.h>
#include <VUEngine.h>

#include "PauseScreenState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern StageROMSpec PauseScreenStage;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PauseScreenState::enter(void* owner __attribute__ ((unused)))
{
	Base::enter(this, owner);

	// Load stage
	GameState::configureStage(this, (StageSpec*)&PauseScreenStage, NULL);

	// Print text
	const char* strTitle = I18n::getText(I18n::getInstance(), kStringPauseTitle);

	FontSize strPauseSize = Printing::getTextSize
	(
		Printing::getInstance(),
		strTitle,
		"Default"
	);

	uint8 strHeaderXPos = ((__HALF_SCREEN_WIDTH_IN_CHARS) - (strPauseSize.x >> 1));
	
	Printing::text
	(
		Printing::getInstance(),
		strTitle,
		strHeaderXPos,
		12,
		"Default"
	);

	// Disable user input
	VUEngine::disableKeypad(VUEngine::getInstance());

	// Start clocks to start animations
	GameState::startClocks(this);

	// Fade in screen
	Camera::startEffect(Camera::getInstance(), kHide);
	
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		__FADE_DELAY, // delay between fading steps (in ms)
		(void (*)(ListenerObject, ListenerObject))PauseScreenState::onFadeInComplete, // callback function
		ListenerObject::safeCast(this) // callback scope
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PauseScreenState::exit(void* owner __attribute__ ((unused)))
{
	Base::exit(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PauseScreenState::processUserInput(const UserInput*  userInput)
{
	if(K_STA & userInput->pressedKey)
	{
		// Disable user input
		VUEngine::disableKeypad(VUEngine::getInstance());

		// Fade out screen
		Brightness brightness = (Brightness){0, 0, 0};
		Camera::startEffect(Camera::getInstance(),
			kFadeTo, // effect type
			0, // initial delay (in ms)
			&brightness, // target brightness
			__FADE_DELAY, // delay between fading steps (in ms)
			(void (*)(ListenerObject, ListenerObject))PauseScreenState::onFadeOutComplete, // callback function
			ListenerObject::safeCast(this) // callback scope
		);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PauseScreenState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PauseScreenState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PauseScreenState::onFadeInComplete(ListenerObject eventFirer __attribute__ ((unused)))
{
	// Re-enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PauseScreenState::onFadeOutComplete(ListenerObject eventFirer __attribute__ ((unused)))
{
	// Re-enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

	// Resume game
	VUEngine::unpause(VUEngine::getInstance(), GameState::safeCast(this));

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
