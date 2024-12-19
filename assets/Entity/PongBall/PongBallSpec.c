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

#include <Ball.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <PongBall.h>
#include <Sphere.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

const ComponentSpec* PongBallWireframeComponentSpecs[] = 
{
	NULL
};

SphereROMSpec PongBallWireframeSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(Sphere),

			// Component type
			kWireframeComponent
		},

		{0, 0, 0},
		
		// color
		__COLOR_BLACK,

		// transparency
		__TRANSPARENCY_NONE,

		// interlaced
		false
	},

	// radius
	__PIXELS_TO_METERS(4),

	// draw center
	true,
};

ColliderROMSpec PongBallCollider =
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{6, 6, 6},

	// displacement (x, y, z, p)
	{0, 0, 0, 0},

	// rotation (x, y, z)
	{0, 0, 0},

	// scale (x, y, z)
	{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

	// if true this collider checks for collisions against other colliders
	true,

	// layers in which I live
	kLayerPongBall,

	// layers to ignore when checking for collisions
	kLayerAll & ~(kLayerPongWalls | kLayerPongPaddle)
};

BodyROMSpec PongBallBodySpec =
{
	// Component
	{
		// Allocator
		__TYPE(Body),

		// Component type
		kPhysicsComponent
	},

	// mass
	__F_TO_FIX10_6(0.1f),

	// friction
	__F_TO_FIX10_6(0.0f),

	// bounciness
	__F_TO_FIX10_6(1.0f),

	// maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// maximum speed
	__I_TO_FIXED(2)
};

const ComponentSpec* PongBallEntityComponentSpecs[] = 
{
	(ComponentSpec*)&PongBallBodySpec,
	(ComponentSpec*)&PongBallWireframeSpec,
	(ComponentSpec*)&PongBallCollider,
	NULL
};

PongBallROMSpec PongBallEntitySpec =
{
	{
		{
			{
				// Class allocator				
				__TYPE(PongBall),

				// Component specs
				(ComponentSpec**)PongBallEntityComponentSpecs,

				// Children specs
				NULL,

				// Extra info
				NULL,

				

				
			
				

				

				// Size
				// If 0, it is computed from the visual components if any
				{0, 0, 0},

				// In-game entity's type
				kTypePongBall,

				
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

	// minimum velocity
	{0, 0, 0},
	
	// maximum velocity
	{__I_TO_FIXED(2), __I_TO_FIXED(2), __I_TO_FIXED(0)},
};
