/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
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

const PixelVector PyramidMeshesSegments[][2]=
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
		{-64, 64, 64, 0}, 
	},
	{
		{64, 64, -64, 0},
		{64, 64, 64, 0}
	},

	// vertex
	{
		{0, -64, 0, 0},
		{-64, 64, -64, 0}
	},
	{
		{0, -64, 0, 0},
		{-64, 64, 64, 0}
	},
	{
		{0, -64, 0, 0},
		{64, 64, -64, 0}, 
	},
	{
		{0, -64, 0, 0},
		{64, 64, 64, 0},
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

ComponentSpec* const PyramidWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec PyramidWireframeSpec =
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
		
		// Wireframe's lines' color
		__COLOR_BLACK,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false,
	},

	// Segments that compose the mesh
	(PixelVector(*)[2])PyramidMeshesSegments
};



ColliderROMSpec PyramidColliderSpec1 =
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

		// Displacement (x, y, z, p)
		{0, 0, 0, 0},

		// Rotation (x, y, z)
		{0, 0, 0},

		// Scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// If true this collider checks for collisions against other colliders
		false,

		// Layers in which I live
		kLayerNone,

		// Layers to ignore when checking for collisions
		kLayerNone
	};

ComponentSpec* const PyramidEntityComponentSpecs[] = 
{
	(ComponentSpec*)&PyramidWireframeSpec,
	(ComponentSpec*)&PyramidColliderSpec1,
	NULL
};

EntityROMSpec PyramidEntitySpec =
{
	// Class allocator	
	__TYPE(Entity),

	// Component specs
	(ComponentSpec**)PyramidEntityComponentSpecs,

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
