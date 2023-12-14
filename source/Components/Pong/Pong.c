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

#include <Pong.h>

#include <CommunicationManager.h>
#include <GameConfig.h>
#include <GameEvents.h>
#include <KeypadManager.h>
#include <MessageDispatcher.h>
#include <PongPaddle.h>
#include <PongState.h>
#include <Sounds.h>
#include <SoundManager.h>
#include <Utilities.h>
#include <VirtualList.h>
#include <VUEngine.h>

#include <debugUtilities.h>

//---------------------------------------------------------------------------------------------------------
//											CLASS'S MACROS
//---------------------------------------------------------------------------------------------------------

#define SCORE_MULTIPLIER_THRESHOLD					5
#define BONUS_INCREMENT_DELAY						100
#define SCORE_MULTIPLIER_TO_ENABLE_BONUS			10

#define PONG_NO_COMMAND								0x00
#define PONG_SYNC_WITH_REMOTE						0x78
#define PONG_SEND_USER_INPUT						0xAB
#define PONG_REMOTE_GO_AWAY							0x3C


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
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
	this->messageForRemote = kPongMessageSync;
	this->allowPaddleMovement = false;
	this->remoteHoldKey = 0;

	Pong::addEventListener(this, ListenerObject::safeCast(this), (EventListener)Pong::onPongBallOutOfBounds, kEventPongBallStreamedOut);
	Pong::addEventListener(this, ListenerObject::safeCast(this), (EventListener)Pong::onPongBallSpawned, kEventPongBallSpawned);
}

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

void Pong::getReady(Stage stage, bool isVersusMode)
{
	this->isVersusMode = isVersusMode;

	VirtualList::clear(this->playerPaddles);
	VirtualList::clear(this->opponentPaddles);
	this->leftScore = 0;
	this->rightScore = 0;
	this->pongBall = NULL;
	this->messageForRemote = kPongMessageSync;
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
		NM_ASSERT(2 == VirtualList::getSize(this->playerPaddles), "Pong::getReady: not all paddles found");
	}
	else if(kPlayerOne == this->playerNumber)
	{
		VirtualList::pushBack(this->playerPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_LEFT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getSize(this->playerPaddles), "Pong::getReady: didn't find left paddle");
		VirtualList::pushBack(this->opponentPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_RIGHT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getSize(this->playerPaddles), "Pong::getReady: didn't find right paddle");
	}
	else if(kPlayerTwo == this->playerNumber)
	{
		VirtualList::pushBack(this->playerPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_RIGHT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getSize(this->playerPaddles), "Pong::getReady: didn't find right paddle");
		VirtualList::pushBack(this->opponentPaddles, PongPaddle::safeCast(Stage::getChildByName(stage, (char*)PADDLE_LEFT_NAME, false)));
		NM_ASSERT(1 == VirtualList::getSize(this->opponentPaddles), "Pong::getReady: didn't find left paddle");
	}

	this->pongBall = PongBall::safeCast(Stage::getChildByName(PongState::getStage(PongState::getInstance()), (char*)PONG_BALL_NAME, false));
}

bool Pong::isVersusMode()
{
	return this->isVersusMode;
}

void Pong::onPongBallSpawned(ListenerObject eventFirer __attribute__ ((unused)))
{
	this->pongBall = PongBall::safeCast(Stage::getChildByName(PongState::getStage(PongState::getInstance()), (char*)PONG_BALL_NAME, false));

	this->messageForRemote = kPongMessageSync;
}

// process user input
void Pong::processUserInput(const UserInput* userInput)
{
	if((K_LT | K_RT) & userInput->releasedKey)
	{
		this->messageForRemote = kPongMessageGoodBye;			
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

static uint32 Pong::getCommunicationCommand(uint32 message)
{
	switch(message)
	{
		case kPongMessageSync:

			return PONG_SYNC_WITH_REMOTE;

		case kPongMessageSendInput:

			return PONG_SEND_USER_INPUT;

		case kPongMessageGoodBye:

			return PONG_REMOTE_GO_AWAY;
	}

	return PONG_NO_COMMAND;
}

bool Pong::isMessageValid(uint32 message, uint8 command)
{
	return Pong::getCommunicationCommand(message) == command;
}

void Pong::syncWithRemote(const UserInput* userInput)
{
	/*
	 * A command is used to verify that the received message and the data
	 * are valid.
	 */
	uint8 command = Pong::getCommunicationCommand(this->messageForRemote);

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

void Pong::transmitData(uint32 messageForRemote, BYTE* data, uint32 dataBytes)
{
	uint32 receivedMessage = kPongMessageDummy;
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

void Pong::processReceivedMessage(uint32 messageForRemote, uint32 receivedMessage, const RemotePlayerData* remotePlayerData)
{
	/*
	 * When both systems send the same message, they are in sync. If the received
	 * message differs from what I've sent, then update appropriately the message 
	 * that I will send in the next cycle.
	 */
	switch(receivedMessage)
	{
		case kPongMessageSync:

			if(kPongMessageSync == messageForRemote)
			{
				Pong::fireEvent(this, kEventPongRemoteInSync);
		
				this->messageForRemote = kPongMessageSendInput;
			}
			else
			{
				this->messageForRemote = kPongMessageSync;
			}

			break;

		case kPongMessageSendInput:

			if(kPongMessageSendInput == messageForRemote)
			{
				this->remoteHoldKey = remotePlayerData->condensedUserInput.holdKey;
				this->allowPaddleMovement = true;
			}
			else if(kPongMessageSync == messageForRemote)
			{
				this->messageForRemote = kPongMessageSync;
			}

			break;

		case kPongMessageGoodBye:

			Pong::fireEvent(this, kEventPongRemoteWentAway);
			
			this->messageForRemote = kPongMessageSync;
			break;
	}
}

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

void Pong::onPongBallOutOfBounds(ListenerObject eventFirer __attribute__ ((unused)))
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

	SoundManager::playSound
	(
		SoundManager::getInstance(), 
		&PointSound, 
		kPlayAll, 
		NULL, 
		kSoundWrapperPlaybackNormal,
		NULL, 
		NULL
	);
}

int Pong::getPlayerNumber()
{
	return this->playerNumber;
}


void Pong::printScore()
{
	int16 y = 26;
	PRINT_TEXT("P1:	  ", 1, y);
	PRINT_INT(this->leftScore, 1 + 5 - Utilities::getDigitsCount(this->leftScore), y);

	PRINT_TEXT("P2:	  ", __SCREEN_WIDTH_IN_CHARS - 1 - 5, y);
	PRINT_INT(this->rightScore, __SCREEN_WIDTH_IN_CHARS - 1 - Utilities::getDigitsCount(this->rightScore), y);
}
