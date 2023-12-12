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

	this->leftScore = 0;
	this->rightScore = 0;
	this->messageForRemote = kPongMessageSync;
}

void Pong::destructor()
{
	ListenerObject::removeEventListener(PongState::getInstance(), ListenerObject::safeCast(this), (EventListener)Pong::onPongBallOutOfBounds, kEventPongBallStreamedOut);
	ListenerObject::removeEventListener(PongState::getInstance(), ListenerObject::safeCast(this), (EventListener)Pong::onPongBallSpawned, kEventPongBallSpawned);

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
	if(isVersusMode)
	{
		// Reset random seed in multiplayer mode so both machines are completely in sync
		Utilities::resetRandomSeed();
	}

	if(!isDeleted(this->pongBall))
	{
		PongBall::deleteMyself(this->pongBall);

	}

	VirtualList::clear(this->playerPaddles);
	VirtualList::clear(this->opponentPaddles);
	this->leftScore = 0;
	this->rightScore = 0;
	this->pongBall = NULL;
	this->messageForRemote = kPongMessageSync;
	
	ListenerObject::removeEventListener(PongState::getInstance(), ListenerObject::safeCast(this), (EventListener)Pong::onPongBallOutOfBounds, kEventPongBallStreamedOut);
	ListenerObject::removeEventListener(PongState::getInstance(), ListenerObject::safeCast(this), (EventListener)Pong::onPongBallSpawned, kEventPongBallSpawned);

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

	ListenerObject::addEventListener(PongState::getInstance(), ListenerObject::safeCast(this), (EventListener)Pong::onPongBallOutOfBounds, kEventPongBallStreamedOut);
	ListenerObject::addEventListener(PongState::getInstance(), ListenerObject::safeCast(this), (EventListener)Pong::onPongBallSpawned, kEventPongBallSpawned);

	PongState::propagateMessage(PongState::getInstance(), kPongMessageResetPositions);

	Pong::printScore(this);
}

void Pong::onPongBallSpawned(ListenerObject eventFirer __attribute__ ((unused)))
{
	NM_ASSERT(PongState::safeCast(eventFirer), "Pong::onPongBallSpawned: wrong event firer");

	this->pongBall = PongBall::safeCast(Stage::getChildByName(PongState::getStage(PongState::getInstance()), (char*)PONG_BALL_NAME, false));
}

// process user input
void Pong::processUserInput(const UserInput* userInput)
{
	if(0 != userInput->holdKey)
	{
		Pong::onKeyHold(this, userInput->holdKey, this->playerPaddles);
	}

	if((K_LT | K_RT) & userInput->releasedKey)
	{
		this->messageForRemote = kPongMessageGoodBye;			
	}

	Pong::syncWithRemote(this, userInput);
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
	uint8 command = Pong::getCommunicationCommand(this->messageForRemote);

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

	// Send data synchronously
	do
	{
		if(!CommunicationManager::sendAndReceiveData(communicationManager, messageForRemote, data, dataBytes))
		{
			CommunicationManager::cancelCommunications(communicationManager);
		}

		receivedMessage = CommunicationManager::getReceivedMessage(communicationManager);
		remotePlayerData = (const RemotePlayerData*)CommunicationManager::getReceivedData(communicationManager);
	}
	while(!Pong::isMessageValid(this, receivedMessage, remotePlayerData->command));

	Pong::processReceivedMessage(this, messageForRemote, receivedMessage, remotePlayerData);
}

void Pong::processReceivedMessage(uint32 messageForRemote, uint32 receivedMessage, const RemotePlayerData* remotePlayerData)
{
	switch(receivedMessage)
	{
		case kPongMessageSync:

			if(kPongMessageSync == messageForRemote)
			{
				this->messageForRemote = kPongMessageSendInput;

				PongState::propagateMessage(PongState::getInstance(), kPongMessageResetPositions);
			}
			else if(kPongMessageSendInput == messageForRemote)
			{
				this->messageForRemote = kPongMessageSync;
			}

			break;

		case kPongMessageSendInput:

			if(kPongMessageSendInput == messageForRemote)
			{
				Pong::onKeyHold(this, remotePlayerData->condensedUserInput.holdKey, this->opponentPaddles);
			}

			break;

		case kPongMessageGoodBye:

			PongState::remoteWentAway(PongState::getInstance());
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

	switch(this->playerNumber)
	{
		case kPlayerAlone:

			if(K_LU & holdKey)
			{
				normalizedDirection.y = __UP;
				PongPaddle::moveTowards(VirtualList::front(paddles), normalizedDirection);
			}
			else if(K_LD & holdKey)
			{
				normalizedDirection.y = __DOWN;
				PongPaddle::moveTowards(VirtualList::front(paddles), normalizedDirection);
			}
			
			if(K_RU & holdKey)
			{
				normalizedDirection.y = __UP;
				PongPaddle::moveTowards(VirtualList::back(paddles), normalizedDirection);
			}
			else if(K_RD & holdKey)
			{
				normalizedDirection.y = __DOWN;
				PongPaddle::moveTowards(VirtualList::back(paddles), normalizedDirection);
			}

			break;

		case kPlayerOne:
		case kPlayerTwo:

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

			break;			
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
	}	

	Pong::printScore(this);

	//SoundManager::playFxSound(SoundManager::getInstance(), BALL_HIT_CEILING_SND, *SpatialObject::getPosition(SpatialObject::safeCast(eventFirer)));
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
