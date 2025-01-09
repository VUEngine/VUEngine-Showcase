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

const PixelVector PowerCableMeshesSegments[][2]=
{
	// Cable starting from 61.928° with radius 272 and circle segment height 32. It is only suitable for 
	// powerpoles with distance of 256
	
	// powercable 1
	// 70°
	{
		{0, 0, 0, 0}, 
		{-34.97, 15.596, 0, 0}
	},
	// 80°
	{
		{-34.97, 15.596, 0, 0}, 
		{-80.768, 27.868, 0, 0}
	},
	// 90°
	{
		{-80.768, 27.868, 0, 0}, 
		{-128, 32, 0, 0}
	},
	// 100°
	{
		{-128, 32, 0, 0}, 
		{-175.232, 27.868, 0, 0}
	},
	// 110°
	{
		{-175.232, 27.868, 0, 0}, 
		{-221.03, 15.596, 0, 0}
	},
	// 118.072°
	{
		{-221.03, 15.596, 0, 0}, 
		{-256, 0, 0, 0}
	},

	// powercable 2
	// 70°
	{
		{0, 0, 0-168, 0}, 
		{-34.97, 15.596, 0-168, 0}
	},
	// 80°
	{
		{-34.97, 15.596, 0-168, 0}, 
		{-80.768, 27.868, 0-168, 0}
	},
	// 90°
	{
		{-80.768, 27.868, 0-168, 0}, 
		{-128, 32, 0-168, 0}
	},
	// 100°
	{
		{-128, 32, 0-168, 0}, 
		{-175.232, 27.868, 0-168, 0}
	},
	// 110°
	{
		{-175.232, 27.868, 0-168, 0}, 
		{-221.03, 15.596, 0-168, 0}
	},
	// 118.072°
	{
		{-221.03, 15.596, 0-168, 0}, 
		{-256, 0, 0-168, 0}
	},

	// powercable 3
	// 70°
	{
		{0, 0-80, 0-16, 0}, 
		{-34.97, 15.596-80, 0-16, 0}
	},
	// 80°
	{
		{-34.97, 15.596-80, 0-16, 0}, 
		{-80.768, 27.868-80, 0-16, 0}
	},
	// 90°
	{
		{-80.768, 27.868-80, 0-16, 0}, 
		{-128, 32-80, 0-16, 0}
	},
	// 100°
	{
		{-128, 32-80, 0-16, 0}, 
		{-175.232, 27.868-80, 0-16, 0}
	},
	// 110°
	{
		{-175.232, 27.868-80, 0-16, 0}, 
		{-221.03, 15.596-80, 0-16, 0}
	},
	// 118.072°
	{
		{-221.03, 15.596-80, 0-16, 0}, 
		{-256, 0-80, 0-16, 0}
	},

	// powercable 4
	// 70°
	{
		{0, 0-80, 0-16-136, 0}, 
		{-34.97, 15.596-80, 0-16-136, 0}
	},
	// 80°
	{
		{-34.97, 15.596-80, 0-16-136, 0}, 
		{-80.768, 27.868-80, 0-16-136, 0}
	},
	// 90°
	{
		{-80.768, 27.868-80, 0-16-136, 0}, 
		{-128, 32-80, 0-16-136, 0}
	},
	// 100°
	{
		{-128, 32-80, 0-16-136, 0}, 
		{-175.232, 27.868-80, 0-16-136, 0}
	},
	// 110°
	{
		{-175.232, 27.868-80, 0-16-136, 0}, 
		{-221.03, 15.596-80, 0-16-136, 0}
	},
	// 118.072°
	{
		{-221.03, 15.596-80, 0-16-136, 0}, 
		{-256, 0-80, 0-16-136, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const PowerCableWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec PowerCableWireframeSpec =
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
	(PixelVector(*)[2])PowerCableMeshesSegments
};

ComponentSpec* const PowerCableActorComponentSpecs[] = 
{
	(ComponentSpec*)&PowerCableWireframeSpec,
	NULL
};

ActorROMSpec PowerCableActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PowerCableActorComponentSpecs,

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
