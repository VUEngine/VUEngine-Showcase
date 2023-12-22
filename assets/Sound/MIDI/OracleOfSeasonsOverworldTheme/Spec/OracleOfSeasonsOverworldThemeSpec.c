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

extern const uint8 OracleOfSeasonsOverworldThemeSoundTrack1[];
extern const uint8 OracleOfSeasonsOverworldThemeSoundTrack2[];
extern const uint8 OracleOfSeasonsOverworldThemeSoundTrack3[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

SoundChannelConfigurationROM OracleOfSeasonsOverworldThemeSoundChannel1Configuration =
{
	/// kMIDI, kPCM
	kMIDI,

	/// SxINT
	0x9F,

	/// Volume SxLRV
	0xFF,

	/// SxRAM (this is overrode by the SoundManager)
	0x00,

	/// SxEV0
	0x40,

	/// SxEV1
	0x00,

	/// SxFQH
	0x00,

	/// SxFQL
	0x00,

	/// Ch. 5 only
	0x00,

	/// Waveform data pointer
	SawtoothWaveForm,

	/// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	/// Volume
	__SOUND_LR
};

SoundChannelConfigurationROM OracleOfSeasonsOverworldThemeSoundChannel2Configuration =
{
	/// kMIDI, kPCM
	kMIDI,

	/// SxINT
	0x9F,

	/// Volume SxLRV
	0xFF,

	/// SxRAM (this is overrode by the SoundManager)
	0x00,

	/// SxEV0
	0x40,

	/// SxEV1
	0x00,

	/// SxFQH
	0x00,

	/// SxFQL
	0x00,

	/// Ch. 5 only
	0x00,

	/// Waveform data pointer
	SawtoothWaveForm,

	/// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	/// Volume
	__SOUND_LR
};

SoundChannelConfigurationROM OracleOfSeasonsOverworldThemeSoundChannel3Configuration =
{
	/// kMIDI, kPCM
	kMIDI,

	/// SxINT
	0x9F,

	/// Volume SxLRV
	0xFF,

	/// SxRAM (this is overrode by the SoundManager)
	0x00,

	/// SxEV0
	0x40,

	/// SxEV1
	0x00,

	/// SxFQH
	0x00,

	/// SxFQL
	0x00,

	/// Ch. 5 only
	0x00,

	/// Waveform data pointer
	SawtoothWaveForm,

	/// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	/// Volume
	__SOUND_LR
};

SoundChannelROM OracleOfSeasonsOverworldThemeSoundChannel1 =
{
	/// Configuration
	(SoundChannelConfiguration*) &OracleOfSeasonsOverworldThemeSoundChannel1Configuration,

	//// Total number of samples
	0,

	/// Sound track
	{
		OracleOfSeasonsOverworldThemeSoundTrack1
	}
};

SoundChannelROM OracleOfSeasonsOverworldThemeSoundChannel2 =
{
	/// Configuration
	(SoundChannelConfiguration*) &OracleOfSeasonsOverworldThemeSoundChannel2Configuration,

	//// Total number of samples
	0,

	/// Sound track
	{
		OracleOfSeasonsOverworldThemeSoundTrack2
	}
};

SoundChannelROM OracleOfSeasonsOverworldThemeSoundChannel3 =
{
	/// Configuration
	(SoundChannelConfiguration*) &OracleOfSeasonsOverworldThemeSoundChannel3Configuration,

	//// Total number of samples
	0,

	/// Sound track
	{
		OracleOfSeasonsOverworldThemeSoundTrack3
	}
};


SoundChannelROM* OracleOfSeasonsOverworldThemeSoundChannels[] =
{
	&OracleOfSeasonsOverworldThemeSoundChannel1,
	&OracleOfSeasonsOverworldThemeSoundChannel2,
	&OracleOfSeasonsOverworldThemeSoundChannel3,
	NULL
};

SoundROMSpec OracleOfSeasonsOverworldThemeSoundSpec =
{
	/// Name
	"Oracle of Seasons - Overworld",

	/// Play in loop
	true,

	/// Target timer resolution in us
	880,

	/// Tracks
	(SoundChannel**)OracleOfSeasonsOverworldThemeSoundChannels
};