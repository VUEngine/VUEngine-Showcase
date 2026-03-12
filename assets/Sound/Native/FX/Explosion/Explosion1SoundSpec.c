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
#include <VSUSoundTrack.h>
#include <WaveForms.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern VSUSoundTrackROMSpec Explosion1SoundTrack1;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

VSUSoundTrackROMSpec* const Explosion1SoundTracks[] =
{
	&Explosion1SoundTrack1,
	NULL
};

SoundROMSpec Explosion1SoundSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Sound),

		// Component type
		kSoundComponent
	},

	// Song/Sound's name
	"Explosion 1",

	// Author's name
	NULL,

	// Play in loop
	false,

	// Tick duration in US
	500,

	// Tracks
	(SoundTrackSpec**)Explosion1SoundTracks,

	// Sound group
	kSoundGroupEffects
};