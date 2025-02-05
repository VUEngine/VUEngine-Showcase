////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <LineField.h>
#include <Texture.h>
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// COLLIDERS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ColliderROMSpec PongWallsCollider1ColliderSpec = 
{
	// Component
	{
		// Allocator
		__TYPE(LineField),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{200, 0, 0},

	// Displacement (x, y, z, p)
	{0, 64, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(0.000f), __F_TO_FIX7_9(0.000f)},

	// If true this collider checks for collisions against other colliders
	false,

	// Layers in which I live
	kLayerPongWalls,

	// Layers to ignore when checking for collisions
	kLayerAll
};
ColliderROMSpec PongWallsCollider2ColliderSpec = 
{
	// Component
	{
		// Allocator
		__TYPE(LineField),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{200, 0, 0},

	// Displacement (x, y, z, p)
	{0, -64, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 255},

	// Scale (x, y, z)
	{__F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f)},

	// If true this collider checks for collisions against other colliders
	false,

	// Layers in which I live
	kLayerPongWalls,

	// Layers to ignore when checking for collisions
	kLayerAll
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PongWallsComponentSpecs[] = 
{
	(ComponentSpec*)&PongWallsCollider1ColliderSpec,
	(ComponentSpec*)&PongWallsCollider2ColliderSpec,
	NULL
};

ActorROMSpec PongWallsActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PongWallsComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypePongWall,

	// Animation to play automatically
	NULL
	
};
