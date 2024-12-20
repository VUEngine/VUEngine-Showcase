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

		// displacement (x, y, z, p)
		{0, -68, 0, 0},

		// rotation (x, y, z)
		{0, 0, 255},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerPongWalls,

		// layers to ignore when checking for collisions
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

		// displacement (x, y, z, p)
		{0, 64, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerPongWalls,

		// layers to ignore when checking for collisions
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
