/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <string.h>

#include <AnimatedEntity.h>
#include <I18n.h>
#include <Languages.h>
#include <KeypadManager.h>
#include <Messages.h>
#include <Printing.h>
#include <VirtualList.h>

#include "ActorsState.h"


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void ActorsState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);

	// Start animations, physics and messaging clocks
	ActorsState::startClocks(this);

	/*
	 * When CharSets are deleted, defragmentation takes place. If the font CharSets are loaded after
	 * the CharSet being deleted, the printed messages can become garbled. So, we listen for when 
	 * the font CharSets are rewritten.
	 */
	Printing::addEventListener(this->printing, ListenerObject::safeCast(this), (EventListener)ActorsState::onFontCharSetRewritten, kEventFontRewritten);

	/*
	 * I need to register both released and hold buttons
	 */
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_RELEASED | __KEY_HOLD);
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(this->showAdditionalDetails)
	{
		ActorsState::showAdditionalDetails(this);
	}
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::exit(void* owner __attribute__((unused)))
{
	Printing::removeEventListener(this->printing, ListenerObject::safeCast(this), (EventListener)ActorsState::onFontCharSetRewritten, kEventFontRewritten);

	Base::exit(this, owner);
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::processUserInput(const UserInput* userInput)
{
	ActorsState::playSoundEffects(this, userInput, false);
	int32 message = kMessageActorsStateNoMessage;

	if(K_LL & userInput->holdKey)
	{
		message = kMessageActorsStateHoldLeft;
	}
	else if(K_LL & userInput->releasedKey)
	{
		message = kMessageActorsStateReleasedLeft;
	}
	else if(K_LR & userInput->holdKey)
	{
		message = kMessageActorsStateHoldRight;
	}
	else if(K_LR & userInput->releasedKey)
	{
		message = kMessageActorsStateReleasedRight;
	}

	if(kMessageActorsStateNoMessage != message)
	{
		/*
		 * Passing input to entities in this way, while elegant, 
		 * is not very performant. Most likely, a way to get a 
		 * pointer to the entity that the user controls and calling
		 * an specific method that its class implements would be
		 * way faster.
		 */
		ActorsState::propagateMessage(this, message);
	}

	Base::processUserInput(this, userInput);
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::showControls()
{
	Printing::text(this->printing, __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::showStuff()
{}
//---------------------------------------------------------------------------------------------------------
void ActorsState::showExplanation()
{
	int16 y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringActorsLabel), 2, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringPhysicsLabel), 2, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringStateMachinesLabel), 2, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, "Actor", 2, y++, NULL);
	Printing::text(this->printing, "MessageDispatcher*", 2, y++, NULL);
	Printing::text(this->printing, "Punk", 2, y++, NULL);
	Printing::text(this->printing, "PunkState*", 2, y++, NULL);

	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, "PunkActorSpec", 2, y++, NULL);

	y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "Debug");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringCollisionsLabel), 26, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringEventsLabel), 26, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMessagingLabel), 26, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "Debug");
	Printing::text(this->printing, "ActorsState", 26, y++, NULL);
	Printing::text(this->printing, " propagateMessage", 26, y++, NULL);
	Printing::text(this->printing, "Punk", 26, y++, NULL);
	Printing::text(this->printing, " collisionStarts", 26, y++, NULL);
	Printing::text(this->printing, " handlePropagatedMe...", 26, y++, NULL);
	y++;
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::showAdditionalDetails()
{
	ActorsState::propagateMessage(this, kMessageActorsStatePrintActorStatus);
}
//---------------------------------------------------------------------------------------------------------


//=========================================================================================================
// CLASS' PRIVATE METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void ActorsState::constructor()
{
	Base::constructor();

	/*
	 * Check assets/stage/ActorsStageSpec.c"
	 */
	extern StageROMSpec ActorsStageSpec;
	this->stageSpec = (StageSpec*)&ActorsStageSpec;
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::destructor()
{
	// destroy base
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
void ActorsState::onFontCharSetRewritten(EventListener eventFirer __attribute__((unused)))
{
	ActorsState::show(this, false);
}
//---------------------------------------------------------------------------------------------------------
