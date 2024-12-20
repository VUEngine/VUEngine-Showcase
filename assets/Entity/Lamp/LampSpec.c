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

ComponentSpec* const LampWireframeComponentSpecs[] = 
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
	(PixelVector(*)[2])LampMeshesSegments
};

ComponentSpec* const LampEntityComponentSpecs[] = 
{
	(ComponentSpec*)&LampWireframeSpec,
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

	// Entity's in-game type
	kTypeNone
};
