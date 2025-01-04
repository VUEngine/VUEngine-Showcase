/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL) <j.leucht@gmx.net>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Entity.h>
#include <Ball.h>
#include <Mesh.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

ComponentSpec* const BusStopWireframeComponentSpecs[] = 
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

		// Displacement relative to the owner's spatial position
		{0, 0, 0},
		
		// Wireframe's lines' color
		__COLOR_BLACK,

		// transparent
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false
	},

	// Segments that compose the mesh
	(PixelVector(*)[2])BusStopMeshesSegments
};

ComponentSpec* const BusStopEntityComponentSpecs[] = 
{
	(ComponentSpec*)&BusStopWireframeSpec,
	NULL
};

EntityROMSpec BusStopEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)BusStopEntityComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Entity's in-game type
	kTypeNone
};
