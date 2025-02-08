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

#include <Actor.h>
#include <BgmapSprite.h>
#include <Body.h>
#include <Box.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Punk.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern AnimationFunctionROMSpec* PunkAnimationSpecs[];
extern TextureROMSpec PunkTextureSpec;
extern SpriteSpec PunkSpriteSpec;
extern SpriteSpec PunkBlackSpriteSpec;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ColliderROMSpec PunkControllableActorColliderSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Box),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{16, 38, 24},

	// Displacement (x, y, z, p)
	{0, 1, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{0, 0, 0},

	// If true this collider checks for collisions against other colliders
	true,

	// Layers in which I live
	kLayerPunk,

	// Layers to ignore when checking for collisions
	~(kLayerSolid | kLayerDangers),
};

BodyROMSpec PunkControllableActorBodySpec =
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
	__F_TO_FIXED(0.5f),

	// Friction
	__F_TO_FIXED(0.1f),

	// Bounciness
	__F_TO_FIXED(0),

	// Maximum velocity
	{__I_TO_FIXED(0), __I_TO_FIXED(0), __I_TO_FIXED(0)},

	// Maximum speed
	__F_TO_FIXED(3),

	// Axises on which the body is subject to gravity
	__NO_AXIS,

	// Axises around which to rotate the owner when syncronizing with body
	__NO_AXIS
};

ComponentSpec* const PunkControllableActorComponentSpecs[] = 
{
	(ComponentSpec*)&PunkSpriteSpec,
	(ComponentSpec*)&PunkBlackSpriteSpec,
	(ComponentSpec*)&PunkControllableActorBodySpec,
	(ComponentSpec*)&PunkControllableActorColliderSpec,
	NULL
};

PunkROMSpec PunkControllableActorSpec =
{
	{
		// Class allocator
		__TYPE(Punk),

		// Component specs
		(ComponentSpec**)PunkControllableActorComponentSpecs,

		// Children specs
		NULL,

		// Extra info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Actor's in-game type
		kTypePunk,

		// Animation to play automatically
		NULL
	}
};