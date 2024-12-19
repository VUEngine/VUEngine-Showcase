/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL) <j.leucht@gmx.net>
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

const PixelVector HouseMeshesSegments[][2]=
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
		{-64, 64, 64, 0}
	},
	{
		{64, 64, -64, 0},
		{64, 64, 64, 0}
	},
	{
		{-64, -64, -64, 0}, 
		{64, -64, -64, 0}
	},
	{
		{-64, -64, 64, 0}, 
		{64, -64, 64, 0}
	},
	{
		{-64, -64, -64, 0}, 
		{-64, -64, 64, 0}
	},
	{
		{64, -64, -64, 0},
		{64, -64, 64, 0}
	},

	// door
	{
		{64, 12, -44, 0},
		{64, 12, -20, 0}
	},
	{
		{64, 64, -44, 0},
		{64, 12, -44, 0}
	},
	{
		{64, 64, -20, 0},
		{64, 12, -20, 0}
	},

	// window
	{
		{64, 0, 8, 0},
		{64, 32, 8, 0}
	},
	{
		{64, 0, 40, 0},
		{64, 32, 40, 0}
	},
	{
		{64, 32, 8, 0},
		{64, 32, 40, 0}
	},
	{
		{64, 0, 8, 0},
		{64, 0, 40, 0}
	},

	// base fence
	{
		{64, 64, 64, 0}, 
		{64, 64, 192, 0}
	},
	{
		{64, 32, 64, 0}, 
		{64, 32, 192, 0}
	},

	// vertex
	{
		{-64, -64, -64, 0},
		{-64, 64, -64, 0}
	},
	{
		{-64, -64, 64, 0},
		{-64, 64, 64, 0}
	},
	{
		{64, -64, -64, 0},
		{64, 64, -64, 0} 
	},
	{
		{64, -64, 64, 0},
		{64, 64, 64, 0}
	},
	// vertex pyramid
	{
		{0, -128, 0, 0},
		{-64, -64, -64, 0}
	},
	{
		{0, -128, 0, 0},
		{-64, -64, 64, 0}
	},
	{
		{0, -128, 0, 0},
		{64, -64, -64, 0} 
	},
	{
		{0, -128, 0, 0},
		{64, -64, 64, 0}
	},
	//vertex fence
	{
		{64, 32, 192, 0},
		{64, 64, 192, 0} 
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

const ComponentSpec* HouseWireframeSpecComponentSpecs[] = 
{
	@COMPONENTS:HouseWireframeSpec@
};

MeshROMSpec HouseWireframeSpec =
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

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false
	},

	// segments
	(PixelVector(*)[2])HouseMeshesSegments
};

@COMP_ARRAY_START:HouseWireframeSpecs
	&HouseWireframeSpec,
	
@COMP_ARRAY_END:HouseWireframeSpecs

ColliderROMSpec HouseColliderSpecsCollider1 =
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

@COMP_ARRAY_START:HouseColliderSpecs
	&HouseColliderSpecsCollider1,


@COMP_ARRAY_END:HouseColliderSpecs

const ComponentSpec* HouseEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:HouseEntitySpec@
};

EntityROMSpec HouseEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpecs**)HouseEntitySpecComponentSpecs,

	// children
	NULL,

	@BEHAVIORS:(BehaviorSpec**)NULL@,

	// extra
	NULL,

	@SPRITES:(SpriteSpec**)NULL@,

	// use z displacement in projection
	false,

	@WIREFRAMES:(WireframeSpec**)HouseWireframeSpecs@,

	@COLLIDERS:(ColliderSpec*)HouseColliderSpecs@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	@PHYSICS:(PhysicalProperties*)NULL@,
};
