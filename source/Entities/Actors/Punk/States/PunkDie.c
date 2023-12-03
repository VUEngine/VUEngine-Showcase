/**
 * Virtual WarZone
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <PunkDie.h>

#include <ActorsState.h>
#include <GameConfig.h>
#include <Punk.h>
#include <Sprite.h>

#include <debugUtilities.h>


//---------------------------------------------------------------------------------------------------------
//												PROTOTYPES
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
//												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

// class's constructor
void PunkDie::constructor()
{
	// construct base
	Base::constructor();
}

// class's destructor
void PunkDie::destructor()
{
	// destroy base
	Base::destructor();
}

// state's enter
void PunkDie::enter(void* owner)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return;
	}

	extern SpriteSpec* const PunkDyingSprites[];

	Punk::addSprites(punk, PunkDyingSprites, true);

	Punk::stopAllMovement(punk);

	Punk::playAnimation(punk, "Die");
}
