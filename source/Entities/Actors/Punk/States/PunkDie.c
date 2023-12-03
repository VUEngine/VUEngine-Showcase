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

	/*
	 * Disable collision checks. They are enabled by the Actor when
	 * starting to move.
	 */
	Punk::activeCollisionChecks(punk, false);
	Punk::stopAllMovement(punk);

	/*
	 * Replace the sprites for the dying sprites
	 */
	extern SpriteSpec* const PunkDyingSprites[];
	Punk::addSprites(punk, PunkDyingSprites, true);

	Punk::playAnimation(punk, "Die");

//	Printing::text(Printing::getInstance(), "YOU REDIED", 18, 20, "Debug");
}

void PunkDie::exit(void* owner)
{
	Punk punk = Punk::safeCast(owner);

	if(isDeleted(punk))
	{
		return;
	}

	/*
	 * Restore the normal sprites
	 */
	extern SpriteSpec* const PunkSprites[];
	Punk::addSprites(punk, PunkSprites, true);

//	Printing::text(Printing::getInstance(), "          ", 18, 27, "Debug");
}