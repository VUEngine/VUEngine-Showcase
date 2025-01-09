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

#include <Actor.h>
#include <Ball.h>
#include <Mesh.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const PixelVector HouseMeshesSegments[][2]=
{
	// Base
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

	// Door
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

	// Window
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

	// Base fence
	{
		{64, 64, 64, 0}, 
		{64, 64, 192, 0}
	},
	{
		{64, 32, 64, 0}, 
		{64, 32, 192, 0}
	},

	// Vertex
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

	// Limiter
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

		// Transparent
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false
	},

	// Segments that compose the mesh
	(PixelVector(*)[2])HouseMeshesSegments
};

ComponentSpec* const HouseActorComponentSpecs[] = 
{
	(ComponentSpec*)&HouseWireframeSpec,
	NULL
};

ActorROMSpec HouseActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)HouseActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Pointer to animation functions array
	NULL,

	// Animation to play automatically
	NULL
};
