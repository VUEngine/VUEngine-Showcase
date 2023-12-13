/**
 * Formula V
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <MIDI.h>


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// Instrument: square;
const uint16 BootSoundTrack1[] =
{
  PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, A_6, A_6, E_6, FS6, ENDSOUND,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 60, 30, 30, 120,
  15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
};

// Instrument: square;
const uint16 BootSoundTrack2[] =
{
  PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, E_6, E_6, CS6, DS6, ENDSOUND,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 60, 30, 30, 120,
  13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13
};

// Instrument: square;
const uint16 BootSoundTrack3[] =
{
  PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, PAU, CS6, CS6, A_5, B_5, ENDSOUND,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 60, 30, 30, 120,
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12
};

