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

const PixelVector PowerPoleMeshesSegments[][2]=
{
	// base Vorderseite
	{
		{-56, 0, -16, 0}, 
		{-32, -48, -12, 0}
	},
	{
		{56, 0, -16, 0}, 
		{32, -48, -12, 0}
	},
	{
		{-32, -48, -12, 0}, 
		{32, -48, -12, 0}
	},
	{
		{-32, -48, -12, 0}, 
		{-16, -256, -12, 0}
	},
	{
		{32, -48, -12, 0}, 
		{16, -256, -12, 0}
	},
	
	// base Rückseite
	{
		{-56, 0, 16, 0}, 
		{-32, -48, 12, 0}
	},
	{
		{56, 0, 16, 0}, 
		{32, -48, 12, 0}
	},
	{
		{-32, -48, 12, 0}, 
		{32, -48, 12, 0}
	},
	{
		{-32, -48, 12, 0}, 
		{-16, -256, 12, 0}
	},
	{
		{32, -48, 12, 0}, 
		{16, -256, 12, 0}
	},

	// Verbindung z-Achse base
	{
		{32, -48, 12, 0}, 
		{32, -48, -12, 0}
	},
	{
		{-32, -48, 12, 0}, 
		{-32, -48, -12, 0}
	},
	{
		{16, -256, -12, 0}, 
		{16, -256, 12, 0}
	},
	{
		{-16, -256, -12, 0}, 
		{-16, -256, 12, 0}
	},

	// erste Strebe Vorderseite
	{
		{-22.135, -176, 12, 0}, 
		{-96, -144, 12, 0}
	},
	{
		{22.135, -176, 12, 0}, 
		{96, -144, 12, 0}
	},
	{
		{-22.135, -176, 12, 0}, 
		{22.135, -176, 12, 0}
	},
	{
		{-96, -144, 12, 0}, 
		{96, -144, 12, 0}
	},

	// Verbindung z-Achse erste Strebe
	{
		{96, -144, -12, 0}, 
		{96, -144, 12, 0}
	},
	{
		{-96, -144, -12, 0}, 
		{-96, -144, 12, 0}
	},
	{
		{-22.135, -176, -12, 0}, 
		{-22.135, -176, 12, 0}
	},
	{
		{22.135, -176, -12, 0}, 
		{22.135, -176, 12, 0}
	},

	// Halter erste Strebe
	{
		{88, -144, 0, 0}, 
		{84, -132, 0, 0}
	},

	// Halter erste Strebe
	{
		{80, -144, 0, 0}, 
		{84, -132, 0, 0}
	},

	// zweiter Halter erste Strebe
	{
		{-88, -144, 0, 0}, 
		{-84, -132, 0, 0}
	},

	// zweiter Halter erste Strebe
	{
		{-80, -144, 0, 0}, 
		{-84, -132, 0, 0}
	},

	// erste Strebe Rückseite
	
	{
		{-22.135, -176, -12, 0}, 
		{-96, -144, -12, 0}
	},
	{
		{22.135, -176, -12, 0}, 
		{96, -144, -12, 0}
	},
	{
		{-22.135, -176, -12, 0}, 
		{22.135, -176, -12, 0}
	},
	{
		{-96, -144, -12, 0}, 
		{96, -144, -12, 0}
	},

	// zweite Strebe Vorderseite
	{
		{-16, -256, -12, 0}, 
		{-80, -224, -12, 0}
	},
	{
		{16, -256, -12, 0}, 
		{80, -224, -12, 0}
	},
	{
		{-80, -224, -12, 0}, 
		{80, -224, -12, 0}
	},
	{
		{-16, -256, -12, 0}, 
		{16, -256, -12, 0}
	},
	
	// Halter zweite Strebe
	{
		{-72, -224, 0, 0}, 
		{-68, -212, 0, 0}
	},
	{
		{-64, -224, 0, 0}, 
		{-68, -212, 0, 0}
	},

	// zweiter Halter zweite Strebe
	{
		{72, -224, 0, 0}, 
		{68, -212, 0, 0}
	},
	{
		{64, -224, 0, 0}, 
		{68, -212, 0, 0}
	},

	//zweite Strebe Rückseite
	{
		{-16, -256, 12, 0}, 
		{-80, -224, 12, 0}
	},
	{
		{16, -256, 12, 0}, 
		{80, -224, 12, 0}
	},
	{
		{-80, -224, 12, 0}, 
		{80, -224, 12, 0}
	},
	{
		{-16, -256, 12, 0}, 
		{16, -256, 12, 0}
	},

	// Verbindung z-Achse zweite Strebe
	{
		{-80, -224, -12, 0}, 
		{-80, -224, 12, 0}
	},
	{
		{80, -224, -12, 0}, 
		{80, -224, 12, 0}
	},

	// Spitze	
	{
		{16, -256, 12, 0}, 
		{0, -320, 0, 0}
	},
	{
		{-16, -256, 12, 0}, 
		{0, -320, 0, 0}
	},
	{
		{16, -256, -12, 0}, 
		{0, -320, 0, 0}
	},
	{
		{-16, -256, -12, 0}, 
		{0, -320, 0, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const PowerPoleWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec PowerPoleWireframeSpec =
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
	(PixelVector(*)[2])PowerPoleMeshesSegments
};

ComponentSpec* const PowerPoleActorComponentSpecs[] = 
{
	(ComponentSpec*)&PowerPoleWireframeSpec,
	NULL
};

ActorROMSpec PowerPoleActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)PowerPoleActorComponentSpecs,

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

