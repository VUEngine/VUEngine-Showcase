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

extern const uint16 ChangeSelection2SoundTrack1[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

SoundChannelConfigurationROM ChangeSelection2SoundChannel1Configuration =
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

	// Waveform data pointer
	PianoWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM ChangeSelection2SoundChannel1 =
{
	// Configuration
	(SoundChannelConfiguration*)&ChangeSelection2SoundChannel1Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)ChangeSelection2SoundTrack1
	}
};


SoundChannelROM* ChangeSelection2SoundChannels[] =
{
	&ChangeSelection2SoundChannel1,
	NULL
};

SoundROMSpec ChangeSelection2SoundSpec =
{
	// Name
	"Change Selection Sound 2",

	// Play in loop
	false,

	// Target timer resolution in us
	500,

	// Tracks
	(SoundChannel**)ChangeSelection2SoundChannels
};
