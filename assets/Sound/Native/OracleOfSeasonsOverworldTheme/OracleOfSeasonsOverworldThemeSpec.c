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
#include <VBSoundTrack.h>
#include <WaveForms.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern VBSoundTrackROMSpec OracleOfSeasonsOverworldThemeSoundTrack1;
extern VBSoundTrackROMSpec OracleOfSeasonsOverworldThemeSoundTrack2;
extern VBSoundTrackROMSpec OracleOfSeasonsOverworldThemeSoundTrack3;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

VBSoundTrackROMSpec* const OracleOfSeasonsOverworldThemeSoundTracks[] =
{
	&OracleOfSeasonsOverworldThemeSoundTrack1,
	&OracleOfSeasonsOverworldThemeSoundTrack2,
	&OracleOfSeasonsOverworldThemeSoundTrack3,
	NULL
};

SoundROMSpec OracleOfSeasonsOverworldThemeSoundSpec =
{
	// Component
	{
		// Allocator
		__TYPE(Sound),

		// Component type
		kSoundComponent
	},

	// Song/Sound's name
	"Oracle of Seasons - Overworld",

	// Author's name
	NULL,

	// Play in loop
	true,

	// Tick duration in US
	880,

	// Tracks
	(SoundTrackSpec**)OracleOfSeasonsOverworldThemeSoundTracks,

	// Sound group
	kSoundGroupEffects
};