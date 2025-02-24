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
#include <Particle.h>
#include <ParticleSystem.h>
#include <ObjectSprite.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern AnimationFunction* const StarAnimationSpecs[];
extern CharSetSpec StarCharsetSpec;
extern TextureSpec StarTextureSpec;
extern ObjectSpriteSpec StarSpriteSpec;
extern ComponentSpec* StarSpriteSpecs[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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
	__NO_AXIS,

	// Axises around which to rotate the owner when syncronizing with body
	__NO_AXIS
};

ParticleROMSpec StarParticlePhysicalSpec =
{
	// Class allocator
	__TYPE(Particle),

	// Minimum life span in milliseconds
	500,

	// Life span delta in milliseconds
	700,

	// Animation to play automatically
	"Vanish",

	// Animation to play upon collision
	NULL,

	// Object's in-game type
	kTypeParticle,
};

ComponentSpec* StarsParticleSystemPhysicalPhysicsSpecs [] =
{
	(ComponentSpec*)&StarsParticleSystemPhysicalBodySpec,
	NULL
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

		// Actor's in-game type
		kTypeNone,
		
		// Animation to play automatically
		NULL
	},

	// Reuse expired particles?
	true,

	// Minimum generation delay in milliseconds
	5 * 8 * 20 / 16,

	// Maximum generation delay in milliseconds
	5 * 8 * 20 / 12,

	// Maximum number of alive particles
	12,

	// Maximum number of particles to spawn in each cycle
	1,

	// Array of visual component specs
	(const ComponentSpec**)StarSpriteSpecs,

	// Array of physics component specs
	(const ComponentSpec**)StarsParticleSystemPhysicalPhysicsSpecs,

	// Array of collider component specs
	(const ComponentSpec**)NULL,

	// Auto start
	false,

	// Particle spec
	(ParticleSpec*)&StarParticlePhysicalSpec,

	// Minimum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0)},

	// Maximum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0), __PIXELS_TO_METERS(0)},

	// Minimum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(-2.5f), __F_TO_FIXED(-5), __F_TO_FIXED(-2)},

	// Maximum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(2.5f), __F_TO_FIXED(-1.5f), __F_TO_FIXED(2)},

	// Movement type (__UNIFORM_MOVEMENT or __ACCELERATED_MOVEMENT)
	__ACCELERATED_MOVEMENT
};
