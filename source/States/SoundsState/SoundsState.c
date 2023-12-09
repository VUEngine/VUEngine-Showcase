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

#include <SoundsState.h>

#include <Printing.h>
#include <SoundManager.h>
#include <TimerManager.h>
#include <Utilities.h>
#include <VUEngine.h>



#include <debugUtilities.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec SoundsStage;

extern Sound NoFearForTheFutureSound;
extern Sound OracleOfSeasonsOverworldThemeSound;
extern Sound EngineSound;
extern Sound ExplosionSound;


const SoundROM* soundSamples[] =
{
	&OracleOfSeasonsOverworldThemeSound,
	&NoFearForTheFutureSound,
	&ExplosionSound,
	&EngineSound,
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

	this->stageSpec = (StageSpec*)&SoundsStage;
	this->soundWrapper = NULL;
	this->selectedSound = 0;
}

/**
 * Class destructor
 *
 * @private
 */
void SoundsState::destructor()
{
	SoundsState::releaseSoundWrapper(this);

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
	this->transform = false;
	this->synchronizeGraphics = false;
	this->updatePhysics = false;
	this->processCollisions = false;

	/*
	 * We want to know when FRAMESTART happens to tell the TimeManager to print is status
	 */
	VUEngine::addEventListener(VUEngine::getInstance(), ListenerObject::safeCast(this), (EventListener)SoundsState::onNextSecondStarted, kEventVUEngineNextSecondStarted);
}

void SoundsState::onNextSecondStarted(ListenerObject eventFirer __attribute__((unused)))
{
	if(!isDeleted(this->soundWrapper) && SoundWrapper::hasPCMTracks(this->soundWrapper))
	{
		if(this->showAdditionalDetails)
		{
			TimerManager::printStatus(TimerManager::getInstance(), 1, 19);
			TimerManager::nextSecondStarted(TimerManager::getInstance());
		}
	}
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

	SoundsState::releaseSoundWrapper(this);

	Base::exit(this, owner);
}

/**
 * Process user input
 *
 * @param userInput		User input
 */
void SoundsState::processUserInput(const UserInput* userInput)
{
	Base::processUserInput(this, userInput);

	if(!(K_PWR & userInput->releasedKey))
	{
		if(K_SEL & userInput->releasedKey)
		{
			SoundsState::loadSound(this);
			return;
		}

		bool timerChanged = false;
		
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
			
			return;
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

			return;
		}
		else if(K_A & userInput->releasedKey)
		{
			if(!isDeleted(this->soundWrapper))
			{
				if(!SoundWrapper::isTurnedOn(this->soundWrapper) || SoundWrapper::isPaused(this->soundWrapper))
				{
					SoundWrapper::play(this->soundWrapper, NULL, kSoundWrapperPlaybackNormal);
				}
				else
				{
					SoundWrapper::pause(this->soundWrapper);
				}

				if(this->showAdditionalDetails)		
				{
					SoundWrapper::printMetadata(this->soundWrapper, 1, 4, true);
				}
				else
				{
					SoundWrapper::printMetadata(this->soundWrapper, 3, 21, false);
				}
			}
		}
		else if(K_B & userInput->releasedKey)
		{
			if(!isDeleted(this->soundWrapper))
			{
				SoundWrapper::rewind(this->soundWrapper);
			}
		}
		
		if(this->showAdditionalDetails)
		{			
			if(K_LD & userInput->releasedKey)
			{
				if(isDeleted(this->soundWrapper))
				{
					SoundsState::loadSound(this);
				}

				SoundWrapper::setSpeed(this->soundWrapper, SoundWrapper::getSpeed(this->soundWrapper) - __F_TO_FIX7_9(0.01f));
			}
			else if(K_LU & userInput->releasedKey)
			{
				if(isDeleted(this->soundWrapper))
				{
					SoundsState::loadSound(this);
				}

				SoundWrapper::setSpeed(this->soundWrapper, SoundWrapper::getSpeed(this->soundWrapper) +  __F_TO_FIX7_9(0.01f));
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
						timePerInterrupt = 10;
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

				if(!isDeleted(this->soundWrapper))
				{
					SoundWrapper::pause(this->soundWrapper);
					SoundWrapper::rewind(this->soundWrapper);
					SoundWrapper::computeTimerResolutionFactor(this->soundWrapper);

					if(!SoundWrapper::isPaused(this->soundWrapper))
					{
						SoundWrapper::play(this->soundWrapper, NULL, kSoundWrapperPlaybackFadeIn);
					}
				}
			}
		}		
	}
}

/**
 * Transform
 *
 */
void SoundsState::transform()
{
}

/**
 * Sync graphics
 *
 */
void SoundsState::synchronizeGraphics()
{
}

/**
 * Release sound
 */
void SoundsState::releaseSoundWrapper()
{
	if(!isDeleted(this->soundWrapper))
	{
		
		SoundWrapper::removeEventListenerScopes(this->soundWrapper, ListenerObject::safeCast(this), kEventSoundReleased);
		SoundWrapper::release(this->soundWrapper);

		this->soundWrapper = NULL;
	}
}

void SoundsState::showStuff()
{
	SoundsState::loadSound(this);
}

void SoundsState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), "CONCEPTS", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Sound specs", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Sound wrappers", 2, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "CLASSES", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "SoundManager", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "SoundWrapper", 2, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), "SPECS", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), " EngineSound", 2, y++, NULL);
	Printing::text(Printing::getInstance(), " ExplosionSound", 2, y++, NULL);
	Printing::text(Printing::getInstance(), " NoFearForTheFutureSound", 2, y++, NULL);
	Printing::text(Printing::getInstance(), " OracleOfSeasonsOverw...", 2, y++, NULL);

	y++;

	if(!isDeleted(this->soundWrapper))
	{
		y++;
		Printing::text(Printing::getInstance(), "Sound", 2, y++, NULL);
		SoundWrapper::printMetadata(this->soundWrapper, 3, 21, false);
	}

	y = 3;
	Printing::text(Printing::getInstance(), "OTHER CONCEPTS", 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "Chiptunes", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "PCM", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "Plaback", 26, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "METHODS", 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "SoundsState", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " loadSound", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " releaseSoundWrapper", 26, y++, NULL);
	y++;
}

void SoundsState::showControls()
{
	if(this->showAdditionalDetails)
	{
		Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printing::text(Printing::getInstance(), __CHAR_R_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_R_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_R_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_R_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 10, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 11, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printing::text(Printing::getInstance(), __CHAR_B_BUTTON, __SCREEN_WIDTH_IN_CHARS - 13, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 14, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	}
	else
	{
		Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_B_BUTTON, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printing::text(Printing::getInstance(), __CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 8, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	}
}

void SoundsState::showAdditionalDetails()
{
	Printing printing = Printing::getInstance();

	uint16 totalSounds = SoundsState::getTotalSounds(this);

	int32 selectedSoundDigits = Utilities::getDigitsCount(this->selectedSound + 1);
	int32 totalSoundsDigits = Utilities::getDigitsCount(totalSounds);
	Printing::int32(printing, this->selectedSound + 1, 1 + 1, 2, NULL);
	Printing::text(printing, "/" , 1 + 1 + selectedSoundDigits, 2, NULL);
	Printing::int32(printing, SoundsState::getTotalSounds(this), 1 + 1 + selectedSoundDigits + 1, 2, NULL);
	Printing::text(printing, __CHAR_SELECTOR, 1 + 1 + selectedSoundDigits + 1 + totalSoundsDigits, 2, NULL);

	if(!isDeleted(this->soundWrapper))
	{
		SoundWrapper::printMetadata(this->soundWrapper, 1, 4, true);
	}

	SoundsState::printTimer(this);
}

void SoundsState::showSoundPlayback(bool showOnlyTime)
{
	if(!isDeleted(this->soundWrapper))
	{
		if(showOnlyTime)
		{
			SoundWrapper::printPlaybackProgress(this->soundWrapper, 3, 23);
			SoundWrapper::printPlaybackTime(this->soundWrapper, 26, 25);
		}
		else
		{
			static bool printVolume = false;
			printVolume = !printVolume;

			if(!printVolume)
			{
				SoundWrapper::printPlaybackProgress(this->soundWrapper, 1, 6);
				SoundWrapper::printPlaybackTime(this->soundWrapper, 24, 8);
			}
			else if(!showOnlyTime)
			{
				if(!SoundWrapper::hasPCMTracks(this->soundWrapper))
				{
					SoundWrapper::printVolume(this->soundWrapper, 1, 17, false);
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

void SoundsState::loadSound()
{
	if(NULL == soundSamples[this->selectedSound])
	{
		return;
	}

	VUEngine::disableKeypad(VUEngine::getInstance());

	SoundsState::releaseSoundWrapper(this);

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
	TimerManager::reset(TimerManager::getInstance());
	TimerManager::setResolution(TimerManager::getInstance(), __TIMER_20US);
	TimerManager::setTimePerInterruptUnits(TimerManager::getInstance(), kUS);
	TimerManager::setTimePerInterrupt(TimerManager::getInstance(), soundSamples[this->selectedSound]->targetTimerResolutionUS);

	/*
	 * We ask for a SoundWrapper to the SoundManager and specify a callback for when the 
	 * SoundWrapper is released, which happens automatically with any sound that doesn't
	 * play in loop or when not explicitly told to not auto release by calling
	 * SoundWrapper::autoReleaseOnFinish.
	 */
	this->soundWrapper = SoundManager::getSound(SoundManager::getInstance(), (Sound*)soundSamples[this->selectedSound], kPlayAll, (EventListener)SoundsState::onSoundWrapperReleased, ListenerObject::safeCast(this));

	NM_ASSERT(!isDeleted(this->soundWrapper), "SoundsState::loadSound: no sound");

	if(!isDeleted(this->soundWrapper))
	{
		/*
		 * Listen for when the plaback finishes to update the UI. 
		 */
		SoundWrapper::addEventListener(this->soundWrapper, ListenerObject::safeCast(this), (EventListener)SoundsState::onSoundPlaybackFinish, kEventSoundFinished);
		SoundWrapper::computeTimerResolutionFactor(this->soundWrapper);
		SoundsState::applyTimerSettings(this);
	}

	VUEngine::enableKeypad(VUEngine::getInstance());
}

void SoundsState::onSoundPlaybackFinish(ListenerObject eventFirer __attribute__((unused)))
{
	if(isDeleted(this->soundWrapper))
	{
		return;
	}

	if(this->showAdditionalDetails)		
	{
		SoundWrapper::printMetadata(this->soundWrapper, 1, 4, false);
	}
	else
	{
		SoundWrapper::printMetadata(this->soundWrapper, 3, 21, false);
	}
}

void SoundsState::onSoundWrapperReleased(ListenerObject eventFirer __attribute__((unused)))
{
	if(SoundWrapper::safeCast(eventFirer) == this->soundWrapper)
	{
		this->soundWrapper = NULL;
		SoundsState::loadSound(this);
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

void SoundsState::applyTimerSettings()
{
	TimerManager::enable(TimerManager::getInstance(), false);
	TimerManager::initialize(TimerManager::getInstance());
	TimerManager::enable(TimerManager::getInstance(), true);
}
