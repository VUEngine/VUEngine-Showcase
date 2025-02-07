////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Ball.h>
#include <Body.h>
#include <Box.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Mesh.h>
#include <PongPaddle.h>
#include <Texture.h>
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// WIREFRAMES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const PixelVector PongPaddleWireframe1WireframeSegments[][2]=
{
	{{0, 0, 0, 0}, {0, 10, 0, 0}},

	// limiter
	{{0, 0, 0, 0}, {0, 0, 0, 0}},
};

MeshROMSpec PongPaddleWireframe1WireframeSpec =
{
	// Wireframe
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(Mesh),

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

	// segments
	(PixelVector (*)[2])PongPaddleWireframe1WireframeSegments
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// COLLIDERS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ColliderROMSpec PongPaddleCollider1ColliderSpec = 
{
	// Component
	{
		// Allocator
		__TYPE(Box),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{4, 20, 16},

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f)},

	// If true this collider checks for collisions against other colliders
	false,

	// Layers in which I live
	kLayerPongPaddle,

	// Layers to ignore when checking for collisions
	kLayerAll
};
ColliderROMSpec PongPaddleCollider2ColliderSpec = 
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{20, 0, 0},

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f)},

	// If true this collider checks for collisions against other colliders
	true,

	// Layers in which I live
	kLayerPongPaddleHelper,

	// Layers to ignore when checking for collisions
	kLayerAll & ~(kLayerPongWalls)
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// BODY
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

BodyROMSpec PongPaddleBodySpec =
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
	__F_TO_FIX10_6(0.000f),

	// Friction
	__F_TO_FIX10_6(0.000f),

	// Bounciness
	__F_TO_FIX10_6(0.000f),

	// Maximum velocity
	{ __I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0) },

	// Maximum speed
	__I_TO_FIX10_6(0),

	// Axises on which the body is subject to gravity
	__NO_AXIS,

	// Axises around which to rotate the owner when syncronizing with body
	__NO_AXIS
};
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const PongPaddleComponentSpecs[] = 
{
	(ComponentSpec*)&PongPaddleWireframe1WireframeSpec,
	(ComponentSpec*)&PongPaddleCollider1ColliderSpec,
	(ComponentSpec*)&PongPaddleCollider2ColliderSpec,
	(ComponentSpec*)&PongPaddleBodySpec,
	NULL
};

PongPaddleROMSpec PongPaddleActorSpec =
{
	{
	// Class allocator
	__TYPE(PongPaddle),

	// Component specs
	(ComponentSpec**)PongPaddleComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypePongPaddle,

	// Animation to play automatically
	NULL
	},
	{0,__I_TO_FIXED(3),0},
};
