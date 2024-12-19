/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <PongPaddle.h>
#include <Box.h>
#include <Ball.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Mesh.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

const PixelVector PongPaddleWireframeSpecSegments[][2]=
{
	{
		{0, -10, 0, 0}, 
		{0, 10, 0, 0}, 
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

const ComponentSpec* PongPaddleWireframeComponentSpecs[] = 
{
	NULL
};

MeshROMSpec PongPaddleWireframeSpec =
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

		// transparency
		__TRANSPARENCY_NONE,

		// interlaced
		false,
	},

	// segments
	(PixelVector(*)[2])PongPaddleWireframeSpecSegments
};

ColliderROMSpec PongPaddleColliderSpec1 =
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{16, 20, 16},

	// displacement (x, y, z, p)
	{0, 0, 0, 0},

	// rotation (x, y, z)
	{0, 0, 0},

	// scale (x, y, z)
	{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

	// if true this collider checks for collisions against other colliders
	true,

	// layers in which I live
	kLayerPongPaddleHelper,

	// layers to ignore when checking for collisions
	kLayerAll & ~(kLayerPongWalls)
};

ColliderROMSpec PongPaddleColliderSpec2 =
{
	// Component
	{
		// Allocator
		__TYPE(Box),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{3, 20, 16},

	// displacement (x, y, z, p)
	{0, 0, 0, 0},

	// rotation (x, y, z)
	{0, 0, 0},

	// scale (x, y, z)
	{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

	// if true this collider checks for collisions against other colliders
	false,

	// layers in which I live
	kLayerPongPaddle,

	// layers to ignore when checking for collisions
	kLayerAll
};

BodyROMSpec PongPaddleBodySpecSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Body),

		// Component type
		kPhysicsComponent
	},

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

const ComponentSpec* PongPaddleEntityComponentSpecs[] = 
{
	(ComponentSpec*)&PongPaddleBodySpecSpec,
	(ComponentSpec*)&PongPaddleWireframeSpec,
	(ComponentSpec*)&PongPaddleColliderSpec1,
	(ComponentSpec*)&PongPaddleColliderSpec2,
	NULL
};

PongPaddleROMSpec PongPaddleEntitySpec =
{
	{
		{
			{
				// Class allocator				
				__TYPE(PongPaddle),

				// Component specs
				(ComponentSpec**)PongPaddleEntityComponentSpecs,

				// Children specs
				NULL,

				// Extra info
				NULL,

				// Size
				// If 0, it is computed from the visual components if any
				{0, 0, 0},

				// In-game entity's type
				kTypePongPaddle
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
