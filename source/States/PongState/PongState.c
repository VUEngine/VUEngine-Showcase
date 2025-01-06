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

#include <AutomaticPauseManager.h>
#include <CommunicationManager.h>
#include <Camera.h>
#include <GameEvents.h>
#include <GameSaveDataManager.h>
#include <I18n.h>
#include <KeypadManager.h>
#include <Languages.h>
#include <MessageDispatcher.h>
#include <Messages.h>
#include <BodyManager.h>
#include <Printing.h>
#include <Pong.h>
#include <Utilities.h>

#include "PongState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::enter(void* owner)
{
	Base::enter(this, owner);

	// Disable automatic pause in versus mode
	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), false);

	// Get the game ready
	Pong::getReady(Pong::getInstance(), this->stage, false);

	Pong::addEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteInSync, kEventPongRemoteInSync);
	Pong::addEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteGoneAway, kEventPongRemoteWentAway);

	// Set input to be notified about
	KeypadManager::registerInput(__KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);

	// Enable comms	
	CommunicationManager::enableCommunications((EventListener)PongState::onCommunicationsEstablished, ListenerObject::safeCast(this));

	// Make sure that the processing of user input is triggered regardless of real user input
	KeypadManager::enableDummyKey();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::exit(void* owner)
{
	Pong::removeEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteInSync, kEventPongRemoteInSync);
	Pong::removeEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteGoneAway, kEventPongRemoteWentAway);

	PongState::setVersusMode(this, false);
	CommunicationManager::disableCommunications();

	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), GameSaveDataManager::getAutomaticPauseStatus(GameSaveDataManager::getInstance()));

	Base::exit(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::processUserInput(const UserInput* userInput)
{
	if(0 == (K_SEL & userInput->releasedKey))
	{
		PongState::playSoundEffects(this, userInput, true);
	}

	if(PongState::isVersusMode(this))
	{
		Pong::processUserInput(Pong::getInstance(), userInput);
	}

	if(K_SEL & userInput->releasedKey)
	{
		return;
	}
	
	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongState::isVersusMode()
{
	return this->isVersusMode;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::showControls()
{
	Printing::clearRow(__SCREEN_HEIGHT_IN_CHARS - 1);

	if(this->isVersusMode)
	{
		Printing::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		switch(Pong::getPlayerNumber(Pong::getInstance()))
		{
			case kPlayerOne:

				Printing::text(__CHAR_L_D_PAD_DOWN, 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				Printing::text(__CHAR_L_D_PAD_UP, 2, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				break;

			case kPlayerTwo:

				Printing::text(__CHAR_L_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				Printing::text(__CHAR_L_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				break;
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::showStuff()
{}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::showExplanation()
{
	int16 y = 3;
	Printing::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printing::text(I18n::getText(I18n::getInstance(), kStringCommunicationsLabel), 2, y++, NULL);

	y++;
	Printing::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printing::text("CommunicationManager", 2, y++, NULL);
	Printing::text("Pong*", 2, y++, NULL);

	y = 3;
	Printing::text(I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printing::text(I18n::getText(I18n::getInstance(), kStringCollisionsLabel), 26, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(), kStringEventsLabel), 26, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(), kStringMessagingLabel), 26, y++, NULL);

	y = 19;

	Printing::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 26, y++, "DefaultBold");
	Printing::text("PongBallActorSpec", 26, y++, NULL);
	Printing::text("PongPaddleActorSpec", 26, y++, NULL);

	y = 19;
	Printing::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "DefaultBold");
	Printing::text("Pong", 2, y++, NULL);
	Printing::text("::syncWithRemote", 2, y++, NULL);
	Printing::text("::transmitData", 2, y++, NULL);
	Printing::text("::processReceivedMessage", 2, y++, NULL);
	y++;

	PongState::showConnectivityStatus(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::showAdditionalDetails()
{
	Pong::printScore(Pong::getInstance());
	PongState::showConnectivityStatus(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/PongStageSpec.c
	 */
	extern StageROMSpec PongStageSpec;
	this->stageSpec = (StageSpec*)&PongStageSpec;
	this->isVersusMode = false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::showConnectivityStatus()
{
	Printing::text("                              ", 10, __SCREEN_HEIGHT_IN_CHARS - 3, "DefaultBold");
	if(CommunicationManager::isConnected())
	{
		const char* strConnected = I18n::getText(I18n::getInstance(), kStringConnected);
		FontSize strConnectedTextSize = Printing::getTextSize(strConnected, "DefaultBold");
		Printing::text(
			
			strConnected, 
			(__HALF_SCREEN_WIDTH_IN_CHARS) - (strConnectedTextSize.x >> 1), 
			__SCREEN_HEIGHT_IN_CHARS - 3, 
			"DefaultBold"
		);
	}
	else	
	{
		const char* strNoLink = I18n::getText(I18n::getInstance(), kStringNoLink);
		FontSize strNoLinkTextSize = Printing::getTextSize(strNoLink, "DefaultBold");
		Printing::text(
			
			strNoLink, 
			(__HALF_SCREEN_WIDTH_IN_CHARS) - (strNoLinkTextSize.x >> 1), 
			__SCREEN_HEIGHT_IN_CHARS - 3, 
			"DefaultBold"
		);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongState::onCommunicationsEstablished(ListenerObject eventFirer __attribute__((unused)))
{	
	PongState::setVersusMode(this, true);
	Pong::getReady(Pong::getInstance(), this->stage, true);

	this->showAdditionalDetails = true;
	PongState::show(this, false);

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongState::setVersusMode(bool value)
{
	this->isVersusMode = value;
	this->showAdditionalDetails = value;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongState::onRemoteInSync(ListenerObject eventFirer __attribute__((unused)))
{
	// Reset random seed in multiplayer mode so both machines are completely in sync
	Math::resetRandomSeed();

	// Must reset the physical world too
	BodyManager::reset(this->bodyManager);

	// Must reset the clocks
	PongState::startClocks(this);
	
	// Reset the actors
	PongState::propagateMessage(this, kMessagePongResetPositions);

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongState::onRemoteGoneAway(ListenerObject eventFirer __attribute__((unused)))
{
	CommunicationManager::disableCommunications();

	PongState::setVersusMode(this, false);
	Pong::getReady(Pong::getInstance(), this->stage, false);
	PongState::show(this, false);
	PongState::propagateMessage(this, kMessagePongResetPositions);

	CommunicationManager::enableCommunications((EventListener)PongState::onCommunicationsEstablished, ListenerObject::safeCast(this));

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
