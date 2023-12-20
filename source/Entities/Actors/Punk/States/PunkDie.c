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

#include <ActorsState.h>
#include <DebugUtilities.h>
#include <Printing.h>
#include <Punk.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <Sounds.h>
#include <Sprite.h>
#include <SoundManager.h>

#include "PunkDie.h"


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

	Punk::stopAllMovement(punk);

	/*
	 * Replace the sprites for the dying sprites
	 */
	extern SpriteSpec* PunkDyingSpriteSpecs[];
	Punk::addSprites(punk, PunkDyingSpriteSpecs, true);

	Punk::playAnimation(punk, "Die");

	RumbleManager::startEffect(&KilledRumbleEffect);

	SoundManager::playSound
	(
		SoundManager::getInstance(), 
		&KilledSoundSpec, 
		kPlayAll, 
		NULL, 
		kSoundPlaybackNormal,
		NULL, 
		NULL
	);

	/*
	 * When CharSets are deleted, defragmentation takes place. If the font CharSets are loaded after
	 * the CharSet being deleted, the printed messages can become garbled. So, we listen for when 
	 * the font CharSets are rewritten, other wise, the next message will not remain on the screen
	 * or will become corrupt.
	 */
	Printing::addEventListener(Printing::getInstance(), ListenerObject::safeCast(this), (EventListener)PunkDie::onFontCharSetRewritten, kEventFontRewritten);
	Printing::text(Printing::getInstance(), "YOU DIED... AGAIN", 18, 20, "Debug");
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
	extern SpriteSpec* PunkSpriteSpecs[];
	Punk::addSprites(punk, PunkSpriteSpecs, true);

	Printing::removeEventListener(Printing::getInstance(), ListenerObject::safeCast(this), (EventListener)PunkDie::onFontCharSetRewritten, kEventFontRewritten);

	Printing::text(Printing::getInstance(), "                  ", 18, 20, "Debug");
}

void PunkDie::onFontCharSetRewritten(EventListener eventFirer __attribute__((unused)))
{
	Printing::text(Printing::getInstance(), "YOU DIED... AGAIN", 18, 20, "Debug");
}
