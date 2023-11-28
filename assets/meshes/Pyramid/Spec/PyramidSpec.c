/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Entity.h>
#include <Ball.h>
#include <Mesh.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

const PixelVector PyramidEntityMeshesSegments[][2]=
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

MeshROMSpec PyramidEntityMesh =
{
	{
		/// class allocator
		__TYPE(Mesh),

		/// displacement
		{0, 0, 0},
		
		/// color
		__COLOR_BLACK,

		/// transparent
		__TRANSPARENCY_NONE,

		/// interlaced
		false
	},

	/// segments
	(PixelVector(*)[2])PyramidEntityMeshesSegments
};

WireframeROMSpec* const PyramidEntityWireframes[] =
{
	(WireframeSpec*)&PyramidEntityMesh,
	NULL
};

ShapeROMSpec PyramidEntityShapes[] =
{
	{
		// shape
		__TYPE(Ball),

		// size (x, y, z)
		{128, 128, 128},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this shape checks for collisions against other shapes
		false,

		// layers in which I live
		kLayerNone,

		// layers to ignore when checking for collisions
		kLayerNone
	},

	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};

EntityROMSpec PyramidEntity =
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

	/// Wireframes
	(WireframeSpec**)PyramidEntityWireframes,

	/// collision shapes
	(ShapeSpec*)PyramidEntityShapes,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	// physical specification
	(PhysicalSpecification*)NULL,
};
