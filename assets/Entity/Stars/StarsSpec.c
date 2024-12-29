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

#include <Body.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <ParticleSystem.h>
#include <ObjectAnimatedSprite.h>
#include <SolidParticle.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 StarTiles[];
extern uint16 StarMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

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

ComponentSpec* StarSpriteSpecs [] =
{
	(ComponentSpec*)&StarSpriteSpec,
	NULL
};

//---------------------------------------------------------------------------------------------------------
//											OBJECT Star
//---------------------------------------------------------------------------------------------------------




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

	// Friction for physics
	__F_TO_FIX10_6(0),

	// Bounciness for physics
	__F_TO_FIX10_6(0.85f),

	// object's in-game type
	kTypeParticle,

	// Layers in which I live
	kLayerParticles,

	// Layers to ignore when checking for collisions
	(~kLayerSolid),

	// disable collision detection when the particle stops
	true,

	// animation to play upon collision
	"Vanish",
};

ComponentSpec* const StarsParticleSystemNormalComponentSpecs[] = 
{
	NULL
};

ParticleSystemROMSpec StarsParticleSystemNormalSpec =
{
	{
		// Class allocator		
		__TYPE(ParticleSystem),

		// Component specs
		(ComponentSpec**)StarsParticleSystemNormalComponentSpecs,

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

ComponentSpec* const StarsParticleSystemPhysicalComponentSpecs[] = 
{
	NULL
};

ParticleSystemROMSpec StarsParticleSystemPhysicalSpec =
{
	{
		// Class allocator		
		__TYPE(ParticleSystem),

		// Component specs
		(ComponentSpec**)StarsParticleSystemPhysicalComponentSpecs,

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

	// array of sprites
	(const ComponentSpec**)StarSpriteSpecs,

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

ComponentSpec* const StarsParticleSystemSolidComponentSpecs[] = 
{
	NULL
};

ParticleSystemROMSpec StarsParticleSystemSolidSpec =
{
	{
		// Class allocator		
		__TYPE(ParticleSystem),

		// Component specs
		(ComponentSpec**)StarsParticleSystemSolidComponentSpecs,

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

	// array of sprites
	(const ComponentSpec**)StarSpriteSpecs,

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