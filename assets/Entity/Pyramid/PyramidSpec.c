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

#include <Entity.h>
#include <Ball.h>
#include <Mesh.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

const PixelVector PyramidMeshesSegments[][2]=
{
	// base
	{
		{-64, 64, -64, 0}, 
		{64, 64, -64, 0}
	},
	{
		{-64, 64, 64, 0}, 
		{64, 64, 64, 0}
	},
	{
		{-64, 64, -64, 0}, 
		{-64, 64, 64, 0}, 
	},
	{
		{64, 64, -64, 0},
		{64, 64, 64, 0}
	},

	// vertex
	{
		{0, -64, 0, 0},
		{-64, 64, -64, 0}
	},
	{
		{0, -64, 0, 0},
		{-64, 64, 64, 0}
	},
	{
		{0, -64, 0, 0},
		{64, 64, -64, 0}, 
	},
	{
		{0, -64, 0, 0},
		{64, 64, 64, 0},
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec** PyramidWireframeSpecComponentSpecs[] = 
{
	@COMPONENTS:PyramidWireframeSpec@
};

MeshROMSpec PyramidWireframeSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(Mesh),

			// Component type
			kWireframeComponent
		},

		{0, 0, 0},
		
		// color
		__COLOR_BLACK,

		// transparency
		__TRANSPARENCY_NONE,

		// interlaced
		false,
	},

	// segments
	(PixelVector(*)[2])PyramidMeshesSegments
};

@COMP_ARRAY_START:PyramidWireframeSpecs
	(WireframeSpec*)&PyramidWireframeSpec,
	
@COMP_ARRAY_END:PyramidWireframeSpecs

ColliderROMSpec PyramidColliderSpecsCollider1 =
	{
		// Component
		{
			// Allocator
			__TYPE(Ball),

			// Component type
			kColliderComponent
		},

		// size (x, y, z)
		{128, 128, 128},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerNone,

		// layers to ignore when checking for collisions
		kLayerNone
	};

@COMP_ARRAY_START:PyramidColliderSpecs
	(ComponentSpec*)&PyramidColliderSpecsCollider1,


@COMP_ARRAY_END:PyramidColliderSpecs

ComponentSpec** PyramidEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:PyramidEntitySpec@
};

EntityROMSpec PyramidEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	@BEHAVIORS:(BehaviorSpec**)NULL@,

	// extra
	NULL,

	@SPRITES:(SpriteSpec**)NULL@,

	// use z displacement in projection
	false,

	@WIREFRAMES:(WireframeSpec**)PyramidWireframeSpecs@,

	@COLLIDERS:(ColliderSpec*)PyramidColliderSpecs@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	@PHYSICS:(PhysicalProperties*)NULL@,
};
