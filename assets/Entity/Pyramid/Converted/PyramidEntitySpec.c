///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <Entity.h>
#include <Mesh.h>
#include <Texture.h>



//---------------------------------------------------------------------------------------------------------
//                                               WIREFRAMES                                                
//---------------------------------------------------------------------------------------------------------

const PixelVector Pyramid1WireframeSegments[][2]=
{
	{
		{ -64, 64, -64, 0 },
		{ 64, 64, -64, 0 },
	},
	{
		{ -64, 64, 64, 0 },
		{ 64, 64, 64, 0 },
	},
	{
		{ -64, 64, -64, 0 },
		{ -64, 64, 64, 0 },
	},
	{
		{ 64, 64, -64, 0 },
		{ 64, 64, 64, 0 },
	},
	{
		{ 0, -64, 0, 0 },
		{ -64, 64, -64, 0 },
	},
	{
		{ 0, -64, 0, 0 },
		{ -64, 64, 64, 0 },
	},
	{
		{ 0, -64, 0, 0 },
		{ 64, 64, -64, 0 },
	},
	{
		{ 0, -64, 0, 0 },
		{ 64, 64, 64, 0 },
	},

	// limiter
	{
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},
};

MeshROMSpec Pyramid1WireframeSpec =
{
	{
		// class allocator
		__TYPE(Mesh),

		// displacement
		{ 0, 0, 0},
		
		// color
		__COLOR_BRIGHT_RED,

		// transparent
		__TRANSPARENCY_NONE,

		// interlaced
		false,
	},

	// segments
	(PixelVector(*)[2])Pyramid1WireframeSegments,
};

WireframeROMSpec* const PyramidWireframeSpecs[] =
{
	(WireframeSpec*)&Pyramid1WireframeSpec,
	NULL
};


//---------------------------------------------------------------------------------------------------------
//                                                 ENTITY                                                  
//---------------------------------------------------------------------------------------------------------

EntityROMSpec PyramidEntitySpec =
{
			// class allocator
			__TYPE(Entity),

			// children
			NULL,

			// behaviors
			NULL,

			// extra
			NULL,

			// sprites
			NULL,

			// use z displacement in projection
			false,

			// wireframes
			(WireframeSpec**)PyramidWireframeSpecs,

			// collider colliders
			NULL,

			// size
			// if 0, width and height will be inferred from the first sprite's texture's size
			{ 0, 0, 0 },

			// gameworld's character's type
			kTypeNone,

			// physical specification
			(PhysicalProperties*)NULL,
};
