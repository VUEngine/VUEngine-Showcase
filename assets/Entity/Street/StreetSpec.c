/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL) <j.leucht@gmx.net>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Entity.h>
#include <Ball.h>
#include <Mesh.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

const PixelVector StreetMeshesSegments[][2]=
{
	// base
	{
		{-128, 0, -512, 0}, 
		{128, 0, -512, 0}
	},
	/*{
		{-128, 0, 384, 0}, 
		{128, 0, 384, 0}
	},*/

	// vertex
	{
		{-128, 0, 384, 0},
		{-128, 0, -512, 0}
	},
	{
		{128, 0, 384, 0},
		{128, 0, -512, 0} 
	},
	
		// vertex lanes
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

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const StreetWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec StreetWireframeSpec =
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
		false,
	},

	// Segments that compose the mesh
	(PixelVector(*)[2])StreetMeshesSegments
};

ComponentSpec* const StreetEntityComponentSpecs[] = 
{
	(ComponentSpec*)&StreetWireframeSpec,
	NULL
};

EntityROMSpec StreetEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)StreetEntityComponentSpecs,

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
