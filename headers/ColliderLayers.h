///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef COLLIDER_LAYERS_H_
#define COLLIDER_LAYERS_H_


//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <CollisionManager.h>


//---------------------------------------------------------------------------------------------------------
//                                               DEFINITIONS                                               
//---------------------------------------------------------------------------------------------------------

enum ColliderLayers
{
	kLayerDangers = 1 << (kLayerNone + 1),
	kLayerParticles = 1 << (kLayerNone + 2),
	kLayerPongBall = 1 << (kLayerNone + 3),
	kLayerPongPaddle = 1 << (kLayerNone + 4),
	kLayerPongPaddleHelper = 1 << (kLayerNone + 5),
	kLayerPongWalls = 1 << (kLayerNone + 6),
	kLayerPunk = 1 << (kLayerNone + 7),
	kLayerSolid = 1 << (kLayerNone + 8),
	kLayerAll = __COLLISION_ALL_LAYERS,
};


#endif
