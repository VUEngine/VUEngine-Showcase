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

extern const uint8 ExplosionSoundTrack[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

SoundChannelConfigurationROM ExplosionSoundChannelConfiguration =
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
	0xF7,

	// SxEV1
	0x11,

	// SxFQH
	0x00,

	// SxFQL
	0x00,

	// Ch. 5 only
	0x00,

	// Waveform data pointer
	TriangleWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNoise,

	// Volume
	__SOUND_LR
};

SoundChannelROM ExplosionSoundChannel =
{
	// Configuration
	(SoundChannelConfiguration*)&ExplosionSoundChannelConfiguration,

	/// Total number of samples
	0,

	// Sound track
	{
		ExplosionSoundTrack
	}
};


SoundChannelROM* ExplosionSoundChannels[] =
{
	&ExplosionSoundChannel,
	NULL
};

SoundROMSpec ExplosionSoundSpec =
{
	// Name
	"Explosion",

	// Play in loop
	false,

	// Target timer resolution in us
	500,

	// Tracks
	(SoundChannel**)ExplosionSoundChannels
};