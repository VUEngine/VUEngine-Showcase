/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <HelloWorldState.h>

#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <VIPManager.h>

#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec HelloWorldStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void HelloWorldState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&HelloWorldStage;
}

// class's destructor
void HelloWorldState::destructor()
{
	// destroy base
	Base::destructor();
}

void HelloWorldState::showStuff()
{
	HelloWorldState::print(this);

	// add wobble effect
	VIPManager::pushBackPostProcessingEffect(VIPManager::getInstance(), HelloWorldState::wobble, NULL);
}

void HelloWorldState::print()
{
	const char* strHelloWorld = I18n::getText(I18n::getInstance(), kStringHelloWorld);

	FontSize textSize = Printing::getTextSize(Printing::getInstance(), strHelloWorld, "VirtualBoyExt");

	Printing::text(
		Printing::getInstance(),
		strHelloWorld,
		(__SCREEN_WIDTH >> 4) - (textSize.x >> 1),
		12,
		"VirtualBoyExt"
	);
}

/**
 * Applies a wobble distortion that is reminiscent of water waves to area that holds text on title.
 *
 * @param currentDrawingFrameBufferSet	The framebuffer set that's currently being accessed
 * @param spatialObject
 */
static void HelloWorldState::wobble(uint32 currentDrawingFrameBufferSet, SpatialObject spatialObject __attribute__ ((unused)))
{
	uint8 buffer = 0;
	uint16 x, y = 0;
	uint32 previousSourcePointerValue = 0;

	// runtime working variables
	static uint8 waveLutIndex = 0;

	// look up table of bitshifts performed on rows
	// values must be multiples of 2
	const uint32 waveLut[64] =
	{
		0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 2, 2, 2,
		4, 4, 4, 4, 4,
		6, 6, 6, 6, 6, 6,
		8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 8, 8, 8,
		6, 6, 6, 6, 6, 6,
		4, 4, 4, 4, 4,
		2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	// loop columns
	for(x = 0; x < 384; x++)
	{
		// increase look up table index, wrap around if necessary
		waveLutIndex += (waveLutIndex < 63) ? 1 : -63;

		// we can skip further processing for the current column if no shifting would be done on it
		if(waveLut[waveLutIndex] == 0)
		{
			continue;
		}

		// write to framebuffers for both screens
		for(buffer = 0; buffer < 2; buffer++)
		{
			// the shifted out pixels on top should be black
			previousSourcePointerValue = 0;

			// loop current column in steps of 16 pixels (32 bits)
			for(y = 6; y < 8; y++)
			{
				// pointer to currently manipulated 32 bits of framebuffer
				uint32* sourcePointer = (uint32*) (currentDrawingFrameBufferSet | (buffer ? 0x00010000 : 0)) + (x << 4) + y;

				// save current pointer value to temp var and shift highest x bits of it, according to lut,
				// to the lowest bits, since we want to insert these
				uint32 sourcePointerCurrentValue = *sourcePointer;
				uint32 previousSourcePointerValueTemp = sourcePointerCurrentValue >> (32 - waveLut[waveLutIndex]);

				// manipulate current 32 bits in frame buffer
				*sourcePointer =
					// shift bits according to wave lut
					// it's two bits per pixel, so 2 bits shifted left = 1 pixel shifted down on screen
					(sourcePointerCurrentValue << waveLut[waveLutIndex])

					// since the above shifting creates black pixels, we need to carry over these pixels
					// from the previous loop
					| previousSourcePointerValue;

				// we need the current source pointer value from _before_ we modified it, therefore we save it
				// it to a temp variable while modifying
				previousSourcePointerValue = previousSourcePointerValueTemp;
			}
		}
	}

	// move the wave one pixel in the next frame
	waveLutIndex++;
}
