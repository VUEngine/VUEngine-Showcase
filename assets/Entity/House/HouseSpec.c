/*
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

ComponentSpec* const HouseWireframeComponentSpecs[] = 
{
	NULL
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
	(PixelVector(*)[2])HouseMeshesSegments
};

ComponentSpec* const HouseEntityComponentSpecs[] = 
{
	(ComponentSpec*)&HouseWireframeSpec,
	NULL
};

EntityROMSpec HouseEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)HouseEntityComponentSpecs,

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
