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


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec SoundsStage;


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
	this->soundTest = SoundTest::getInstance();
}

/**
 * Class destructor
 *
 * @private
 */
void SoundsState::destructor()
{
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
}

void SoundsState::showStuff()
{
	if(!isDeleted(this->soundTest))
	{
		SoundTest::show(this->soundTest);
	}

	SoundsState::showHeader(this);
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
	if(!isDeleted(this->soundTest))
	{
		SoundTest::update(this->soundTest);
//	SoundsState::showHeader(this);
	}
}

/**
 * Method called when the Game's StateMachine exits from this state
 *
 * @param owner		StateMachine's owner
 */
void SoundsState::exit(void* owner __attribute__ ((unused)))
{
	if(!isDeleted(this->soundTest))
	{
		SoundTest::hide(this->soundTest);
	}

	Base::exit(this, owner);
}

/**
 * Process user input
 *
 * @param userInput		User input
 */
void SoundsState::processUserInput(const UserInput* userInput)
{
	if(K_SEL & userInput->releasedKey)
	{
		return;
	}
	
	if(!isDeleted(this->soundTest))
	{
		SoundTest::processUserInput(this->soundTest, userInput->releasedKey);
	}

	Base::processUserInput(this, userInput);
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

