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

const PixelVector CurveLeftMeshesSegments[][2]=
{
	// Base in
	/* {
		{-128, 0, 0, 0}, 
		{128, 0, 0, 0}
	},*/

	// Inner arc
	{
		{-128, 0, 0, 0}, 
		{-136.72, 0, 66.26, 0}
	},
	{
		{-136.72, 0, 66.26, 0}, 
		{-162.3, 0, 128, 0}
	},
	{
		{-162.3, 0, 128, 0}, 
		{-202.98, 0, 181.02, 0}
	},
	{
		{-202.98, 0, 181.02, 0}, 
		{-256, 0, 221.7, 0}
	},
	{
		{-256, 0, 221.7, 0}, 
		{-317.74, 0, 247.28, 0}
	},
	{
		{-317.74, 0, 247.28, 0}, 
		{-384, 0, 256, 0}
	},

	// Inner guard
	{
		{-128, 0, 0, 0}, 
		{-136.72,-24, 66.26, 0}
	},
	{
		{-136.72, -24, 66.26, 0}, 
		{-162.3, -24, 128, 0}
	},
	{
		{-162.3, -24, 128, 0}, 
		{-202.98, -24, 181.02, 0}
	},
	{
		{-202.98, -24, 181.02, 0}, 
		{-256, -24, 221.7, 0}
	},
	{
		{-256, -24, 221.7, 0}, 
		{-317.74, -24, 247.28, 0}
	},
	{
		{-317.74, -24, 247.28, 0}, 
		{-384, 0, 256, 0}
	},

	// Inner guard vertex
	{
		{-136.72, 0, 66.26, 0}, 
		{-136.72,-24, 66.26, 0}
	},
	{
		{-162.3, 0, 128, 0}, 
		{-162.3, -24, 128, 0}
	},
	{
		{-202.98, 0, 181.02, 0}, 
		{-202.98, -24, 181.02, 0}
	},
	{
		{-256, 0, 221.7, 0}, 
		{-256, -24, 221.7, 0}
	},
	{
		{-317.74, 0, 247.28, 0}, 
		{-317.74, -24, 247.28, 0}
	},

	// Outer arc
	{
		{128, 0, 0, 0}, 
		{110.55, 0, 132.52, 0}
	},
	{
		{110.55, 0, 132.52, 0}, 
		{59.41, 0, 256, 0}
	},
	{
		{59.41, 0, 256, 0}, 
		{-21.96, 0, 362.04, 0}
	},
	{
		{-21.96, 0, 362.04, 0}, 
		{-128, 0, 443.41, 0}
	},
	{
		{-128, 0, 443.41, 0}, 
		{-251.48, 0, 494.55, 0}
	},
	{
		{-251.48, 0, 494.55, 0}, 
		{-384, 0, 512, 0}
	},

	// Outer guard
	{
		{128, 0, 0, 0}, 
		{110.55, -24, 132.52, 0}
	},
	{
		{110.55, -24, 132.52, 0}, 
		{59.41, -24, 256, 0}
	},
	{
		{59.41, -24, 256, 0}, 
		{-21.96, -24, 362.04, 0}
	},
	{
		{-21.96, -24, 362.04, 0}, 
		{-128, -24, 443.41, 0}
	},
	{
		{-128, -24, 443.41, 0}, 
		{-251.48, -24, 494.55, 0}
	},
	{
		{-251.48, -24, 494.55, 0}, 
		{-384, 0, 512, 0}
	},
	
	// outer guard vertex
	{
		{110.55, 0, 132.52, 0}, 
		{110.55, -24, 132.52, 0}
	},
	{
		{59.41, 0, 256, 0}, 
		{59.41, -24, 256, 0}
	},
	{
		{-21.96, 0, 362.04, 0}, 
		{-21.96, -24, 362.04, 0}
	},
	{
		{-128, 0, 443.41, 0}, 
		{-128, -24, 443.41, 0}
	},
	{
		{-251.48, 0, 494.55, 0}, 
		{-251.48, -24, 494.55, 0}
	},

	// Lanes
	/*{
		{0, 0, 0, 0}, 
		{-13.08, 0, 99.38, 0}
	},*/
	{
		{-13.08, 0, 99.38, 0}, 
		{-51.45, 0, 192, 0}
	},
	/*{
		{-51.45, 0, 192, 0}, 
		{-112.47, 0, 271.53, 0}
	},*/
	{
		{-112.47, 0, 271.53, 0}, 
		{-192, 0, 332.55, 0}
	},
	/*{
		{-192, 0, 332.55, 0}, 
		{-284.62, 0, 370.92, 0}
	},*/
	{
		{-284.62, 0, 370.92, 0}, 
		{-384, 0, 384, 0}
	},

	// Limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

MeshROMSpec CurveLeftWireframeSpec =
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
	(PixelVector(*)[2])CurveLeftMeshesSegments
};

ComponentSpec* const  CurveLeftComponentSpecs[] =
{
	(ComponentSpec*)&CurveLeftWireframeSpec,
	NULL
};

ActorROMSpec CurveLeftActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Components
	(ComponentSpec**)CurveLeftComponentSpecs,

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
