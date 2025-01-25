/*
 * VUEngine Core
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <I18n.h>
#include <Languages.h>
#include <Printer.h>
#include <SoundManager.h>
#include <Sounds.h>
#include <TimerManager.h>
#include <Utilities.h>
#include <VUEngine.h>

#include "SoundsState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' ATTRIBUTES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

static const SoundROMSpec* _soundSamples[] =
{
	&OracleOfSeasonsOverworldThemeSoundSpec,
	&NoFearForTheFutureSoundSpec,
	&Explosion1SoundSpec,
	&Engine1SoundSpec,
	NULL
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool SoundsState::onEvent(ListenerObject eventFirer __attribute__((unused)), uint16 eventCode)
{
	switch(eventCode)
	{
		case kEventVUEngineNextSecondStarted:
		{
			if(!isDeleted(this->sound))
			{
				if(this->showAdditionalDetails)
				{
					TimerManager::printInterruptStats(1, 18);
				}
			}

			return true;
		}

		case kEventSoundFinished:
		{
			SoundsState::showSoundMetadata(this);

			return true;
		}
	}

	return Base::onEvent(this, eventFirer, eventCode);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::enter(void* owner __attribute__ ((unused)))
{
	Base::enter(this, owner);

	this->stream = false;
	this->updatePhysics = false;
	this->processCollisions = false;

	// PCM playback hits hard on the CPU, let's make it easier on the poor VB
	SoundsState::changeFramerate(this, 25, -1);

	// We want to know when FRAMESTART happens to tell the TimeManager to print is status
	VUEngine::addEventListener(VUEngine::getInstance(), ListenerObject::safeCast(this), kEventVUEngineNextSecondStarted);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::execute(void* owner __attribute__ ((unused)))
{
	Base::execute(this, owner);
	
	SoundsState::showSoundPlayback(this, !this->showAdditionalDetails);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::exit(void* owner __attribute__ ((unused)))
{
	VUEngine::removeEventListener(VUEngine::getInstance(), ListenerObject::safeCast(this), kEventVUEngineNextSecondStarted);

	SoundsState::releaseSound(this);

	Base::exit(this, owner);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool SoundsState::stream()
{
	return false;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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

	// Must release the sound before playig the UI's sound effects because of the PCM sound track
	SoundsState::releaseSound(this);

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
				Sound::setSpeed(this->sound, Sound::getSpeed(this->sound) -  __F_TO_FIX7_9(0.01f));
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

				TimerManager::setResolution(timerResolution);
				timerChanged = true;
			}
			else if(K_RD & userInput->releasedKey)
			{
				uint16 targetTimePerInterrupttUnits = TimerManager::getTargetTimePerInterruptUnits(TimerManager::getInstance());
				uint16 targetTimePerInterrupt = TimerManager::getTargetTimePerInterrupt();

				switch(targetTimePerInterrupttUnits)
				{
					case kUS:

						targetTimePerInterrupttUnits = kMS;
						targetTimePerInterrupt = 1;
						break;

					case kMS:

						targetTimePerInterrupttUnits = kUS;
						targetTimePerInterrupt = 1000;
						break;

					default:

						ASSERT(false, "SoundsState::processUserInput: wrong timer resolution scale");
						break;
				}

				TimerManager::setTargetTimePerInterruptUnits(targetTimePerInterrupttUnits);
				TimerManager::setTargetTimePerInterrupt(targetTimePerInterrupt);
				timerChanged = true;
			}
			else if(K_RL & userInput->releasedKey)
			{
				uint16 targetTimePerInterrupt = TimerManager::getTargetTimePerInterrupt(TimerManager::getInstance());

				targetTimePerInterrupt -= TimerManager::getMinimumTimePerInterruptStep(TimerManager::getInstance());

				TimerManager::setTargetTimePerInterrupt(targetTimePerInterrupt);
				timerChanged = true;
			}
			else if(K_RR & userInput->releasedKey)
			{
				uint16 targetTimePerInterrupt = TimerManager::getTargetTimePerInterrupt(TimerManager::getInstance());

				targetTimePerInterrupt += TimerManager::getMinimumTimePerInterruptStep(TimerManager::getInstance());

				TimerManager::setTargetTimePerInterrupt(targetTimePerInterrupt);
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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::showControls()
{
	if(this->showAdditionalDetails)
	{
		Printer::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printer::text(__CHAR_R_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_R_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_R_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 6, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_R_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printer::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 10, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 11, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

		Printer::text(__CHAR_B_BUTTON, __SCREEN_WIDTH_IN_CHARS - 13, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 14, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	}
	else
	{
		Printer::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_B_BUTTON, __SCREEN_WIDTH_IN_CHARS - 7, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
		Printer::text(__CHAR_A_BUTTON, __SCREEN_WIDTH_IN_CHARS - 8, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::showStuff()
{
	SoundsState::loadSound(this, true);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::showExplanation()
{
	int16 y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printer::text(I18n::getText(I18n::getInstance(), kStringSoundPlaybackLabel), 2, y++, NULL);
	Printer::text(I18n::getText(I18n::getInstance(), kStringTimerSettingsLabel), 2, y++, NULL);
	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printer::text("SoundManager", 2, y++, NULL);
	Printer::text("Sound", 2, y++, NULL);

	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "DefaultBold");
	Printer::text("EngineSound", 2, y++, NULL);
	Printer::text("ExplosionSound", 2, y++, NULL);
	Printer::text("NoFearForTheFutureSound", 2, y++, NULL);
	Printer::text("OracleOfSeasonsOverworld", 2, y++, NULL);

	y++;
	y++;
	Printer::text("Sound", 2, y++, NULL);
	SoundsState::showSoundMetadata(this);

	y = 3;
	Printer::text(I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printer::text("Chiptunes", 26, y++, NULL);
	Printer::text("PCM", 26, y++, NULL);
	y++;
	Printer::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "DefaultBold");
	Printer::text("SoundsState", 26, y++, NULL);
	Printer::text("::loadSound", 26, y++, NULL);
	Printer::text("::releaseSound", 26, y++, NULL);
	y++;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::showAdditionalDetails()
{
	uint16 totalSounds = SoundsState::getTotalSounds(this);

	int32 selectedSoundDigits = Math::getDigitsCount(this->selectedSound + 1);
	int32 totalSoundsDigits = Math::getDigitsCount(totalSounds);
	Printer::int32(this->selectedSound + 1, 1 + 1, 2, NULL);
	Printer::text("/" , 1 + 1 + selectedSoundDigits, 2, NULL);
	Printer::int32(SoundsState::getTotalSounds(this), 1 + 1 + selectedSoundDigits + 1, 2, NULL);
	Printer::text(__CHAR_SELECTOR, 1 + 1 + selectedSoundDigits + 1 + totalSoundsDigits, 2, NULL);

	SoundsState::showSoundMetadata(this);

	SoundsState::printTimer(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::constructor()
{
	// Always explicitly call the base's constructor 
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

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::destructor()
{
	SoundsState::releaseSound(this);

	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

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
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

uint16 SoundsState::getTotalSounds()
{
	uint16 totalSounds = 0;

	for(; _soundSamples[totalSounds]; totalSounds++);

	return totalSounds;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::loadSound(bool resetTimerSettings)
{
	if(NULL == _soundSamples[this->selectedSound])
	{
		return;
	}

	KeypadManager::disable();

	SoundsState::releaseSound(this);

	/*
	 * Since PCM playback is too heavy on the CPU, it makes sense to set it per stage.
	 * So, we set globally the target playback framerate (Hz) before creating any sound. 
.	 */
	SoundManager::setPCMTargetPlaybackRefreshRate(SoundManager::getInstance(), this->stageSpec->sound.pcmTargetPlaybackRefreshRate);

	/*
	 * We configure the timer manager to match the sound's timing. This is done here as and example and shouldn't 
	 * be used during gameplay, when it makes no sense to modify on the fly the timer interrupts' targets. 
 	 */
	if(resetTimerSettings)
	{
		SoundsState::setTimerSettings(this);
	}

	/*
	 * We ask for a Sound to the SoundManager and specify a callback for when the Sound is released, which happens
	 * automatically with any sound that doesn't play in loop or when not explicitly told to not auto release by 
	 * calling Sound::autoReleaseOnFinish.
	 */
	this->sound = SoundManager::getSound((SoundSpec*)_soundSamples[this->selectedSound], ListenerObject::safeCast(this));

	NM_ASSERT(!isDeleted(this->sound), "SoundsState::loadSound: no sound");

	if(!isDeleted(this->sound))
	{
		// Listen for when the plaback finishes to update the UI. 
		Sound::addEventListener(this->sound, ListenerObject::safeCast(this), kEventSoundFinished);
		SoundsState::applyTimerSettings(this);
	}

	KeypadManager::enable();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::releaseSound()
{
	if(!isDeleted(this->sound))
	{
		Sound::release(this->sound);

		this->sound = NULL;
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool SoundsState::onSoundReleased(ListenerObject eventFirer __attribute__((unused)))
{
	if(Sound::safeCast(eventFirer) == this->sound)
	{
		this->sound = NULL;
		SoundsState::loadSound(this, true);
	}

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::showSoundMetadata()
{
	if(isDeleted(this->sound))
	{
		return;
	}

	if(this->showAdditionalDetails)		
	{
		Sound::print(this->sound, 1, 4);
	}
	else
	{
		Sound::print(this->sound, 3, 21);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::printTimer()
{
	if(NULL == _soundSamples[this->selectedSound])
	{
		return;
	}

	TimerManager::print(1, 11);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::setTimerSettings()
{
	TimerManager::setResolution(__TIMER_20US);
	TimerManager::setTargetTimePerInterruptUnits(kUS);
	TimerManager::setTargetTimePerInterrupt(_soundSamples[this->selectedSound]->targetTimerResolutionUS);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void SoundsState::applyTimerSettings()
{
	TimerManager::applySettings(true);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

bool SoundsState::onNextSecondStarted(ListenerObject eventFirer __attribute__((unused)))
{
	if(!isDeleted(this->sound))
	{
		if(this->showAdditionalDetails)
		{
			TimerManager::printInterruptStats(1, 18);
		}
	}

	return true;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
