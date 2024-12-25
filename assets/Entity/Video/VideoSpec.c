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

#include <AnimatedEntity.h>
#include <BgmapAnimatedSprite.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern uint32 VideoLTiles[];
extern uint32 VideoLTilesFrameOffsets[];
extern uint16 VideoLMap[];
extern uint32 VideoRTiles[];
extern uint32 VideoRTilesFrameOffsets[];
extern uint16 VideoRMap[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

AnimationFunctionROMSpec VideoHiColorAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	470,

	// Frames to play in animation
	{
		  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
		 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
		 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
		 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
		120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,
		150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,
		180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,
		210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
		240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,
		270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,298,299,
		300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,323,324,325,326,327,328,329,
		330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,
		360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,
		390,391,392,393,394,395,396,397,398,399,400,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,
		420,421,422,423,424,425,426,427,428,429,430,431,432,433,434,435,436,437,438,439,440,441,442,443,444,445,446,447,448,449,
		450,451,452,453,454,455,456,457,458,459,460,461,462,463,464,465,466,467,468,469,
	},

	// Number of cycles a frame of animation is displayed
	1,

	// Whether to play it in loop or not
	true,

	// Callback on animation completion
	NULL,

	// Animation's name
	"HiColor",
};

AnimationFunctionROMSpec Video4ColorAnimationSpec =
{
	// Number of frames that the texture supports of this animation function
	470,

	// Frames to play in animation
	{
		  0,  0,  2,  2,  4,  4,  6,  6,  8,  8, 10, 10, 12, 12, 14, 14, 16, 16, 18, 18, 20, 20, 22, 22, 24, 24, 26, 26, 28, 28,
		 30, 30, 32, 32, 34, 34, 36, 36, 38, 38, 40, 40, 42, 42, 44, 44, 46, 46, 48, 48, 50, 50, 52, 52, 54, 54, 56, 56, 58, 58,
		 60, 60, 62, 62, 64, 64, 66, 66, 68, 68, 70, 70, 72, 72, 74, 74, 76, 76, 78, 78, 80, 80, 82, 82, 84, 84, 86, 86, 88, 88,
		 90, 90, 92, 92, 94, 94, 96, 96, 98, 98,100,100,102,102,104,104,106,106,108,108,110,110,112,112,114,114,116,116,118,118,
		120,120,122,122,124,124,126,126,128,128,130,130,132,132,134,134,136,136,138,138,140,140,142,142,144,144,146,146,148,148,
		150,150,152,152,154,154,156,156,158,158,160,160,162,162,164,164,166,166,168,168,170,170,172,172,174,174,176,176,178,178,
		180,180,182,182,184,184,186,186,188,188,190,190,192,192,194,194,196,196,198,198,200,200,202,202,204,204,206,206,208,208,
		210,210,212,212,214,214,216,216,218,218,220,220,222,222,224,224,226,226,228,228,230,230,232,232,234,234,236,236,238,238,
		240,240,242,242,244,244,246,246,248,248,250,250,252,252,254,254,256,256,258,258,260,260,262,262,264,264,266,266,268,268,
		270,270,272,272,274,274,276,276,278,278,280,280,282,282,284,284,286,286,288,288,290,290,292,292,294,294,296,296,298,298,
		300,300,302,302,304,304,306,306,308,308,310,310,312,312,314,314,316,316,318,318,320,320,322,322,324,324,326,326,328,328,
		330,330,332,332,334,334,336,336,338,338,340,340,342,342,344,344,346,346,348,348,350,350,352,352,354,354,356,356,358,358,
		360,360,362,362,364,364,366,366,368,368,370,370,372,372,374,374,376,376,378,378,380,380,382,382,384,384,386,386,388,388,
		390,390,392,392,394,394,396,396,398,398,400,400,402,402,404,404,406,406,408,408,410,410,412,412,414,414,416,416,418,418,
		420,420,422,422,424,424,426,426,428,428,430,430,432,432,434,434,436,436,438,438,440,440,442,442,444,444,446,446,448,448,
		450,450,452,452,454,454,456,456,458,458,460,460,462,462,464,464,466,466,468,468,
	},

	// Number of cycles a frame of animation is displayed
	1,

	// Whether to play it in loop or not
	true,

	// Callback on animation completion
	NULL,

	// Animation's name
	"4Color",
};

// an animation spec
AnimationFunctionROMSpec* VideoAnimationSpecs[] =
{
	(AnimationFunction*)&VideoHiColorAnimationSpec,
	(AnimationFunction*)&Video4ColorAnimationSpec,
	NULL,
};

CharSetROMSpec VideoLCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	633,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	VideoLTiles,

	// Frame offsets array
	VideoLTilesFrameOffsets
};

CharSetROMSpec VideoRCharsetSpec =
{
	// Number of chars in function of the number of frames to load at the same time
	647,

	// Whether it is shared or not
	false,
	
	// Whether the tiles are optimized or not
	true,

	// Tiles array
	VideoRTiles,

	// Frame offsets array
	VideoRTilesFrameOffsets
};

TextureROMSpec VideoLTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&VideoLCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	VideoLMap,

	// Horizontal size in tiles of the texture (max. 64)
	48,

	// Vertical size in tiles of the texture (max. 64)
	28,

	// padding for affine transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

TextureROMSpec VideoRTextureSpec =
{
	// Pointer to the char spec that the texture uses
	(CharSetSpec*)&VideoRCharsetSpec,

	// Pointer to the map array that defines how to use the tiles from the char set
	VideoRMap,

	// Horizontal size in tiles of the texture (max. 64)
	48,

	// Vertical size in tiles of the texture (max. 64)
	28,

	// padding for affine transformations
	{0, 0},

	// Number of frames that the texture supports
	1,

	// Palette index to use by the graphical data (0 - 3)
	0,

	// Flag to recyble the texture with a different map
	false,

	// Flag to vertically flip the image
	false,

	// Flag to horizontally flip the image
	false
};

BgmapSpriteROMSpec VideoLSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&VideoLTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 4},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_LON,
};

BgmapSpriteROMSpec VideoRSpriteSpec =
{
	{
		// Component
		{
			// Allocator
			__TYPE(BgmapAnimatedSprite),

			// Component type
			kSpriteComponent
		},

		// Spec for the texture to display
		(TextureSpec*)&VideoRTextureSpec,

		// Transparency mode (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// Displacement added to the sprite's position
		{0, 0, 0, 4},
	},

	// The display mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine / hbias manipulation function
	NULL,

	// Flag to indicate in which display to show the texture (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_RON,
};

ComponentSpec* const VideoEntityComponentSpecs[] = 
{
	(ComponentSpec*)&VideoLSpriteSpec,
	(ComponentSpec*)&VideoRSpriteSpec,
	NULL
};

AnimatedEntityROMSpec VideoEntitySpec =
{
	{
		// Class allocator		
		__TYPE(AnimatedEntity),

		// Component specs
		(ComponentSpec**)VideoEntityComponentSpecs,

		// Children specs
		NULL,

		// Extra info info
		NULL,

		// Size
		// If 0, it is computed from the visual components if any
		{0, 0, 0},

		// Entity's in-game type
		0,

		
	},

	// Pointer to animation functions array
	(const AnimationFunction**)&VideoAnimationSpecs,

	// Animation to play automatically
	"HiColor"
};
