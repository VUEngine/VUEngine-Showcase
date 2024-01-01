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

extern const uint16 BootSoundTrack1[];
extern const uint16 BootSoundTrack2[];
extern const uint16 BootSoundTrack3[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

SoundChannelConfigurationROM BootSoundChannel1Configuration =
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
	SquareWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM BootSoundChannel1 =
{
	// Configuration
	(SoundChannelConfiguration*)&BootSoundChannel1Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)BootSoundTrack1
	}
};

SoundChannelConfigurationROM BootSoundChannel2Configuration =
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
	SquareWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM BootSoundChannel2 =
{
	// Configuration
	(SoundChannelConfiguration*)&BootSoundChannel2Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)BootSoundTrack2
	}
};

SoundChannelConfigurationROM BootSoundChannel3Configuration =
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
	SquareWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM BootSoundChannel3 =
{
	// Configuration
	(SoundChannelConfiguration*)&BootSoundChannel3Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)BootSoundTrack3
	}
};

SoundChannelROM* const BootSoundChannels[] =
{
	&BootSoundChannel1,
	&BootSoundChannel2,
	&BootSoundChannel3,
	NULL
};

SoundROMSpec BootSoundSpec =
{
	// Name
	"Boot Sound",

	// Play in loop
	false,

	// Target timer resolution in us
	3340,

	// Tracks
	(SoundChannel**)BootSoundChannels
};
