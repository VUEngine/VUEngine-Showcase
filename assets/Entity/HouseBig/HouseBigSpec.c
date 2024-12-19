/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL) <j.leucht@gmx.net>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Entity.h>
#include <Ball.h>
#include <Mesh.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

const PixelVector HouseBigMeshesSegments[][2]=
{
	// base
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

	// door
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

	// window 1
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

	// window 2
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

	// vertex
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

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

const ComponentSpec* HouseBigWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec HouseBigWireframeSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(Mesh),

			// Component type
			kWireframeComponent
		},

		// displacement
		{0, 0, 0},
		
		// color
		__COLOR_BLACK,

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false
	},

	// segments
	(PixelVector(*)[2])HouseBigMeshesSegments
};

const ComponentSpec* HouseBigEntityComponentSpecs[] = 
{
	(ComponentSpec*)&HouseBigWireframeSpec,
	NULL
};

EntityROMSpec HouseBigEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)HouseBigEntityComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// In-game entity's type
	kTypeNone
};
