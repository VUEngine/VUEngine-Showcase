
/* VUEngine - Virtual Utopia Engine <http://vuengine.planetvb.com/>
 * A universal game engine for the Nintendo Virtual Boy
 *
 * Copyright (C) 2007, 2019 by Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <chris@vr32.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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

SoundROM OracleOfSeasonsOverworldThemeSound =
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