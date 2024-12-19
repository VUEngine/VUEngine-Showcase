/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 * © 3D meshes by Julian Leucht (JnL) <j.leucht@gmx.net>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Entity.h>
#include <Ball.h>
#include <Mesh.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

const PixelVector TunnelMeshesSegments[][2]=
{
	// base
	/* {
		{-128, 0, -512, 0}, 
		{128, 0, -512, 0}
	},
	{
		{-128, 0, 384, 0}, 
		{128, 0, 384, 0}
	},*/

	// vertex z-axis base
	{
		{-128, 0, 384, 0},
		{-128, 0, -512, 0}
	},
	{
		{128, 0, 384, 0},
		{128, 0, -512, 0} 
	},

	// vertex y-axis entrance with arc
	{
		{-128, -128, -512, 0},
		{-128, 0, -512, 0}
	},
	{
		{128, -128, -512, 0},
		{128, 0, -512, 0} 
	},
	{
		{-128, -128, -512, 0},
		{-96, -192, -512, 0}
	},
	
	{
		{-96, -192, -512, 0},
		{-32, -240, -512, 0}
	},
	{
		{-32, -240, -512, 0},
		{0, -240, -512, 0}
	},
	{
		{128, -128, -512, 0},
		{96, -192, -512, 0}
	},
	{
		{96, -192, -512, 0},
		{32, -240, -512, 0}
	},
	{
		{32, -240, -512, 0},
		{0, -240, -512, 0}
	},

	// vertex y-axis exit with arc
	{
		{-128, -128, 384, 0},
		{-128, 0, 384, 0}
	},
	{
		{128, -128, 384, 0},
		{128, 0, 384, 0} 
	},
	{
		{-128, -128, 384, 0},
		{-96, -192, 384, 0}
	},
	{
		{-96, -192, 384, 0},
		{-32, -240, 384, 0}
	},
	{
		{-32, -240, 384, 0},
		{0, -240, 384, 0}
	},
	{
		{128, -128, 384, 0},
		{96, -192, 384, 0}
	},
	{
		{96, -192, 384, 0},
		{32, -240, 384, 0}
	},
	{
		{32, -240, 384, 0},
		{0, -240, 384, 0}
	},

	// vertex z-axis of arc
	{
		{-128, -128, -512, 0},
		{-128, -128, 384, 0} 
	},
	{
		{-96, -192, -512, 0},
		{-96, -192, 384, 0}
	},
	{
		{-32, -240, -512, 0},
		{-32, -240, 384, 0}
	},
	{
		{128, -128, -512, 0},
		{128, -128, 384, 0} 
	},
	{
		{96, -192, -512, 0},
		{96, -192, 384, 0}
	},
	{
		{32, -240, -512, 0},
		{32, -240, 384, 0}
	},

	// vertex lanes on bottom
	{
		{0, 0, -384, 0},
		{0, 0, -448, 0}
	},
	{
		{0, 0, -256, 0},
		{0, 0, -320, 0} 
	},
	{
		{0, 0, -128, 0},
		{0, 0, -192, 0} 
	},
	{
		{0, 0, 0, 0},
		{0, 0, -64, 0} 
	},
	{
		{0, 0, 128, 0},
		{0, 0, 64, 0} 
	},
	{
		{0, 0, 256, 0},
		{0, 0, 192, 0} 
	},
	{
		{0, 0, 384, 0},
		{0, 0, 320, 0} 
	},

	// lights corps
	{
		{0, -224, 256, 0},
		{0, -224, 128, 0} 
	},
	{
		{0, -224, 64, 0},
		{0, -224, -64, 0} 
	},
	{
		{0, -224, -128, 0},
		{0, -224, -256, 0} 
	},
		{
		{0, -224, -320, 0},
		{0, -224, -448, 0} 
	},
	
	// lights holder
	{
		{0, -240, 224, 0},
		{0, -224, 224, 0} 
	},
	{
		{0, -240, 160, 0},
		{0, -224, 160, 0} 
	},
	{
		{0, -240, 32, 0},
		{0, -224, 32, 0} 
	},
	{
		{0, -240, -32, 0},
		{0, -224, -32, 0} 
	},
	{
		{0, -240, -160, 0},
		{0, -224, -160, 0} 
	},
	{
		{0, -240, -222, 0},
		{0, -224, -222, 0} 
	},
	{
		{0, -240, -352, 0},
		{0, -224, -352, 0} 
	},
	{
		{0, -240, -416, 0},
		{0, -224, -416, 0} 
	},

	// emergency exit
	{
		{-128, 0, 0, 0}, 
		{-128, -64, 0, 0}
	},
	{
		{-128, 0, 32, 0}, 
		{-128, -64, 32, 0}
	},
	{
		{-128, -64, 0, 0}, 
		{-128, -64, 32, 0}
	},
	{
		{-120, -64, 36, 0}, 
		{-128, -64, 36, 0}
	},
	{
		{-120, -60, 36, 0}, 
		{-128, -60, 36, 0}
	},
	{
		{-120, -60, 36, 0}, 
		{-120, -64, 36, 0}
	},
	{
		{-128, -60, 36, 0}, 
		{-128, -64, 36, 0}
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

const ComponentSpec* TunnelWireframeSpecComponentSpecs[] = 
{
	@COMPONENTS:TunnelWireframeSpec@
};

MeshROMSpec TunnelWireframeSpec =
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
		
		// color
		__COLOR_BLACK,

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false,
	},

	// segments
	(PixelVector(*)[2])TunnelMeshesSegments
};

@COMP_ARRAY_START:TunnelWireframeSpecs
	&TunnelWireframeSpec,
	
@COMP_ARRAY_END:TunnelWireframeSpecs

ColliderROMSpec TunnelColliderSpecsCollider1 =
	{
		// Component
		{
			// Allocator
			__TYPE(Ball),

			// Component type
			kColliderComponent
		},

		// size (x, y, z)
		{128, 128, 128},

		// displacement (x, y, z, p)
		{0, 0, 0, 0},

		// rotation (x, y, z)
		{0, 0, 0},

		// scale (x, y, z)
		{__I_TO_FIX7_9(1), __I_TO_FIX7_9(1), __I_TO_FIX7_9(1)},

		// if true this collider checks for collisions against other colliders
		false,

		// layers in which I live
		kLayerNone,

		// layers to ignore when checking for collisions
		kLayerNone
	};

@COMP_ARRAY_START:TunnelColliderSpecs
	&TunnelColliderSpecsCollider1,


@COMP_ARRAY_END:TunnelColliderSpecs

const ComponentSpec* TunnelEntitySpecComponentSpecs[] = 
{
	@COMPONENTS:TunnelEntitySpec@
};

EntityROMSpec TunnelEntitySpec =
{
	// class allocator
	__TYPE(Entity),

	// children
	NULL,

	@BEHAVIORS:(BehaviorSpec**)NULL@,

	// extra
	NULL,

	@SPRITES:(SpriteSpec**)NULL@,

	// use z displacement in projection
	false,

	@WIREFRAMES:(WireframeSpec**)TunnelWireframeSpecs@,

	@COLLIDERS:(ColliderSpec*)TunnelColliderSpecs@,

	// size
	// if 0, width and height will be inferred from the first sprite's texture's size
	{0, 0, 0},

	// gameworld's character's type
	kTypeNone,

	@PHYSICS:(PhysicalProperties*)NULL@,
};
