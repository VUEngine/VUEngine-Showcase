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

#include <ShowcaseState.h>

#include <ActorsState.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <EntitiesState.h>
#include <Printing.h>
#include <VIPManager.h>
#include <VUEngine.h>
#include <WireframesState.h>

#include <Showcases.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
// 												CLASS' ATTRIBUTES
//---------------------------------------------------------------------------------------------------------

static int8 _currentShowcaseState = 0;

static ShowcaseStateGetInstance _showcaseStates [] =
{
	(ShowcaseStateGetInstance)ActorsState::getInstance,
	(ShowcaseStateGetInstance)SpritesState::getInstance,
	(ShowcaseStateGetInstance)AnimationSchemesState::getInstance,
	(ShowcaseStateGetInstance)EntitiesState::getInstance,
	(ShowcaseStateGetInstance)WireframesState::getInstance,
	(ShowcaseStateGetInstance)PostProcessingEffectsState::getInstance
};

//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

static ShowcaseStateGetInstance ShowcaseState::getFirstShowcase()
{
	return _showcaseStates [0];
}

// class's constructor
void ShowcaseState::constructor()
{
	Base::constructor();

	this->stageSpec = NULL;
	this->showAdditionalDetails = false;
}

// class's destructor
void ShowcaseState::destructor()
{
	// destroy base
	Base::destructor();
}

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
		ShowcaseState::loadStage(this, this->stageSpec, NULL, true, false);
	}

	// show everything
	ShowcaseState::show(this, true);

	// enable user input
	VUEngine::enableKeypad(VUEngine::getInstance());

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

/*
 *	The StateMachine calls State::exit when popping the State from its stack.
 */
void ShowcaseState::exit(void* owner __attribute__((unused)))
{
	Base::exit(this, owner);

	// Since all instances are dynamic_singleton, I must delete myself upon exit
	delete this;
}

/*
 *	The StateMachine calls State::suspend when a new State is put at the top of its stack.
 */
void ShowcaseState::suspend(void* owner)
{
	if(!VUEngine::isEnteringToolState(VUEngine::getInstance()))
	{
		// do a fade out effect
		Camera::startEffect(Camera::getInstance(), kFadeOut, __FADE_DELAY);
	}

	// call base
	Base::suspend(this, owner);
}

/*
 *	The StateMachine calls State::resume when the State is again at the top of its stack
 *  after the previous State at the top has been popped.
 */
void ShowcaseState::resume(void* owner)
{
	// call base
	Base::resume(this, owner);

	// show stuff
	ShowcaseState::showStuff(this);

	if(!VUEngine::isExitingToolState(VUEngine::getInstance()))
	{
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
}

/*
 *	The engine calls State::processUserInput on the State top of its StateMachine's stack.
 */
void ShowcaseState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(!(K_PWR & userInput->releasedKey))
	{
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
}

void ShowcaseState::show(bool reloadStuff)
{
	Printing::clear(Printing::getInstance());
	
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

	SpritesState::setupBrightness(this, this->showAdditionalDetails);
}


void ShowcaseState::showHeader()
{
	const char* currentShowCaseNumberPrefix = "( / ) ";
	FontSize currentShowCaseNumberPrefixTextSize = Printing::getTextSize(Printing::getInstance(), currentShowCaseNumberPrefix, NULL);
	uint8 numberOfShowCaseStates = (signed)(sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1) + 1;

	const char* statePrefix = "STATE: ";
	FontSize statePrefixTextSize = Printing::getTextSize(Printing::getInstance(), statePrefix, NULL);

	const char* className = __GET_CLASS_NAME(this);
	FontSize classNameTextSize = Printing::getTextSize(Printing::getInstance(), className, NULL);

	uint8 textStartXPosition = (__SCREEN_WIDTH >> 4) - (currentShowCaseNumberPrefixTextSize.x >> 1) - (statePrefixTextSize.x >> 1) - (classNameTextSize.x >> 1);

	Printing::text(Printing::getInstance(), __CHAR_SELECTOR_LEFT, 0, 0, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_TRIGGER, 1, 0, NULL);
	Printing::text(Printing::getInstance(), currentShowCaseNumberPrefix, textStartXPosition, 0, NULL);
	Printing::int32(Printing::getInstance(), _currentShowcaseState + 1, textStartXPosition + 1, 0, NULL);
	Printing::int32(Printing::getInstance(), numberOfShowCaseStates, textStartXPosition + 3, 0, NULL);
	Printing::text(Printing::getInstance(), statePrefix, textStartXPosition + currentShowCaseNumberPrefixTextSize.x, 0, "Debug");
	Printing::text(Printing::getInstance(), className, textStartXPosition + currentShowCaseNumberPrefixTextSize.x + statePrefixTextSize.x, 0, NULL);
	Printing::text(Printing::getInstance(), __CHAR_R_TRIGGER, 46, 0, NULL);
	Printing::text(Printing::getInstance(), __CHAR_SELECTOR, 47, 0, NULL);
}

void ShowcaseState::showControls()
{
}

void ShowcaseState::showStuff()
{
}

void ShowcaseState::showExplanation()
{
}

void ShowcaseState::goToNext()
{
	VUEngine::enableKeypad(VUEngine::getInstance());

	VUEngine::changeState(VUEngine::getInstance(), GameState::safeCast(_showcaseStates[_currentShowcaseState]()));
}

void ShowcaseState::showAdditionalDetails()
{}

void ShowcaseState::setupBrightness(bool dimm)
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

	VIPManager::setupPalettes(VIPManager::getInstance(), &paletteConfig);
}