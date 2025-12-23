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

const WaveformData HerdingPidgeonsWaveform1 =
{
	// Data
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63, 63
	},

	// Checksum
	2566268968
};

const WaveformData HerdingPidgeonsWaveform2 =
{
	// Data
	{
		0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63
	},

	// Checksum
	3677078911
};

const WaveformData HerdingPidgeonsWaveform3 =
{
	// Data
	{
		43, 47, 51, 55, 59, 63, 59, 55, 51, 47, 43, 0, 7, 11, 15, 59, 55, 51, 47, 43, 47, 51, 55, 59, 63, 59, 55, 51, 15, 11, 7, 0
	},

	// Checksum
	2914655623
};

const WaveformData HerdingPidgeonsWaveform4 =
{
	// Data
	{
		63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},

	// Checksum
	3778786901
};

// Modulation Data

const int8 HerdingPidgeonsModulationData1[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
};

// Track 1

const uint8 HerdingPidgeonsSoundTrack0SxINT[] =
{
	0x80, 0x80, 0x80, 
};

const uint8 HerdingPidgeonsSoundTrack0SxLRV[] =
{
	0x00, 0xFF, 0xFF, 0xFF, 
};

const uint16 HerdingPidgeonsSoundTrack0SxFQ[] =
{
	0x0000, 0x04E3, 0x0672, 0x05EC, 0x0626, 0x0626, 0x0626, 0x05EC, 0x05EC, 0x04E3, 0x04E3, 0x05EC, 0x0626, 0x0626, 0x0626, 0x04B3, 
	0x0626, 0x0626, 0x04E3, 
};

const uint8 HerdingPidgeonsSoundTrack0SxEV0[] =
{
	0xF1, 0xF1, 0xF1, 
};

const uint8 HerdingPidgeonsSoundTrack0SxEV1[] =
{
	0x01, 0x01, 0x01, 
};

const WaveformData* const HerdingPidgeonsSoundTrack0SxRAM[] =
{
	&HerdingPidgeonsWaveform2, &HerdingPidgeonsWaveform1, &HerdingPidgeonsWaveform2, 
};

const uint8 HerdingPidgeonsSoundTrack0SxSWP[] =
{
	0x80, 
};

const int8* const HerdingPidgeonsSoundTrack0SxMOD[] =
{
	NULL, 
};

const SoundTrackKeyframe HerdingPidgeonsSoundTrack0Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{800, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{1200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{100, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{800, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{200, kSoundTrackEventSxFQ},
	{1200, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec HerdingPidgeonsSoundTrack0 =
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
	(SoundTrackKeyframe*)HerdingPidgeonsSoundTrack0Keyframes,

	// SxINT values
	(uint8*)HerdingPidgeonsSoundTrack0SxINT,

	// SxLRV values
	(uint8*)HerdingPidgeonsSoundTrack0SxLRV,

	// SxFQH and SxFQL values
	(uint16*)HerdingPidgeonsSoundTrack0SxFQ,

	// SxEV0 values
	(uint8*)HerdingPidgeonsSoundTrack0SxEV0,

	// SxEV1 values
	(uint8*)HerdingPidgeonsSoundTrack0SxEV1,

	// SxRAM pointers
	(WaveformData**)HerdingPidgeonsSoundTrack0SxRAM,

	// SxSWP values
	(uint8*)HerdingPidgeonsSoundTrack0SxSWP,

	// SxMOD pointers
	(int8**)HerdingPidgeonsSoundTrack0SxMOD,
};

// Track 2

const uint8 HerdingPidgeonsSoundTrack1SxINT[] =
{
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 
};

const uint8 HerdingPidgeonsSoundTrack1SxLRV[] =
{
	0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 
};

const uint16 HerdingPidgeonsSoundTrack1SxFQ[] =
{
	0x0000, 0x03D8, 0x03D8, 0x044C, 0x044C, 0x0626, 0x0626, 0x044C, 0x044C, 0x0626, 0x0626, 0x044C, 0x044C, 0x0626, 0x0626, 0x044C, 
	0x044C, 0x0626, 0x0626, 0x03D8, 0x03D8, 0x05EC, 0x05EC, 0x03D8, 0x03D8, 0x05EC, 0x05EC, 0x03D8, 0x03D8, 0x05EC, 0x05EC, 0x03D8, 
	0x03D8, 0x044C, 0x044C, 0x03D8, 0x03D8, 0x044C, 0x044C, 0x0626, 0x0626, 0x044C, 0x044C, 0x0626, 0x0626, 0x044C, 0x044C, 0x0626, 
	0x0626, 0x044C, 0x044C, 0x0626, 0x0626, 0x044C, 0x044C, 0x0587, 0x0587, 0x06C4, 0x06C4, 0x0626, 0x0626, 0x044C, 0x044C, 0x044C, 
	0x044C, 0x044C, 0x044C, 0x044C, 0x044C, 
};

const uint8 HerdingPidgeonsSoundTrack1SxEV0[] =
{
	0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 
	0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 
	0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 
	0x71, 0x71, 
};

const uint8 HerdingPidgeonsSoundTrack1SxEV1[] =
{
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x01, 
};

const WaveformData* const HerdingPidgeonsSoundTrack1SxRAM[] =
{
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
	&HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, &HerdingPidgeonsWaveform3, &HerdingPidgeonsWaveform4, 
};

const uint8 HerdingPidgeonsSoundTrack1SxSWP[] =
{
	0x10, 
};

const int8* const HerdingPidgeonsSoundTrack1SxMOD[] =
{
	NULL, 
};

const SoundTrackKeyframe HerdingPidgeonsSoundTrack1Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{150, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{50, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec HerdingPidgeonsSoundTrack1 =
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
	(SoundTrackKeyframe*)HerdingPidgeonsSoundTrack1Keyframes,

	// SxINT values
	(uint8*)HerdingPidgeonsSoundTrack1SxINT,

	// SxLRV values
	(uint8*)HerdingPidgeonsSoundTrack1SxLRV,

	// SxFQH and SxFQL values
	(uint16*)HerdingPidgeonsSoundTrack1SxFQ,

	// SxEV0 values
	(uint8*)HerdingPidgeonsSoundTrack1SxEV0,

	// SxEV1 values
	(uint8*)HerdingPidgeonsSoundTrack1SxEV1,

	// SxRAM pointers
	(WaveformData**)HerdingPidgeonsSoundTrack1SxRAM,

	// SxSWP values
	(uint8*)HerdingPidgeonsSoundTrack1SxSWP,

	// SxMOD pointers
	(int8**)HerdingPidgeonsSoundTrack1SxMOD,
};

// Track 3

const uint8 HerdingPidgeonsSoundTrack2SxINT[] =
{
	0x80, 0x80, 0x80, 
};

const uint8 HerdingPidgeonsSoundTrack2SxLRV[] =
{
	0x00, 0xFF, 0xFF, 0xFF, 
};

const uint16 HerdingPidgeonsSoundTrack2SxFQ[] =
{
	0x0000, 0x0640, 0x0587, 0x0672, 0x0688, 0x0587, 0x0587, 0x053A, 0x053A, 0x0640, 0x0640, 0x0672, 0x0688, 0x0587, 0x0587, 0x05EC, 
	0x0510, 0x0510, 0x0640, 
};

const uint8 HerdingPidgeonsSoundTrack2SxEV0[] =
{
	0xF1, 0xF1, 0xF1, 
};

const uint8 HerdingPidgeonsSoundTrack2SxEV1[] =
{
	0x01, 0x01, 0x01, 
};

const WaveformData* const HerdingPidgeonsSoundTrack2SxRAM[] =
{
	&HerdingPidgeonsWaveform1, &HerdingPidgeonsWaveform2, &HerdingPidgeonsWaveform1, 
};

const uint8 HerdingPidgeonsSoundTrack2SxSWP[] =
{
	0x80, 0x80, 0x80, 
};

const int8* const HerdingPidgeonsSoundTrack2SxMOD[] =
{
	NULL, NULL, NULL, 
};

const SoundTrackKeyframe HerdingPidgeonsSoundTrack2Keyframes[] =
{
	{0, kSoundTrackEventStart},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxLRV | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{800, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{1200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSxINT | kSoundTrackEventSxLRV | kSoundTrackEventSxEV0 | kSoundTrackEventSxEV1 | kSoundTrackEventSxRAM | kSoundTrackEventSxSWP | kSoundTrackEventSxMOD | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{800, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{1200, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{100, kSoundTrackEventSxFQ | kSoundTrackEventSweepMod},
	{0, kSoundTrackEventEnd}, 
};

SoundTrackROMSpec HerdingPidgeonsSoundTrack2 =
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
	(SoundTrackKeyframe*)HerdingPidgeonsSoundTrack2Keyframes,

	// SxINT values
	(uint8*)HerdingPidgeonsSoundTrack2SxINT,

	// SxLRV values
	(uint8*)HerdingPidgeonsSoundTrack2SxLRV,

	// SxFQH and SxFQL values
	(uint16*)HerdingPidgeonsSoundTrack2SxFQ,

	// SxEV0 values
	(uint8*)HerdingPidgeonsSoundTrack2SxEV0,

	// SxEV1 values
	(uint8*)HerdingPidgeonsSoundTrack2SxEV1,

	// SxRAM pointers
	(WaveformData**)HerdingPidgeonsSoundTrack2SxRAM,

	// SxSWP values
	(uint8*)HerdingPidgeonsSoundTrack2SxSWP,

	// SxMOD pointers
	(int8**)HerdingPidgeonsSoundTrack2SxMOD,
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SoundTrackROMSpec* const HerdingPidgeonsSoundTracks[] =
{
	&HerdingPidgeonsSoundTrack0,
	&HerdingPidgeonsSoundTrack1,
	&HerdingPidgeonsSoundTrack2,
	NULL
};

SoundROMSpec HerdingPidgeonsSoundSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Sound),

		// Component type
		kSoundComponent
	},

	// Name
	"Herding Pidgeons DX",

	// Play in loop
	true,

	// Tick duration in US
	1200,

	// Tracks
	(SoundTrackSpec**)HerdingPidgeonsSoundTracks,
};
