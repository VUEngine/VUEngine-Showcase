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

#include <CommunicationManager.h>
#include <GameEvents.h>
#include <KeypadManager.h>
#include <Messages.h>
#include <MessageDispatcher.h>
#include <PongPaddle.h>
#include <PongState.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <Sounds.h>
#include <SoundManager.h>
#include <Utilities.h>
#include <VirtualList.h>
#include <VUEngine.h>

#include "Pong.h"


//=========================================================================================================
// CLASS' MACROS
//=========================================================================================================

#define SCORE_MULTIPLIER_THRESHOLD					5
#define BONUS_INCREMENT_DELAY						100
#define SCORE_MULTIPLIER_TO_ENABLE_BONUS			10

#define PONG_NO_COMMAND								0x00
#define PONG_SYNC_WITH_REMOTE						0x78
#define PONG_SEND_USER_INPUT						0xAB
#define PONG_REMOTE_GO_AWAY							0x3C


//=========================================================================================================
// CLASS' DATA
//=========================================================================================================

typedef struct CondensedUserInput
{
	// Currently pressed key(s)
	uint16 pressedKey;

	// Released key(s)
	uint16 releasedKey;
	
	// Hold key(s)
	uint16 holdKey;

} CondensedUserInput;


typedef struct RemotePlayerData
{
	uint32 command;

	CondensedUserInput condensedUserInput;

} RemotePlayerData;


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void Pong::getReady(Stage stage, bool isVersusMode)
{
	this->isVersusMode = isVersusMode;

	VirtualList::clear(this->playerPaddles);
	VirtualList::clear(this->opponentPaddles);
	this->leftScore = 0;
	this->rightScore = 0;
	this->pongBall = NULL;
	this->messageForRemote = kMessagePongSync;
	this->allowPaddleMovement = false;
	this->remoteHoldKey = 0;
	
	if(isDeleted(stage))
	{
		return;	
	}

	this->playerNumber = kPlayerAlone;

	if(isVersusMode)
	{
		if(CommunicationManager::isMaster(CommunicationManager::getInstance()))
		{
			this->playerNumber = kPlayerOne;
		}
		else
		{
			this->playerNumber = kPlayerTwo;
		}
	}

	if(kPlayerAlone == this->playerNumber)
	{
		VirtualList::pushBack(this->playerPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_LEFT_NAME, true)));
		VirtualList::pushBack(this->playerPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_RIGHT_NAME, true)));
		NM_ASSERT(2 == VirtualList::getCount(this->playerPaddles), "Pong::getReady: not all paddles found");
	}
	else if(kPlayerOne == this->playerNumber)
	{
		VirtualList::pushBack(this->playerPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_LEFT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getCount(this->playerPaddles), "Pong::getReady: didn't find left paddle");
		VirtualList::pushBack(this->opponentPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_RIGHT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getCount(this->playerPaddles), "Pong::getReady: didn't find right paddle");
	}
	else if(kPlayerTwo == this->playerNumber)
	{
		VirtualList::pushBack(this->playerPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_RIGHT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getCount(this->playerPaddles), "Pong::getReady: didn't find right paddle");
		VirtualList::pushBack(this->opponentPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_LEFT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getCount(this->opponentPaddles), "Pong::getReady: didn't find left paddle");
	}

	this->pongBall = PongBall::safeCast(Stage::getChildByName(PongState::getStage(PongState::getInstance()), (char*)PONG_BALL_NAME, false));
}
//---------------------------------------------------------------------------------------------------------
bool Pong::isVersusMode()
{
	return this->isVersusMode;
}
//---------------------------------------------------------------------------------------------------------
void Pong::processUserInput(const UserInput* userInput)
{
	if((K_LT | K_RT) & userInput->releasedKey)
	{
		this->messageForRemote = kMessagePongGoodBye;			
	}

	this->allowPaddleMovement = false;
	this->remoteHoldKey = 0;

	/*
	 * This call will sync both systems. The approach in this example is to get both
	 * systems to follow the same code paths and only transmit the user input. So,
	 * both are at the end of each frame in the same state. It is possible to run
	 * the game in one and send the data to the other so this only shows it.
	 */
	Pong::syncWithRemote(this, userInput);

	if(this->allowPaddleMovement)
	{
		if(0 != userInput->holdKey)
		{
			Pong::onKeyHold(this, userInput->holdKey, this->playerPaddles);
		}

		if(0 != this->remoteHoldKey)
		{
			Pong::onKeyHold(this, this->remoteHoldKey, this->opponentPaddles);
		}
	}
}
//---------------------------------------------------------------------------------------------------------
int Pong::getPlayerNumber()
{
	return this->playerNumber;
}
//---------------------------------------------------------------------------------------------------------
void Pong::printScore()
{
	int16 y = 26;
	PRINT_TEXT("P1:	  ", 1, y);
	PRINT_INT(this->leftScore, 1 + 5 - Math::getDigitsCount(this->leftScore), y);

	PRINT_TEXT("P2:	  ", __SCREEN_WIDTH_IN_CHARS - 1 - 5, y);
	PRINT_INT(this->rightScore, __SCREEN_WIDTH_IN_CHARS - 1 - Math::getDigitsCount(this->rightScore), y);
}
//---------------------------------------------------------------------------------------------------------

//=========================================================================================================
// CLASS' PRIVATE METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void Pong::constructor()
{
	Base::constructor();

	this->pongBall = NULL;
	this->playerPaddles = new VirtualList();
	this->opponentPaddles = new VirtualList();

	this->isVersusMode = false;
	this->leftScore = 0;
	this->rightScore = 0;
	this->messageForRemote = kMessagePongSync;
	this->allowPaddleMovement = false;
	this->remoteHoldKey = 0;

	Pong::addEventListener(this, ListenerObject::safeCast(this), (EventListener)Pong::onPongBallOutOfBounds, kEventPongBallStreamedOut);
	Pong::addEventListener(this, ListenerObject::safeCast(this), (EventListener)Pong::onPongBallSpawned, kEventPongBallSpawned);
}
//---------------------------------------------------------------------------------------------------------
void Pong::destructor()
{
	Pong::removeEventListener(this, ListenerObject::safeCast(this), (EventListener)Pong::onPongBallOutOfBounds, kEventPongBallStreamedOut);
	Pong::removeEventListener(this, ListenerObject::safeCast(this), (EventListener)Pong::onPongBallSpawned, kEventPongBallSpawned);

	this->pongBall = NULL;
	delete this->playerPaddles;
	this->playerPaddles = NULL;
	delete this->opponentPaddles;
	this->opponentPaddles = NULL;

	// allow a new construct
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
bool Pong::onPongBallSpawned(ListenerObject eventFirer __attribute__ ((unused)))
{
	this->pongBall = PongBall::safeCast(Stage::getChildByName(PongState::getStage(PongState::getInstance()), (char*)PONG_BALL_NAME, false));

	this->messageForRemote = kMessagePongSync;

	return true;
}
//---------------------------------------------------------------------------------------------------------
uint32 Pong::getCommunicationCommand(uint32 message)
{
	switch(message)
	{
		case kMessagePongSync:

			return PONG_SYNC_WITH_REMOTE;

		case kMessagePongSendInput:

			return PONG_SEND_USER_INPUT;

		case kMessagePongGoodBye:

			return PONG_REMOTE_GO_AWAY;
	}

	return PONG_NO_COMMAND;
}
//---------------------------------------------------------------------------------------------------------
bool Pong::isMessageValid(uint32 message, uint8 command)
{
	return Pong::getCommunicationCommand(this, message) == command;
}
//---------------------------------------------------------------------------------------------------------
void Pong::syncWithRemote(const UserInput* userInput)
{
	/*
	 * A command is used to verify that the received message and the data
	 * are valid.
	 */
	uint8 command = Pong::getCommunicationCommand(this, this->messageForRemote);

	/*
	 * This is the struct that we are going to send down the link port.
	 */
	RemotePlayerData remotePlayerData;

	remotePlayerData.command = command;
	remotePlayerData.condensedUserInput.pressedKey = userInput->pressedKey;
	remotePlayerData.condensedUserInput.releasedKey = userInput->releasedKey;
	remotePlayerData.condensedUserInput.holdKey = userInput->holdKey;

	Pong::transmitData(this, this->messageForRemote, (BYTE*)&remotePlayerData, sizeof(remotePlayerData));
}
//---------------------------------------------------------------------------------------------------------
void Pong::transmitData(uint32 messageForRemote, BYTE* data, uint32 dataBytes)
{
	uint32 receivedMessage = kMessagePongDummy;
	const RemotePlayerData* remotePlayerData = NULL;
	CommunicationManager communicationManager = CommunicationManager::getInstance();

	/*
	 * Data will be send sychroniously. This means that if the cable is disconnect during
	 * transmission, the behavior is undefined.
	 */
	do
	{
		/*
		 * Data transmission can fail if there was already a request to send data.
		 */
		if(!CommunicationManager::sendAndReceiveData(communicationManager, messageForRemote, data, dataBytes))
		{
			/*
			 * In this case, simply cancel all communications and try again. This supposes
			 * that there are no other calls that could cause a race condition.
			 */
			CommunicationManager::cancelCommunications(communicationManager);
		}

		/*
		 * Every transmission sends a control message and then the data itself.
		 */
		receivedMessage = CommunicationManager::getReceivedMessage(communicationManager);
		remotePlayerData = (const RemotePlayerData*)CommunicationManager::getReceivedData(communicationManager);
	}
	/*
	 * The validity of the message is based on the command that was received
	 */
	while(!Pong::isMessageValid(this, receivedMessage, remotePlayerData->command));

	Pong::processReceivedMessage(this, messageForRemote, receivedMessage, remotePlayerData);
}
//---------------------------------------------------------------------------------------------------------
void Pong::processReceivedMessage(uint32 messageForRemote, uint32 receivedMessage, const RemotePlayerData* remotePlayerData)
{
	/*
	 * When both systems send the same message, they are in sync. If the received
	 * message differs from what I've sent, then update appropriately the message 
	 * that I will send in the next cycle.
	 */
	switch(receivedMessage)
	{
		case kMessagePongSync:

			if(kMessagePongSync == messageForRemote)
			{
				Pong::fireEvent(this, kEventPongRemoteInSync);
		
				this->messageForRemote = kMessagePongSendInput;
			}
			else
			{
				this->messageForRemote = kMessagePongSync;
			}

			break;

		case kMessagePongSendInput:

			if(kMessagePongSendInput == messageForRemote)
			{
				this->remoteHoldKey = remotePlayerData->condensedUserInput.holdKey;
				this->allowPaddleMovement = true;
			}
			else if(kMessagePongSync == messageForRemote)
			{
				this->messageForRemote = kMessagePongSync;
			}

			break;

		case kMessagePongGoodBye:

			Pong::fireEvent(this, kEventPongRemoteWentAway);
			
			this->messageForRemote = kMessagePongSync;
			break;
	}
}
//---------------------------------------------------------------------------------------------------------
void Pong::onKeyHold(uint16 holdKey, VirtualList paddles)
{
	NormalizedDirection normalizedDirection =
	{
		0,
		0,
		0
	};

	if((K_LU | K_RU) & holdKey)
	{
		normalizedDirection.y = __UP;
		PongPaddle::moveTowards(VirtualList::front(paddles), normalizedDirection);
	}
	else if((K_LD | K_RD) & holdKey)
	{
		normalizedDirection.y = __DOWN;
		PongPaddle::moveTowards(VirtualList::front(paddles), normalizedDirection);
	}
}
//---------------------------------------------------------------------------------------------------------
bool Pong::onPongBallOutOfBounds(ListenerObject eventFirer __attribute__ ((unused)))
{
	if(!isDeleted(this->pongBall))
	{
		if(0 < PongBall::getPosition(this->pongBall)->x)
		{
			if(99 > this->leftScore)
			{
				this->leftScore++;			
			}
		}
		else
		{
			if(99 > this->rightScore)
			{
				this->rightScore++;			
			}
		}

		this->pongBall = NULL;
	}	

	Pong::printScore(this);

	RumbleManager::startEffect(&PointRumbleEffectSpec);

	SoundManager::playSound
	(
		SoundManager::getInstance(), 
		&Point1SoundSpec, 
		NULL, 
		kSoundPlaybackNormal,
		NULL, 
		NULL
	);

	return true;
}
//---------------------------------------------------------------------------------------------------------
