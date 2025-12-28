////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Actor.h>
#include <Ball.h>
#include <BgmapSprite.h>
#include <CogWheel.h>
#include <ColliderLayers.h>
#include <InGameTypes.h>
#include <Mutator.h>
#include <Texture.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern uint16 CogWheelActorCogWheelMap[];
extern uint32 CogWheelActorCogWheelTiles[];

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// SPRITES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

CharSetROMSpec CogWheelSprite1CharsetSpec =
{
	// Number of CHARs in function of the number of frames to load at the same time
	26,

	// Whether it is shared or not
	true,

	// Whether the tiles are optimized or not
	true,

	// Tiles array
	CogWheelActorCogWheelTiles,

	// Frame offsets array
	NULL
};

TextureROMSpec CogWheelSprite1TextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&CogWheelSprite1CharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	CogWheelActorCogWheelMap,

	// Horizontal size in tiles of the texture (max. 64)
	16,

	// Vertical size in tiles of the texture (max. 64)
	16,

	// padding for affine/hbias transformations
	{4, 4},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recycle the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec CogWheelSprite1SpriteSpec =
{
	{
		// VisualComponent
		{
			// Component
			{
				// Allocator
				__TYPE(BgmapSprite),

				// Component type
				kSpriteComponent
			},

			// Array of animation functions
			(const AnimationFunction**)NULL
		},

		// Spec for the texture to display
		(TextureSpec*)&CogWheelSprite1TextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 0}
	},

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE or __WORLD_HBIAS)
	__WORLD_AFFINE,
	
	// Pointer to affine/hbias manipulation function
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// COLLIDERS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ColliderROMSpec CogWheelCollider1ColliderSpec = 
{
	// Component
	{
		// Allocator
		__TYPE(Ball),

		// Component type
		kColliderComponent
	},

	// Size (x, y, z)
	{128, 0, 0},

	// Displacement (x, y, z, p)
	{0, 0, 0, 0},

	// Rotation (x, y, z)
	{0, 0, 0},

	// Scale (x, y, z)
	{__F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f), __F_TO_FIX7_9(1.000f)},

	// If true this collider checks for collisions against other colliders
	false,

	// Layers in which I live
	kLayerDangers,

	// Layers to ignore when checking for collisions
	kLayerAll
};


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// MUTATORS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

MutatorROMSpec CogWheelMutator1MutatorSpec =
{
	{
		// Allocator
		__TYPE(Mutator),

		// Component type
		kMutatorComponent
	},

	// Mutation target class
	class(CogWheel),

	// Enabled
	true
};


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// ACTOR
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ComponentSpec* const CogWheelComponentSpecs[] = 
{
	(ComponentSpec*)&CogWheelSprite1SpriteSpec,
	(ComponentSpec*)&CogWheelCollider1ColliderSpec,
	(ComponentSpec*)&CogWheelMutator1MutatorSpec,
	NULL
};

ActorROMSpec CogWheelActorSpec =
{
	// Class allocator
	__TYPE(Actor),

	// Component specs
	(ComponentSpec**)CogWheelComponentSpecs,

	// Children specs
	NULL,

	// Extra info
	NULL,

	// Size
	// If 0, it is computed from the visual components if any
	{0, 0, 0},

	// Actor's in-game type
	kTypeCogWheel,

	// Animation to play automatically
	NULL
	
};
