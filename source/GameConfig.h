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
};

enum InGameTypes
{
	kTypeSolidObject = kTypeNone + 1,
	kTypePunk,
	kTypeCogWheel,
	kTypeParticle
};

enum CollisionLayers
{
	kLayerSolid = kLayerNone + 1,
	kLayerDangers,
	kLayerPunk,
	kLayerParticles
};


#endif
