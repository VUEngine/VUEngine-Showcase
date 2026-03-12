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

extern VSUSoundTrackROMSpec HitPaddle1SoundTrack1;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

VSUSoundTrackROMSpec* const HitPaddle1SoundTracks[] =
{
	&HitPaddle1SoundTrack1,
	NULL
};

SoundROMSpec HitPaddle1SoundSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Sound),

		// Component type
		kSoundComponent
	},

	// Song/Sound's name
	"Hit Paddle Sound 1",

	// Author's name
	NULL,

	// Play in loop
	false,

	// Tick duration in US
	500,

	// Tracks
	(SoundTrackSpec**)HitPaddle1SoundTracks,

	// Sound group
	kSoundGroupEffects
};
