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
ColliderROMSpec PongWallsColliderSpecsCollider1 =
	{
		// Component
		{
			// Allocator
			__TYPE(LineField),

			// Component type
			kColliderComponent
		},

		// size (x, y, z)
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
ColliderROMSpec PongWallsColliderSpecsCollider2 =
	{
		// Component
		{
			// Allocator
			__TYPE(LineField),

			// Component type
			kColliderComponent
		},

		// size (x, y, z)
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

@COMP_ARRAY_START:PongWallsColliderSpecs
	(ComponentSpec*)&PongWallsColliderSpecsCollider2,
	(ComponentSpec*)&PongWallsColliderSpecsCollider1,


@COMP_ARRAY_END:PongWallsColliderSpecs

ComponentSpec** PongWallsEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:PongWallsEntitySpec@
};

EntityROMSpec PongWallsEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	@BEHAVIORS:NULL@,

	// extra
	NULL,

	@SPRITES:(SpriteSpec**)NULL@,

	// use z displacement in projection
	false,

	@WIREFRAMES:(WireframeSpec**)NULL@,

	@COLLIDERS:(ColliderSpec*)PongWallsColliderSpecs@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypePongWall,

	@PHYSICS:(PhysicalProperties*)NULL@,
};
