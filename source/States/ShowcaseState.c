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

#include <Camera.h>
#include <CameraEffectManager.h>
#include <FrameRate.h>
#include <I18n.h>
#include <KeypadManager.h>
#include <Languages.h>
#include <Printer.h>
#include <PauseScreenState.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <Showcases.h>
#include <Sounds.h>
#include <TimerManager.h>
#include <Utilities.h>
#include <VIPManager.h>
#include <VUEngine.h>

#include "ShowcaseState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' ATTRIBUTES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static int8 _currentShowcaseState = 0;

static ShowcaseStateGetInstance _showcaseStates [] =
{
	(ShowcaseStateGetInstance)SpritesState::getInstance,
	(ShowcaseStateGetInstance)AnimationSchemesState::getInstance,
	(ShowcaseStateGetInstance)ActorsState::getInstance,
	(ShowcaseStateGetInstance)CollisionsState::getInstance,
	(ShowcaseStateGetInstance)ParticlesState::getInstance,
	(ShowcaseStateGetInstance)WireframesState::getInstance,
	(ShowcaseStateGetInstance)PostProcessingEffectsState::getInstance,
	(ShowcaseStateGetInstance)VideoPlayerState::getInstance,
	(ShowcaseStateGetInstance)SoundsState::getInstance,
	(ShowcaseStateGetInstance)CommunicationsState::getInstance,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC STATIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static ShowcaseStateGetInstance ShowcaseState::getFirstShowcase()
{
	return _showcaseStates [0];
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool ShowcaseState::onEvent(ListenerObject eventFirer __attribute__((unused)), uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventEffectFadeInComplete:
		{
			KeypadManager::enable();

			return true;
		}
		
		case kEventFramerateReady:
		{
			FrameRate::print(FrameRate::getInstance(), 14, 27);

			return true;
		}

		case kEventSoundReleased:
		case kEventSoundFinished:
		{
			ShowcaseState::acceptUserInput(this);
			return false;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::enter when the State is put at the top of its stack.
 */
void ShowcaseState::enter(void* owner __attribute__ ((unused)))
{
	Base::enter(this, owner);

	if(NULL != this->stageSpec)
	{		
		ShowcaseState::configureStage(this, this->stageSpec, NULL);
	}

	// Show everything
	ShowcaseState::show(this, true);
	
	// This starts animations, physics and messaging
	ShowcaseState::startClocks(this);

	// Only register when a button is released
	KeypadManager::registerInput(__KEY_RELEASED);

	// Enable user input
	KeypadManager::disable();

	// Printer the framerate
	FrameRate::addEventListener(FrameRate::getInstance(), ListenerObject::safeCast(this), kEventFramerateReady);

	// Start fade in effect
	Camera::startEffect(Camera::getInstance(), kHide);
	Camera::startEffect
	(
		Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		__FADE_DELAY, // delay between fading steps (in ms)
		ListenerObject::safeCast(this) 		// callback scope
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::exit when popping the State from its stack.
 */
void ShowcaseState::exit(void* owner __attribute__((unused)))
{
	FrameRate::removeEventListener(FrameRate::getInstance(), ListenerObject::safeCast(this), kEventFramerateReady);

	// Always call the base implementation!
	Base::exit(this, owner);

	// Since all instances are dynamic_singleton, I must delete myself upon exit
	delete this;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::resume when the State is again at the top of its stack
 *  after the previous State at the top has been popped.
 */
void ShowcaseState::resume(void* owner)
{
	Base::resume(this, owner);

	// Show stuff
	ShowcaseState::show(this, true);

	// Start a fade in effect
	Camera::startEffect(Camera::getInstance(), kHide);
	Camera::startEffect
	(
		Camera::getInstance(),
		kFadeTo, 				// effect type
		0, 						// initial delay (in ms)
		NULL, 					// target brightness
		__FADE_DELAY, 			// delay between fading steps (in ms)
		ListenerObject::safeCast(this) 		// callback scope
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The engine calls State::processUserInput on the State top of its StateMachine's stack.
 */
void ShowcaseState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(K_STA & userInput->releasedKey)
	{
		VUEngine::pause(GameState::safeCast(PauseScreenState::getInstance()));
	}
	else if(K_LT & userInput->releasedKey)
	{
		if(0 > --_currentShowcaseState)
		{
			_currentShowcaseState = sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1;
		}

		ShowcaseState::goToNext(this);
	}
	else if(K_RT & userInput->releasedKey)
	{
		if((signed)(sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1)< ++_currentShowcaseState)
		{
			_currentShowcaseState = 0;
		}

		ShowcaseState::goToNext(this);
	}
	else if(K_SEL & userInput->releasedKey)
	{
		this->showAdditionalDetails = !this->showAdditionalDetails;

		ShowcaseState::show(this, false);
	}
	else if(K_B & userInput->releasedKey)
	{
		// TODO
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::playSoundEffects(const UserInput* userInput, bool lock)
{
	const RumbleEffectSpec* rumbleEffect = NULL;
	SoundSpec* soundEffectSpec = NULL;

	if((this->validSuboptionKeys) & userInput->releasedKey)
	{
		soundEffectSpec = &ChangeSelection3SoundSpec;
		rumbleEffect = &ChangeSelection3RumbleEffectSpec;
	}
	else if((K_LT | K_RT) & userInput->releasedKey)
	{
		soundEffectSpec = &ChangeSelection1SoundSpec;
		rumbleEffect = &ChangeSelection1RumbleEffectSpec;
		lock = true;
	}
	else if(K_SEL & userInput->releasedKey)
	{
		soundEffectSpec = &ChangeSelection4SoundSpec;
		rumbleEffect = &ChangeSelection4RumbleEffectSpec;
	}

	if(NULL != soundEffectSpec)
	{
		RumbleManager::startEffect(rumbleEffect);

		// Prevent the user to mess up the playback by pressig the keypad's buttons like a maniac.
		KeypadManager::disable();

		/*
		 * Make sure that the timer interrupts happen at a controlled frequency to make sure that 
		 * the sound effects sound the same in all stages
		 */
		TimerManager::disable();
		TimerManager::setResolution(__TIMER_20US);
		TimerManager::setTargetTimePerInterruptUnits(kUS);
		TimerManager::setTargetTimePerInterrupt(500);
		TimerManager::applySettings(true);

		Sound soundEffect = SoundManager::getSound(soundEffectSpec, ListenerObject::safeCast(this));

		if(NULL != soundEffect)
		{
			Sound::play(soundEffect, NULL, kSoundPlaybackNormal);
			
			// Wait until the sound playback is done.
			while(lock && Sound::isPlaying(soundEffect));

			// Manually release the sound effect
			Sound::release(soundEffect);

			// The same could have been achieved by the following call
			// Sound::autoReleaseOnFinish(soundEffect, true);
		}
		else
		{
			ShowcaseState::acceptUserInput(this);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::acceptUserInput()
{
	if(isDeleted(this->stage))
	{
		return;
	}

	// Restore timer settings
	const StageSpec* stageSpec = Stage::getSpec(this->stage);

	TimerManager::configure
	(
		stageSpec->timer.resolution, stageSpec->timer.targetTimePerInterrupt, 
		stageSpec->timer.targetTimePerInterrupttUnits
	);

	// Allow the player to interact again.
	KeypadManager::enable();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::configurePalettes(bool dimm)
{
	if(isDeleted(this->stage))
	{
		return;
	}

	PaletteConfig paletteConfig = Stage::getPaletteConfig(this->stage);

	if(dimm)
	{
		paletteConfig.bgmap.gplt1 = 0x50;
		paletteConfig.bgmap.gplt2 = 0x50;
		paletteConfig.bgmap.gplt3 = 0x50;
		paletteConfig.object.jplt1 = 0x50;
		paletteConfig.object.jplt2 = 0x50;
		paletteConfig.object.jplt3 = 0x50;
	}

	VIPManager::configurePalettes(&paletteConfig);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::show(bool reloadStuff)
{
	Printer::clear();
	
	ShowcaseState::showHeader(this);
	ShowcaseState::showControls(this);

	if(reloadStuff)
	{		
		ShowcaseState::showStuff(this);
	}

	if(!this->showAdditionalDetails)
	{		
		ShowcaseState::showExplanation(this);
	}
	else
	{
		ShowcaseState::showAdditionalDetails(this);
	}

	ShowcaseState::configurePalettes(this, this->showAdditionalDetails);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::showHeader()
{
	const char* currentShowCaseNumberPrefix = "(  /  ) ";
	FontSize currentShowCaseNumberPrefixTextSize = Printer::getTextSize(currentShowCaseNumberPrefix, NULL);
	uint8 numberOfShowCaseStates = (signed)(sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1) + 1;

	const char* statePrefix = I18n::getText(I18n::getInstance(), kStringStateTitle);
	FontSize statePrefixTextSize = Printer::getTextSize(statePrefix, NULL);

	const char* className = __GET_CLASS_NAME(this);
	FontSize classNameTextSize = Printer::getTextSize(className, NULL);

	uint8 textStartXPosition = 
		(__SCREEN_WIDTH >> 4) - (currentShowCaseNumberPrefixTextSize.x >> 1) - 
		(statePrefixTextSize.x >> 1) - (classNameTextSize.x >> 1) - 1;

	Printer::text(__CHAR_SELECTOR_LEFT, 0, 0, NULL);
	Printer::text(__CHAR_L_TRIGGER, 1, 0, NULL);
	Printer::text(currentShowCaseNumberPrefix, textStartXPosition, 0, NULL);
	Printer::text(Utilities::itoa(_currentShowcaseState + 1, 10, 2), textStartXPosition + 1, 0, NULL);
	Printer::int32(numberOfShowCaseStates, textStartXPosition + 4, 0, NULL);
	Printer::text(statePrefix, textStartXPosition + currentShowCaseNumberPrefixTextSize.x, 0, "DefaultBold");
	Printer::text(className, textStartXPosition + currentShowCaseNumberPrefixTextSize.x + statePrefixTextSize.x + 1, 0, NULL);
	Printer::text(__CHAR_R_TRIGGER, 46, 0, NULL);
	Printer::text(__CHAR_SELECTOR, 47, 0, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::showControls()
{}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::showStuff()
{}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::showExplanation()
{}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::showAdditionalDetails()
{}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	this->stageSpec = NULL;
	this->showAdditionalDetails = false;
	this->validSuboptionKeys = K_NON;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::goToNext()
{
	KeypadManager::disable();

	VUEngine::changeState(GameState::safeCast(_showcaseStates[_currentShowcaseState]()));
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
