/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <VUEngine.h>
#include <Debug.h>
#include <StageEditor.h>
#include <AnimationInspector.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern Sound NoFearForTheFutureSound;
extern Sound OracleOfSeasonsOverworldThemeSound;
extern Sound EngineSound;
extern Sound ExplosionSound;


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

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
	{NULL, ""},
};

const SoundROM* _userSounds[] =
{
	&OracleOfSeasonsOverworldThemeSound,
	&ExplosionSound,
	&NoFearForTheFutureSound,
	&EngineSound,
	NULL
};

const ToolState _userToolStates[] =
{
	NULL
};
