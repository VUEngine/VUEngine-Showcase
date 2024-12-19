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

const ComponentSpec* BillboardWireframeSpecComponentSpecs[] = 
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

		{0, 0, 0},
		
		// color
		__COLOR_BLACK,

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false
	},

	// segments
	(PixelVector(*)[2])BillboardMeshesSegments
};



ColliderROMSpec BillboardColliderSpecsCollider1 =
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

const ComponentSpec* BillboardEntitySpecComponentSpecs[] = 
{
	(ComponentSpec*)&BillboardWireframeSpec,
    (ComponentSpec*)&BillboardColliderSpecsCollider1,
	NULL
};

EntityROMSpec BillboardEntitySpec =
{
	// class allocator	
	__TYPE(Entity),

	// Components
	(ComponentSpec**)BillboardEntitySpecComponentSpecs,

	// children
	NULL,

	// extra
	NULL,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone
};
