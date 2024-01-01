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

#include <SoundManager.h>
#include <WaveForms.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern const uint8 EngineSoundTrack[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

SoundChannelConfigurationROM EngineSoundChannelConfiguration =
{
	// kMIDI, kPCM
	kMIDI,

	// SxINT
	0x00,

	// Volume SxLRV
	0x00,

	// SxRAM (this is overrode by the SoundManager)
	0x00,

	// SxEV0
	0xF0,

	// SxEV1
	0x00,

	// SxFQH
	0x00,

	// SxFQL
	0x00,

	// Ch. 5 only
	0x00,

	// Waveform data pointer
	TriangleWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM EngineSoundChannel =
{
	// Configuration
	(SoundChannelConfiguration*)&EngineSoundChannelConfiguration,

	// Total number of samples
	0,

	// Sound track
	{
		EngineSoundTrack
	}
};


SoundChannelROM* EngineSoundChannels[] =
{
	&EngineSoundChannel,
	NULL
};

SoundROMSpec EngineSoundSpec =
{
	// Name
	"Engine",

	// Play in loop
	true,

	// Target timer resolution in us
	1000,

	// Tracks
	(SoundChannel**)EngineSoundChannels
};