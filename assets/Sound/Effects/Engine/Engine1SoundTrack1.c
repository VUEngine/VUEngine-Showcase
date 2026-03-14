/*
 * VUEngine Plugins Library
 *
 * (c) Christian Radke and Jorge Eremiev
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <Sound.h>
#include <VSUSoundTrack.h>
#include <WaveForms.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// MACROS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define ENGINE_FREQ			MINIMUM_AUDIBLE_NOTE + 0x0AA + 96

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

const WaveformData* const Engine1SoundTrack1SxRAM[] =
{
	&TriangleWaveForm
};

const uint8 Engine1SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe Engine1SoundTrack1Keyframes[] =
{
	{100, kSoundTrackEventStart},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{100, kSoundTrackEventSxFQ},
	{0, kSoundTrackEventEnd},
};

VSUSoundTrackROMSpec Engine1SoundTrack1 =
{
	// SoundTrack
	{
		// Allocator
		__TYPE(VSUSoundTrack),

		/// Priority for sound channel usage
		10,

		/// Skip if no sound source available?
		false,

		/// Loop back point (cursor)
		0,

		/// Keyframes that define the track
		(SoundTrackKeyframe*)Engine1SoundTrack1Keyframes
	},

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
