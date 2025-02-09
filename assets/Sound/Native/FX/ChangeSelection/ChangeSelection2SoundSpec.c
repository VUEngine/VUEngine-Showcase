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

extern SoundTrackROMSpec ChangeSelection2SoundTrack1;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// DEFINITIONS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

SoundTrackROMSpec* const ChangeSelection2SoundTracks[] =
{
	&ChangeSelection2SoundTrack1,
	NULL
};

SoundROMSpec ChangeSelection2SoundSpec =
{
	// Name
	"Change Selection Sound 2",

	// Play in loop
	false,

	// Tick duration in US
	500,

	// Tracks
	(SoundTrackSpec**)ChangeSelection2SoundTracks
};