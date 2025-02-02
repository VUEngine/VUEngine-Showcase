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

#include <ColliderLayers.h>
#include <Actor.h>
#include <InGameTypes.h>
#include <LineField.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

	// Linefield
ColliderROMSpec PongWallsColliderSpec1 =
	{
		// Component
		{
			// Allocator
			__TYPE(LineField),

			// Component type
			kColliderComponent
		},

		// Size (x, y, z)
		{100 * 2, 0, 0},

		// Displacement (x, y, z, p)
		{0, -68, 0, 0},

		// Rotation (x, y, z)
		{0, 0, 255},

		// Scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// If true this collider checks for collisions against other colliders
		false,

		// Layers in which I live
		kLayerPongWalls,

		// Layers to ignore when checking for collisions
		kLayerAll,
	};

	// Linefield
ColliderROMSpec PongWallsColliderSpec2 =
	{
		// Component
		{
			// Allocator
			__TYPE(LineField),

			// Component type
			kColliderComponent
		},

		// Size (x, y, z)
		{100 * 2, 0, 0},

		// Displacement (x, y, z, p)
		{0, 64, 0, 0},

		// Rotation (x, y, z)
		{0, 0, 0},

		// Scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// If true this collider checks for collisions against other colliders
		false,

		// Layers in which I live
		kLayerPongWalls,

		// Layers to ignore when checking for collisions
		kLayerAll,
	};

ComponentSpec* const PongWallsActorComponentSpecs[] = 
{
	(ComponentSpec*)&PongWallsColliderSpec2,
	(ComponentSpec*)&PongWallsColliderSpec1,
	NULL
};

ActorROMSpec PongWallsActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PongWallsActorComponentSpecs,

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
