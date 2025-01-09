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

const PixelVector StreetInclinedMeshesSegments[][2]=
{
	// Straße -96 hoch, 384 lang und 14,036° Steigung
	// base
	{
		{-128, 0, 384, 0}, 
		{-128, -96, 0, 0}
	},
	{
		{128, 0, 384, 0}, 
		{128, -96, 0, 0}
	},
	
	// lanes
	{
		{0, -96, 0, 0},
		{0, -77.61, 64, 0}
	},
	{
		{0, -31.04, 256, 0},
		{0, -15.52, 320, 0} 
	},
	{
		{0, -46.57, 192, 0},
		{0, -62.09, 128, 0} 
	},

	// guards, 24 hoch
	{
		{-128, 0, 384, 0},
		{-128, -31.761, 352, 0} 
	},
	{
		{-128, -31.761, 352, 0},
		{-128, -109.37, 32, 0} 
	},
	{
		{-128, -109.37, 32, 0},
		{-128, -96, 0, 0} 
	},
	{
		{128, 0, 384, 0},
		{128, -31.761, 352, 0} 
	},
	{
		{128, -31.761, 352, 0},
		{128, -109.37, 32, 0} 
	},
	{
		{128, -109.37, 32, 0},
		{128, -96, 0, 0} 
	},

	// guards holder
	{
		{128, -62.09, 128, 0},
		{128, -84.67, 133.65, 0} 
	},
	{
		{128, -31.04, 256, 0},
		{128, -53.62, 261.65, 0} 
	},
	{
		{128, -9.181, 346.35, 0},
		{128, -31.761, 352, 0} 
	},
	{
		{128, -109.37, 32, 0},
		{128, -86.79, 26.35, 0} 
	},
	{
		{-128, -62.09, 128, 0},
		{-128, -84.67, 133.65, 0} 
	},
	{
		{-128, -31.04, 256, 0},
		{-128, -53.62, 261.65, 0} 
	},
	{
		{-128, -9.181, 346.35, 0},
		{-128, -31.761, 352, 0} 
	},
	{
		{-128, -109.37, 32, 0},
		{-128, -86.79, 26.35, 0} 
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const StreetInclinedWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec StreetInclinedWireframeSpec =
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
	(PixelVector(*)[2])StreetInclinedMeshesSegments
};

ComponentSpec* const StreetInclinedActorComponentSpecs[] = 
{
	(ComponentSpec*)&StreetInclinedWireframeSpec,
	NULL
};

ActorROMSpec StreetInclinedActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)StreetInclinedActorComponentSpecs,

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
