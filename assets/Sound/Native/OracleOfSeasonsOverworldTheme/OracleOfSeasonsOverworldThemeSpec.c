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
// DECLARATIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

extern SoundTrackROMSpec OracleOfSeasonsOverworldThemeSoundTrack1;
extern SoundTrackROMSpec OracleOfSeasonsOverworldThemeSoundTrack2;
extern SoundTrackROMSpec OracleOfSeasonsOverworldThemeSoundTrack3;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SoundTrackROMSpec* const OracleOfSeasonsOverworldThemeSoundTracks[] =
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

	// Name
	"Oracle of Seasons - Overworld",

	// Play in loop
	true,

	// Tick duration in US
	880,

	// Tracks
	(SoundTrackSpec**)OracleOfSeasonsOverworldThemeSoundTracks
};