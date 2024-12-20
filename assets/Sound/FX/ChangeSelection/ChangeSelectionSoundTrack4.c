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
// DEFINITIONS
//=========================================================================================================

const uint8 ChangeSelection4SoundTrack1SxINT[] =
{
	0x9F,
};

const uint8 ChangeSelection4SoundTrack1SxLRV[] =
{
	0xFF, 0xBB, 0x77, 0x33,
};

const uint16 ChangeSelection4SoundTrack1SxFQ[] =
{
	A_4, B_4, E_5
};

const uint8 ChangeSelection4SoundTrack1SxEV0[] =
{
	0xF0,
};

const uint8 ChangeSelection4SoundTrack1SxEV1[] =
{
	0x01,
};

const int8* const ChangeSelection4SoundTrack1SxRAM[] =
{
	SawSquareWaveForm,
};

const uint8 ChangeSelection4SoundTrack1SxSWP[] =
{
	0x00,
};

const SoundTrackKeyframe ChangeSelection4SoundTrack1Keyframes[] =
{
	{80, kSoundTrackEventStart},
	{80, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxLRV | kSoundTrackEventSxFQ},
	{80, kSoundTrackEventSxLRV},
	{0, kSoundTrackEventEnd},
};

SoundTrackROMSpec ChangeSelection4SoundTrack1 =
{
	/// kTrackNative, kTrackPCM
	kTrackNative,

	/// Skip if no sound source available?
	false,

	/// Total number of samples (0 if not PCM)
	0,

	/// Keyframes that define the track
	(SoundTrackKeyframe*)ChangeSelection4SoundTrack1Keyframes,

	/// SxINT values
	(uint8*)ChangeSelection4SoundTrack1SxINT,

	/// SxLRV values
	(uint8*)ChangeSelection4SoundTrack1SxLRV,

	/// SxFQH and SxFQL values
	(uint16*)ChangeSelection4SoundTrack1SxFQ,

	/// SxEV0 values
	(uint8*)ChangeSelection4SoundTrack1SxEV0,

	/// SxEV1 values
	(uint8*)ChangeSelection4SoundTrack1SxEV1,

	/// SxRAM pointers
	(int8**)ChangeSelection4SoundTrack1SxRAM,

	/// SxSWP values
	(uint8*)ChangeSelection4SoundTrack1SxSWP,

	/// SxMOD values
	(int8**)NULL
};
