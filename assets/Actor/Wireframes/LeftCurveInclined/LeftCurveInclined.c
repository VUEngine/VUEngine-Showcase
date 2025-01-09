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

const PixelVector LeftCurveInclinedMeshesSegments[][2]=
{
	// +16 bei jedem Winkel, bis +96 insgesamt

	// base in
	/* {
		{-128, 0, 0, 0}, 
		{128, 0, 0, 0}
	},*/

	// inner arc
	{
		{-128, 0, 0, 0}, 
		{-136.72, 16, 66.26, 0}
	},
	{
		{-136.72, 16, 66.26, 0}, 
		{-162.3, 32, 128, 0}
	},
	{
		{-162.3, 32, 128, 0}, 
		{-202.98, 48, 181.02, 0}
	},
	{
		{-202.98, 48, 181.02, 0}, 
		{-256, 64, 221.7, 0}
	},
	{
		{-256, 64, 221.7, 0}, 
		{-317.74, 80, 247.28, 0}
	},
	{
		{-317.74, 80, 247.28, 0}, 
		{-384, 96, 256, 0}
	},

	// inner guard
	{
		{-128, 0, 0, 0}, 
		{-136.72, -8, 66.26, 0}
	},
	{
		{-136.72, -8, 66.26, 0}, 
		{-162.3, 8, 128, 0}
	},
	{
		{-162.3, 8, 128, 0}, 
		{-202.98, 24, 181.02, 0}
	},
	{
		{-202.98, 24, 181.02, 0}, 
		{-256, 40, 221.7, 0}
	},
	{
		{-256, 40, 221.7, 0}, 
		{-317.74, 56, 247.28, 0}
	},
	{
		{-317.74, 56, 247.28, 0}, 
		{-384, 96, 256, 0}
	},

	// inner guard vertex
	{
		{-136.72, 16, 66.26, 0}, 
		{-136.72, -8, 66.26, 0}
	},
	{
		{-162.3, 32, 128, 0}, 
		{-162.3, 8, 128, 0}
	},
	{
		{-202.98, 48, 181.02, 0}, 
		{-202.98, 24, 181.02, 0}
	},
	{
		{-256, 64, 221.7, 0}, 
		{-256, 40, 221.7, 0}
	},
	{
		{-317.74, 80, 247.28, 0}, 
		{-317.74, 56, 247.28, 0}
	},

	// outer arc
	{
		{128, 0, 0, 0}, 
		{110.55, 16, 132.52, 0}
	},
	{
		{110.55, 16, 132.52, 0}, 
		{59.41, 32, 256, 0}
	},
	{
		{59.41, 32, 256, 0}, 
		{-21.96, 48, 362.04, 0}
	},
	{
		{-21.96, 48, 362.04, 0}, 
		{-128, 64, 443.41, 0}
	},
	{
		{-128, 64, 443.41, 0}, 
		{-251.48, 80, 494.55, 0}
	},
	{
		{-251.48, 80, 494.55, 0}, 
		{-384, 96, 512, 0}
	},

	// outer guard
	{
		{128, 0, 0, 0}, 
		{110.55, -8, 132.52, 0}
	},
	{
		{110.55, -8, 132.52, 0}, 
		{59.41, 8, 256, 0}
	},
	{
		{59.41, 8, 256, 0}, 
		{-21.96, 24, 362.04, 0}
	},
	{
		{-21.96, 24, 362.04, 0}, 
		{-128, 40, 443.41, 0}
	},
	{
		{-128, 40, 443.41, 0}, 
		{-251.48, 56, 494.55, 0}
	},
	{
		{-251.48, 56, 494.55, 0}, 
		{-384, 96, 512, 0}
	},
	
	// outer guard vertex
	{
		{110.55, 16, 132.52, 0}, 
		{110.55, -8, 132.52, 0}
	},
	{
		{59.41, 32, 256, 0}, 
		{59.41, 8, 256, 0}
	},
	{
		{-21.96, 48, 362.04, 0}, 
		{-21.96, 24, 362.04, 0}
	},
	{
		{-128, 64, 443.41, 0}, 
		{-128, 40, 443.41, 0}
	},
	{
		{-251.48, 80, 494.55, 0}, 
		{-251.48, 56, 494.55, 0}
	},

	// lanes
	/*{
		{0, 0, 0, 0}, 
		{-13.08, 16, 99.38, 0}
	},*/
	{
		{-13.08, 16, 99.38, 0}, 
		{-51.45, 32, 192, 0}
	},
	/*{
		{-51.45, 32, 192, 0}, 
		{-112.47, 48, 271.53, 0}
	},*/
	{
		{-112.47, 48, 271.53, 0}, 
		{-192, 64, 332.55, 0}
	},
	/*{
		{-192, 64, 332.55, 0}, 
		{-284.62, 80, 370.92, 0}
	},*/
	{
		{-284.62, 80, 370.92, 0}, 
		{-384, 96, 384, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},	
};

ComponentSpec* const LeftCurveInclinedWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec LeftCurveInclinedWireframeSpec =
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
	(PixelVector(*)[2])LeftCurveInclinedMeshesSegments
};

ComponentSpec* const LeftCurveInclinedActorComponentSpecs[] = 
{
	(ComponentSpec*)&LeftCurveInclinedWireframeSpec,
	NULL
};

ActorROMSpec LeftCurveInclinedActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)LeftCurveInclinedActorComponentSpecs,

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
