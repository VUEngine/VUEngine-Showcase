/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL)
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

MeshROMSpec HouseBigWireframeSpec =
{
	{
		// class allocator
		__TYPE(Mesh),

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

WireframeROMSpec* const HouseBigWireframeSpecs[] =
{
	(WireframeSpec*)&HouseBigWireframeSpec,
	NULL
};

ColliderROMSpec HouseBigColliderSpecs[] =
{
	{
		// collider
		__TYPE(Ball),

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
	},

	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};

EntityROMSpec HouseBigEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	// behaviors
	(BehaviorSpec**)NULL,

	// extra
	NULL,

	// sprites
	(SpriteSpec**)NULL,

	// use z displacement in projection
	false,

	// Wireframes
	(WireframeSpec**)HouseBigWireframeSpecs,

	// collision colliders
	(ColliderSpec*)HouseBigColliderSpecs,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	// physical specification
	(PhysicalProperties*)NULL,
};
