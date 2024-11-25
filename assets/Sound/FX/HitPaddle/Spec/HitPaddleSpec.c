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

#include <SoundManager.h>
#include <WaveForms.h>


//=========================================================================================================
// DECLARATIONS
//=========================================================================================================

extern const uint16 HitPaddleSoundTrack1[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

SoundChannelConfigurationROM HitPaddleSoundChannel1Configuration =
{
	// kMIDI, kPCM
	kMIDI,

	// SxINT
	0x9F,

	// Volume SxLRV
	0xFF,

	// SxRAM (this is overrode by the SoundManager)
	0x00,

	// SxEV0
	0x80,

	// SxEV1
	0x01,

	// SxFQH
	0x00,

	// SxFQL
	0x00,

	// Ch. 5 only
	0x00,

	// Waveform data HitPaddleer
	SquareWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM HitPaddleSoundChannel1 =
{
	// Configuration
	(SoundChannelConfiguration*)&HitPaddleSoundChannel1Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)HitPaddleSoundTrack1
	}
};


SoundChannelROM* HitPaddleSoundChannels[] =
{
	&HitPaddleSoundChannel1,
	NULL
};

SoundROMSpec HitPaddleSoundSpec =
{
	// Name
	"Change Selection Sound 3",

	// Play in loop
	false,

	// Target timer resolution in us
	500,

	// Tracks
	(SoundChannel**)HitPaddleSoundChannels
};
