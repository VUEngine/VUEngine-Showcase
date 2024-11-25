/**
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

extern const uint16 GameOverSoundTrack1[];
extern const uint16 GameOverSoundTrack2[];
extern const uint16 GameOverSoundTrack3[];
extern const uint16 GameOverSoundTrack4[];


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

SoundChannelConfigurationROM GameOverSoundChannel1Configuration =
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
	TriangleWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM GameOverSoundChannel1 =
{
	// Configuration
	(SoundChannelConfiguration*)&GameOverSoundChannel1Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)GameOverSoundTrack1
	}
};

SoundChannelConfigurationROM GameOverSoundChannel2Configuration =
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
	TrumpetWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM GameOverSoundChannel2 =
{
	// Configuration
	(SoundChannelConfiguration*)&GameOverSoundChannel2Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)GameOverSoundTrack2
	}
};

SoundChannelConfigurationROM GameOverSoundChannel3Configuration =
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
	TrumpetWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM GameOverSoundChannel3 =
{
	// Configuration
	(SoundChannelConfiguration*)&GameOverSoundChannel3Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)GameOverSoundTrack3
	}
};

SoundChannelConfigurationROM GameOverSoundChannel4Configuration =
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

SoundChannelROM GameOverSoundChannel4 =
{
	// Configuration
	(SoundChannelConfiguration*)&GameOverSoundChannel4Configuration,

	// Length (PCM)
	0,

	// Sound track
	{
		(const uint8*)GameOverSoundTrack4
	}
};


SoundChannelROM* const GameOverSoundChannels[] =
{
	//&GameOverSoundChannel1,
	&GameOverSoundChannel2,
	&GameOverSoundChannel3,
	//&GameOverSoundChannel4,
	NULL
};

SoundROMSpec GameOverSoundSoundSpec =
{
	// Name
	"Game Over Sound",

	// Play in loop
	false,

	// Target timer resolution in us
	1420,

	// Tracks
	(SoundChannel**)GameOverSoundChannels
};
