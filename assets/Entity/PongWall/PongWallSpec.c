/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <ColliderLayers.h>
#include <Entity.h>
#include <InGameTypes.h>
#include <LineField.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

	// linefield
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

	// linefield
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

ComponentSpec* const PongWallsEntityComponentSpecs[] = 
{
	(ComponentSpec*)&PongWallsColliderSpec2,
	(ComponentSpec*)&PongWallsColliderSpec1,
	NULL
};

EntityROMSpec PongWallsEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)PongWallsEntityComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Entity's in-game type
	kTypePongWall
};
