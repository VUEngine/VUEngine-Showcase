////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MESSAGES_H_
#define MESSAGES_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Constants.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

enum Messages
{
	kMessageCollisionsStateHoldLeft = kMessageLastEngine + 1,
	kMessageCollisionsStateHoldRight,
	kMessageCollisionsStateNoMessage,
	kMessageCollisionsStatePrintStatefulActorStatus,
	kMessageCollisionsStateReleasedLeft,
	kMessageCollisionsStateReleasedRight,
	kMessageCollisionsStateResuscitate,
	kMessagePongBallStartMoving,
	kMessagePongDummy,
	kMessagePongGoodBye,
	kMessagePongResetPositions,
	kMessagePongSendInput,
	kMessagePongSync,
};

#endif
