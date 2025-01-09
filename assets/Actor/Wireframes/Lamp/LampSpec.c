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

const PixelVector LampMeshesSegments[][2]=
{

	// Vertex lamp
	{
		{-56, -64, -72, 0},
		{-56, 64, -72, 0}
	},

	// Lamp arch
	{
		{-56, -64, -72, 0},
		{-72, -80, -72, 0}
	},
	{
		{-72, -80, -72, 0},
		{-88, -80, -72, 0}
	},
	{
		{-88, -80, -72, 0},
		{-104, -64, -72, 0}
	},

	// Light bulb circle
	{
		{-108, -48, -80, 0},
		{-100, -48, -80, 0}
	},
	{
		{-108, -48, -80, 0},
		{-112, -48, -76, 0}
	},
	{
		{-112, -48, -76, 0},
		{-112, -48, -68, 0}
	},
	{
		{-112, -48, -68, 0},
		{-108, -48, -64, 0}
	},
	{
		{-108, -48, -64, 0},
		{-100, -48, -64, 0}
	},
	{
		{-100, -48, -64, 0},
		{-96, -48, -68, 0}
	},
	{
		{-96, -48, -68, 0},
		{-96, -48, -76, 0}
	},
	{
		{-96, -48, -76, 0},
		{-100, -48, -80, 0}
	},

	// Light bulb vertex
	{
		{-96, -48, -76, 0},
		{-104, -64, -72, 0}
	},
	{
		{-100, -48, -80, 0},
		{-104, -64, -72, 0}
	},
	{
		{-96, -48, -68, 0},
		{-104, -64, -72, 0}
	},
	{
		{-100, -48, -64, 0},
		{-104, -64, -72, 0}
	},
	{
		{-108, -48, -64, 0},
		{-104, -64, -72, 0}
	},
	{
		{-112, -48, -68, 0},
		{-104, -64, -72, 0}
	},
	{
		{-112, -48, -76, 0},
		{-104, -64, -72, 0}
	},
	{
		{-108, -48, -80, 0},
		{-104, -64, -72, 0}
	},

	// Limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const LampWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec LampWireframeSpec =
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
	(PixelVector(*)[2])LampMeshesSegments
};

ComponentSpec* const LampActorComponentSpecs[] = 
{
	(ComponentSpec*)&LampWireframeSpec,
	NULL
};

ActorROMSpec LampActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)LampActorComponentSpecs,

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
