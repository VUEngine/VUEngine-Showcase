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

const PixelVector ViewpointMeshesSegments[][2]=
{
	// base viewpoint area
	{
		{0, 0, 0, 0}, 
		{128, 0, 112, 0}
	},
	{
		{128, 0, 112, 0}, 
		{192, 0, 224, 0}
	},
	{
		{192, 0, 224, 0}, 
		{320, 0, 224, 0}
	},
	{
		{320, 0, 224, 0}, 
		{352, 0, 160, 0}
	},
	{
		{352, 0, 160, 0}, 
		{480, 0, 160, 0}
	},
	{
		{480, 0, 160, 0}, 
		{512, 0, 0, 0}
	},
	/*{
		{0, 0, 0, 0}, 
		{256, 0, 0, 0}
	},
	{
		{256, 0, 0, 0}, 
		{512, 0, 0, 0}
	},*/

	// fence
	{
		{128, 0, 112, 0}, 
		{128, -32, 112, 0}
	},
	{
		{192, 0, 224, 0}, 
		{192, -32, 224, 0}
	},
	{
		{128, -32, 112, 0}, 
		{192, -32, 224, 0}
	},
	{
		{192, -32, 224, 0}, 
		{320, -32, 224, 0}
	},
	{
		{320, -32, 224, 0}, 
		{352, -32, 160, 0}
	},
	{
		{320, 0, 224, 0}, 
		{320, -32, 224, 0}
	},
	{
		{352, 0, 160, 0}, 
		{352, -32, 160, 0}
	},
	{
		{352, -32, 160, 0}, 
		{480, -32, 160, 0}
	},
	{
		{480, 0, 160, 0}, 
		{480, -32, 160, 0}
	},

	// seating 1, 128 lang, 24 breit, -16 hoch
	{
		{192, -16, 32, 0}, 
		{216, -16, 32, 0}
	},
	{
		{192, -16, 32, 0}, 
		{192, -16, 160, 0}
	},
	{
		{216, -16, 32, 0}, 
		{216, -16, 160, 0}
	},
	{
		{192, -16, 160, 0}, 
		{216, -16, 160, 0}
	},
	{
		{204, -16, 36, 0}, 
		{204, 0, 36, 0}
	},
	{
		{204, -16, 156, 0}, 
		{204, 0, 156, 0}
	},

	// seating 2, 128 lang, 24 breit, -16 hoch
	{
		{280, -16, 32, 0}, 
		{304, -16, 32, 0}
	},
	{
		{280, -16, 32, 0}, 
		{280, -16, 160, 0}
	},
	{
		{304, -16, 32, 0}, 
		{304, -16, 160, 0}
	},
	{
		{280, -16, 160, 0}, 
		{304, -16, 160, 0}
	},
	{
		{292, -16, 36, 0}, 
		{292, 0, 36, 0}
	},
	{
		{292, -16, 156, 0}, 
		{292, 0, 156, 0}
	},

	// Tisch, 128 lang, 44 breit, -30 hoch
	{
		{226, -30, 32, 0}, 
		{226, -30, 160, 0}
	},
	{
		{270, -30, 32, 0}, 
		{270, -30, 160, 0}
	},
	{
		{226, -30, 160, 0}, 
		{270, -30, 160, 0}
	},
	{
		{226, -30, 32, 0}, 
		{270, -30, 32, 0}
	},
	{
		{248, -30, 156, 0}, 
		{230, 0, 156, 0}
	},
	{
		{248, -30, 156, 0}, 
		{266, 0, 156, 0}
	},
	{
		{248, -30, 36, 0}, 
		{230, 0, 36, 0}
	},
	{
		{248, -30, 36, 0}, 
		{266, 0, 36, 0}
	},

	// wastebin, 16x16, -24 hoch, oben 20x20
	{
		{156, 0, 60, 0}, 
		{140, 0, 60, 0}
	},
	{
		{156, 0, 60, 0}, 
		{156, 0, 76, 0}
	},
	{
		{140, 0, 60, 0}, 
		{140, 0, 76, 0}
	},
	{
		{140, 0, 76, 0}, 
		{156, 0, 76, 0}
	},

	{
		{158, -24, 58, 0}, 
		{138, -24, 58, 0}
	},
	{
		{158, -24, 58, 0}, 
		{158, -24, 78, 0}
	},
	{
		{138, -24, 58, 0}, 
		{138, -24, 78, 0}
	},
	{
		{138, -24, 78, 0}, 
		{158, -24, 78, 0}
	},

	{
		{158, -24, 58, 0}, 
		{156, 0, 60, 0}
	},
	{
		{138, -24, 58, 0}, 
		{140, 0, 60, 0}
	},
	{
		{158, -24, 78, 0}, 
		{156, 0, 76, 0}
	},
	{
		{138, -24, 78, 0}, 
		{140, 0, 76, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const ViewpointWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec ViewpointWireframeSpec =
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
	(PixelVector(*)[2])ViewpointMeshesSegments
};

ComponentSpec* const ViewpointActorComponentSpecs[] = 
{
	(ComponentSpec*)&ViewpointWireframeSpec,
	NULL
};

ActorROMSpec ViewpointActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)ViewpointActorComponentSpecs,

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
