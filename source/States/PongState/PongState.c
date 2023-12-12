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
#include <GameConfig.h>
#include <GameEvents.h>
#include <I18n.h>
#include <KeypadManager.h>
#include <Languages.h>
#include <MessageDispatcher.h>
#include <Pong.h>
#include <Utilities.h>

#include <debugUtilities.h>
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

void PongState::setVersusMode(bool value)
{
	this->isVersusMode = value;
}

bool PongState::getVersusMode()
{
	return this->isVersusMode;
}

bool PongState::isVersusMode()
{
	return PongState::getVersusMode(this);
}

void PongState::enter(void* owner)
{
	if(PongState::isVersusMode(this))
	{
		// Reset random seed in multiplayer mode so both machines are completely in sync
		Utilities::resetRandomSeed();
	}

	// call base
	Base::enter(this, owner);

	// disable automatic pause in versus mode
	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(), !this->isVersusMode);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// get the game ready
	Pong::getReady(Pong::getInstance(), this->stage);
	
	// set input to be notified about
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);
}

void PongState::exit(void* owner)
{
	// call base
	Base::exit(this, owner);
}

void PongState::processUserInput(const UserInput* userInput)
{
	if(userInput->pressedKey)
	{
		if(K_SEL & userInput->pressedKey)
		{
			// adjustment screen
//				PlatformerLevelState::setModeToPaused(this);

			// set next state of adjustment screen state to null so it can differentiate between
			// being called the splash screen sequence or from within the game (a bit hacky...)
//				SplashScreenState::setNextState(SplashScreenState::safeCast(AdjustmentScreenState::getInstance()), NULL);

			// pause game and switch to adjustment screen state
//				VUEngine::pause(VUEngine::getInstance(), GameState::safeCast(AdjustmentScreenState::getInstance()));

			return;
		}
	}

	if(this->isVersusMode)
	{
		this->opponentData.resumedUserInput.pressedKey = userInput->pressedKey;
		this->opponentData.resumedUserInput.releasedKey = userInput->releasedKey;
		this->opponentData.resumedUserInput.holdKey = userInput->holdKey;

		uint32 sentMessage = kCommunicationMessageSendAndReceiveInput;
		uint32 receivedMessage = sentMessage + 1;

		do
		{
			CommunicationManager::sendAndReceiveData(CommunicationManager::getInstance(), sentMessage, (BYTE*)&this->opponentData, sizeof(this->opponentData));

			receivedMessage = CommunicationManager::getReceivedMessage(CommunicationManager::getInstance());
		}
		while(receivedMessage != sentMessage);

		this->opponentData = *(DataToTransmit*)CommunicationManager::getReceivedData(CommunicationManager::getInstance());
	}

	PongState::fireEvent(this, kEventUserInput);

	Base::processUserInput(this, userInput);
}

bool PongState::processUserInputRegardlessOfInput()
{
	return true;
}

ResumedUserInput PongState::getOpponentInput()
{
	return this->opponentData.resumedUserInput;
}

