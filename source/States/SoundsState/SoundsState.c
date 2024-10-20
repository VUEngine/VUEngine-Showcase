/**
 * VUEngine Core
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <SoundManager.h>
#include <Sounds.h>
#include <TimerManager.h>
#include <Utilities.h>
#include <VUEngine.h>

#include "SoundsState.h"


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

const SoundROMSpec* soundSamples[] =
{
	&OracleOfSeasonsOverworldThemeSoundSpec,
	&NoFearForTheFutureSoundSpec,
	&ExplosionSoundSpec,
	&EngineSoundSpec,
	NULL
};

//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

/**
 * Get instance
 *
 * @fn			SoundsState::getInstance()
 * @memberof	SoundsState
 * @public
 * @return		SoundsState instance
 */


/**
 * Class constructor
 *
 * @private
 */
void SoundsState::constructor()
{
	Base::constructor();

	/*
	 * Check assets/stage/SoundsStageSpec.c
	 */
	extern StageROMSpec SoundsStageSpec;
	this->stageSpec = (StageSpec*)&SoundsStageSpec;
	this->sound = NULL;
	this->selectedSound = 0;
	this->validSuboptionKeys = K_LL | K_LR;
}

/**
 * Class destructor
 *
 * @private
 */
void SoundsState::destructor()
{
	SoundsState::releaseSound(this);

	// destroy base
	Base::destructor();
}

/**
 * Method called when the Game's StateMachine enters to this state
 *
 * @param owner		StateMachine's owner
 */
void SoundsState::enter(void* owner __attribute__ ((unused)))
{
	Base::enter(this, owner);

	this->stream = false;
	this->updatePhysics = false;
	this->processCollisions = false;

	/*
	 * We want to know when FRAMESTART happens to tell the TimeManager to print is status
	 */
	VUEngine::addEventListener(VUEngine::getInstance(), ListenerObject::safeCast(this), (EventListener)SoundsState::onNextSecondStarted, kEventVUEngineNextSecondStarted);
}

bool SoundsState::onNextSecondStarted(ListenerObject eventFirer __attribute__((unused)))
{
	if(!isDeleted(this->sound) && Sound::hasPCMTracks(this->sound))
	{
		if(this->showAdditionalDetails)
		{
			TimerManager::printStatus(TimerManager::getInstance(), 1, 18);
			TimerManager::nextSecondStarted(TimerManager::getInstance());
		}
	}

	return true;
}

bool SoundsState::stream()
{
	return false;
}

/**
 * Method called when by the StateMachine's update method
 *
 * @param owner		StateMachine's owner
 */
void SoundsState::execute(void* owner __attribute__ ((unused)))
{
	Base::execute(this, owner);
	
	SoundsState::showSoundPlayback(this, !this->showAdditionalDetails);
}

/**
 * Method called when the Game's StateMachine exits from this state
 *
 * @param owner		StateMachine's owner
 */
void SoundsState::exit(void* owner __attribute__ ((unused)))
{
	VUEngine::removeEventListener(VUEngine::getInstance(), ListenerObject::safeCast(this), (EventListener)SoundsState::onNextSecondStarted, kEventVUEngineNextSecondStarted);

	SoundsState::releaseSound(this);

	Base::exit(this, owner);
}

/**
 * Process user input
 *
 * @param userInput		User input
 */
void SoundsState::processUserInput(const UserInput* userInput)
{
	if(!isDeleted(this->sound))
	{
		if(K_A & userInput->releasedKey)
		{
			if(!Sound::isPlaying(this->sound))
			{
				Sound::play(this->sound, NULL, kSoundPlaybackNormal);
			}
			else
			{
				Sound::pause(this->sound);
			}

			SoundsState::showSoundMetadata(this);

			return;
		}
		else if(K_B & userInput->releasedKey)
		{
			Sound::rewind(this->sound);
			SoundsState::showSoundMetadata(this);

			return;
		}
	}	

	if(!isDeleted(this->sound))
	{
		Sound::pause(this->sound);
	}

	SoundsState::playSoundEffects(this, userInput, true);

	Base::processUserInput(this, userInput);

	bool timerChanged = false;

	if(K_SEL & userInput->releasedKey)
	{
		SoundsState::loadSound(this, true);
		SoundsState::showSoundMetadata(this);

		timerChanged = true;
	}
	
	if(K_LL & userInput->releasedKey)
	{
		uint16 totalSounds = SoundsState::getTotalSounds(this);

		if(0 == this->selectedSound)
		{
			this->selectedSound = totalSounds - 1;
		}
		else
		{
			this->selectedSound--;
		}

		SoundsState::show(this, true);
	}
	else if(K_LR & userInput->releasedKey)
	{
		uint16 totalSounds = SoundsState::getTotalSounds(this);

		if(totalSounds - 1 == this->selectedSound)
		{
			this->selectedSound = 0;
		}
		else
		{
			this->selectedSound++;
		}

		SoundsState::show(this, true);

	}
	
	if(this->showAdditionalDetails)
	{
		if(!isDeleted(this->sound))
		{
			if(K_LD & userInput->releasedKey)
			{
				Sound::pause(this->sound);
				Sound::rewind(this->sound);
				Sound::setSpeed(this->sound, Sound::getSpeed(this->sound) +  __F_TO_FIX7_9(0.01f));
				SoundsState::showSoundMetadata(this);
			}
			else if(K_LU & userInput->releasedKey)
			{
				Sound::pause(this->sound);
				Sound::rewind(this->sound);
				Sound::setSpeed(this->sound, Sound::getSpeed(this->sound) +  __F_TO_FIX7_9(0.01f));
				SoundsState::showSoundMetadata(this);
			}
			// Timer controls
			else if(K_RU & userInput->releasedKey)
			{
				uint16 timerResolution = TimerManager::getResolution(TimerManager::getInstance());

				switch(timerResolution)
				{
					case __TIMER_20US:

						timerResolution = __TIMER_100US;
						break;

					case __TIMER_100US:

						timerResolution = __TIMER_20US;
						break;

					default:

						ASSERT(false, "SoundsState::processUserInput: wrong timer frequency");
						break;
				}

				TimerManager::setResolution(TimerManager::getInstance(), timerResolution);
				timerChanged = true;
			}
			else if(K_RD & userInput->releasedKey)
			{
				uint16 timePerInterruptUnits = TimerManager::getTimePerInterruptUnits(TimerManager::getInstance());
				uint16 timePerInterrupt = TimerManager::getTimePerInterrupt(TimerManager::getInstance());

				switch(timePerInterruptUnits)
				{
					case kUS:

						timePerInterruptUnits = kMS;
						timePerInterrupt = 1;
						break;

					case kMS:

						timePerInterruptUnits = kUS;
						timePerInterrupt = 1000;
						break;

					default:

						ASSERT(false, "SoundsState::processUserInput: wrong timer resolution scale");
						break;
				}

				TimerManager::setTimePerInterruptUnits(TimerManager::getInstance(), timePerInterruptUnits);
				TimerManager::setTimePerInterrupt(TimerManager::getInstance(), timePerInterrupt);
				timerChanged = true;
			}
			else if(K_RL & userInput->releasedKey)
			{
				uint16 timePerInterrupt = TimerManager::getTimePerInterrupt(TimerManager::getInstance());

				timePerInterrupt -= TimerManager::getMinimumTimePerInterruptStep(TimerManager::getInstance());

				TimerManager::setTimePerInterrupt(TimerManager::getInstance(), timePerInterrupt);
				timerChanged = true;
			}
			else if(K_RR & userInput->releasedKey)
			{
				uint16 timePerInterrupt = TimerManager::getTimePerInterrupt(TimerManager::getInstance());

				timePerInterrupt += TimerManager::getMinimumTimePerInterruptStep(TimerManager::getInstance());

				TimerManager::setTimePerInterrupt(TimerManager::getInstance(), timePerInterrupt);
				timerChanged = true;
			}

			if(timerChanged)
			{
				SoundsState::applyTimerSettings(this);
				SoundsState::printTimer(this);
				SoundsState::loadSound(this, false);
				SoundsState::showSoundMetadata(this);
			}
		}
	}		
}


/**
 * Release sound
 */
void SoundsState::releaseSound()
{
	if(!isDeleted(this->sound))
	{
		
		Sound::removeEventListenerScopes(this->sound, ListenerObject::safeCast(this), kEventSoundReleased);
		Sound::release(this->sound);

		this->sound = NULL;
	}
}

void SoundsState::showStuff()
{
	SoundsState::loadSound(this, true);
}

void SoundsState::showExplanation()
{
	int16 y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSoundPlaybackLabel), 2, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringTimerSettingsLabel), 2, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, "SoundManager", 2, y++, NULL);
	Printing::text(this->printing, "Sound", 2, y++, NULL);

	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "Debug");
	Printing::text(this->printing, " EngineSound", 2, y++, NULL);
	Printing::text(this->printing, " ExplosionSound", 2, y++, NULL);
	Printing::text(this->printing, " NoFearForTheFutureSound", 2, y++, NULL);
	Printing::text(this->printing, " OracleOfSeasonsOverw...", 2, y++, NULL);

	y++;
	y++;
	Printing::text(this->printing, "Sound", 2, y++, NULL);
	SoundsState::showSoundMetadata(this);

	y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "Debug");
	Printing::text(this->printing, "Chiptunes", 26, y++, NULL);
	Printing::text(this->printing, "PCM", 26, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "Debug");
	Printing::text(this->printing, "SoundsState", 26, y++, NULL);
	Printing::text(this->printing, " loadSound", 26, y++, NULL);
	Printing::text(this->printing, " releaseSound", 26, y++, NULL);
	y++;
}

void SoundsState::showControls()
{
	if(this->showAdditionalDetails)
	{
		Printing::text(this->printing, __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printing::text(this->printing, __CHAR_R_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_R_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_R_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_R_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printing::text(this->printing, __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 10, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 11, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printing::text(this->printing, __CHAR_B_BUTTON, __SCREEN_WIDTH_IN_CHARS - 13, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 14, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	}
	else
	{
		Printing::text(this->printing, __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_B_BUTTON, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(this->printing, __CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 8, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	}
}

void SoundsState::showAdditionalDetails()
{
	Printing printing = this->printing;

	uint16 totalSounds = SoundsState::getTotalSounds(this);

	int32 selectedSoundDigits = Math::getDigitsCount(this->selectedSound + 1);
	int32 totalSoundsDigits = Math::getDigitsCount(totalSounds);
	Printing::int32(printing, this->selectedSound + 1, 1 + 1, 2, NULL);
	Printing::text(printing, "/" , 1 + 1 + selectedSoundDigits, 2, NULL);
	Printing::int32(printing, SoundsState::getTotalSounds(this), 1 + 1 + selectedSoundDigits + 1, 2, NULL);
	Printing::text(printing, __CHAR_SELECTOR, 1 + 1 + selectedSoundDigits + 1 + totalSoundsDigits, 2, NULL);

	SoundsState::showSoundMetadata(this);

	SoundsState::printTimer(this);
}

void SoundsState::showSoundPlayback(bool showOnlyTime)
{
	if(!isDeleted(this->sound))
	{
		if(showOnlyTime)
		{
			Sound::printPlaybackProgress(this->sound, 3, 23);
			Sound::printPlaybackTime(this->sound, 26, 25);
		}
		else
		{
			static bool printVolume = false;
			printVolume = !printVolume;

			if(!printVolume)
			{
				Sound::printPlaybackProgress(this->sound, 1, 6);
				Sound::printPlaybackTime(this->sound, 24, 8);
			}
			else if(!showOnlyTime)
			{
				if(!Sound::hasPCMTracks(this->sound))
				{
					Sound::printVolume(this->sound, 1, 17, false);
				}
			}
		}
	}
}

uint16 SoundsState::getTotalSounds()
{
	uint16 totalSounds = 0;

	for(; soundSamples[totalSounds]; totalSounds++);

	return totalSounds;
}

void SoundsState::loadSound(bool resetTimerSettings)
{
	if(NULL == soundSamples[this->selectedSound])
	{
		return;
	}

	VUEngine::disableKeypad(VUEngine::getInstance());

	SoundsState::releaseSound(this);

	/*
	 * Since PCM playback is too heavy on the CPU, it makes sense to set it per stage.
	 * So, we set globally the target playback framerate (Hz) before creating any sound. 
.	 */
	SoundManager::setTargetPlaybackFrameRate(SoundManager::getInstance(), this->stageSpec->sound.pcmTargetPlaybackFrameRate);

	/*
	 * We configure the timer manager to match the sound's timing. This is done here as 
	 * and example and shouldn't be used during gameplay, when it makes no sense to 
	 * modify on the fly the timer interrupts' targets. 
 	 */
	if(resetTimerSettings)
	{
		SoundsState::setTimerSettings(this);
	}

	/*
	 * We ask for a Sound to the SoundManager and specify a callback for when the 
	 * Sound is released, which happens automatically with any sound that doesn't
	 * play in loop or when not explicitly told to not auto release by calling
	 * Sound::autoReleaseOnFinish.
	 */
	this->sound = SoundManager::getSound(SoundManager::getInstance(), (SoundSpec*)soundSamples[this->selectedSound], kPlayAll, (EventListener)SoundsState::onSoundReleased, ListenerObject::safeCast(this));

	NM_ASSERT(!isDeleted(this->sound), "SoundsState::loadSound: no sound");

	if(!isDeleted(this->sound))
	{
		/*
		 * Listen for when the plaback finishes to update the UI. 
		 */
		Sound::addEventListener(this->sound, ListenerObject::safeCast(this), (EventListener)SoundsState::onSoundPlaybackFinish, kEventSoundFinished);
		Sound::computeTimerResolutionFactor(this->sound);
		SoundsState::applyTimerSettings(this);
	}

	VUEngine::enableKeypad(VUEngine::getInstance());
}

bool SoundsState::onSoundPlaybackFinish(ListenerObject eventFirer __attribute__((unused)))
{
	SoundsState::showSoundMetadata(this);

	return true;
}

bool SoundsState::onSoundReleased(ListenerObject eventFirer __attribute__((unused)))
{
	if(Sound::safeCast(eventFirer) == this->sound)
	{
		this->sound = NULL;
		SoundsState::loadSound(this, true);
	}

	return true;
}

void SoundsState::showSoundMetadata()
{
	if(isDeleted(this->sound))
	{
		return;
	}

	if(this->showAdditionalDetails)		
	{
		Sound::printMetadata(this->sound, 1, 4, true);
	}
	else
	{
		Sound::printMetadata(this->sound, 3, 21, false);
	}
}

void SoundsState::printTimer()
{
	if(NULL == soundSamples[this->selectedSound])
	{
		return;
	}

	TimerManager::print(TimerManager::getInstance(), 1, 11);
}

void SoundsState::setTimerSettings()
{
	TimerManager::setResolution(TimerManager::getInstance(), __TIMER_20US);
	TimerManager::setTimePerInterruptUnits(TimerManager::getInstance(), kUS);
	TimerManager::setTimePerInterrupt(TimerManager::getInstance(), soundSamples[this->selectedSound]->targetTimerResolutionUS);
}

void SoundsState::applyTimerSettings()
{
	TimerManager::enable(TimerManager::getInstance(), false);
	TimerManager::initialize(TimerManager::getInstance());
	TimerManager::enable(TimerManager::getInstance(), true);
}
