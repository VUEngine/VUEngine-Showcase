#ifndef GAME_CONFIG_H_
#define GAME_CONFIG_H_

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
	kLayerSolid = kLayerNone + 1,
	kLayerDangers,
	kLayerPunk,
	kLayerParticles,
	kLayerPongPlayfield,
	kLayerPongBall,
	kLayerAll,
};


#endif
