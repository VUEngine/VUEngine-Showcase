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

#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
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

static int8 _currentShowCaseState = 0;

static ShowcaseStateGetInstance _showcaseStates [] =
{
	(ShowcaseStateGetInstance)HelloWorldState::getInstance,
	(ShowcaseStateGetInstance)SpritesState::getInstance,
	(ShowcaseStateGetInstance)WireframesState::getInstance
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
}

// class's destructor
void ShowcaseState::destructor()
{
	// destroy base
	Base::destructor();
}

// state's enter
void ShowcaseState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// load stage
	if(NULL != this->stageSpec)
	{		
		ShowcaseState::loadStage(this, this->stageSpec, NULL, true, false);
	}

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// print header
	ShowcaseState::printHeader(this);

	// show stuff
	ShowcaseState::showStuff(this);

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

void ShowcaseState::suspend(void* owner)
{
	if(!VUEngine::isEnteringSpecialMode(VUEngine::getInstance()))
	{
		// do a fade out effect
		Camera::startEffect(Camera::getInstance(), kFadeOut, __FADE_DELAY);
	}

	// call base
	Base::suspend(this, owner);
}

void ShowcaseState::resume(void* owner)
{
	// call base
	Base::resume(this, owner);

	// show stuff
	ShowcaseState::showStuff(this);

	if(!VUEngine::isExitingSpecialMode(VUEngine::getInstance()))
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

void ShowcaseState::printHeader()
{
	Printing::clear(Printing::getInstance());
	Printing::text(Printing::getInstance(), "State: ", 1, 0, NULL);
	Printing::text(Printing::getInstance(), __GET_CLASS_NAME(this), 8, 0, NULL);
}

void ShowcaseState::showStuff()
{
}


void ShowcaseState::processUserInput(const UserInput* userInput)
{
	if(!(K_PWR & userInput->releasedKey))
	{
		if(K_LT & userInput->releasedKey)
		{
			if(0 > --_currentShowCaseState)
			{
				_currentShowCaseState = sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1;
			}

			VUEngine::changeState(VUEngine::getInstance(), GameState::safeCast(_showcaseStates[_currentShowCaseState]()));
		}
		else if(K_RT & userInput->releasedKey)
		{
			if(sizeof(_showcaseStates) / sizeof(ShowcaseState) - 1 < ++_currentShowCaseState)
			{
				_currentShowCaseState = 0;
			}

			VUEngine::changeState(VUEngine::getInstance(), GameState::safeCast(_showcaseStates[_currentShowCaseState]()));
		}
		else if(K_B & userInput->releasedKey)
		{
			// TODO
		}
	}
}