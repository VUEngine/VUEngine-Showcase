/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Sound.h>
#include <SoundTrack.h>
#include <WaveForms.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// MACROS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define ENGINE_FREQ			0x8FF

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const uint8 Engine1SoundTrack1SxINT[] =
{
	0x1F,
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
	0x30,
};

const WaveformData* const Engine1SoundTrack1SxRAM[] =
{
	&TriangleWaveForm,
};

const uint8 Engine1SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe Engine1SoundTrack1Keyframes[] =
{
	{50, kSoundTrackEventStart},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{50, kSoundTrackEventSxFQ},
	{0, kSoundTrackEventEnd},
};

SoundTrackROMSpec Engine1SoundTrack1 =
{
	/// kTrackNative, kTrackPCM
	kTrackNative,

	/// Skip if no sound source available?
	true,

	/// Total number of samples (0 if not PCM)
	0,

	/// Loop back point (cursor)
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
	(WaveformData**)Engine1SoundTrack1SxRAM,

	/// SxSWP values
	(uint8*)Engine1SoundTrack1SxSWP,

	/// SxMOD values
	(int8**)NULL
};
