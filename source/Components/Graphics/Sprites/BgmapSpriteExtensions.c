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

#include <BgmapTexture.h>
#include <Camera.h>
#include <ParamTableManager.h>
#include <Utilities.h>
#include <VUEngine.h>

#include "BgmapSpriteExtensions.h"


//---------------------------------------------------------------------------------------------------------
//												CLASS'S DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extension class BgmapSprite;

friend class Texture;
friend class BgmapTexture;


//---------------------------------------------------------------------------------------------------------
//												CLASS'S DEFINITIONS
//---------------------------------------------------------------------------------------------------------

static const int8 waveLutHBias[] =
{
	-2, -2, -2, -2,
	-1, -1, -1,
	0, 0,
	1, 1, 1,
	2, 2, 2, 2,
	2, 2, 2, 2,
	1, 1, 1,
	0, 0,
	-1, -1, -1,
	-2, -2, -2, -2,
};

#define HBIAS_WAVE_LUT_ENTRIES 	(sizeof(waveLutHBias) / sizeof(int8))


//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

static int16 BgmapSprite::applyHBias(BgmapSprite bgmapSprite, int16 waveHBiasThrottle)
{
	// look up table offset
	static uint8 step = 0;
	step = (step < ((HBIAS_WAVE_LUT_ENTRIES << waveHBiasThrottle) - 1)) ? step + 1 : 0;

	WorldAttributes* worldPointer = &_worldAttributesCache[bgmapSprite->index];

	HbiasEntry* hbiasEntry = (HbiasEntry*)bgmapSprite->param;

	int16 my = (int16)worldPointer->my;

	if(0 > my)
	{
		my = (bgmapSprite->halfHeight << 2) + my;
	}

	CACHE_RESET;

	for(int16 i = 0; i < (bgmapSprite->halfHeight << 2) - my; i++)
	{
		register int16 waveLutHBiasValue = waveLutHBias[(i + my + (step >> waveHBiasThrottle)) & (HBIAS_WAVE_LUT_ENTRIES - 1)];
		hbiasEntry[i].offsetLeft = waveLutHBiasValue;
		hbiasEntry[i].offsetRight = waveLutHBiasValue;
	}

	// Possible return values and their effects:
	//
	// 0:  forces the effect to be triggered on the next rendering cycle without having to call
	//	 Sprite::applyHbiasEffects.
	//
	// >0: forces the effect to be triggered on the next rendering cycle without having to call
	//	 Sprite::applyHbiasEffects. The returned value means the next param table row to compute.
	//	 Only used when deferring the effect across multiple rendering cycles.
	//
	// -1: means that the param table writing has been completed. To trigger the effect again,
	//	 Sprite::applyHbiasEffects must be called.

	return 0;
}

static int16 BgmapSprite::waveEffect(BgmapSprite bgmapSprite)
{
	return BgmapSprite::applyHBias(bgmapSprite, 2);
}
