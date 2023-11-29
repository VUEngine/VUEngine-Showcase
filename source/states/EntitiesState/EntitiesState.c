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

#include <EntitiesState.h>

#include <AnimatedEntity.h>
#include <Camera.h>
#include <CameraEffectManager.h>
#include <DirectDraw.h>
#include <Printing.h>

#include <debugConfig.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

/*
 * Check assets/stage/EntitiesStageSpec.c
 */
extern StageROMSpec EntitiesStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void EntitiesState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&EntitiesStage;
	this->leaderPunk = NULL;
}

// class's destructor
void EntitiesState::destructor()
{
	// destroy base
	Base::destructor();
}

void EntitiesState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);

	// Must explicity call it otherwise nothing happens
	EntitiesState::startAnimations(this);
}

void EntitiesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->leaderPunk))
	{
		/*
		 * Since the other punks are added as children to the leader punk, 
		 * moving and rotating it will propagate to its children, so we don't
		 * need to move nor rotate the children. Notice their relative positions
		 * when changing direction:
		 * If moving right the order is: Larry, Moe, Curly, then if Moe rotates
		 * half way around the Y axies, then the order becomes: Curly, Moe, Larry.
		 */
		Vector3D localPosition = *AnimatedEntity::getLocalPosition(this->leaderPunk);
		Rotation localRotation = *AnimatedEntity::getLocalRotation(this->leaderPunk);
		Vector3D translation = Vector3D::zero();

		bool movingRight = 0 == localRotation.y;

		if(movingRight)
		{
			if(__PIXELS_TO_METERS(__HALF_SCREEN_WIDTH) > localPosition.x)
			{
				translation.x = __PIXELS_TO_METERS(1);
			}
			else
			{
				localRotation.y = __I_TO_FIX10_6(255);
			}
		}
		else
		{
			if(-__PIXELS_TO_METERS(__HALF_SCREEN_WIDTH) <= localPosition.x)
			{
				translation.x = -__PIXELS_TO_METERS(1);
			}
			else
			{
				localRotation.y = __I_TO_FIX10_6(0);
			}
		}

		// Add a translation to the leader punk
		AnimatedEntity::translate(this->leaderPunk, &translation);

		// Make it to face left or right by rotating it around its Y axis
		AnimatedEntity::setLocalRotation(this->leaderPunk, &localRotation);

		// Let just print some useful info
		EntitiesState::showDetails(this);
	}
}

void EntitiesState::processUserInput(const UserInput* userInput)
{
	if(!isDeleted(this->leaderPunk))
	{
		/*
		* Let add some children to the leader punk taking into account
		* whether it is moving to the left or to the right just to 
		* make the input more intuitive		
		*/
		Vector3D childPunkPosition = Vector3D::zero();

		char* childPunkName = NULL;

		Rotation rotation = *AnimatedEntity::getRotation(this->leaderPunk);

		bool movingRight = 0 == rotation.y;

		if(K_LL & userInput->releasedKey)
		{
			childPunkPosition.x = movingRight ? -__PIXELS_TO_METERS(80) : __PIXELS_TO_METERS(80);
			childPunkName = movingRight ? "Larry" : "Curly";
		}
		else if(K_LR & userInput->releasedKey)
		{
			childPunkPosition.x = !movingRight ? -__PIXELS_TO_METERS(80) : __PIXELS_TO_METERS(80);
			childPunkName = !movingRight ? "Larry" : "Curly";
		}

		if(NULL != childPunkName)
		{
			/*
			 * Let see if the punk already has a child with the selected name.
			 * If not, then create and add it as a child.
			 */
			AnimatedEntity childPunk = AnimatedEntity::safeCast(AnimatedEntity::getChildByName(this->leaderPunk, childPunkName, false));

			if(NULL != childPunk)
			{
				AnimatedEntity::deleteMyself(childPunk);
			}
			else
			{
				extern EntitySpec Punk;
				AnimatedEntity::addChildEntity(this->leaderPunk, &Punk, 0, childPunkName, &childPunkPosition, NULL);
			}
		}
	}
	
	return Base::processUserInput(this, userInput);
}

void EntitiesState::showStuff()
{
	// Check the specification in assets/images/Punk/Spec/PunkSpec.c
	extern EntitySpec Punk;
	PositionedEntity positionedEntity = {&Punk, {0, 32, 16, 0}, 0, "Moe", NULL, NULL, false};

	/*
	 * This is how we add entities to the Stage. Notice that we don't creates Sprites nor animate them
	 * directly anymore. Now, the engine takes care of all that by reading the EntitySpec.
	 */
	this->leaderPunk = AnimatedEntity::safeCast(Stage::addChildEntity(this->stage, (const PositionedEntity* const)&positionedEntity, false));
	
	EntitiesState::printHeader(this);
}

void EntitiesState::printHeader()
{
	Base::printHeader(this);

	if(!isDeleted(this->leaderPunk))
	{
		int16 y = 3;
		Printing::text(Printing::getInstance(), "                      ", 1, y, NULL);
		Printing::text(Printing::getInstance(), "Entity: ", 1, y, NULL);
		Printing::text(Printing::getInstance(), __GET_CLASS_NAME(this->leaderPunk), 11, y++, NULL);
		Printing::text(Printing::getInstance(), "Name: ", 1, y, NULL);
		Printing::text(Printing::getInstance(), AnimatedEntity::getName(this->leaderPunk), 11, y++, NULL);
	}
}

void EntitiesState::showDetails()
{
	Printing::text(Printing::getInstance(), "Children:   ", 1, 5, NULL);
	Printing::int32(Printing::getInstance(), AnimatedEntity::getChildCount(this->leaderPunk), 11, 5, NULL);
	Printing::text(Printing::getInstance(), "Position:   ", 1, 6, NULL);
	Vector3D::print(*AnimatedEntity::getLocalPosition(this->leaderPunk), 11, 6);
	Printing::text(Printing::getInstance(), "Rotation:   ", 30, 6, NULL);
	Rotation::print(*AnimatedEntity::getLocalRotation(this->leaderPunk), 40, 6);
	Printing::text(Printing::getInstance(), "                                                ", 1, 21, NULL);
	EntitiesState::printPunkName(this->leaderPunk, 21);
	EntitiesState::printPunkName(AnimatedEntity::safeCast(AnimatedEntity::getChildByName(this->leaderPunk, "Larry", false)), 21);
	EntitiesState::printPunkName(AnimatedEntity::safeCast(AnimatedEntity::getChildByName(this->leaderPunk, "Curly", false)), 21);
}

static void EntitiesState::printPunkName(AnimatedEntity punk, int16 row)
{
	if(isDeleted(punk))
	{
		return;
	}

	Vector3D position = *AnimatedEntity::getPosition(punk);
	char* punkName = AnimatedEntity::getName(punk);
	int16 col = __METERS_TO_PIXELS(position.x) / 10 + __HALF_SCREEN_WIDTH_IN_CHARS - strlen(punkName) / 2;

	if(0 >= col || __SCREEN_WIDTH_IN_CHARS <= col + strlen(punkName))
	{
		return;
	}

	Printing::text(Printing::getInstance(), punkName, col, row, NULL);
}