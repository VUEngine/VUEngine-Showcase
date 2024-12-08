/*
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

#include <AnimationInspector.h>
#include <Debug.h>
#include <StageEditor.h>
#include <Sounds.h>
#include <VUEngine.h>


//=========================================================================================================
// GLOBALS' DECLARATIONS
//=========================================================================================================

extern AnimatedEntityROMSpec PunkEntitySpec;


//=========================================================================================================
// GLOBALS' DEFINITIONS
//=========================================================================================================

#ifdef __DEBUG_TOOL
const ClassSizeData _userClassesSizeData[] =
{
	{NULL, ""},
};
#endif

const UserObject _userObjects[] =
{
	{NULL, ""},
};

const UserAnimatedEntity _userAnimatedEntities[] =
{
	{&PunkEntitySpec, "Punk"},
	{NULL, ""},
};

const SoundROMSpec* _userSounds[] =
{
	&OracleOfSeasonsOverworldThemeSoundSpec,
	&NoFearForTheFutureSoundSpec,
	&Explosion1SoundSpec,
	&Engine1SoundSpec,
	NULL
};

const ToolState _userToolStates[] =
{
	NULL
};
