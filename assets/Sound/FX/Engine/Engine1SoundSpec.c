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

extern SoundTrackROMSpec Engine1SoundTrack1;

//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

SoundTrackROMSpec* const Engine1SoundTracks[] =
{
	&Engine1SoundTrack1,
	NULL
};

SoundROMSpec Engine1SoundSpec =
{
	// Name
	"Engine 1",

	// Play in loop
	true,

	// Target timer resolution in us
	1000,

	// Tracks
	(SoundTrackSpec**)Engine1SoundTracks
};