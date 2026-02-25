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

extern uint32 StarTiles[];
extern uint16 StarMap[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

AnimationFunctionROMSpec StarDefaultAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	1,

	// Frames to play in animation
	{0},

	// Number of cycles a frame of animation is displayed
	8,

	// Whether to play it in loop or not
	false
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
	false
	"Vanish",
};

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

	// Flag to recycle the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false,

};

ObjectSpriteROMSpec StarSpriteSpec =
{
	{
		{
			// Component
			{
				// Allocator
				__TYPE(ObjectSprite),

				// Component type
				kSpriteComponent
			},

			// Array of function animations
			(const AnimationFunction**)StarAnimationSpecs
		},

		// Spec for the texture to display
		(TextureSpec*)&StarTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0},
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

ComponentSpec* StarSpriteSpecs [] =
{
	(ComponentSpec*)&StarSpriteSpec,
	NULL
};

ParticleROMSpec StarParticleNormalSpec =
{
	// Class allocator
	__TYPE(Particle),

	// Minimum life span in milliseconds
	5 * 8 * 20,

	// Life span delta in milliseconds
	100,

	// Animation to play automatically
	"Vanish",

	// Animation to play upon collision
	NULL,

	// Object's in-game type
	kTypeParticle,
};

ParticleSystemROMSpec StarsParticleSystemNormalSpec =
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
	5 * 8 * 20 / 8,

	// Maximum generation delay in milliseconds
	5 * 8 * 20 / 6,

	// Maximum number of alive particles
	12,

	// Maximum number of particles to spawn in each cycle
	1,

	// Array of visual component specs
	(const ComponentSpec**)StarSpriteSpecs,

	// Array of physics component specs
	(const ComponentSpec**)NULL,

	// Array of collider component specs
	(const ComponentSpec**)NULL,

	// Auto start
	false,

	// Particle spec
	(ParticleSpec*)&StarParticleNormalSpec,

	// Minimum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(-20), __PIXELS_TO_METERS(-16), __PIXELS_TO_METERS(0)},

	// Maximum relative spawn position (x, y, z)
	{__PIXELS_TO_METERS(20), __PIXELS_TO_METERS(16), __PIXELS_TO_METERS(16)},

	// Minimum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(0), __F_TO_FIXED(0), 0},

	// Maximum force to apply (x, y, z)
	// (use int values in the spec to avoid overflow)
	{__F_TO_FIXED(0), __F_TO_FIXED(0), 0},

	// Movement type (__UNIFORM_MOVEMENT or __ACCELERATED_MOVEMENT)
	__NO_MOVEMENT
};
