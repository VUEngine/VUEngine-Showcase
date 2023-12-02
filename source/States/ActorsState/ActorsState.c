/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ActorsState.h>

#include <AnimatedEntity.h>
#include <Printing.h>
#include <VirtualList.h>

#include <debugUtilities.h>
#include <string.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

/*
 * Check assets/stage/ActorsStageSpec.c"
 */
extern StageROMSpec ActorsStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void ActorsState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&ActorsStage;
}

// class's destructor
void ActorsState::destructor()
{
	// destroy base
	Base::destructor();
}

void ActorsState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);

	// Start animations, physics and messaging clocks
	ActorsState::startClocks(this);
}

void ActorsState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(this->showAdditionalDetails)
	{
		ActorsState::showAdditionalDetails(this);
	}
}

void ActorsState::processUserInput(const UserInput* userInput)
{
	if(K_LL & userInput->holdKey)
	{
		ShowcaseState::propagateMessage(this, kActorsStateHoldLeft);
	}
	else if(K_LL & userInput->releasedKey)
	{
		ShowcaseState::propagateMessage(this, kActorsStateReleasedLeft);
	}
	else if(K_LR & userInput->holdKey)
	{
		ShowcaseState::propagateMessage(this, kActorsStateHoldRight);
	}
	else if(K_LR & userInput->releasedKey)
	{
		ShowcaseState::propagateMessage(this, kActorsStateReleasedRight);
	}
	
	return Base::processUserInput(this, userInput);
}

void ActorsState::showControls()
{
	Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

void ActorsState::showStuff()
{
}

void ActorsState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), "CONCEPTS", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Actors", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Physics", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "State machines", 2, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "CLASSES", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Actor", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Punk", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "PunkState*", 2, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), "SPECS", 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Punk", 2, y++, NULL);

	y = 3;
	Printing::text(Printing::getInstance(), "OTHER CONCEPTS", 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "Collisions", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "Events", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "Messaging", 26, y++, NULL);
	y++;
	Printing::text(Printing::getInstance(), "METHODS", 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "ActorsState", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " propagateMessage", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "Punk", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " enterCollision", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " handlePropagatedMessage", 26, y++, NULL);
	y++;
}

void ActorsState::showAdditionalDetails()
{
	ShowcaseState::propagateMessage(this, kActorsStatePrintActorStatus);
}


