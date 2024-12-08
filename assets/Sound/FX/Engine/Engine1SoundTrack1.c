/*
 * VUEngine Plugins Library
 *
 * (c) Christian Radke and Jorge Eremiev
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <Sound.h>
#include <SoundTrack.h>
#include <WaveForms.h>


//=========================================================================================================
// MACROS
//=========================================================================================================

#define ENGINE_FREQ    		0x8FF


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

const uint8 Engine1SoundTrack1SxINT[] =
{
	0x9F,
};

const uint8 Engine1SoundTrack1SxLRV[] =
{
	0xEE, 0xFF, 0xEE,
};

const uint16 Engine1SoundTrack1SxFQ[] =
{
	0x016 + ENGINE_FREQ, 0x016 + ENGINE_FREQ, 0x016 + ENGINE_FREQ, 0x024 + ENGINE_FREQ, 0x024 + ENGINE_FREQ, 0x032 + ENGINE_FREQ, 0x032 + ENGINE_FREQ, 0x040 + ENGINE_FREQ, 0x032 + ENGINE_FREQ, 0x032 + ENGINE_FREQ, 0x024 + ENGINE_FREQ, 0x024 + ENGINE_FREQ, 0x016 + ENGINE_FREQ, 0x016 + ENGINE_FREQ, 0x016 + ENGINE_FREQ,
};

const uint8 Engine1SoundTrack1SxEV0[] =
{
	0xF0,
};

const uint8 Engine1SoundTrack1SxEV1[] =
{
	0x00,
};

const int8* const Engine1SoundTrack1SxRAM[] =
{
	TriangleWaveForm,
};

const uint8 Engine1SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe Engine1SoundTrack1Keyframes[] =
{
	{80, kSoundTrackEventStart},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxFQ},
	{0, kSoundTrackEventEnd},
};

SoundTrackROMSpec Engine1SoundTrack1 =
{
	/// kTrackNative, kTrackPCM
	kTrackNative,

	/// Total number of samples (0 if not PCM)
	0,

	/// Keyframes that define the track
	(SoundTrackKeyframe*)Engine1SoundTrack1Keyframes,

	/// SxINT values
	(uint8*)Engine1SoundTrack1SxINT,

	/// SxLRV values
	(uint8*)Engine1SoundTrack1SxLRV,

	/// SxFQH and SxFQL values
	(uint16*)Engine1SoundTrack1SxFQ,

	/// SxEV0 values
	(uint8*)Engine1SoundTrack1SxEV0,

	/// SxEV1 values
	(uint8*)Engine1SoundTrack1SxEV1,

	/// SxRAM pointers
	(int8**)Engine1SoundTrack1SxRAM,

	/// S5SWP values
	(uint8*)Engine1SoundTrack1SxSWP
};
