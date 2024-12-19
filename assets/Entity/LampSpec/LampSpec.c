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



//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

const PixelVector LampMeshesSegments[][2]=
{

	// vertex lamp
	{
		{-56, -64, -72, 0},
		{-56, 64, -72, 0}
	},

	// lamp arch
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

	// light bulb circle
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

	// light bulb vertex
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

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

const ComponentSpec* LampWireframeComponentSpecs[] = 
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

		{0, 0, 0},
		
		// color
		__COLOR_BLACK,

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false
	},

	// segments
	(PixelVector(*)[2])LampMeshesSegments
};



ColliderROMSpec LampColliderSpec1 =
	{
		// Component
		{
			// Allocator
			__TYPE(Ball),

			// Component type
			kColliderComponent
		},

		// Size (x, y, z)
		{128, 128, 128},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerNone,

		// layers to ignore when checking for collisions
		kLayerNone
	};

const ComponentSpec* LampEntityComponentSpecs[] = 
{
	(ComponentSpec*)&LampWireframeSpec,
	(ComponentSpec*)&LampColliderSpec1,
	NULL
};

EntityROMSpec LampEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)LampEntityComponentSpecs,

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
