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

#include <Ball.h>
#include <Body.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <PongBall.h>
#include <Sphere.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PongBallWireframeComponentSpecs[] = 
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
		
		// Wireframe's lines' color
		__COLOR_BLACK,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false
	},

	// Radius
	__PIXELS_TO_METERS(4),

	// Draw center
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

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

	// If true this collider checks for collisions against other colliders
	true,

	// Layers in which I live
	kLayerPongBall,

	// Layers to ignore when checking for collisions
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

	// Create body
	true,

	// Mass
	__F_TO_FIX10_6(0.1f),

	// Friction
	__F_TO_FIX10_6(0.0f),

	// Bounciness
	__F_TO_FIX10_6(1.0f),

	// Maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// Maximum speed
	__I_TO_FIXED(2),

	// Axises on which the body is subject to gravity
	__NO_AXIS,

	// Axises around which to rotate the owner when syncronizing with body
	__NO_AXIS
};

ComponentSpec* const PongBallActorComponentSpecs[] = 
{
	(ComponentSpec*)&PongBallBodySpec,
	(ComponentSpec*)&PongBallWireframeSpec,
	(ComponentSpec*)&PongBallCollider,
	NULL
};

PongBallROMSpec PongBallActorSpec =
{
	{
		{
			// Class allocator
			__TYPE(PongBall),

			// Component specs
			(ComponentSpec**)PongBallActorComponentSpecs,

			// Children specs
			NULL,

			// Extra info
			NULL,

			// Size
			// If 0, it is computed from the visual components if any
			{0, 0, 0},

			// Actor's in-game type
			kTypePongBall				,

			// Pointer to animation functions array
			(const AnimationFunction**)NULL,

			// Animation to play automatically
			NULL,
		},
	},

	// Minimum velocity
	{0, 0, 0},
	
	// Maximum velocity
	{__I_TO_FIXED(2), __I_TO_FIXED(2), __I_TO_FIXED(0)},
};
