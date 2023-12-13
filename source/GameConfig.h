#ifndef GAME_CONFIG_H_
#define GAME_CONFIG_H_

//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <CollisionManager.h>

//---------------------------------------------------------------------------------------------------------
// 												ENUMS
//---------------------------------------------------------------------------------------------------------

enum Messages
{
	/*
	 * Must always start at kMessageLastEngine + 1
	 */
	kActorsStateNoMessage = kMessageLastEngine + 1,
	kActorsStateHoldLeft,
	kActorsStateReleasedLeft,
	kActorsStateHoldRight,
	kActorsStateReleasedRight,
	kActorsStatePrintActorStatus,
	kActorsStateResucitate,
	kPongBallMessageStartMoving,
	kPongMessageResetPositions,
	kPongMessageDummy,
	kPongMessageSendInput,
	kPongMessageSync,
	kPongMessageGoodBye,	
};

enum InGameTypes
{
	kTypeSolidObject = kTypeNone + 1,
	kTypePunk,
	kTypeCogWheel,
	kTypeParticle,
	kTypePongPaddle,
	kTypePongBall,
	kTypePongGoal,
	kTypePongWall
};

enum CollisionLayers
{
	kLayerSolid 				= 1 << (kLayerNone + 1),
	kLayerDangers				= 1 << (kLayerNone + 2),
	kLayerPunk					= 1 << (kLayerNone + 3),
	kLayerParticles				= 1 << (kLayerNone + 4),
	kLayerPongWalls				= 1 << (kLayerNone + 5),
	kLayerPongPaddle			= 1 << (kLayerNone + 6),
	kLayerPongPaddleHelper		= 1 << (kLayerNone + 7),
	kLayerPongBall				= 1 << (kLayerNone + 8),
	kLayerAll					= __COLLISION_ALL_LAYERS,
};


#endif
