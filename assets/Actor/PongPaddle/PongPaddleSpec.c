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

#include <Body.h>
#include <Box.h>
#include <Ball.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Mesh.h>
#include <PongPaddle.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

ComponentSpec* const PongPaddleWireframeComponentSpecs[] = 
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
		
		// Wireframe's lines' color
		__COLOR_BLACK,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Flag to render the wireframe in interlaced mode
		false,
	},

	// Segments that compose the mesh
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

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

	// If true this collider checks for collisions against other colliders
	true,

	// Layers in which I live
	kLayerPongPaddleHelper,

	// Layers to ignore when checking for collisions
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

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

	// If true this collider checks for collisions against other colliders
	false,

	// Layers in which I live
	kLayerPongPaddle,

	// Layers to ignore when checking for collisions
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

	// Create body
	true,

	// Mass
	__F_TO_FIX10_6(0.55f),

	// Friction
	__F_TO_FIX10_6(0.25f),

	// Bounciness
	__F_TO_FIX10_6(1.0f),

	// Maximum velocity
	{0, 0, 0},

	// Maximum speed
	__I_TO_FIX10_6(8),

	// Axises on which the body is subject to gravity
	__NO_AXIS,

	// Axises around which to rotate the owner when syncronizing with body
	__NO_AXIS
};

ComponentSpec* const PongPaddleActorComponentSpecs[] = 
{
	(ComponentSpec*)&PongPaddleBodySpecSpec,
	(ComponentSpec*)&PongPaddleWireframeSpec,
	(ComponentSpec*)&PongPaddleColliderSpec1,
	(ComponentSpec*)&PongPaddleColliderSpec2,
	NULL
};

PongPaddleROMSpec PongPaddleActorSpec =
{
	{
		{
			// Class allocator
			__TYPE(PongPaddle),

			// Component specs
			(ComponentSpec**)PongPaddleActorComponentSpecs,

			// Children specs
			NULL,

			// Extra info
			NULL,

			// Size
			// If 0, it is computed from the visual components if any
			{0, 0, 0},

			// Actor's in-game type
			kTypePongPaddle,

			// Pointer to animation functions array
			(const AnimationFunction**)NULL,

			// Animation to play automatically
			NULL,
		},
	},

	// force
	{
		0,
		__I_TO_FIX10_6(3),
		0
	}
};
