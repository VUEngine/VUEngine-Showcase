////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Ball.h>
#include <Body.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <PongBall.h>
#include <Sphere.h>
#include <Texture.h>
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// WIREFRAMES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SphereROMSpec PongBallWireframe1WireframeSpec =
{
	// Wireframe
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(Sphere),

				// Component type
				kWireframeComponent
			},

			// Array of function animations
			(const AnimationFunction**)NULL
		},

		// Displacement
		{0, 0, 0},
		
		// color
		__COLOR_BRIGHT_RED,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false,
	},

	// radius
	__PIXELS_TO_METERS(4),

	// draw center
	false
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// COLLIDERS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ColliderROMSpec PongBallCollider1ColliderSpec = 
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{4, 0, 0},

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{ __F_TO_FIX7_9(0.000f), __F_TO_FIX7_9(0.000f), __F_TO_FIX7_9(0.000f) },

	// Scale (x, y, z)
	{ __F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f) },

	// If true this collider checks for collisions against other colliders
	true,

	// Layers in which I live
	kLayerPongBall,

	// Layers to ignore when checking for collisions
	kLayerAll & ~(kLayerPongWalls | kLayerPongPaddle)
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// BODY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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
	__F_TO_FIX10_6(0.100f),

	// Friction
	__F_TO_FIX10_6(0.000f),

	// Bounciness
	__F_TO_FIX10_6(1.000f),

	// Maximum velocity
	{ __I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0) },

	// Maximum speed
	__I_TO_FIX10_6(2),

	// Axises on which the body is subject to gravity
	__NO_AXIS,

	// Axises around which to rotate the owner when syncronizing with body
	__NO_AXIS
};
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PongBallComponentSpecs[] = 
{
	(ComponentSpec*)&PongBallWireframe1WireframeSpec,
	(ComponentSpec*)&PongBallCollider1ColliderSpec,
	(ComponentSpec*)&PongBallBodySpec,
	NULL
};

PongBallROMSpec PongBallActorSpec =
{
	{
	// Class allocator
	__TYPE(PongBall),

	// Component specs
	(ComponentSpec**)PongBallComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypePongBall,

	// Animation to play automatically
	NULL
	},
	{0,0,0},
	{__I_TO_FIXED(2),__I_TO_FIXED(2),0},
};
