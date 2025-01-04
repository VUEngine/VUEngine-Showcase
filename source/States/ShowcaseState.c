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
#include <Printing.h>
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
	(ShowcaseStateGetInstance)EntitiesState::getInstance,
	(ShowcaseStateGetInstance)ActorsState::getInstance,
	(ShowcaseStateGetInstance)ParticlesState::getInstance,
	(ShowcaseStateGetInstance)PostProcessingEffectsState::getInstance,
	(ShowcaseStateGetInstance)WireframesState::getInstance,
	(ShowcaseStateGetInstance)VideoPlayerState::getInstance,
	(ShowcaseStateGetInstance)SoundsState::getInstance,
	(ShowcaseStateGetInstance)PongState::getInstance,
};


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' STATIC METHODS
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

/*
 *	The StateMachine calls State::enter when the State is put at the top of its stack.
 */
void ShowcaseState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// load stage
	if(NULL != this->stageSpec)
	{		
		ShowcaseState::configureStage(this, this->stageSpec, NULL);
	}

	// show everything
	ShowcaseState::show(this, true);
	
	// This starts animations, physics and messaging
	ShowcaseState::startClocks(this);

	// Only register when a button is released
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_RELEASED);

	// enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

	// Printing the framerate
	FrameRate::addEventListener(FrameRate::getInstance(), ListenerObject::safeCast(this), 
		(EventListener)ShowcaseState::onFramerateReady, kEventFramerateReady);

	// start fade in effect
	Camera::startEffect(Camera::getInstance(), kHide);
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		__FADE_DELAY, // delay between fading steps (in ms)
		NULL, // callback function
		NULL // callback scope
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::exit when popping the State from its stack.
 */
void ShowcaseState::exit(void* owner __attribute__((unused)))
{
	FrameRate::removeEventListener(FrameRate::getInstance(), ListenerObject::safeCast(this), (EventListener)ShowcaseState::onFramerateReady, kEventFramerateReady);

	Base::exit(this, owner);

	// Since all instances are dynamic_singleton, I must delete myself upon exit
	delete this;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::suspend when a new State is put at the top of its stack.
 */
void ShowcaseState::suspend(void* owner)
{
	Camera::startEffect(Camera::getInstance(), kFadeOut, __FADE_DELAY);

	// call base
	Base::suspend(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::resume when the State is again at the top of its stack
 *  after the previous State at the top has been popped.
 */
void ShowcaseState::resume(void* owner)
{
	// call base
	Base::resume(this, owner);

	// show stuff
	ShowcaseState::show(this, false);

	// start a fade in effect
	Camera::startEffect(Camera::getInstance(), kHide);
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		__FADE_DELAY, // delay between fading steps (in ms)
		NULL, // callback function
		NULL // callback scope
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The engine calls State::processUserInput on the State top of its StateMachine's stack.
 */
void ShowcaseState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(K_LT & userInput->releasedKey)
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
	this->playingSoundEffect = NULL;

	if((this->validSuboptionKeys) & userInput->releasedKey)
	{
		this->playingSoundEffect = &ChangeSelection3SoundSpec;
		rumbleEffect = &ChangeSelection3RumbleEffectSpec;
	}
	else if((K_LT | K_RT) & userInput->releasedKey)
	{
		this->playingSoundEffect = &ChangeSelection1SoundSpec;
		rumbleEffect = &ChangeSelection1RumbleEffectSpec;
		lock = true;
	}
	else if(K_SEL & userInput->releasedKey)
	{
		this->playingSoundEffect = &ChangeSelection4SoundSpec;
		rumbleEffect = &ChangeSelection4RumbleEffectSpec;
	}

	if(NULL != this->playingSoundEffect)
	{
		RumbleManager::startEffect(rumbleEffect);

		/*
		 * Prevent the user to mess up the playback by pressig the keypad's buttons
		 * like a maniac.
		 */
		VUEngine::disableKeypad(VUEngine::getInstance());

		/*
		 * Make sure that the timer interrupts happen at a controlled frequency to
		 * make sure that the sound effects sound the same in all stages
		 */
		TimerManager::disable(TimerManager::getInstance());
		TimerManager::setResolution(TimerManager::getInstance(), __TIMER_20US);
		TimerManager::setTargetTimePerInterruptUnits(TimerManager::getInstance(), kUS);
		TimerManager::setTargetTimePerInterrupt(TimerManager::getInstance(), 500);
		TimerManager::applySettings(TimerManager::getInstance(), true);

		SoundManager::playSound
		(
			SoundManager::getInstance(), 
			this->playingSoundEffect, 
			NULL, 
			kSoundPlaybackNormal,
			(EventListener)ShowcaseState::onSoundEffectDone, 
			ListenerObject::safeCast(this)
		);
		
		if(lock)
		{
			/*
			 * Wait until ShowcaseState::onSoundEffectDone is called.
			 * The dummy is necessary to prevent that the compiler
			 * optimizes away the while loop.
			 */
			volatile bool dummy = true;
			while(dummy && NULL != this->playingSoundEffect);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::configurePalettes(bool dimm)
{
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

	VIPManager::configurePalettes(VIPManager::getInstance(), &paletteConfig);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::show(bool reloadStuff)
{
	Printing::clear(this->printing);
	
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
	FontSize currentShowCaseNumberPrefixTextSize = Printing::getTextSize(this->printing, currentShowCaseNumberPrefix, NULL);
	uint8 numberOfShowCaseStates = (signed)(sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1) + 1;

	const char* statePrefix = I18n::getText(I18n::getInstance(), kStringStateTitle);
	FontSize statePrefixTextSize = Printing::getTextSize(this->printing, statePrefix, NULL);

	const char* className = __GET_CLASS_NAME(this);
	FontSize classNameTextSize = Printing::getTextSize(this->printing, className, NULL);

	uint8 textStartXPosition = (__SCREEN_WIDTH >> 4) - (currentShowCaseNumberPrefixTextSize.x >> 1) - (statePrefixTextSize.x >> 1) - (classNameTextSize.x >> 1) - 1;

	Printing::text(this->printing, __CHAR_SELECTOR_LEFT, 0, 0, NULL);
	Printing::text(this->printing, __CHAR_L_TRIGGER, 1, 0, NULL);
	Printing::text(this->printing, currentShowCaseNumberPrefix, textStartXPosition, 0, NULL);
	Printing::text(this->printing, Utilities::itoa(_currentShowcaseState + 1, 10, 2), textStartXPosition + 1, 0, NULL);
	Printing::int32(this->printing, numberOfShowCaseStates, textStartXPosition + 4, 0, NULL);
	Printing::text(this->printing, statePrefix, textStartXPosition + currentShowCaseNumberPrefixTextSize.x, 0, "DefaultBold");
	Printing::text(this->printing, className, textStartXPosition + currentShowCaseNumberPrefixTextSize.x + statePrefixTextSize.x + 1, 0, NULL);
	Printing::text(this->printing, __CHAR_R_TRIGGER, 46, 0, NULL);
	Printing::text(this->printing, __CHAR_SELECTOR, 47, 0, NULL);
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
	this->printing = Printing::getInstance();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool ShowcaseState::onFramerateReady(ListenerObject eventFirer __attribute__((unused)))
{
	FrameRate::print(FrameRate::getInstance(), 14, 27);

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool ShowcaseState::onSoundEffectDone(ListenerObject eventFirer __attribute__((unused)))
{
	this->playingSoundEffect = NULL;

	/*
	 * Restore timer settings
	 */
	Stage::configureTimer(this->stage);

	/*
	 * Allow the player to interact again.
	 */
	VUEngine::enableKeypad(VUEngine::getInstance());

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ShowcaseState::goToNext()
{
	VUEngine::disableKeypad(VUEngine::getInstance());

	VUEngine::changeState(VUEngine::getInstance(), GameState::safeCast(_showcaseStates[_currentShowcaseState]()));
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

