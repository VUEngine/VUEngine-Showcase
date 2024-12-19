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
	NULL
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



ColliderROMSpec BusStopColliderSpecsCollider1 =
	{
		// Component
		{
			// Allocator
			__TYPE(Ball),

			// Component type
			kColliderComponent
		},

		// Size (x, y, z)
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

const ComponentSpec* BusStopEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)&BusStopWireframeSpec,
	(ComponentSpec*)&BusStopColliderSpecsCollider1,
	NULL
};

EntityROMSpec BusStopEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)BusStopEntitySpecComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// In-game entity's type
	kTypeNone
};
