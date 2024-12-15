/**
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

const PixelVector CurveLeftMeshesSegments[][2]=
{
	// base in
	/* {
		{-128, 0, 0, 0}, 
		{128, 0, 0, 0}
	},*/

	// inner arc
	{
		{-128, 0, 0, 0}, 
		{-136.72, 0, 66.26, 0}
	},
	{
		{-136.72, 0, 66.26, 0}, 
		{-162.3, 0, 128, 0}
	},
	{
		{-162.3, 0, 128, 0}, 
		{-202.98, 0, 181.02, 0}
	},
	{
		{-202.98, 0, 181.02, 0}, 
		{-256, 0, 221.7, 0}
	},
	{
		{-256, 0, 221.7, 0}, 
		{-317.74, 0, 247.28, 0}
	},
	{
		{-317.74, 0, 247.28, 0}, 
		{-384, 0, 256, 0}
	},

	// inner guard
	{
		{-128, 0, 0, 0}, 
		{-136.72,-24, 66.26, 0}
	},
	{
		{-136.72, -24, 66.26, 0}, 
		{-162.3, -24, 128, 0}
	},
	{
		{-162.3, -24, 128, 0}, 
		{-202.98, -24, 181.02, 0}
	},
	{
		{-202.98, -24, 181.02, 0}, 
		{-256, -24, 221.7, 0}
	},
	{
		{-256, -24, 221.7, 0}, 
		{-317.74, -24, 247.28, 0}
	},
	{
		{-317.74, -24, 247.28, 0}, 
		{-384, 0, 256, 0}
	},

	// inner guard vertex
	{
		{-136.72, 0, 66.26, 0}, 
		{-136.72,-24, 66.26, 0}
	},
	{
		{-162.3, 0, 128, 0}, 
		{-162.3, -24, 128, 0}
	},
	{
		{-202.98, 0, 181.02, 0}, 
		{-202.98, -24, 181.02, 0}
	},
	{
		{-256, 0, 221.7, 0}, 
		{-256, -24, 221.7, 0}
	},
	{
		{-317.74, 0, 247.28, 0}, 
		{-317.74, -24, 247.28, 0}
	},

	// outer arc
	{
		{128, 0, 0, 0}, 
		{110.55, 0, 132.52, 0}
	},
	{
		{110.55, 0, 132.52, 0}, 
		{59.41, 0, 256, 0}
	},
	{
		{59.41, 0, 256, 0}, 
		{-21.96, 0, 362.04, 0}
	},
	{
		{-21.96, 0, 362.04, 0}, 
		{-128, 0, 443.41, 0}
	},
	{
		{-128, 0, 443.41, 0}, 
		{-251.48, 0, 494.55, 0}
	},
	{
		{-251.48, 0, 494.55, 0}, 
		{-384, 0, 512, 0}
	},

	// outer guard
	{
		{128, 0, 0, 0}, 
		{110.55, -24, 132.52, 0}
	},
	{
		{110.55, -24, 132.52, 0}, 
		{59.41, -24, 256, 0}
	},
	{
		{59.41, -24, 256, 0}, 
		{-21.96, -24, 362.04, 0}
	},
	{
		{-21.96, -24, 362.04, 0}, 
		{-128, -24, 443.41, 0}
	},
	{
		{-128, -24, 443.41, 0}, 
		{-251.48, -24, 494.55, 0}
	},
	{
		{-251.48, -24, 494.55, 0}, 
		{-384, 0, 512, 0}
	},
	
	// outer guard vertex
	{
		{110.55, 0, 132.52, 0}, 
		{110.55, -24, 132.52, 0}
	},
	{
		{59.41, 0, 256, 0}, 
		{59.41, -24, 256, 0}
	},
	{
		{-21.96, 0, 362.04, 0}, 
		{-21.96, -24, 362.04, 0}
	},
	{
		{-128, 0, 443.41, 0}, 
		{-128, -24, 443.41, 0}
	},
	{
		{-251.48, 0, 494.55, 0}, 
		{-251.48, -24, 494.55, 0}
	},

	// lanes
	/*{
		{0, 0, 0, 0}, 
		{-13.08, 0, 99.38, 0}
	},*/
	{
		{-13.08, 0, 99.38, 0}, 
		{-51.45, 0, 192, 0}
	},
	/*{
		{-51.45, 0, 192, 0}, 
		{-112.47, 0, 271.53, 0}
	},*/
	{
		{-112.47, 0, 271.53, 0}, 
		{-192, 0, 332.55, 0}
	},
	/*{
		{-192, 0, 332.55, 0}, 
		{-284.62, 0, 370.92, 0}
	},*/
	{
		{-284.62, 0, 370.92, 0}, 
		{-384, 0, 384, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

MeshROMSpec CurveLeftWireframeSpec =
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
		false,
	},

	// segments
	(PixelVector(*)[2])CurveLeftMeshesSegments
};

WireframeROMSpec* const CurveLeftWireframeSpecs[] =
{
	(WireframeSpec*)&CurveLeftWireframeSpec,
	NULL
};

ColliderROMSpec CurveLeftColliderSpecs[] =
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

EntityROMSpec CurveLeftEntitySpec =
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
	(WireframeSpec**)CurveLeftWireframeSpecs,

	// collision colliders
	(ColliderSpec*)CurveLeftColliderSpecs,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	// physical specification
	(PhysicalProperties*)NULL,
};
