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

#include <ActorsState.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <Punk.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <Sounds.h>
#include <Sprite.h>
#include <SoundManager.h>

#include "PunkDie.h"


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void PunkDie::constructor()
{
	// construct base
	Base::constructor();
}
//---------------------------------------------------------------------------------------------------------
void PunkDie::destructor()
{
	// destroy base
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
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

	RumbleManager::startEffect(&KilledRumbleEffectSpec);

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
	 * the font CharSets are rewritten, otherwise, the next message will not remain on the screen
	 * or will become corrupt.
	 */
	Printing::addEventListener(Printing::getInstance(), ListenerObject::safeCast(this), (EventListener)PunkDie::onFontCharSetRewritten, kEventFontRewritten);
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringYouDiedAgain), 18, 19, NULL);
}
//---------------------------------------------------------------------------------------------------------
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

	Printing::text(Printing::getInstance(), "                        ", 18, 19, NULL);
}
//---------------------------------------------------------------------------------------------------------

//=========================================================================================================
// CLASS' PRIVATE METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void PunkDie::onFontCharSetRewritten(EventListener eventFirer __attribute__((unused)))
{
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringYouDiedAgain), 18, 19, NULL);
}
//---------------------------------------------------------------------------------------------------------
