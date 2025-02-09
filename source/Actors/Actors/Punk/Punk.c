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

#include <Body.h>
#include <CollisionsState.h>
#include <I18n.h>
#include <InGameTypes.h>
#include <Languages.h>
#include <MessageDispatcher.h>
#include <Messages.h>
#include <PunkDeath.h>
#include <PunkFrozen.h>
#include <PunkStopping.h>
#include <PunkWalking.h>
#include <RumbleEffects.h>
#include <RumbleManager.h>
#include <ShowcaseState.h>
#include <Sounds.h>
#include <StateMachine.h>
#include <Telegram.h>

#include "Punk.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::constructor(const PunkSpec* punkSpec, int16 internalId, const char* const name)
{
	// Always explicitly call the base's constructor
	Base::constructor((ActorSpec*)&punkSpec->actorSpec, internalId, name);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::destructor()
{
	// Always explicitly call the base's destructor
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool Punk::onEvent(ListenerObject eventFirer __attribute__((unused)), uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventAnimationCompleted:
		{
			if(Punk::isPlayingAnimation(this, "Die"))
			{
				/*
				 * Restore myself after 1 second
				 */
				Punk::sendMessageToSelf(this, kMessageCollisionsStateResuscitate, 1000, 0);

				return false;
			}

			break;
		}

		case kEventFontRewritten:
		{
			Printer::text(I18n::getText(I18n::getInstance(), kStringYouDiedAgain), 18, 19, NULL);

			break;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * Returning true stops the propagation
 */
bool Punk::handlePropagatedMessage(int32 message)
{
	switch(message)
	{
		case kMessageCollisionsStateHoldLeft:
		case kMessageCollisionsStateHoldRight:
		case kMessageCollisionsStateReleasedLeft:
		case kMessageCollisionsStateReleasedRight:

			/*
			 * My state machine will process this Telegram. This is not very performant, but it is certainly,
			 * more elegant than calling directly a specific method in the current state, and this showcases
			 * how to send messages to the current state in the state machine
			 */
			Punk::sendMessageToSelf(this, message, 0, 0);
			return true;
			break;

		case kMessageCollisionsStatePrintActorStatus:

			if(!isDeleted(this->body))
			{
				Body::print(this->body, 1, 3);
			}
			return true;
			break;
	}

	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * This method is called when the actor has been fully initialized
 */
void Punk::ready(bool recursive)
{
	Base::ready(this, recursive);

	Punk::freeze(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::freeze()
{
	Punk::stopAnimation(this);
	Punk::setActualFrame(this, 0);

	Punk::mutateTo(this, PunkFrozen::getClass());
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::walk()
{
	Punk::playAnimation(this, "Move");

	/*
	 * Disable collision checks so this doesn't fire multiple times.
	 * They are enabled by the Actor when starting to move.
	 */
	PunkWalking::checkCollisions(this, true);

	Punk::mutateTo(this, PunkWalking::getClass());
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::stop()
{
	Punk::mutateTo(this, PunkStopping::getClass());
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::die()
{
	Punk::stopAllMovement(this);

	/*
	 * Replace the sprites for the dying sprites
	 */
	extern SpriteSpec* PunkDyingComponentSpecs[];
	Punk::removeComponents(this, kSpriteComponent);
	Punk::addComponents(this, (ComponentSpec**)PunkDyingComponentSpecs, kSpriteComponent);

	Punk::playAnimation(this, "Die");

	RumbleManager::startEffect(&KilledRumbleEffectSpec);

	SoundManager::playSound(&Killed1SoundSpec, NULL, kSoundPlaybackNormal, NULL);

	/*
	 * When CharSets are deleted, defragmentation takes place. If the font CharSets are loaded after
	 * the CharSet being deleted, the printed messages can become garbled. So, we listen for when
	 * the font CharSets are rewritten, otherwise, the next message will not remain on the screen
	 * or will become corrupt.
	 */
	Printer::addEventListener(Printer::getInstance(), ListenerObject::safeCast(this), kEventFontRewritten);
	Printer::text(I18n::getText(I18n::getInstance(), kStringYouDiedAgain), 18, 19, NULL);

	Punk::mutateTo(this, PunkDeath::getClass());
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void Punk::resuscitate()
{
	/*
	 * Restore the normal sprites
	 */
	extern ComponentSpec* PunkControllableComponentSpecs[];
	Punk::removeComponents(this, kSpriteComponent);
	Punk::addComponents(this, (ComponentSpec**)PunkControllableComponentSpecs, kSpriteComponent);

	Printer::removeEventListener(Printer::getInstance(), ListenerObject::safeCast(this), kEventFontRewritten);

	Printer::text("                        ", 18, 19, NULL);

	Vector3D position = Vector3D::getFromPixelVector((PixelVector){0, 64, 0, 0});
	Punk::setLocalPosition(this, &position);

	Rotation rotation = Rotation::zero();
	Punk::setLocalRotation(this, &rotation);

	Punk::freeze(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
