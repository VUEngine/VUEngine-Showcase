/**
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

const PixelVector BusStopMeshesSegments[][2]=
{
	// base housing
	{
		{-64, 64, -64, 0}, 
		{0, 64, -64, 0}
	},
	{
		{-64, 64, 64, 0}, 
		{0, 64, 64, 0}
	},
	{
		{-64, 64, -64, 0}, 
		{-64, 64, 64, 0}
	},
	{
		{0, 64, -64, 0},
		{0, 64, 64, 0}
	},
	{
		{-64, -32, -64, 0}, 
		{0, -32, -64, 0}
	},
	{
		{-64, -32, 64, 0}, 
		{0, -32, 64, 0}
	},
	{
		{-64, -32, -64, 0}, 
		{-64, -32, 64, 0}
	},
	{
		{0, -32, -64, 0},
		{0, -32, 64, 0}
	},

	// base seating
	{
		{-48, 40, -32, 0}, 
		{-16, 40, -32, 0}
	},
	{
		{-48, 40, 32, 0}, 
		{-16, 40, 32, 0}
	},
	{
		{-48, 40, -32, 0}, 
		{-48, 40, 32, 0}
	},
	{
		{-16, 40, -32, 0},
		{-16, 40, 32, 0}
	},

	// vertex seating
	{
		{-32, 64, -32, 0}, 
		{-32, 40, -32, 0}
	},
	{
		{-32, 64, 32, 0}, 
		{-32, 40, 32, 0}
	},

	// vertex sign
	{
		{-56, -16, -80, 0},
		{-56, 64, -80, 0}
	},

	// sign
	{
		{-56, -16, -80, 0},
		{-64, -16, -80, 0}
	},
	{
		{-56, -16, -80, 0},
		{-48, -16, -80, 0}
	},
	{
		{-64, -16, -80, 0},
		{-72, -24, -80, 0}
	},
	{
		{-72, -24, -80, 0},
		{-72, -32, -80, 0}
	},
	{
		{-72, -32, -80, 0},
		{-64, -40, -80, 0}
	},
	{
		{-64, -40, -80, 0},
		{-48, -40, -80, 0}
	},
	{
		{-48, -40, -80, 0},
		{-40, -32, -80, 0}
	},
	{
		{-40, -32, -80, 0},
		{-40, -24, -80, 0}
	},
	{
		{-40, -24, -80, 0},
		{-48, -16, -80, 0}
	},

	// vertex housing
	{
		{-64, -32, -64, 0},
		{-64, 64, -64, 0}
	},
	{
		{-64, -32, 64, 0},
		{-64, 64, 64, 0}
	},
	{
		{0, -32, -64, 0},
		{0, 64, -64, 0} 
	},
	{
		{0, -32, 64, 0},
		{0, 64, 64, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

const ComponentSpec* BusStopWireframeSpecComponentSpecs[] = 
{
	@COMPONENTS:BusStopWireframeSpec@
};

MeshROMSpec BusStopWireframeSpec =
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
	(PixelVector(*)[2])BusStopMeshesSegments
};

@COMP_ARRAY_START:BusStopWireframeSpecs
	&BusStopWireframeSpec,
	
@COMP_ARRAY_END:BusStopWireframeSpecs

ColliderROMSpec BusStopColliderSpecsCollider1 =
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

@COMP_ARRAY_START:BusStopColliderSpecs
	&BusStopColliderSpecsCollider1,


@COMP_ARRAY_END:BusStopColliderSpecs

const ComponentSpec* BusStopEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:BusStopEntitySpec@
};

EntityROMSpec BusStopEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpecs**)BusStopEntitySpecComponentSpecs,

	// children
	NULL,

	@BEHAVIORS:(BehaviorSpec**)NULL@,

	// extra
	NULL,

	@SPRITES:(SpriteSpec**)NULL@,

	// use z displacement in projection
	false,

	@WIREFRAMES:(WireframeSpec**)BusStopWireframeSpecs@,

	@COLLIDERS:(ColliderSpec*)BusStopColliderSpecs@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	@PHYSICS:(PhysicalProperties*)NULL@,
};
