///////////////////////////////////////////////////////////////////////////////////////////////////////////
//                              THIS FILE WAS AUTO-GENERATED - DO NOT EDIT                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------------------------------------
//                                                INCLUDES                                                 
//---------------------------------------------------------------------------------------------------------

#include <SoundManager.h>
#include <WaveForms.h>


//---------------------------------------------------------------------------------------------------------
//                                              DECLARATIONS                                               
//---------------------------------------------------------------------------------------------------------

#define NoFearForTheFutureSoundTrackLength 690646

extern const uint8 NoFearForTheFutureSoundTrack[];


//---------------------------------------------------------------------------------------------------------
//                                               DEFINITIONS                                               
//---------------------------------------------------------------------------------------------------------

SoundChannelConfigurationROM NoFearForTheFutureSoundChannelConfiguration =
{
	// Type (kMIDI or kPCM)
	kPCM,

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
	PCMWaveForm,

	// kChannelNormal, kChannelModulation, kChannelNoise
	kChannelNormal,

	// Volume
	__SOUND_LR
};

SoundChannelROM NoFearForTheFutureSoundChannel =
{
	// Configuration
	(SoundChannelConfiguration*) &NoFearForTheFutureSoundChannelConfiguration,

	// Length (PCM)
	NoFearForTheFutureSoundTrackLength,

	// Sound track
	{
		NoFearForTheFutureSoundTrack
	}
};

SoundChannelROM* const NoFearForTheFutureSoundChannels[] =
{
    &NoFearForTheFutureSoundChannel,
    &NoFearForTheFutureSoundChannel,
    &NoFearForTheFutureSoundChannel,
    &NoFearForTheFutureSoundChannel,
    NULL
};

SoundROM NoFearForTheFutureSound =
{
	// Name
	"Teknoaxe - No Fear For The Future",

	// Play in loop
	false,

	// Target timer resolution in us
	260,

	// Tracks
	(SoundChannel**)NoFearForTheFutureSoundChannels
};
