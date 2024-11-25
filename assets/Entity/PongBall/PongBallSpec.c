/**
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

SphereROMSpec PongBallWireframeSpec =
{
	{
		// class allocator
		__TYPE(Sphere),

		// displacement
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

WireframeROMSpec* const PongBallWireframeSpecs[] =
{
	(WireframeSpec*)&PongBallWireframeSpec,
	NULL
};

ColliderROMSpec PongBallColliderSpecs[] =
{
	// ball
	{
		// collider
		__TYPE(Ball),

		// size (x, y, z)
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
	},

	{NULL, {0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0}, false, kLayerNone, kLayerNone}
};

PhysicalPropertiesROMSpec PongBallPhysicalPropertiesSpec =
{
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

PongBallROMSpec PongBallEntitySpec =
{
	{
		{
			{
				// class allocator
				__TYPE(PongBall),

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
				(WireframeSpec**)PongBallWireframeSpecs,

				// collision colliders
				(ColliderSpec*)PongBallColliderSpecs,

				// size
				// if 0, width and height will be inferred from the first sprite's texture's size
				{0, 0, 0},

				// gameworld's character's type
				kTypePongBall,

				// physical specification
				(PhysicalProperties*)&PongBallPhysicalPropertiesSpec,
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
