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
#include <SoundTrack.h>
#include <WaveForms.h>


//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const uint8 Killed1SoundTrack1SxINT[] =
{
	0x9F,
};

const uint8 Killed1SoundTrack1SxLRV[] =
{
	0xAA, 0x88, 0x44,
};

const uint16 Killed1SoundTrack1SxFQ[] =
{
	0x3E8
};

const uint8 Killed1SoundTrack1SxEV0[] =
{
	0xF7,
};

const uint8 Killed1SoundTrack1SxEV1[] =
{
	0x31,
};

const int8* const Killed1SoundTrack1SxRAM[] =
{
	SquareWaveForm,
};

const uint8 Killed1SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe Killed1SoundTrack1Keyframes[] =
{
	{100, kSoundTrackEventStart | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{100, kSoundTrackEventSxLRV | kSoundTrackEventNoise},
	{0, kSoundTrackEventEnd},
};

SoundTrackROMSpec Killed1SoundTrack1 =
{
	/// kTrackNative, kTrackPCM
	kTrackNative,

	/// Skip if no sound source available?
	false,

	/// Total number of samples (0 if not PCM)
	0,

	/// Keyframes that define the track
	(SoundTrackKeyframe*)Killed1SoundTrack1Keyframes,

	/// SxINT values
	(uint8*)Killed1SoundTrack1SxINT,

	/// SxLRV values
	(uint8*)Killed1SoundTrack1SxLRV,

	/// SxFQH and SxFQL values
	(uint16*)Killed1SoundTrack1SxFQ,

	/// SxEV0 values
	(uint8*)Killed1SoundTrack1SxEV0,

	/// SxEV1 values
	(uint8*)Killed1SoundTrack1SxEV1,

	/// SxRAM pointers
	(int8**)Killed1SoundTrack1SxRAM,

	/// SxSWP values
	(uint8*)Killed1SoundTrack1SxSWP,

	/// SxMOD values
	(int8**)NULL
};
