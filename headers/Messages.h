////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MESSAGES_H_
#define MESSAGES_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Constants.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum Messages
{
	kMessageStatefulActorsStateHoldLeft = kMessageLastEngine + 1,
	kMessageStatefulActorsStateHoldRight,
	kMessageStatefulActorsStateNoMessage,
	kMessageStatefulActorsStatePrintStatefulActorStatus,
	kMessageStatefulActorsStateReleasedLeft,
	kMessageStatefulActorsStateReleasedRight,
	kMessageStatefulActorsStateResuscitate,
	kMessagePongBallStartMoving,
	kMessagePongDummy,
	kMessagePongGoodBye,
	kMessagePongResetPositions,
	kMessagePongSendInput,
	kMessagePongSync,
};

#endif
