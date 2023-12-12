/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <PongPaddle.h>
#include <Box.h>
#include <GameConfig.h>
#include <Mesh.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

const PixelVector PongPaddleMeshesSegments[][2]=
{
	{
		{0, -8, 0, 0}, 
		{0, 8, 0, 0}, 
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

MeshROMSpec PongPaddleMesh =
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
	(PixelVector(*)[2])PongPaddleMeshesSegments
};

WireframeROMSpec* const PongPaddleWireframes[] =
{
	(WireframeSpec*)&PongPaddleMesh,
	NULL
};

ShapeROMSpec PongPaddleShapes[] =
{
/*
	// wall collider
	{
		// shape
		__TYPE(Ball),

		// size (x, y, z)
		{12, 28, 12},

		// displacement (x, y, z, p)
		{0, 0, -14, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this shape checks for collisions against other shapes
		true,

		// layers in which I live
		kLayerPongPlayfield,

		// layers to ignore when checking for collisions
		kLayerAll & ~(kLayerPongPlayfieldWalls | kLayerPongPlayfieldFloor | kLayerPongPlayfieldFloor),
	},
*/
	// collider
	{
		// shape
		__TYPE(Box),

		// size (x, y, z)
		{3, 16, 16},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this shape checks for collisions against other shapes
		false,

		// layers in which I live
		kLayerPongPlayfield,

		// layers to ignore when checking for collisions
		kLayerAll,
	},

	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};

PhysicalSpecificationROMSpec PongPaddlePhysicalProperties =
{
	// mass
	__F_TO_FIX10_6(0.55f),

	// friction
	__F_TO_FIX10_6(0.25f),

	// bounciness
	__F_TO_FIX10_6(1.0f),

	// maximum velocity
	{0, 0, 0},

	// maximum speed
	__I_TO_FIX10_6(8)
};

PongPaddleROMSpec PongPaddleEntity =
{
	{
		{
			{
				// class allocator
				__TYPE(PongPaddle),

				// children
				NULL,

				// behaviors
				NULL,

				// extra
				NULL,

				// sprites
				(SpriteSpec**)NULL,

				// use z displacement in projection
				false,
			
				// wireframes
				(WireframeSpec**)PongPaddleWireframes,

				// collision shapes
				(ShapeSpec*)PongPaddleShapes,

				// size
				// if 0, width and height will be inferred from the first sprite's texture's size
				{0, 0, 0},

				// gameworld's character's type
				kTypePongPaddle,

				// physical specification
				(PhysicalSpecification*)&PongPaddlePhysicalProperties,
			},

			// pointer to the animation spec for the item
			(const AnimationFunction**)NULL,

			// initial animation
			NULL,
		},

		// true to create a body
		true,

		// axes subject to gravity
		__NO_AXIS,

		// axis around which to rotate the entity when syncronizing with body
		__NO_AXIS
	},

	// force
	{
		0,
		__I_TO_FIX10_6(3),
		0
	}
};
