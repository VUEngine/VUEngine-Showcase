/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------


#include <PongState.h>

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
#include <PhysicalWorld.h>
#include <Printing.h>
#include <Pong.h>
#include <Utilities.h>

#include <DebugUtilities.h>
#include <string.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec PongStage;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void PongState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&PongStage;
	this->isVersusMode = false;
}

void PongState::destructor()
{
	// destroy base
	Base::destructor();
}

void PongState::enter(void* owner)
{
	// call base
	Base::enter(this, owner);

	// disable automatic pause in versus mode
	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), false);

	// get the game ready
	Pong::getReady(Pong::getInstance(), this->stage, false);

	Pong::addEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteInSync, kEventPongRemoteInSync);
	Pong::addEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteGoneAway, kEventPongRemoteWentAway);

	// set input to be notified about
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);

	// enable comms	
	CommunicationManager::enableCommunications(CommunicationManager::getInstance(), (EventListener)PongState::onCommunicationsEstablished, ListenerObject::safeCast(this), 100);
}

void PongState::exit(void* owner)
{
	Pong::removeEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteInSync, kEventPongRemoteInSync);
	Pong::removeEventListener(Pong::getInstance(), ListenerObject::safeCast(this), (EventListener)PongState::onRemoteGoneAway, kEventPongRemoteWentAway);

	PongState::setVersusMode(this, false);
	CommunicationManager::disableCommunications(CommunicationManager::getInstance());

	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), GameSaveDataManager::getAutomaticPauseStatus(GameSaveDataManager::getInstance()));

	Base::exit(this, owner);
}

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

bool PongState::processUserInputRegardlessOfInput()
{
	return true;
}

void PongState::showControls()
{
	Printing::clearRow(Printing::getInstance(), __SCREEN_HEIGHT_IN_CHARS - 1);

	if(this->isVersusMode)
	{
		Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		switch(Pong::getPlayerNumber(Pong::getInstance()))
		{
			case kPlayerOne:

				Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_DOWN, 3, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_UP, 2, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				break;

			case kPlayerTwo:

				Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
				break;
		}
	}
}

void PongState::showStuff()
{
}

void PongState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "Debug");
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringCommunicationsLabel), 2, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "CommunicationManager", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Pong*", 2, y++, NULL);

	y = 3;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "Debug");
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringCollisionsLabel), 26, y++, NULL);
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringEventsLabel), 26, y++, NULL);
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringMessagingLabel), 26, y++, NULL);

	y = 19;

	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "PongBallSpec", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "PongPaddleSpec", 26, y++, NULL);

	y = 19;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Pong", 2, y++, NULL);
	Printing::text(Printing::getInstance(), " syncWithRemote", 2, y++, NULL);
	Printing::text(Printing::getInstance(), " transmitData", 2, y++, NULL);
	Printing::text(Printing::getInstance(), " processReceived..", 2, y++, NULL);
	y++;

	PongState::showConnectivityStatus(this);
}

void PongState::showAdditionalDetails()
{
	Pong::printScore(Pong::getInstance());
	PongState::showConnectivityStatus(this);
}

void PongState::showConnectivityStatus()
{
	if(CommunicationManager::isConnected(CommunicationManager::getInstance()))
	{
		Printing::text(Printing::getInstance(), "CONNECTED", 19, __SCREEN_HEIGHT_IN_CHARS - 1, "Debug");
	}
	else	
	{
		Printing::text(Printing::getInstance(), " NO LINK ", 20, __SCREEN_HEIGHT_IN_CHARS - 1, "Debug");
	}
}

void PongState::onCommunicationsEstablished(ListenerObject eventFirer __attribute__((unused)))
{	
	PongState::setVersusMode(this, true);
	Pong::getReady(Pong::getInstance(), this->stage, true);

	this->showAdditionalDetails = true;
	PongState::show(this, false);
}

void PongState::setVersusMode(bool value)
{
	this->isVersusMode = value;
	this->showAdditionalDetails = value;
}

bool PongState::getVersusMode()
{
	return this->isVersusMode;
}

bool PongState::isVersusMode()
{
	return PongState::getVersusMode(this);
}

void PongState::onRemoteInSync(ListenerObject eventFirer __attribute__((unused)))
{
	// Reset random seed in multiplayer mode so both machines are completely in sync
	Utilities::resetRandomSeed();

	// Must reset the physical world too
	PhysicalWorld::reset(this->physicalWorld);

	// Must reset the clocks
	PongState::startClocks(this);
	
	// Reset the entities
	PongState::propagateMessage(this, kMessagePongResetPositions);
}

void PongState::onRemoteGoneAway(ListenerObject eventFirer __attribute__((unused)))
{
	CommunicationManager::disableCommunications(CommunicationManager::getInstance());

	PongState::setVersusMode(this, false);
	Pong::getReady(Pong::getInstance(), this->stage, false);
	PongState::show(this, false);
	PongState::propagateMessage(this, kMessagePongResetPositions);

	CommunicationManager::enableCommunications(CommunicationManager::getInstance(), (EventListener)PongState::onCommunicationsEstablished, ListenerObject::safeCast(this), 100);
}
