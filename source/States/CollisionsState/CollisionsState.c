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

#include <Actor.h>
#include <I18n.h>
#include <KeypadManager.h>
#include <Languages.h>
#include <Messages.h>
#include <Printing.h>
#include <VirtualList.h>

#include "CollisionsState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool CollisionsState::onEvent(ListenerObject eventFirer __attribute__((unused)), uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventFontRewritten:
		{
			CollisionsState::show(this, false);

			return true;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);

	// Start animations, physics and messaging clocks
	CollisionsState::startClocks(this);

	/*
	 * When CharSets are deleted, defragmentation takes place. If the font CharSets are loaded after
	 * the CharSet being deleted, the printed messages can become garbled. So, we listen for when
	 * the font CharSets are rewritten.
	 */
	Printing::addEventListener(Printing::getInstance(), ListenerObject::safeCast(this), kEventFontRewritten);

	/*
	 * I need to register both released and hold buttons
	 */
	KeypadManager::registerInput(__KEY_RELEASED | __KEY_HOLD);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(this->showAdditionalDetails)
	{
		CollisionsState::showAdditionalDetails(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::exit(void* owner __attribute__((unused)))
{
	Printing::removeEventListener(Printing::getInstance(), ListenerObject::safeCast(this), kEventFontRewritten);

	Base::exit(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 *	The StateMachine calls State::resume when the State is again at the top of its stack
 *  after the previous State at the top has been popped.
 */
void CollisionsState::resume(void* owner)
{
	Base::resume(this, owner);

	Printing::addEventListener(Printing::getInstance(), ListenerObject::safeCast(this), kEventFontRewritten);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::processUserInput(const UserInput* userInput)
{
	CollisionsState::playSoundEffects(this, userInput, false);
	int32 message = kMessageCollisionsStateNoMessage;

	if(K_LL & userInput->holdKey)
	{
		message = kMessageCollisionsStateHoldLeft;
	}
	else if(K_LL & userInput->releasedKey)
	{
		message = kMessageCollisionsStateReleasedLeft;
	}
	else if(K_LR & userInput->holdKey)
	{
		message = kMessageCollisionsStateHoldRight;
	}
	else if(K_LR & userInput->releasedKey)
	{
		message = kMessageCollisionsStateReleasedRight;
	}

	if(kMessageCollisionsStateNoMessage != message)
	{
		/*
		 * Passing input to actors in this way, while elegant,
		 * is not very performant. Most likely, a way to get a
		 * pointer to the actor that the user controls and calling
		 * an specific method that its class implements would be
		 * way faster.
		 */
		CollisionsState::propagateMessage(this, message);
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::showControls()
{
	Printing::text
	(
		
		__CHAR_SELECT_BUTTON,
		__SCREEN_WIDTH_IN_CHARS - 1,
		__SCREEN_HEIGHT_IN_CHARS - 1,
		NULL
	);
	Printing::text
	(
		
		__CHAR_L_D_PAD_RIGHT,
		__SCREEN_WIDTH_IN_CHARS - 4,
		__SCREEN_HEIGHT_IN_CHARS - 1,
		NULL
	);
	Printing::text
	(
		
		__CHAR_L_D_PAD_LEFT,
		__SCREEN_WIDTH_IN_CHARS - 5,
		__SCREEN_HEIGHT_IN_CHARS - 1,
		NULL
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::showStuff()
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::showExplanation()
{
	int16 y = 3;

	Printing::text
	(
		I18n::getText(I18n::getInstance(), kStringConceptsSubtitle),
		2,
		y++,
		"DefaultBold"
	);
	
	Printing::text(I18n::getText(I18n::getInstance(), kStringActorsLabel), 2, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(), kStringPhysicsLabel), 2, y++, NULL);
	
	Printing::text
	(	
		I18n::getText(I18n::getInstance(), kStringStateMachinesLabel),
		2,
		y++,
		NULL
	);
	
	y++;
	
	Printing::text
	(
		I18n::getText(I18n::getInstance(), kStringClassesSubtitle),
		2,
		y++,
		"DefaultBold"
	);

	Printing::text("Actor", 2, y++, NULL);
	Printing::text("MessageDispatcher*", 2, y++, NULL);
	Printing::text("Punk", 2, y++, NULL);
	Printing::text("PunkState*", 2, y++, NULL);

	y++;
	
	Printing::text
	(
		I18n::getText(I18n::getInstance(), kStringSpecsSubtitle),
		2,
		y++,
		"DefaultBold"
	);

	Printing::text("PunkActorSpec", 2, y++, NULL);

	y = 3;

	Printing::text
	(	
		I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle),
		26,
		y++,
		"DefaultBold"
	);
	
	Printing::text
	(	
		I18n::getText(I18n::getInstance(), kStringCollisionsLabel),
		26,
		y++,
		NULL
	);
	
	Printing::text(I18n::getText(I18n::getInstance(), kStringEventsLabel), 26, y++, NULL);
	
	Printing::text
	(	
		I18n::getText(I18n::getInstance(), kStringMessagingLabel),
		26,
		y++,
		NULL
	);

	y++;

	Printing::text
	(	
		I18n::getText(I18n::getInstance(), kStringMethodsSubtitle),
		26,
		y++,
		"DefaultBold"
	);
	
	Printing::text("CollisionsState", 26, y++, NULL);
	Printing::text("::propagateMessage", 26, y++, NULL);
	Printing::text("Punk", 26, y++, NULL);
	Printing::text("::collisionStarts", 26, y++, NULL);
	Printing::text("::handlePropagatedMes\x85", 26, y++, NULL);
	
	y++;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::showAdditionalDetails()
{
	CollisionsState::propagateMessage(this, kMessageCollisionsStatePrintActorStatus);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/CollisionsStageSpec.c
	 */
	extern StageROMSpec CollisionsStageSpec;
	this->stageSpec = (StageSpec*)&CollisionsStageSpec;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CollisionsState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
