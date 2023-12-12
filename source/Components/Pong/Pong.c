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

#define SCORE_MULTIPLIER_THRESHOLD			5
#define BONUS_INCREMENT_DELAY				100
#define SCORE_MULTIPLIER_TO_ENABLE_BONUS	10


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
	if(!isDeleted(this->pongBall))
	{
		PongBall::deleteMyself(this->pongBall);

	}

	VirtualList::clear(this->playerPaddles);
	VirtualList::clear(this->opponentPaddles);
	this->leftScore = 0;
	this->rightScore = 0;
	this->pongBall = NULL;
	
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

	if(PongState::isVersusMode(PongState::getInstance()))
	{
		Pong::syncWithRemote(this, userInput);

		CondensedUserInput condensedUserInput = this->opponentData.condensedUserInput;

		if((K_LT | K_RT) & condensedUserInput.releasedKey)
		{
			PongState::reload(PongState::getInstance());
		}
		else if(0 != condensedUserInput.holdKey)
		{
			Pong::onKeyHold(this, condensedUserInput.holdKey, this->opponentPaddles);
		}
	}
}

void Pong::syncWithRemote(const UserInput* userInput)
{
	this->opponentData.condensedUserInput.pressedKey = userInput->pressedKey;
	this->opponentData.condensedUserInput.releasedKey = userInput->releasedKey;
	this->opponentData.condensedUserInput.holdKey = userInput->holdKey;

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

			if((K_RU | K_RU) & holdKey)
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
