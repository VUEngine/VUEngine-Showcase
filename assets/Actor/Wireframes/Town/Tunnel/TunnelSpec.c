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

#include <Actor.h>
#include <Ball.h>
#include <Mesh.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const PixelVector TunnelMeshesSegments[][2]=
{
	// Base
	/* {
		{-128, 0, -512, 0}, 
		{128, 0, -512, 0}
	},
	{
		{-128, 0, 384, 0}, 
		{128, 0, 384, 0}
	},*/

	// Vertex z-axis base
	{
		{-128, 0, 384, 0},
		{-128, 0, -512, 0}
	},
	{
		{128, 0, 384, 0},
		{128, 0, -512, 0} 
	},

	// Vertex y-axis entrance with arc
	{
		{-128, -128, -512, 0},
		{-128, 0, -512, 0}
	},
	{
		{128, -128, -512, 0},
		{128, 0, -512, 0} 
	},
	{
		{-128, -128, -512, 0},
		{-96, -192, -512, 0}
	},
	
	{
		{-96, -192, -512, 0},
		{-32, -240, -512, 0}
	},
	{
		{-32, -240, -512, 0},
		{0, -240, -512, 0}
	},
	{
		{128, -128, -512, 0},
		{96, -192, -512, 0}
	},
	{
		{96, -192, -512, 0},
		{32, -240, -512, 0}
	},
	{
		{32, -240, -512, 0},
		{0, -240, -512, 0}
	},

	// Vertex y-axis exit with arc
	{
		{-128, -128, 384, 0},
		{-128, 0, 384, 0}
	},
	{
		{128, -128, 384, 0},
		{128, 0, 384, 0} 
	},
	{
		{-128, -128, 384, 0},
		{-96, -192, 384, 0}
	},
	{
		{-96, -192, 384, 0},
		{-32, -240, 384, 0}
	},
	{
		{-32, -240, 384, 0},
		{0, -240, 384, 0}
	},
	{
		{128, -128, 384, 0},
		{96, -192, 384, 0}
	},
	{
		{96, -192, 384, 0},
		{32, -240, 384, 0}
	},
	{
		{32, -240, 384, 0},
		{0, -240, 384, 0}
	},

	// Vertex z-axis of arc
	{
		{-128, -128, -512, 0},
		{-128, -128, 384, 0} 
	},
	{
		{-96, -192, -512, 0},
		{-96, -192, 384, 0}
	},
	{
		{-32, -240, -512, 0},
		{-32, -240, 384, 0}
	},
	{
		{128, -128, -512, 0},
		{128, -128, 384, 0} 
	},
	{
		{96, -192, -512, 0},
		{96, -192, 384, 0}
	},
	{
		{32, -240, -512, 0},
		{32, -240, 384, 0}
	},

	// Vertex lanes on bottom
	{
		{0, 0, -384, 0},
		{0, 0, -448, 0}
	},
	{
		{0, 0, -256, 0},
		{0, 0, -320, 0} 
	},
	{
		{0, 0, -128, 0},
		{0, 0, -192, 0} 
	},
	{
		{0, 0, 0, 0},
		{0, 0, -64, 0} 
	},
	{
		{0, 0, 128, 0},
		{0, 0, 64, 0} 
	},
	{
		{0, 0, 256, 0},
		{0, 0, 192, 0} 
	},
	{
		{0, 0, 384, 0},
		{0, 0, 320, 0} 
	},

	// Lights corps
	{
		{0, -224, 256, 0},
		{0, -224, 128, 0} 
	},
	{
		{0, -224, 64, 0},
		{0, -224, -64, 0} 
	},
	{
		{0, -224, -128, 0},
		{0, -224, -256, 0} 
	},
		{
		{0, -224, -320, 0},
		{0, -224, -448, 0} 
	},
	
	// lights holder
	{
		{0, -240, 224, 0},
		{0, -224, 224, 0} 
	},
	{
		{0, -240, 160, 0},
		{0, -224, 160, 0} 
	},
	{
		{0, -240, 32, 0},
		{0, -224, 32, 0} 
	},
	{
		{0, -240, -32, 0},
		{0, -224, -32, 0} 
	},
	{
		{0, -240, -160, 0},
		{0, -224, -160, 0} 
	},
	{
		{0, -240, -222, 0},
		{0, -224, -222, 0} 
	},
	{
		{0, -240, -352, 0},
		{0, -224, -352, 0} 
	},
	{
		{0, -240, -416, 0},
		{0, -224, -416, 0} 
	},

	// Emergency exit
	{
		{-128, 0, 0, 0}, 
		{-128, -64, 0, 0}
	},
	{
		{-128, 0, 32, 0}, 
		{-128, -64, 32, 0}
	},
	{
		{-128, -64, 0, 0}, 
		{-128, -64, 32, 0}
	},
	{
		{-120, -64, 36, 0}, 
		{-128, -64, 36, 0}
	},
	{
		{-120, -60, 36, 0}, 
		{-128, -60, 36, 0}
	},
	{
		{-120, -60, 36, 0}, 
		{-120, -64, 36, 0}
	},
	{
		{-128, -60, 36, 0}, 
		{-128, -64, 36, 0}
	},

	// Limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const TunnelWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec TunnelWireframeSpec =
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
		false,
	},

	// Segments that compose the mesh
	(PixelVector(*)[2])TunnelMeshesSegments
};

ComponentSpec* const TunnelActorComponentSpecs[] = 
{
	(ComponentSpec*)&TunnelWireframeSpec,
	NULL
};

ActorROMSpec TunnelActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)TunnelActorComponentSpecs,

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
