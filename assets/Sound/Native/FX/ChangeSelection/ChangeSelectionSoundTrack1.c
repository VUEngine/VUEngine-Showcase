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
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const uint8 ChangeSelection1SoundTrack1SxINT[] =
{
	0x9F,
};

const uint8 ChangeSelection1SoundTrack1SxLRV[] =
{
	0xFF, 0xBB, 0x77, 0x33,
};

const uint16 ChangeSelection1SoundTrack1SxFQ[] =
{
	CS4, A_4
};

const uint8 ChangeSelection1SoundTrack1SxEV0[] =
{
	0xF0,
};

const uint8 ChangeSelection1SoundTrack1SxEV1[] =
{
	0x01,
};

const WaveformData* const ChangeSelection1SoundTrack1SxRAM[] =
{
	&SawWaveForm,
};

const uint8 ChangeSelection1SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe ChangeSelection1SoundTrack1Keyframes[] =
{
	{80, kSoundTrackEventStart},
	{20, kSoundTrackEventSxLRV},
	{80, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{20, kSoundTrackEventSxLRV},
	{0, kSoundTrackEventEnd},
};

SoundTrackROMSpec ChangeSelection1SoundTrack1 =
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
	(SoundTrackKeyframe*)ChangeSelection1SoundTrack1Keyframes,

	/// SxINT values
	(uint8*)ChangeSelection1SoundTrack1SxINT,

	/// SxLRV values
	(uint8*)ChangeSelection1SoundTrack1SxLRV,

	/// SxFQH and SxFQL values
	(uint16*)ChangeSelection1SoundTrack1SxFQ,

	/// SxEV0 values
	(uint8*)ChangeSelection1SoundTrack1SxEV0,

	/// SxEV1 values
	(uint8*)ChangeSelection1SoundTrack1SxEV1,

	/// SxRAM pointers
	(WaveformData**)ChangeSelection1SoundTrack1SxRAM,

	/// SxSWP values
	(uint8*)ChangeSelection1SoundTrack1SxSWP,

	/// SxMOD values
	(int8**)NULL
};
