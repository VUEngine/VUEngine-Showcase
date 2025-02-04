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

const PixelVector HouseBigMeshesSegments[][2]=
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
	// base fence
	{
		{64, 64, 64, 0}, 
		{64, 64, 320, 0}
	},
	{
		{64, 32, 64, 0}, 
		{64, 32, 320, 0}
	},

	// Door
	{
		{64, 12, -12, 0},
		{64, 12, 12, 0}
	},
	{
		{64, 64, -12, 0},
		{64, 12, -12, 0}
	},
	{
		{64, 64, 12, 0},
		{64, 12, 12, 0}
	},

	// Window 1
	{
		{64, 0, -48, 0},
		{64, 24, -48, 0}
	},
	{
		{64, 0, -24, 0},
		{64, 24, -24, 0}
	},
	{
		{64, 24, -48, 0},
		{64, 24, -24, 0}
	},
	{
		{64, 0, -48, 0},
		{64, 0, -24, 0}
	},

	// Window 2
	{
		{64, 0, 48, 0},
		{64, -24, 48, 0}
	},
	{
		{64, 0, 24, 0},
		{64, -24, 24, 0}
	},
	{
		{64, -24, 48, 0},
		{64, -24, 24, 0}
	},
	{
		{64, 0, 48, 0},
		{64, 0, 24, 0}
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
		{0, -192, 0, 0},
		{-64, -64, -64, 0}
	},
	{
		{0, -192, 0, 0},
		{-64, -64, 64, 0}
	},
	{
		{0, -192, 0, 0},
		{64, -64, -64, 0} 
	},
	{
		{0, -192, 0, 0},
		{64, -64, 64, 0}
	},
	//vertex fence
	{
		{64, 32, 320, 0},
		{64, 64, 320, 0} 
	},

	// Limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const HouseBigWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec HouseBigWireframeSpec =
{
	{
		{
			// Component
			{
				// Allocator
				__TYPE(Mesh),

				// Component type
				kWireframeComponent
			},

			// Array of function animations
			(const AnimationFunction**)NULL
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
	(PixelVector(*)[2])HouseBigMeshesSegments
};

ComponentSpec* const HouseBigActorComponentSpecs[] = 
{
	(ComponentSpec*)&HouseBigWireframeSpec,
	NULL
};

ActorROMSpec HouseBigActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)HouseBigActorComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeNone,

	// Animation to play automatically
	NULL
};
