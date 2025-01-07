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

#include "StatefulActorsState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);

	// Start animations, physics and messaging clocks
	StatefulActorsState::startClocks(this);

	/*
	 * When CharSets are deleted, defragmentation takes place. If the font CharSets are loaded after
	 * the CharSet being deleted, the printed messages can become garbled. So, we listen for when
	 * the font CharSets are rewritten.
	 */
	Printing::registerEventListener
	(
		ListenerObject::safeCast(this),
		(EventListener)StatefulActorsState::onFontCharSetRewritten,
		kEventFontRewritten
	);

	/*
	 * I need to register both released and hold buttons
	 */
	KeypadManager::registerInput(__KEY_RELEASED | __KEY_HOLD);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(this->showAdditionalDetails)
	{
		StatefulActorsState::showAdditionalDetails(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::exit(void* owner __attribute__((unused)))
{
	Printing::unregisterEventListener
	(
		ListenerObject::safeCast(this), (EventListener)StatefulActorsState::onFontCharSetRewritten,
		kEventFontRewritten
	);

	Base::exit(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::processUserInput(const UserInput* userInput)
{
	StatefulActorsState::playSoundEffects(this, userInput, false);
	int32 message = kMessageStatefulActorsStateNoMessage;

	if(K_LL & userInput->holdKey)
	{
		message = kMessageStatefulActorsStateHoldLeft;
	}
	else if(K_LL & userInput->releasedKey)
	{
		message = kMessageStatefulActorsStateReleasedLeft;
	}
	else if(K_LR & userInput->holdKey)
	{
		message = kMessageStatefulActorsStateHoldRight;
	}
	else if(K_LR & userInput->releasedKey)
	{
		message = kMessageStatefulActorsStateReleasedRight;
	}

	if(kMessageStatefulActorsStateNoMessage != message)
	{
		/*
		 * Passing input to actors in this way, while elegant,
		 * is not very performant. Most likely, a way to get a
		 * pointer to the actor that the user controls and calling
		 * an specific method that its class implements would be
		 * way faster.
		 */
		StatefulActorsState::propagateMessage(this, message);
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::showControls()
{
	Printing::text(
		
		__CHAR_SELECT_BUTTON,
		__SCREEN_WIDTH_IN_CHARS - 1,
		__SCREEN_HEIGHT_IN_CHARS - 1,
		NULL
	);
	Printing::text(
		
		__CHAR_L_D_PAD_RIGHT,
		__SCREEN_WIDTH_IN_CHARS - 4,
		__SCREEN_HEIGHT_IN_CHARS - 1,
		NULL
	);
	Printing::text(
		
		__CHAR_L_D_PAD_LEFT,
		__SCREEN_WIDTH_IN_CHARS - 5,
		__SCREEN_HEIGHT_IN_CHARS - 1,
		NULL
	);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::showStuff()
{
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::showExplanation()
{
	int16 y = 3;
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringConceptsSubtitle),
		2,
		y++,
		"DefaultBold"
	);
	Printing::text(I18n::getText(I18n::getInstance(), kStringStatefulActorsLabel), 2, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(), kStringPhysicsLabel), 2, y++, NULL);
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringStateMachinesLabel),
		2,
		y++,
		NULL
	);
	y++;
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringClassesSubtitle),
		2,
		y++,
		"DefaultBold"
	);
	Printing::text("StatefulActor", 2, y++, NULL);
	Printing::text("MessageDispatcher*", 2, y++, NULL);
	Printing::text("Punk", 2, y++, NULL);
	Printing::text("PunkState*", 2, y++, NULL);

	y++;
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringSpecsSubtitle),
		2,
		y++,
		"DefaultBold"
	);
	Printing::text("PunkStatefulActorSpec", 2, y++, NULL);

	y = 3;
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle),
		26,
		y++,
		"DefaultBold"
	);
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringCollisionsLabel),
		26,
		y++,
		NULL
	);
	Printing::text(I18n::getText(I18n::getInstance(), kStringEventsLabel), 26, y++, NULL);
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringMessagingLabel),
		26,
		y++,
		NULL
	);
	y++;
	Printing::text(
		
		I18n::getText(I18n::getInstance(), kStringMethodsSubtitle),
		26,
		y++,
		"DefaultBold"
	);
	Printing::text("StatefulActorsState", 26, y++, NULL);
	Printing::text("::propagateMessage", 26, y++, NULL);
	Printing::text("Punk", 26, y++, NULL);
	Printing::text("::collisionStarts", 26, y++, NULL);
	Printing::text("::handlePropagatedMes\x85", 26, y++, NULL);
	y++;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::showAdditionalDetails()
{
	StatefulActorsState::propagateMessage(this, kMessageStatefulActorsStatePrintStatefulActorStatus);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/StatefulActorsStageSpec.c
	 */
	extern StageROMSpec StatefulActorsStageSpec;
	this->stageSpec = (StageSpec*)&StatefulActorsStageSpec;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void StatefulActorsState::onFontCharSetRewritten(EventListener eventFirer __attribute__((unused)))
{
	StatefulActorsState::show(this, false);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
