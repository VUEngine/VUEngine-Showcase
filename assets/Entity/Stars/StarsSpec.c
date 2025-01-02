/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Ball.h>
#include <Body.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <ParticleSystem.h>
#include <ObjectAnimatedSprite.h>
#include <SolidParticle.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint32 StarTiles[];
extern uint16 StarMap[];


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec StarDefaultAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{0},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"Default",
};

AnimationFunctionROMSpec StarVanishAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	5,

	// Frames to play in animation
	{0, 0, 1, 2, 3},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false,

	// Callback on animation completion
	NULL,

	// Animation's name
	"Vanish",
};

// an animation spec
AnimationFunctionROMSpec* const StarAnimationSpecs[] =
{
	(AnimationFunction*)&StarDefaultAnimationSpec,
	(AnimationFunction*)&StarVanishAnimationSpec,
    NULL,
};

CharSetROMSpec StarCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	5,

	// Whether it is shared or not
	true,
	
	// Whether the tiles are optimized or not
	false,

	// Tiles array
	StarTiles,

	// Frame offsets array
	NULL,
};

TextureROMSpec StarTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&StarCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	StarMap,

	// Horizontal size in tiles of the texture (max. 64)
	1,

	// Vertical size in tiles of the texture (max. 64)
	1,

	// Padding added to the size for affine/hbias transformations (cols, rows)
	{0, 0},

	// Number of frames that the texture supports
	5,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,

};

ObjectSpriteROMSpec StarSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(ObjectAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&StarTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_OBJECT,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BodyROMSpec StarsParticleSystemPhysicalBodySpec =
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
	__F_TO_FIX10_6(0.05f),

	// Friction
	__F_TO_FIX10_6(0.0f),

	// Bounciness
	__F_TO_FIX10_6(0.85f),

	// Maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// Maximum speed
	__I_TO_FIXED(2),

	// Axises on which the body is subject to gravity
	__NO_AXIS
};

BodyROMSpec StarsParticleSystemSolidBodySpec =
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
	__F_TO_FIX10_6(0.05f),

	// Friction
	__F_TO_FIX10_6(0.0f),

	// Bounciness
	__F_TO_FIX10_6(0.85f),

	// Maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// Maximum speed
	__I_TO_FIXED(0),

	// Axises on which the body is subject to gravity
	__Y_AXIS
};


ColliderROMSpec StarsParticleSystemSolidColliderSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{__PIXELS_TO_METERS(4), __PIXELS_TO_METERS(4), __PIXELS_TO_METERS(4)},

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{1, 1, 1},

	// check for collisions against other colliders
	true,

	// Layers in which I live
	kLayerParticles,

	// Layers to ignore when checking for collisions
	(~kLayerSolid),
};

ComponentSpec* StarSpriteSpecs [] =
{
	(ComponentSpec*)&StarSpriteSpec,
	NULL
};

ComponentSpec* StarsParticleSystemPhysicalPhysicsSpecs [] =
{
	(ComponentSpec*)&StarsParticleSystemPhysicalBodySpec,
	NULL
};

ComponentSpec* StarsParticleSystemSolidPhysicsSpecs [] =
{
	(ComponentSpec*)&StarsParticleSystemSolidBodySpec,
	NULL
};

ComponentSpec* StarsParticleSystemSolidColliderSpecs [] =
{
	(ComponentSpec*)&StarsParticleSystemSolidColliderSpec,
	NULL
};


//——————————————————————————————————————————————————————————————————————————————————————————————————————————
// OBJECT Star
//——————————————————————————————————————————————————————————————————————————————————————————————————————————


// Particle's spec
ParticleROMSpec StarParticleNormalSpec =
{
	// Class allocator
	__TYPE(Particle),

	// Minimum life span in milliseconds
	5 * 8 * 20,

	// Life span delta in milliseconds
	100,

	// Function pointer to control particle's behavior
	NULL,

	// Array of available animations
	(const AnimationFunction**)&StarAnimationSpecs,

	// Animation to play automatically
	"Vanish"
};

// Particle's spec
PhysicalParticleROMSpec StarParticlePhysicalSpec =
{
	{
		// Class allocator
		__TYPE(PhysicalParticle),

		// Minimum life span in milliseconds
		500,

		// Life span delta in milliseconds
		700,

		// Function pointer to control particle's behavior
		NULL,

		// Array of available animations
		(const AnimationFunction**)&StarAnimationSpecs,

		// Animation to play automatically
		"Vanish"
	},
};

BodyROMSpec StarParticleSolidBodySpec =
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
	__F_TO_FIX10_6(0.05f),

	// Friction
	__F_TO_FIX10_6(0.0f),

	// Bounciness
	__F_TO_FIX10_6(0.85f),

	// Maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// Maximum speed
	__I_TO_FIXED(0),

	// Axises on which the body is subject to gravity
	__Y_AXIS
};

// Particle's spec
SolidParticleROMSpec StarParticleSolidSpec =
{
	{
		{
			// Class allocator
			__TYPE(SolidParticle),

			// Minimum life span in milliseconds
			1500,

			// Life span delta in milliseconds
			1000,

			// Function pointer to control particle's behavior
			NULL,

			// Array of available animations
			(const AnimationFunction**)&StarAnimationSpecs,

			// Animation to play automatically
			"Default"
		},
	},

	// object's in-game type
	kTypeParticle,

	// animation to play upon collision
	"Vanish",
};

ParticleSystemROMSpec StarsParticleSystemNormalSpec =
{
	// Entity
	{
		// Class allocator		
		__TYPE(ParticleSystem),

		// Component specs
		(ComponentSpec**)NULL,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		kTypeNone
	},

	// reuse expired particles?
	true,

	// minimum generation delay in milliseconds
	5 * 8 * 20 / 8,

	// maximum generation delay in milliseconds
	5 * 8 * 20 / 6,

	// maximum number of alive particles
	12,

	// maximum number of particles to spawn in each cycle
	1,

	// array of visual component specs
	(const ComponentSpec**)StarSpriteSpecs,

	// array of physics component specs
	(const ComponentSpec**)NULL,

	// array of collider component specs
	(const ComponentSpec**)NULL,

	// auto start
	false,

	// particle spec
	(ParticleSpec*)&StarParticleNormalSpec,

	// minimum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(-20), __PIXELS_TO_METERS(-16), __PIXELS_TO_METERS(0)},

	// maximum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(20), __PIXELS_TO_METERS(16), __PIXELS_TO_METERS(16)},

	// minimum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(0), __F_TO_FIXED(0), 0},

	// maximum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(0), __F_TO_FIXED(0), 0},

	// movement type (__UNIFORM_MOVEMENT or __ACCELERATED_MOVEMENT)
	__NO_MOVEMENT
};

ParticleSystemROMSpec StarsParticleSystemPhysicalSpec =
{
	{
		// Class allocator		
		__TYPE(ParticleSystem),

		// Component specs
		(ComponentSpec**)NULL,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		kTypeNone
	},

	// reuse expired particles?
	true,

	// minimum generation delay in milliseconds
	5 * 8 * 20 / 16,

	// maximum generation delay in milliseconds
	5 * 8 * 20 / 12,

	// maximum number of alive particles
	12,

	// maximum number of particles to spawn in each cycle
	1,

	// array of visual component specs
	(const ComponentSpec**)StarSpriteSpecs,

	// array of physics component specs
	(const ComponentSpec**)StarsParticleSystemPhysicalPhysicsSpecs,

	// array of collider component specs
	(const ComponentSpec**)NULL,

	// auto start
	false,

	// particle spec
	(ParticleSpec*)&StarParticlePhysicalSpec,

	// minimum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0)},

	// maximum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0)},

	// minimum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(-2.5f), __F_TO_FIXED(-5), __F_TO_FIXED(-2)},

	// maximum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(2.5f), __F_TO_FIXED(-1.5f), __F_TO_FIXED(2)},

	// movement type (__UNIFORM_MOVEMENT or __ACCELERATED_MOVEMENT)
	__ACCELERATED_MOVEMENT
};

ParticleSystemROMSpec StarsParticleSystemSolidSpec =
{
	{
		// Class allocator		
		__TYPE(ParticleSystem),

		// Component specs
		(ComponentSpec**)NULL,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		kTypeNone
	},

	// reuse expired particles?
	true,

	// minimum generation delay in milliseconds
	5 * 8 * 20 / 16,

	// maximum generation delay in milliseconds
	5 * 8 * 20 / 12,

	// maximum number of alive particles
	12,

	// maximum number of particles to spawn in each cycle
	1,

	// array of visual component specs
	(const ComponentSpec**)StarSpriteSpecs,

	// array of physics component specs
	(const ComponentSpec**)StarsParticleSystemSolidPhysicsSpecs,

	// array of collider component specs
	(const ComponentSpec**)StarsParticleSystemSolidColliderSpecs,

	// auto start
	false,

	// particle spec
	(ParticleSpec*)&StarParticleSolidSpec,

	// minimum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0)},

	// maximum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0)},

	// minimum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(-2), __F_TO_FIXED(-13), __F_TO_FIXED(-0.5f)},

	// maximum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(2), __F_TO_FIXED(-8), __F_TO_FIXED(-0.25f)},

	// movement type (__UNIFORM_MOVEMENT or __ACCELERATED_MOVEMENT)
	__ACCELERATED_MOVEMENT
};