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

const PixelVector StreetEndMeshesSegments[][2]=
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
		{-128, 0, -64, 0}
	},
		{
		{-128, 0, -64, 0},
		{-128, 0, -512, 0}
	},
	{
		{128, 0, 384, 0},
		{128, 0, -64, 0} 
	},
	{
		{128, 0, -64, 0},
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

ComponentSpec* const StreetEndWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec StreetEndWireframeSpec =
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
	(PixelVector(*)[2])StreetEndMeshesSegments
};

ComponentSpec* const StreetEndActorComponentSpecs[] = 
{
	(ComponentSpec*)&StreetEndWireframeSpec,
	NULL
};

ActorROMSpec StreetEndActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)StreetEndActorComponentSpecs,

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

