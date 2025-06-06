/*
 * VUExplosion Plugins Library
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
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const uint8 Explosion1SoundTrack1SxINT[] =
{
	0x1F,
};

const uint8 Explosion1SoundTrack1SxLRV[] =
{
	0xEE, 0xBB, 0xAA, 0x88, 0x44
};

const uint16 Explosion1SoundTrack1SxFQ[] =
{
	0x3E8
};

const uint8 Explosion1SoundTrack1SxEV0[] =
{
	0xF7,
};

const uint8 Explosion1SoundTrack1SxEV1[] =
{
	0x11,
};

const WaveformData* const Explosion1SoundTrack1SxRAM[] =
{
	&TriangleWaveForm,
};

const uint8 Explosion1SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe Explosion1SoundTrack1Keyframes[] =
{
	{500, kSoundTrackEventStart | kSoundTrackEventNoise},
	{500, kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{500, kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{500, kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{500, kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{0, kSoundTrackEventEnd},
};

SoundTrackROMSpec Explosion1SoundTrack1 =
{
	/// kTrackNative, kTrackPCM
	kTrackNative,

	/// Skip if no sound source available?
	false,

	/// Total number of samples (0 if not PCM)
	0,

	/// Loop back point (cursor)
	0,

	/// Keyframes that define the track
	(SoundTrackKeyframe*)Explosion1SoundTrack1Keyframes,

	/// SxINT values
	(uint8*)Explosion1SoundTrack1SxINT,

	/// SxLRV values
	(uint8*)Explosion1SoundTrack1SxLRV,

	/// SxFQH and SxFQL values
	(uint16*)Explosion1SoundTrack1SxFQ,

	/// SxEV0 values
	(uint8*)Explosion1SoundTrack1SxEV0,

	/// SxEV1 values
	(uint8*)Explosion1SoundTrack1SxEV1,

	/// SxRAM pointers
	(WaveformData**)Explosion1SoundTrack1SxRAM,

	/// SxSWP values
	(uint8*)Explosion1SoundTrack1SxSWP,

	/// SxMOD values
	(int8**)NULL
};
