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
#include <BodyManager.h>
#include <CommunicationManager.h>
#include <Camera.h>
#include <GameEvents.h>
#include <GameSaveDataManager.h>
#include <I18n.h>
#include <KeypadManager.h>
#include <Languages.h>
#include <MessageDispatcher.h>
#include <Messages.h>
#include <Printer.h>
#include <PongManager.h>
#include <Singleton.h>
#include <Utilities.h>

#include "CommunicationsState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool CommunicationsState::onEvent(ListenerObject eventFirer, uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventPongRemoteInSync:
		{
			this->showAdditionalDetails = true;
			CommunicationsState::show(this, false);
			return true;
		}

		case kEventPongRemoteWentAway:
		{
			this->showAdditionalDetails = false;
			CommunicationsState::show(this, false);
			return true;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::enter(void* owner)
{
	Base::enter(this, owner);

	// Configure the pong manager
	this->pongManager = new PongManager(this->stage);
	PongManager::addEventListener(this->pongManager, ListenerObject::safeCast(this), kEventPongRemoteInSync);
	PongManager::addEventListener(this->pongManager, ListenerObject::safeCast(this), kEventPongRemoteWentAway);

	// Disable automatic pause in versus mode
	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), false);

	// Start physics, animations, etc
	CommunicationsState::startClocks(this);

	// Set input to be notified about
	KeypadManager::registerInput(__KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);

	// Make sure that the processing of user input is triggered regardless of real user input
	KeypadManager::enableDummyKey();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::exit(void* owner)
{
	if(!isDeleted(this->pongManager))
	{
		delete this->pongManager;
	}	

	this->pongManager = NULL;

	AutomaticPauseManager::setActive
	(
		AutomaticPauseManager::getInstance(), GameSaveDataManager::getAutomaticPauseStatus(GameSaveDataManager::getInstance())
	);

	Base::exit(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::processUserInput(const UserInput* userInput)
{
	if(0 == (K_SEL & userInput->releasedKey))
	{
		CommunicationsState::playSoundEffects(this, userInput);
	}

	if(K_SEL & userInput->releasedKey)
	{
		return;
	}

	if(!isDeleted(this->pongManager))
	{
		PongManager::processUserInput(this->pongManager, userInput);
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::showControls()
{
	Printer::clearRow(__SCREEN_HEIGHT_IN_CHARS - 1);

	if(!isDeleted(this->pongManager))
	{
		if(CommunicationManager::isConnected(CommunicationManager::getInstance()))
		{
			Printer::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

			switch(PongManager::getPlayerNumber(this->pongManager))
			{
				case kPlayerOne:

					Printer::text(__CHAR_L_D_PAD_DOWN, 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
					Printer::text(__CHAR_L_D_PAD_UP, 2, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
					break;

				case kPlayerTwo:

					Printer::text(__CHAR_L_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
					Printer::text(__CHAR_L_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
					break;
			}
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::showStuff()
{}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::showExplanation()
{
	int16 y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printer::text(I18n::getText(I18n::getInstance(), kStringCommunicationsLabel), 2, y++, NULL);

	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printer::text("CommunicationManager", 2, y++, NULL);
	Printer::text("Pong*", 2, y++, NULL);

	y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printer::text(I18n::getText(I18n::getInstance(), kStringCollisionsLabel), 26, y++, NULL);
	Printer::text(I18n::getText(I18n::getInstance(), kStringEventsLabel), 26, y++, NULL);
	Printer::text(I18n::getText(I18n::getInstance(), kStringMessagingLabel), 26, y++, NULL);

	y = 19;

	Printer::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 26, y++, "DefaultBold");
	Printer::text("PongBallActorSpec", 26, y++, NULL);
	Printer::text("PongPaddleActorSpec", 26, y++, NULL);

	y = 19;
	Printer::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "DefaultBold");
	Printer::text("Pong", 2, y++, NULL);
	Printer::text("::syncWithRemote", 2, y++, NULL);
	Printer::text("::transmitData", 2, y++, NULL);
	Printer::text("::processReceivedMessage", 2, y++, NULL);
	y++;

	CommunicationsState::showConnectivityStatus(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::showAdditionalDetails()
{
	CommunicationsState::showConnectivityStatus(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/CommunicationsStageSpec.c
	 */
	extern StageROMSpec CommunicationsStageSpec;
	this->stageSpec = (StageSpec*)&CommunicationsStageSpec;

	this->pongManager = NULL;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void CommunicationsState::showConnectivityStatus()
{
	Printer::text("                              ", 10, __SCREEN_HEIGHT_IN_CHARS - 3, "DefaultBold");

	if(CommunicationManager::isConnected(CommunicationManager::getInstance()))
	{
		const char* strConnected = I18n::getText(I18n::getInstance(), kStringConnected);
		FontSize strConnectedTextSize = Printer::getTextSize(strConnected, "DefaultBold");
		Printer::text
		(
			
			strConnected, 
			(__HALF_SCREEN_WIDTH_IN_CHARS) - (strConnectedTextSize.x >> 1), 
			__SCREEN_HEIGHT_IN_CHARS - 3, 
			"DefaultBold"
		);
	}
	else	
	{
		const char* strNoLink = I18n::getText(I18n::getInstance(), kStringNoLink);
		FontSize strNoLinkTextSize = Printer::getTextSize(strNoLink, "DefaultBold");
		Printer::text
		(
			
			strNoLink, 
			(__HALF_SCREEN_WIDTH_IN_CHARS) - (strNoLinkTextSize.x >> 1), 
			__SCREEN_HEIGHT_IN_CHARS - 3, 
			"DefaultBold"
		);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
