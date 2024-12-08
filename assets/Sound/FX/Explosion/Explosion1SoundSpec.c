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
// DECLARATIONS
//=========================================================================================================

extern SoundTrackROMSpec Explosion1SoundTrack1;


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

SoundTrackROMSpec* const Explosion1SoundTracks[] =
{
	&Explosion1SoundTrack1,
	NULL
};

SoundROMSpec Explosion1SoundSpec =
{
	// Name
	"Explosion 1",

	// Play in loop
	false,

	// Tick duraction in US
	500,

	// Tracks
	(SoundTrackSpec**)Explosion1SoundTracks
};