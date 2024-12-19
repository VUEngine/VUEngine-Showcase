/**
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

const ComponentSpec* StreetWireframeSpecComponentSpecs[] = 
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

		{0, 0, 0},
		
		// color
		__COLOR_BLACK,

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false,
	},

	// segments
	(PixelVector(*)[2])StreetMeshesSegments
};



ColliderROMSpec StreetColliderSpecsCollider1 =
	{
		// Component
		{
			// Allocator
			__TYPE(Ball),

			// Component type
			kColliderComponent
		},

		// size (x, y, z)
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



const ComponentSpec* StreetEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)StreetWireframeSpec,
    (ComponentSpec*)StreetColliderSpecsCollider1,
	NULL
};

EntityROMSpec StreetEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpecs**)StreetEntitySpecComponentSpecs,

	// children
	NULL,

	

	// extra
	NULL,

	

	// use z displacement in projection
	false,

	

	

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	
};
