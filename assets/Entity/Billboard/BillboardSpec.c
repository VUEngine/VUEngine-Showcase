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

const PixelVector BillboardMeshesSegments[][2]=
{
	// vertex billboard
	{
		{-64, 16, -64, 0},
		{-64, 64, -64, 0}
	},
	{
		{0, 16, -64, 0},
		{0, 64, -64, 0} 
	},

	// billboard
	{
		{-96, 16, -64, 0},
		{32, 16, -64, 0}
	},
	{
		{-96, -64, -64, 0},
		{32, -64, -64, 0}
	},
	{
		{-96, 16, -64, 0},
		{-96, -64, -64, 0}
	},
	{
		{32, 16, -64, 0},
		{32, -64, -64, 0}
	},

	// writing W
	{
		{-82, -8, -64, 0},
		{-88, -40, -64, 0}
	},
	{
		{-82, -8, -64, 0},
		{-80, -12, -64, 0}
	},
	{
		{-78, -8, -64, 0},
		{-80, -12, -64, 0}
	},
	{
		{-78, -8, -64, 0},
		{-72, -40, -64, 0}
	},

	// writing E
	{
		{-68, -8, -64, 0},
		{-68, -40, -64, 0}
	},
	{
		{-68, -40, -64, 0},
		{-60, -40, -64, 0}
	},
	{
		{-68, -8, -64, 0},
		{-60, -8, -64, 0}
	},
	{
		{-68, -24, -64, 0},
		{-60, -24, -64, 0}
	},

	// writing L
	{
		{-52, -40, -64, 0},
		{-52, -8, -64, 0}
	},
	{
		{-52, -8, -64, 0},
		{-44, -8, -64, 0}
	},
	
	// writing C
	{
		{-36, -40, -64, 0},
		{-36, -8, -64, 0}
	},
	{
		{-36, -8, -64, 0},
		{-28, -8, -64, 0}
	},
	{
		{-36, -40, -64, 0},
		{-28, -40, -64, 0}
	},

	// writing O
	{
		{-20, -40, -64, 0},
		{-20, -8, -64, 0}
	},
	{
		{-20, -8, -64, 0},
		{-12, -8, -64, 0}
	},
	{
		{-20, -40, -64, 0},
		{-12, -40, -64, 0}
	},
	{
		{-12, -40, -64, 0},
		{-12, -8, -64, 0}
	},

	// writing M
	{
		{-4, -40, -64, 0},
		{-4, -8, -64, 0}
	},
	{
		{-4, -40, -64, 0},
		{0, -8, -64, 0}
	},
	{
		{0, -8, -64, 0},
		{4, -40, -64, 0}
	},
	{
		{4, -40, -64, 0},
		{4, -8, -64, 0}
	},

	// writing E
	{
		{12, -8, -64, 0},
		{12, -40, -64, 0}
	},
	{
		{12, -40, -64, 0},
		{20, -40, -64, 0}
	},
	{
		{12, -8, -64, 0},
		{20, -8, -64, 0}
	},
	{
		{12, -24, -64, 0},
		{20, -24, -64, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const BillboardWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec BillboardWireframeSpec =
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
	(PixelVector(*)[2])BillboardMeshesSegments
};

ComponentSpec* const BillboardEntityComponentSpecs[] = 
{
	(ComponentSpec*)&BillboardWireframeSpec,
	NULL
};

EntityROMSpec BillboardEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)BillboardEntityComponentSpecs,

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
