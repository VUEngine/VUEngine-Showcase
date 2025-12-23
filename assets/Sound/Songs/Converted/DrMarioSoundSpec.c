////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  THIS FILE WAS AUTO-GENERATED - DO NOT EDIT  ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Sound.h>
#include <SoundTrack.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

// Waveforms

const WaveformData DrMarioWaveform1 =
{
	// Data
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},

	// Checksum
	3931527250
};

const WaveformData DrMarioWaveform2 =
{
	// Data
	{
		63, 59, 55, 51, 47, 43, 39, 35, 31, 27, 23, 19, 15, 11, 7, 0, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63, 63
	},

	// Checksum
	2065905002
};

const WaveformData DrMarioWaveform3 =
{
	// Data
	{
		0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63
	},

	// Checksum
	3677078911
};

const WaveformData DrMarioWaveform4 =
{
	// Data
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63, 63
	},

	// Checksum
	2566268968
};

const WaveformData DrMarioWaveform5 =
{
	// Data
	{
		59, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 59, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4
	},

	// Checksum
	1219202089
};

// Modulation Data

const int8 DrMarioModulationData1[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
};

// Track 1

const uint8 DrMarioSoundTrack0SxINT[] =
{
	0x80, 0x80, 
};

const uint8 DrMarioSoundTrack0SxLRV[] =
{
	0x00, 0xFF, 0xFF, 
};

const uint16 DrMarioSoundTrack0SxFQ[] =
{
	0x0000, 0x06D5, 0x0672, 0x0626, 0x0640, 0x0672, 0x0640, 0x0626, 0x05AB, 0x060B, 0x0640, 0x0640, 0x060B, 0x0562, 0x05AB, 0x060B, 
	0x05AB, 0x0640, 0x0659, 0x060B, 0x0562, 0x05AB, 0x05AB, 0x05AB, 0x060B, 0x0562, 0x05AB, 0x05AB, 0x05AB, 0x06D5, 0x0672, 0x0626, 
	0x0640, 0x0672, 0x0640, 0x0626, 0x05AB, 0x060B, 0x0640, 0x0640, 0x060B, 0x0562, 0x05AB, 0x060B, 0x05AB, 0x0640, 0x0659, 0x060B, 
	0x0562, 0x05AB, 0x05AB, 0x05AB, 0x060B, 0x0562, 0x05AB, 0x05AB, 0x05AB, 0x05AB, 0x060B, 0x060B, 0x060B, 0x060B, 0x0672, 0x0672, 
	0x060B, 0x060B, 0x05AB, 0x05AB, 0x060B, 0x060B, 0x0672, 0x0672, 0x05AB, 0x05AB, 0x060B, 0x060B, 0x060B, 0x060B, 0x0672, 0x0672, 
	0x060B, 0x060B, 0x05AB, 0x05AB, 0x060B, 0x060B, 0x0672, 0x0672, 0x05AB, 0x05AB, 
};

const uint8 DrMarioSoundTrack0SxEV0[] =
{
	0xE2, 0xF0, 
};

const uint8 DrMarioSoundTrack0SxEV1[] =
{
	0x01, 0x01, 
};

const WaveformData* const DrMarioSoundTrack0SxRAM[] =
{
	&DrMarioWaveform5, &DrMarioWaveform3, 
};

const uint8 DrMarioSoundTrack0SxSWP[] =
{
	0x80, 
};

const int8* const DrMarioSoundTrack0SxMOD[] =
{
	NULL, 
};

const SoundTrackKeyframe DrMarioSoundTrack0Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{6500, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec DrMarioSoundTrack0 =
{
	// kTrackNative, kTrackPCM
	kTrackNative,

	// Skip if no sound source available?
	false,

	// Total number of samples (0 if not PCM)
	0,

	// Loop back point (cursor)
	0,

	// Keyframes that define the track
	(SoundTrackKeyframe*)DrMarioSoundTrack0Keyframes,

	// SxINT values
	(uint8*)DrMarioSoundTrack0SxINT,

	// SxLRV values
	(uint8*)DrMarioSoundTrack0SxLRV,

	// SxFQH and SxFQL values
	(uint16*)DrMarioSoundTrack0SxFQ,

	// SxEV0 values
	(uint8*)DrMarioSoundTrack0SxEV0,

	// SxEV1 values
	(uint8*)DrMarioSoundTrack0SxEV1,

	// SxRAM pointers
	(WaveformData**)DrMarioSoundTrack0SxRAM,

	// SxSWP values
	(uint8*)DrMarioSoundTrack0SxSWP,

	// SxMOD pointers
	(int8**)DrMarioSoundTrack0SxMOD,
};

// Track 2

const uint8 DrMarioSoundTrack1SxINT[] =
{
	0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 
	0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 0xAB, 
	0xA8, 0xAB, 0xA8, 0xAB, 0xA8, 
};

const uint8 DrMarioSoundTrack1SxLRV[] =
{
	0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
};

const uint16 DrMarioSoundTrack1SxFQ[] =
{
	0x0000, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 
	0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 
	0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 
	0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 
	0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 
	0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 
	0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 
	0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 
	0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 
	0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 
	0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 
	0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 
	0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 
	0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 
	0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 
	0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 0x0027, 0x0027, 
	0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 0x0102, 0x0102, 0x01C6, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0027, 0x0102, 
	0x0102, 0x0102, 0x01C6, 0x01C6, 0x01C6, 
};

const uint8 DrMarioSoundTrack1SxEV0[] =
{
	0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 
	0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 0xD7, 
	0xD3, 0xD7, 0xD3, 0xD7, 0xD3, 
};

const uint8 DrMarioSoundTrack1SxEV1[] =
{
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 
};

const WaveformData* const DrMarioSoundTrack1SxRAM[] =
{
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, &DrMarioWaveform3, 
	&DrMarioWaveform3, 
};

const uint8 DrMarioSoundTrack1SxSWP[] =
{
	0x30, 
};

const int8* const DrMarioSoundTrack1SxMOD[] =
{
	NULL, 
};

const SoundTrackKeyframe DrMarioSoundTrack1Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec DrMarioSoundTrack1 =
{
	// kTrackNative, kTrackPCM
	kTrackNative,

	// Skip if no sound source available?
	false,

	// Total number of samples (0 if not PCM)
	0,

	// Loop back point (cursor)
	0,

	// Keyframes that define the track
	(SoundTrackKeyframe*)DrMarioSoundTrack1Keyframes,

	// SxINT values
	(uint8*)DrMarioSoundTrack1SxINT,

	// SxLRV values
	(uint8*)DrMarioSoundTrack1SxLRV,

	// SxFQH and SxFQL values
	(uint16*)DrMarioSoundTrack1SxFQ,

	// SxEV0 values
	(uint8*)DrMarioSoundTrack1SxEV0,

	// SxEV1 values
	(uint8*)DrMarioSoundTrack1SxEV1,

	// SxRAM pointers
	(WaveformData**)DrMarioSoundTrack1SxRAM,

	// SxSWP values
	(uint8*)DrMarioSoundTrack1SxSWP,

	// SxMOD pointers
	(int8**)DrMarioSoundTrack1SxMOD,
};

// Track 3

const uint8 DrMarioSoundTrack2SxINT[] =
{
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
};

const uint8 DrMarioSoundTrack2SxLRV[] =
{
	0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
};

const uint16 DrMarioSoundTrack2SxFQ[] =
{
	0x0000, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 0x07A8, 
	0x0713, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 0x07A8, 
	0x0713, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 0x07A8, 
	0x0713, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 0x07A8, 
	0x0713, 0x0739, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 
	0x07A8, 0x0713, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 
	0x07A8, 0x0713, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 
	0x07A8, 0x0713, 0x0720, 0x0713, 0x07A8, 0x0713, 0x0720, 0x0720, 0x07A8, 0x0720, 0x0720, 0x06D5, 0x07A8, 0x06D5, 0x0720, 0x0713, 
	0x07A8, 0x0713, 
};

const uint8 DrMarioSoundTrack2SxEV0[] =
{
	0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 
	0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 
	0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 
	0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 
	0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 
	0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 0xC0, 0x70, 
};

const uint8 DrMarioSoundTrack2SxEV1[] =
{
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
	0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
};

const WaveformData* const DrMarioSoundTrack2SxRAM[] =
{
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
	&DrMarioWaveform2, &DrMarioWaveform4, &DrMarioWaveform2, &DrMarioWaveform4, 
};

const uint8 DrMarioSoundTrack2SxSWP[] =
{
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
	0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
};

const int8* const DrMarioSoundTrack2SxMOD[] =
{
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
	NULL, NULL, NULL, NULL, 
};

const SoundTrackKeyframe DrMarioSoundTrack2Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{6400, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec DrMarioSoundTrack2 =
{
	// kTrackNative, kTrackPCM
	kTrackNative,

	// Skip if no sound source available?
	false,

	// Total number of samples (0 if not PCM)
	0,

	// Loop back point (cursor)
	0,

	// Keyframes that define the track
	(SoundTrackKeyframe*)DrMarioSoundTrack2Keyframes,

	// SxINT values
	(uint8*)DrMarioSoundTrack2SxINT,

	// SxLRV values
	(uint8*)DrMarioSoundTrack2SxLRV,

	// SxFQH and SxFQL values
	(uint16*)DrMarioSoundTrack2SxFQ,

	// SxEV0 values
	(uint8*)DrMarioSoundTrack2SxEV0,

	// SxEV1 values
	(uint8*)DrMarioSoundTrack2SxEV1,

	// SxRAM pointers
	(WaveformData**)DrMarioSoundTrack2SxRAM,

	// SxSWP values
	(uint8*)DrMarioSoundTrack2SxSWP,

	// SxMOD pointers
	(int8**)DrMarioSoundTrack2SxMOD,
};

// Track 4

const uint8 DrMarioSoundTrack3SxINT[] =
{
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
};

const uint8 DrMarioSoundTrack3SxLRV[] =
{
	0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
};

const uint16 DrMarioSoundTrack3SxFQ[] =
{
	0x0000, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x0790, 0x0790, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 
	0x0739, 0x078A, 0x0782, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x0782, 0x079C, 0x0739, 0x07BA, 
	0x07BA, 0x079C, 0x0782, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x0790, 0x0790, 0x07BA, 0x07BA, 
	0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x078A, 0x0782, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 
	0x0782, 0x079C, 0x0739, 0x07BA, 0x07BA, 0x079C, 0x0782, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 
	0x0790, 0x0790, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x078A, 0x0782, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 
	0x07BA, 0x0739, 0x07BA, 0x07BA, 0x0782, 0x079C, 0x0739, 0x07BA, 0x07BA, 0x079C, 0x0782, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 
	0x07BA, 0x07BA, 0x07BA, 0x0739, 0x0790, 0x0790, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x078A, 0x0782, 0x07BA, 
	0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x0782, 0x079C, 0x0739, 0x07BA, 0x07BA, 0x079C, 0x0782, 0x0739, 
	0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x0790, 0x0790, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 
	0x0739, 0x078A, 0x0782, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x0782, 0x079C, 0x0739, 0x07BA, 
	0x07BA, 0x079C, 0x0782, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x0790, 0x0790, 0x07BA, 0x07BA, 
	0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x078A, 0x0782, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 0x07BA, 0x0739, 0x07BA, 0x07BA, 
	0x0782, 0x079C, 0x0739, 0x07BA, 0x07BA, 0x079C, 0x0782, 0x0739, 0x07BA, 
};

const uint8 DrMarioSoundTrack3SxEV0[] =
{
	0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0xE0, 
	0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0xE0, 0x80, 0xE0, 
	0x60, 0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 
	0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 
	0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0xE0, 0x80, 0xE0, 0x60, 0x80, 0xE0, 0x80, 0xE0, 0x60, 
	0x80, 0xE0, 0x80, 0xE0, 0x80, 0x60, 0xE0, 0x80, 0x60, 0xE0, 0x80, 
};

const uint8 DrMarioSoundTrack3SxEV1[] =
{
	0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x21, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 
	0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 
	0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x01, 0x01, 0x21, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x01, 0x01, 0x21, 0x01, 0x01, 
};

const WaveformData* const DrMarioSoundTrack3SxRAM[] =
{
	NULL, 
};

const uint8 DrMarioSoundTrack3SxSWP[] =
{
	0x10, 
};

const int8* const DrMarioSoundTrack3SxMOD[] =
{
	NULL, 
};

const SoundTrackKeyframe DrMarioSoundTrack3Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventNoise},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec DrMarioSoundTrack3 =
{
	// kTrackNative, kTrackPCM
	kTrackNative,

	// Skip if no sound source available?
	false,

	// Total number of samples (0 if not PCM)
	0,

	// Loop back point (cursor)
	0,

	// Keyframes that define the track
	(SoundTrackKeyframe*)DrMarioSoundTrack3Keyframes,

	// SxINT values
	(uint8*)DrMarioSoundTrack3SxINT,

	// SxLRV values
	(uint8*)DrMarioSoundTrack3SxLRV,

	// SxFQH and SxFQL values
	(uint16*)DrMarioSoundTrack3SxFQ,

	// SxEV0 values
	(uint8*)DrMarioSoundTrack3SxEV0,

	// SxEV1 values
	(uint8*)DrMarioSoundTrack3SxEV1,

	// SxRAM pointers
	(WaveformData**)DrMarioSoundTrack3SxRAM,

	// SxSWP values
	(uint8*)DrMarioSoundTrack3SxSWP,

	// SxMOD pointers
	(int8**)DrMarioSoundTrack3SxMOD,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SoundTrackROMSpec* const DrMarioSoundTracks[] =
{
	&DrMarioSoundTrack0,
	&DrMarioSoundTrack1,
	&DrMarioSoundTrack2,
	&DrMarioSoundTrack3,
	NULL
};

SoundROMSpec DrMarioSoundSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Sound),

		// Component type
		kSoundComponent
	},

	// Name
	"BEATSCRIBE - DR. MARIO",

	// Play in loop
	false,

	// Tick duration in US
	2240,

	// Tracks
	(SoundTrackSpec**)DrMarioSoundTracks,
};
