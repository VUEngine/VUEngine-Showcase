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

#include <string.h>

#include <Actor.h>
#include <ComponentManager.h>
#include <DebugConfig.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <VirtualList.h>
#include <VUEngine.h>

#include "ActorsState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->leaderPunk))
	{
		ActorsState::movePunks(this);

		Printing::text("                                                ", 0, 25, NULL);
		ActorsState::printPunkName(this, this->leaderPunk, 25);
		ActorsState::printPunkName(this, Actor::safeCast(Actor::getChildByName(this->leaderPunk, "Larry", false)), 25);
		ActorsState::printPunkName(this, Actor::safeCast(Actor::getChildByName(this->leaderPunk, "Curly", false)), 25);
	}

	if(this->showAdditionalDetails)
	{
		ActorsState::showAdditionalDetails(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::processUserInput(const UserInput* userInput)
{
	ActorsState::playSoundEffects(this, userInput, false);

	if(!isDeleted(this->leaderPunk))
	{
		/*
		* Let add some children to the leader punk taking into account
		* whether it is moving to the left or to the right just to 
		* make the input more intuitive		
		*/
		if(K_LL & userInput->releasedKey)
		{
			ActorsState::createSlavePunk(this, K_LL);
		}
		else if(K_LR & userInput->releasedKey)
		{
			ActorsState::createSlavePunk(this, K_LR);
		}
	}
	
	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::showControls()
{
	Printing::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::showStuff()
{
	ActorsState::createLeaderPunk(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::showExplanation()
{
	int16 y = 3;
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringActorsLabel), 2, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringParentingLabel), 2, y++, NULL);
	y++;
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printing::text("Actor", 2, y++, NULL);
	Printing::text("Actor", 2, y++, NULL);
	Printing::text("Stage", 2, y++, NULL);

	y++;
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringSpecsSubtitle), 2, y++, "DefaultBold");
	Printing::text("PunkActorSpec", 2, y++, NULL);

	y = 3;
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringActorCreationLabel), 26, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringActorDestructionLabel), 26, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringStagesLabel), 26, y++, NULL);
	y++;
	Printing::text(I18n::getText(I18n::getInstance(NULL), kStringMethodsSubtitle), 26, y++, "DefaultBold");
	Printing::text("ActorsState", 26, y++, NULL);
	Printing::text("::createLeaderPunk", 26, y++, NULL);
	Printing::text("::movePunks", 26, y++, NULL);
	Printing::text("::createSlavePunk", 26, y++, NULL);
	y++;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::showAdditionalDetails()
{
	if(isDeleted(this->leaderPunk))
	{
		return;;
	}

	int16 y = 3;
	Printing::text(__GET_CLASS_NAME(this->leaderPunk), 2, y++, NULL);

	Printing::text("Internal ID:   ", 2, ++y, NULL);
	Printing::int32(Actor::getInternalId(this->leaderPunk), 15, y++, NULL);
	Printing::text("Name:          ", 2, ++y, NULL);
	Printing::text(Actor::getName(this->leaderPunk), 15, y++, NULL);
	Printing::text("Children:      ", 2, ++y, NULL);
	Printing::int32(Actor::getChildrenCount(this->leaderPunk), 15, y++, NULL);

	Printing::text("Sprites:       ", 2, ++y, NULL);
	Printing::int32(ComponentManager::getComponentsCount(Entity::safeCast(this->leaderPunk), kSpriteComponent), 15, y++, NULL);

	Printing::text("Wireframes:  ", 2, ++y, NULL);
	Printing::int32(ComponentManager::getComponentsCount(Entity::safeCast(this->leaderPunk), kWireframeComponent), 15, y++, NULL);

	Printing::text("Colliders:  ", 2, ++y, NULL);
	Printing::int32(ComponentManager::getCount(Entity::safeCast(this->leaderPunk), kColliderComponent), 15, y++, NULL);

	y = 5;
	Printing::text("Position", 22, y, NULL);
	Printing::text("Rotation", 37, y++, NULL);
	Vector3D::print(*Actor::getPosition(this->leaderPunk), 22, ++y);
	Rotation::print(*Actor::getRotation(this->leaderPunk), 37, y);

	y = 11;
	Printing::text("Scale", 30, y++, NULL);
	Scale::print(*Actor::getScale(this->leaderPunk), 30, ++y);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/ActorsStageSpec.c"
	 */
	extern StageROMSpec ActorsStageSpec;
	this->stageSpec = (StageSpec*)&ActorsStageSpec;
	this->leaderPunk = NULL;
	this->validSuboptionKeys = K_LL | K_LR;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::printPunkName(Actor punk, int16 row)
{
	if(isDeleted(punk))
	{
		return;
	}

	Vector3D position = *Actor::getPosition(punk);
	const char* punkName = Actor::getName(punk);
	int16 col = __METERS_TO_PIXELS(position.x) / 8 + __HALF_SCREEN_WIDTH_IN_CHARS - strlen(punkName) / 2;

	if(0 >= col || __SCREEN_WIDTH_IN_CHARS <= col + strlen(punkName))
	{
		return;
	}

	Printing::text(punkName, col, row, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::createLeaderPunk()
{
	if(NULL != this->leaderPunk)
	{
		return;
	}
		
	// Check the specification in assets/images/Punk/Spec/PunkSpec.c
	extern ActorSpec PunkActorSpec;
	
	PositionedActor positionedActor = 
	{
		&PunkActorSpec, {0, 64, 16}, {0, 0, 0}, {1, 1, 1},  0, "Moe", NULL, NULL, false
	};

	/*
	 * This is how we add actors to the Stage. Notice that we don't creates Sprites nor animate them
	 * directly anymore. Now, the engine takes care of all that by reading the ActorSpec.
	 */
	this->leaderPunk = Actor::safeCast(Stage::spawnChildActor(this->stage, (const PositionedActor* const)&positionedActor, false));
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::createSlavePunk(uint16 input)
{
	if(isDeleted(this->leaderPunk))
	{
		return;
	}

	char* childPunkName = NULL;
	Vector3D childPunkPosition = Vector3D::zero();
	Rotation rotation = *Actor::getRotation(this->leaderPunk);

	bool movingRight = 0 == rotation.y;

	if(K_LL == input)
	{
		childPunkPosition.x = movingRight ? -__PIXELS_TO_METERS(80) : __PIXELS_TO_METERS(80);
		childPunkName = movingRight ? "Larry" : "Curly";
	}
	else if(K_LR == input)
	{
		childPunkPosition.x = !movingRight ? -__PIXELS_TO_METERS(80) : __PIXELS_TO_METERS(80);
		childPunkName = !movingRight ? "Larry" : "Curly";
	}

	if(NULL != childPunkName)
	{
		/*
		 * Let's see if the punk already has a child with the selected name.
		 * If not, then create and add it as a child.
		 */
		Actor childPunk = Actor::safeCast(Actor::getChildByName(this->leaderPunk, childPunkName, false));

		if(NULL != childPunk)
		{
			Actor::deleteMyself(childPunk);
		}
		else
		{
			extern ActorSpec PunkActorSpec;

			PositionedActor positionedActor = 
			{
					&PunkActorSpec, 
					{__METERS_TO_PIXELS(childPunkPosition.x), __METERS_TO_PIXELS(childPunkPosition.y), __METERS_TO_PIXELS(childPunkPosition.z)},
					{0, 0, 0},
					{1, 1, 1},
					0,
					childPunkName,
					NULL,
					NULL,
					false
			};

			Actor::spawnChildActor(this->leaderPunk, &positionedActor);
		}
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ActorsState::movePunks()
{
	if(!isDeleted(this->leaderPunk))
	{
		/*
		 * Since the other punks are added as children to the leader punk, 
		 * moving and rotating it will propagate to its children, so we don't
		 * need to move nor rotate the children. 
		 * Notice their relative positions when changing direction:
		 * If moving right the order is Larry, Moe, Curly, then if Moe rotates
		 * half way around the Y axis (512 = 360 degrees), then the order becomes 
		 * Curly, Moe, Larry. Another way: Curly is always in front of the others.
		 */
		Vector3D localPosition = *Actor::getLocalPosition(this->leaderPunk);
		Rotation localRotation = *Actor::getLocalRotation(this->leaderPunk);
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

			translation.z++;
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

			translation.z--;
		}

		// Add a translation to the leader punk
		Actor::translate(this->leaderPunk, &translation);

		// Make it to face left or right by rotating it around its Y axis
		Actor::setLocalRotation(this->leaderPunk, &localRotation);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
