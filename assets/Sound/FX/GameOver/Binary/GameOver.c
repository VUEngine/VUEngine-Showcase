/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//=========================================================================================================
// INCLUDES
//=========================================================================================================

#include <MIDI.h>


//=========================================================================================================
// DEFINITIONS
//=========================================================================================================

// Instrument: 0 patchchange ch: 1 electric bass(pick);
const uint16 GameOverSoundTrack1[] =
{
  PAU, B_2, PAU, E_3, PAU, A_2, PAU, ENDSOUND,
  1, 372, 356, 340, 260, 1680, 88,
  11, 11, 11, 11, 11, 11, 11
};

// Instrument: 0 patchchange ch: 2 trumpet;
const uint16 GameOverSoundTrack2[] =
{
  PAU, FS5, PAU, A_4, CS5, D_5, FS5, A_5, GS5, PAU, E_5, PAU, B_5, ENDSOUND,
  1, 192, 68, 116, 96, 112, 116, 104, 196, 16, 140, 208, 1784,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11
};

// Instrument: 0 patchchange ch: 2 trumpet;
const uint16 GameOverSoundTrack3[] =
{
  PAU, A_4, PAU, FS4, A_4, B_4, D_5, PAU, F_5, PAU, E_5, B_4, PAU, E_5, PAU, ENDSOUND,
  1, 236, 64, 88, 108, 96, 104, 8, 80, 12, 244, 148, 196, 1752, 8,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11
};

// Instrument: 0 patchchange ch: 10 acoustic grand;
const uint16 GameOverSoundTrack4[] =
{
  PAU, GS2, PAU, GS2, PAU, GS2, PAU, E_2, PAU, E_2, PAU, E_2, CS4, PAU, ENDSOUND,
  1, 96, 672, 112, 464, 96, 1364, 44, 32, 44, 16, 40, 60, 92,
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11
};


