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

#include <AdjustmentScreenState.h>
#include <AutomaticPauseManager.h>
#include <AutomaticPauseSelectionScreenState.h>
#include <GameSaveDataManager.h>
#include <I18n.h>
#include <LanguageSelectionScreenState.h>
#include <PrecautionScreenState.h>
#include <ShowcaseState.h>
#include <VUEngine.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// GAME'S ENTRY POINT
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

int game(void)
{
	// Initialize plugins
	AutomaticPauseManager::setActive(AutomaticPauseManager::getInstance(NULL), GameSaveDataManager::getAutomaticPauseStatus(GameSaveDataManager::getInstance(NULL)));
	I18n::setActiveLanguage(I18n::getInstance(NULL), GameSaveDataManager::getLanguage(GameSaveDataManager::getInstance(NULL)));

	SplashScreenState::setNextState
	(
		SplashScreenState::safeCast(PrecautionScreenState::getInstance(NULL)),
		GameState::safeCast(AdjustmentScreenState::getInstance(NULL))
	);

	SplashScreenState::setNextState
	(
		SplashScreenState::safeCast(AdjustmentScreenState::getInstance(NULL)),
		GameState::safeCast(LanguageSelectionScreenState::getInstance(NULL))
	);

	SplashScreenState::setNextState
	(
		SplashScreenState::safeCast(LanguageSelectionScreenState::getInstance(NULL)),
		GameState::safeCast(AutomaticPauseSelectionScreenState::getInstance(NULL))
	);

	SplashScreenState::setNextState
	(
		SplashScreenState::safeCast(AutomaticPauseSelectionScreenState::getInstance(NULL)),
		GameState::safeCast(ShowcaseState::getFirstShowcase()())
	);

	// Start the game
	return VUEngine::start(GameState::safeCast(PrecautionScreenState::getInstance(NULL)));
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
