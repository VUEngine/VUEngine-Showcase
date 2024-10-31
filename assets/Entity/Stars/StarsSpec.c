/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <ParticleSystem.h>
#include <SolidParticle.h>
#include <ObjectAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 StarTiles[];
extern uint16 StarMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec StarDefaultAnimationSpec =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{0},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"Default",
};

AnimationFunctionROMSpec StarVanishAnimationSpec =
{
	// number of frames of this animation function
	5,

	// frames to play in animation
	{0, 0, 1, 2, 3},

	// number of cycles a frame of animation is displayed
	8,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
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
	// number of chars in function of the number of frames to load at the same time
	5,

	// whether it is shared or not
	true,
	
	// whether the tiles are optimized or not
	false,

	// char spec
	StarTiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec StarTextureSpec =
{
	// charset spec
	(CharSetSpec*)&StarCharsetSpec,

	// bgmap spec
	StarMap,

	// cols (max 64)
	1,

	// rows (max 64)
	1,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames
	5,

	// palette number (0-3)
	0,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,

};

ObjectSpriteROMSpec StarSpriteSpec =
{
	{
		// sprite's type
		__TYPE(ObjectAnimatedSprite),

		// texture spec
		(TextureSpec*)&StarTextureSpec,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_OBJECT,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

//---------------------------------------------------------------------------------------------------------
//											OBJECT Star
//---------------------------------------------------------------------------------------------------------


SpriteSpec* const StarSpriteSpecs[] =
{
	(SpriteSpec*)&StarSpriteSpec,
	NULL
};

// particle's spec
ParticleROMSpec StarParticleNormalSpec =
{
	// allocator
	__TYPE(Particle),

	// particle's minimum life span in milliseconds
	5 * 8 * 20,

	// particle's life span delta in milliseconds (maximum = minimum + delta)
	100,

	// function pointer to control particle's behavior
	//(void (*)(Particle))&dustParticleBehavior,
	NULL,

	// animation description (used only if sprite is animated)
	(const AnimationFunction**)&StarAnimationSpecs,

	// name of animation to play
	"Vanish"
};

// particle's spec
PhysicalParticleROMSpec StarParticlePhysicalSpec =
{
	{
		// allocator
		__TYPE(PhysicalParticle),

		// particle's minimum life span in milliseconds
		500,

		// particle's life span delta in milliseconds (maximum = minimum + delta)
		700,

		// function pointer to control particle's behavior
		//(void (*)(Particle))&dustParticleBehavior,
		NULL,

		// animation description (used only if sprite is animated)
		(const AnimationFunction**)&StarAnimationSpecs,

		// name of animation to play
		"Vanish"
	},

	// particle's minimum mass
	__F_TO_FIX10_6(0.05f),

	// particle's mass delta (maximum = minimum + delta)
	__F_TO_FIX10_6(0),

	// axis subject to gravity (bitwise or of __X_AXIS, __Y_AXIS, __Z_AXIS, or false to disable)
	__NO_AXIS,
};

// particle's spec
SolidParticleROMSpec StarParticleSolidSpec =
{
	{
		{
			// allocator
			__TYPE(SolidParticle),

			// particle's minimum life span in milliseconds
			1500,

			// particle's life span delta in milliseconds (maximum = minimum + delta)
			1000,

			// function pointer to control particle's behavior
			//(void (*)(Particle))&dustParticleBehavior,
			NULL,

			// animation description (used only if sprite is animated)
			(const AnimationFunction**)&StarAnimationSpecs,

			// name of animation to play
			"Default"
		},

		// particle's minimum mass
		__F_TO_FIX10_6(0.05f),

		// particle's mass delta (maximum = minimum + delta)
		__F_TO_FIX10_6(0),

		// axis subject to gravity (bitwise or of __X_AXIS, __Y_AXIS, __Z_AXIS, or false to disable)
		__Y_AXIS,
	},

	// ball's radius
	__PIXELS_TO_METERS(4),

	// friction for physics
	__F_TO_FIX10_6(0),

	// bounciness for physics
	__F_TO_FIX10_6(0.85f),

	// object's in-game type
	kTypeParticle,

	// layers in which I live
	kLayerParticles,

	// layers to ignore when checking for collisions
	(~kLayerSolid),

	// disable collision detection when the particle stops
	true,

	// animation to play upon collision
	"Vanish",
};

ParticleSystemROMSpec StarsParticleSystemNormalSpec =
{
	{
		// class allocator
		__TYPE(ParticleSystem),

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
		(WireframeSpec**)NULL,

		// collision colliders
		(ColliderSpec*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kTypeNone,

		// physical specification
		(PhysicalProperties*)NULL,
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

	// array of sprites
	(const SpriteSpec**)StarSpriteSpecs,

	// array of wireframes
	(const WireframeSpec**)NULL,

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
	__NO_MOVEMENT,

	// use particle system movement vector for the force to apply to the particles
	false
};

ParticleSystemROMSpec StarsParticleSystemPhysicalSpec =
{
	{
		// class allocator
		__TYPE(ParticleSystem),

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
		(WireframeSpec**)NULL,

		// collision colliders
		(ColliderSpec*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kTypeNone,

		// physical specification
		(PhysicalProperties*)NULL,
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

	// array of sprites
	(const SpriteSpec**)StarSpriteSpecs,

	// array of wireframes
	(const WireframeSpec**)NULL,

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
	__ACCELERATED_MOVEMENT,

	// use particle system movement vector for the force to apply to the particles
	false
};

ParticleSystemROMSpec StarsParticleSystemSolidSpec =
{
	{
		// class allocator
		__TYPE(ParticleSystem),

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
		(WireframeSpec**)NULL,

		// collision colliders
		(ColliderSpec*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kTypeNone,

		// physical specification
		(PhysicalProperties*)NULL,
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

	// array of sprites
	(const SpriteSpec**)StarSpriteSpecs,

	// array of wireframes
	(const WireframeSpec**)NULL,

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
	__ACCELERATED_MOVEMENT,

	// use particle system movement vector for the force to apply to the particles
	false
};