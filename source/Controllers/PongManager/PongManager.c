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

#include <CommunicationManager.h>
#include <GameEvents.h>
#include <KeypadManager.h>
#include <MessageDispatcher.h>
#include <Messages.h>
#include <PongPaddle.h>
#include <CommunicationsState.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <Singleton.h>
#include <SoundManager.h>
#include <Sounds.h>
#include <Utilities.h>
#include <VUEngine.h>
#include <VirtualList.h>

#include "PongManager.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' MACROS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define SCORE_MULTIPLIER_THRESHOLD		 5
#define BONUS_INCREMENT_DELAY			 100
#define SCORE_MULTIPLIER_TO_ENABLE_BONUS 10

#define PONG_NO_COMMAND					 0x00
#define PONG_REGISTER_POINT				 0x78
#define PONG_SYNC_WITH_REMOTE			 0x3D
#define PONG_SEND_USER_INPUT			 0xAB
#define PONG_REMOTE_GO_AWAY				 0x3C

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::constructor(Stage stage)
{
	// Always explicitly call the base's constructor
	Base::constructor();

	this->stage = stage;
	this->leftScore = 0;
	this->rightScore = 0;
	
	this->messageForRemote = kMessagePongSync;
	this->allowPaddleMovement = false;
	this->remoteHoldKey = 0;

	// Enable comms	
	CommunicationManager::enableCommunications(CommunicationManager::getInstance(), ListenerObject::safeCast(this));
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::destructor()
{
	// Always explicitly call the base's destructor
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongManager::onEvent(ListenerObject eventFirer __attribute__((unused)), uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventCommunicationsConnected:
		{
			PongManager::getReady(this);
			return false;
		}

		case kEventActorDeleted:
		{
			if(0 == strcmp(PONG_BALL_NAME, Actor::getName(eventFirer)))
			{
				/*
				if(0 < PongBall::getPosition(eventFirer)->x)
				{
					this->messageForRemote = kPlayerOne == this->playerNumber ? kMessagePongMyPoint : kMessagePongYourPoint;
				}
				else
				{
					this->messageForRemote = kPlayerOne == this->playerNumber ? kMessagePongYourPoint : kMessagePongMyPoint;
				}
				*/
			}

			return true;
		}

		case kEventActorCreated:
		{
			if(__GET_CAST(PongBall, eventFirer))
			{
				Actor::addEventListener(eventFirer, ListenerObject::safeCast(this), kEventActorDeleted);
			}

			return true;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::getReady()
{
	if(CommunicationManager::isConnected(CommunicationManager::getInstance()))
	{
	//	CommunicationManager::startSyncCycle(CommunicationManager::getInstance());
	}

	this->leftScore = 0;
	this->rightScore = 0;
	this->messageForRemote = kMessagePongSync;
	this->allowPaddleMovement = false;
	this->remoteHoldKey = 0;

	if(isDeleted(this->stage))
	{
		return;
	}

	this->playerNumber = kPlayerAlone;

	if(CommunicationManager::isConnected(CommunicationManager::getInstance()))
	{
		this->playerNumber = kPlayerOne;

		if(!CommunicationManager::isMaster(CommunicationManager::getInstance()))
		{
			this->playerNumber = kPlayerTwo;
		}

		uint32 leftPaddleType = kPlayerOne == this->playerNumber ? kPaddleLocal : kPaddleRemote;
		uint32 rightPaddleType = kPlayerTwo == this->playerNumber ? kPaddleLocal : kPaddleRemote;

		PongPaddle leftPaddle = PongPaddle::safeCast(Stage::getChildByName(this->stage, (char*)PADDLE_LEFT_NAME, true));

		if(!isDeleted(leftPaddle))
		{
			PongPaddle::setType(leftPaddle, leftPaddleType);
		}

		PongPaddle rightPaddle = PongPaddle::safeCast(Stage::getChildByName(this->stage, (char*)PADDLE_RIGHT_NAME, true));

		if(!isDeleted(rightPaddle))
		{
			PongPaddle::setType(rightPaddle, rightPaddleType);
		}
	}

	Actor ball = Actor::safeCast(Stage::getChildByName(this->stage, (char*)PONG_BALL_NAME, false));

	if(!isDeleted(ball))
	{
		Actor::addEventListener(ball, ListenerObject::safeCast(this), kEventActorDeleted);
	}

	Stage::addActorLoadingListener(this->stage, ListenerObject::safeCast(this));
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::processUserInput(const UserInput* userInput)
{
	if((K_LT | K_RT) & userInput->releasedKey)
	{
		this->messageForRemote = kMessagePongGoodBye;
	}

	PongManager::syncWithRemote(this, userInput);

	PongManager::propagateInputMessage(this, userInput->holdKey, kMessageShowcaseStateHoldUp, kMessageShowcaseStateHoldDown);
	PongManager::propagateInputMessage(this, this->remoteHoldKey, kMessageShowcaseStateRemoteHoldUp, kMessageShowcaseStateRemoteHoldDown);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::propagateInputMessage(uint16 holdKey, uint32 upMessage, uint32 downMessage)
{
	if(0 == holdKey)
	{
		return;
	}

	int32 message = kMessageNone;

	if(K_LU & holdKey)
	{
		message = upMessage;
	}
	else if(K_LD & holdKey)
	{
		message = downMessage;
	}
	
	if(kMessageNone != message && this->allowPaddleMovement)
	{
		/*
		* Passing input to actors in this way, while elegant, is not very performant. Most likely, a way to get a
		* pointer to the actor that the user controls and calling an specific method that its class implements would be
		* way faster.
		*/
		Stage::propagateMessage(this->stage, Container::onPropagatedMessage, message);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

int PongManager::getPlayerNumber()
{
	return this->playerNumber;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::printScore()
{
	int16 y = 26;
	PRINT_TEXT("P1:	  ", 1, y);
	PRINT_INT(this->leftScore, 1 + 5 - Math::getDigitsCount(this->leftScore), y);

	PRINT_TEXT("P2:	  ", __SCREEN_WIDTH_IN_CHARS - 1 - 5, y);
	PRINT_INT(this->rightScore, __SCREEN_WIDTH_IN_CHARS - 1 - Math::getDigitsCount(this->rightScore), y);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint32 PongManager::getCommunicationCommand(uint32 message)
{
	switch(message)
	{
		case kMessagePongSync:

			return PONG_SYNC_WITH_REMOTE;

		case kMessagePongMyPoint:
		case kMessagePongYourPoint:

			return PONG_REGISTER_POINT;

		case kMessagePongSendInput:

			return PONG_SEND_USER_INPUT;

		case kMessagePongGoodBye:

			return PONG_REMOTE_GO_AWAY;
	}

	return PONG_NO_COMMAND;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool PongManager::isMessageValid(uint32 message, uint8 command)
{
	return PongManager::getCommunicationCommand(this, message) == command;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::syncWithRemote(const UserInput* userInput)
{
	/*
	 * This call will sync both systems. The approach in this example is to get both
	 * systems to follow the same code paths and only transmit the user input. So,
	 * both are at the end of each frame in the same state. It is possible to run
	 * the game in one and send the data to the other so this only shows it.
	 */
	if(CommunicationManager::isConnected(CommunicationManager::getInstance()))
	{
		this->remoteHoldKey = 0;

		/*
		* A command is used to verify that the received message and the data
		* are valid.
		*/
		uint8 command = PongManager::getCommunicationCommand(this, this->messageForRemote);

		/*
		* This is the struct that we are going to send down the link port.
		*/
		RemotePlayerData remotePlayerData;

		remotePlayerData.command = command;
		remotePlayerData.condensedUserInput.pressedKey = userInput->pressedKey;
		remotePlayerData.condensedUserInput.releasedKey = userInput->releasedKey;
		remotePlayerData.condensedUserInput.holdKey = userInput->holdKey;

		PongManager::transmitData(this, this->messageForRemote, (BYTE*)&remotePlayerData, sizeof(remotePlayerData));
	}
		
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::transmitData(uint32 messageForRemote, BYTE* data, uint32 dataBytes)
{
	uint32 receivedMessage = kMessagePongDummy;
	const RemotePlayerData* remotePlayerData = NULL;

	/*
	 * Data will be sent sychroniously. This means that if the cable is disconnected during
	 * transmission, the mutator is undefined.
	 */
	do
	{
		/*
		 * Data transmission can fail if there was already a request to send data.
		 */
		if(!CommunicationManager::sendAndReceiveData(CommunicationManager::getInstance(), messageForRemote, data, dataBytes))
		{
			/*
			 * In this case, simply cancel all communications and try again. This supposes
			 * that there are no other calls that could cause a race condition.
			 */
//			CommunicationManager::cancelCommunications(CommunicationManager::getInstance());
		}

		/*
		 * Every transmission sends a control message and then the data itself.
		 */
		receivedMessage = CommunicationManager::getReceivedMessage(CommunicationManager::getInstance());
		remotePlayerData = (const RemotePlayerData*)CommunicationManager::getReceivedData(CommunicationManager::getInstance());
	}
	/*
	 * The validity of the message is based on the command that was received
	 */
	while(!PongManager::isMessageValid(this, receivedMessage, remotePlayerData->command));

	PongManager::processReceivedMessage(this, messageForRemote, receivedMessage, remotePlayerData);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::processReceivedMessage(uint32 messageForRemote, uint32 receivedMessage, const RemotePlayerData* remotePlayerData)
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
				// Reset random seed in multiplayer mode so both machines are completely in sync
				Math::resetRandomSeed();

				Stage::propagateMessage(this->stage, Container::onPropagatedMessage, kMessagePongResetPositions);

				PongManager::fireEvent(this, kEventPongRemoteInSync);

				this->messageForRemote = kMessagePongSendInput;
			}
			else
			{
				this->messageForRemote = kMessagePongSync;
			}

			break;

		case kMessagePongMyPoint:

			if(kMessagePongYourPoint == messageForRemote)
			{
				PongManager::registerPoint(this, kMessagePongYourPoint);

				this->messageForRemote = kMessagePongSync;
			}
			else
			{
				this->messageForRemote = kMessagePongYourPoint;
			}

			break;

		case kMessagePongYourPoint:

			if(kMessagePongMyPoint == messageForRemote)
			{
				PongManager::registerPoint(this, kMessagePongMyPoint);

				this->messageForRemote = kMessagePongSync;
			}
			else
			{
				this->messageForRemote = kMessagePongMyPoint;
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

			CommunicationManager::disableCommunications(CommunicationManager::getInstance());

			PongManager::fireEvent(this, kEventPongRemoteWentAway);

			PongManager::getReady(this);

			this->messageForRemote = kMessagePongSync;

			Stage::propagateMessage(this->stage, Container::onPropagatedMessage, kMessagePongResetPositions);

			//CommunicationManager::enableCommunications(CommunicationManager::getInstance(), ListenerObject::safeCast(this));
			break;
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void PongManager::registerPoint(uint32 message)
{
	switch(message)
	{
		case kMessagePongMyPoint:
		{
			if(kPlayerOne == this->playerNumber)
			{
				this->leftScore++;
			}
			else
			{
				this->rightScore++;
			}

			break;
		}

		case kMessagePongYourPoint:
		{
			if(kPlayerOne == this->playerNumber)
			{
				this->rightScore++;
			}
			else
			{
				this->leftScore++;
			}

			break;
		}
	}

	PongManager::printScore(this);

	RumbleManager::startEffect(&PointRumbleEffectSpec);

	SoundManager::playSound(&Point1SoundSpec, NULL, kSoundPlaybackNormal, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
