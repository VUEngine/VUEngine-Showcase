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

#include <string.h>

#include <AnimatedEntity.h>
#include <DebugConfig.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <VirtualList.h>

#include "EntitiesState.h"


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void EntitiesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	if(!isDeleted(this->leaderPunk))
	{
		EntitiesState::movePunks(this);

		Printing::text(this->printing, "                                                ", 0, 25, NULL);
		EntitiesState::printPunkName(this, this->leaderPunk, 25);
		EntitiesState::printPunkName(this, AnimatedEntity::safeCast(AnimatedEntity::getChildByName(this->leaderPunk, "Larry", false)), 25);
		EntitiesState::printPunkName(this, AnimatedEntity::safeCast(AnimatedEntity::getChildByName(this->leaderPunk, "Curly", false)), 25);
	}

	if(this->showAdditionalDetails)
	{
		EntitiesState::showAdditionalDetails(this);
	}
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::processUserInput(const UserInput* userInput)
{
	EntitiesState::playSoundEffects(this, userInput, false);

	if(!isDeleted(this->leaderPunk))
	{
		/*
		* Let add some children to the leader punk taking into account
		* whether it is moving to the left or to the right just to 
		* make the input more intuitive		
		*/
		if(K_LL & userInput->releasedKey)
		{
			EntitiesState::createSlavePunk(this, K_LL);
		}
		else if(K_LR & userInput->releasedKey)
		{
			EntitiesState::createSlavePunk(this, K_LR);
		}
	}
	
	Base::processUserInput(this, userInput);
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::showControls()
{
	Printing::text(this->printing, __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(this->printing, __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::showStuff()
{
	EntitiesState::createLeaderPunk(this);
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::showExplanation()
{
	int16 y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringEntitiesLabel), 2, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringParentingLabel), 2, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printing::text(this->printing, "AnimatedEntity", 2, y++, NULL);
	Printing::text(this->printing, "Entity", 2, y++, NULL);
	Printing::text(this->printing, "Stage", 2, y++, NULL);

	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "DefaultBold");
	Printing::text(this->printing, "PunkEntitySpec", 2, y++, NULL);

	y = 3;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringOtherConceptsSubtitle), 26, y++, "DefaultBold");
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringEntityCreationLabel), 26, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringEntityDestructionLabel), 26, y++, NULL);
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringStagesLabel), 26, y++, NULL);
	y++;
	Printing::text(this->printing, I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "DefaultBold");
	Printing::text(this->printing, "EntitiesState", 26, y++, NULL);
	Printing::text(this->printing, "::createLeaderPunk", 26, y++, NULL);
	Printing::text(this->printing, "::movePunks", 26, y++, NULL);
	Printing::text(this->printing, "::createSlavePunk", 26, y++, NULL);
	y++;
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::showAdditionalDetails()
{
	if(isDeleted(this->leaderPunk))
	{
		return;;
	}

	int16 y = 3;
	Printing::text(this->printing, __GET_CLASS_NAME(this->leaderPunk), 2, y++, NULL);

	Printing::text(this->printing, "Internal ID:   ", 2, ++y, NULL);
	Printing::int32(this->printing, AnimatedEntity::getInternalId(this->leaderPunk), 15, y++, NULL);
	Printing::text(this->printing, "Name:          ", 2, ++y, NULL);
	Printing::text(this->printing, AnimatedEntity::getName(this->leaderPunk), 15, y++, NULL);
	Printing::text(this->printing, "Children:      ", 2, ++y, NULL);
	Printing::int32(this->printing, AnimatedEntity::getChildrenCount(this->leaderPunk), 15, y++, NULL);

	Printing::text(this->printing, "Sprites:       ", 2, ++y, NULL);
	Printing::int32(this->printing, SpriteManager::getCount(SpriteManager::getInstance(), SpatialObject::safeCast(this->leaderPunk)), 15, y++, NULL);

	Printing::text(this->printing, "Wireframes:  ", 2, ++y, NULL);
	Printing::int32(this->printing, WireframeManager::getCount(WireframeManager::getInstance(), SpatialObject::safeCast(this->leaderPunk)), 15, y++, NULL);

	Printing::text(this->printing, "Colliders:  ", 2, ++y, NULL);
	Printing::int32(this->printing, ColliderManager::getCount(VUEngine::getColliderManager(VUEngine::getInstance()), SpatialObject::safeCast(this->leaderPunk)), 15, y++, NULL);

	y = 5;
	Printing::text(this->printing, "Position", 22, y, NULL);
	Printing::text(this->printing, "Rotation", 37, y++, NULL);
	Vector3D::print(*AnimatedEntity::getPosition(this->leaderPunk), 22, ++y);
	Rotation::print(*AnimatedEntity::getRotation(this->leaderPunk), 37, y);

	y = 11;
	Printing::text(this->printing, "Scale", 30, y++, NULL);
	Scale::print(*AnimatedEntity::getScale(this->leaderPunk), 30, ++y);
}
//---------------------------------------------------------------------------------------------------------

//=========================================================================================================
// CLASS' PRIVATE METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void EntitiesState::constructor()
{
	Base::constructor();

	/*
	 * Check assets/stage/EntitiesStageSpec.c"
	 */
	extern StageROMSpec EntitiesStageSpec;
	this->stageSpec = (StageSpec*)&EntitiesStageSpec;
	this->leaderPunk = NULL;
	this->validSuboptionKeys = K_LL | K_LR;
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::destructor()
{
	// destroy base
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::printPunkName(AnimatedEntity punk, int16 row)
{
	if(isDeleted(punk))
	{
		return;
	}

	Vector3D position = *AnimatedEntity::getPosition(punk);
	const char* punkName = AnimatedEntity::getName(punk);
	int16 col = __METERS_TO_PIXELS(position.x) / 8 + __HALF_SCREEN_WIDTH_IN_CHARS - strlen(punkName) / 2;

	if(0 >= col || __SCREEN_WIDTH_IN_CHARS <= col + strlen(punkName))
	{
		return;
	}

	Printing::text(this->printing, punkName, col, row, NULL);
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::createLeaderPunk()
{
	if(NULL != this->leaderPunk)
	{
		return;
	}
		
	// Check the specification in assets/images/Punk/Spec/PunkSpec.c
	extern EntitySpec PunkEntitySpec;
	PositionedEntity positionedEntity = {&PunkEntitySpec, {0, 64, 16}, {0, 0, 0}, {1, 1, 1},  0, "Moe", NULL, NULL, false};

	/*
	 * This is how we add entities to the Stage. Notice that we don't creates Sprites nor animate them
	 * directly anymore. Now, the engine takes care of all that by reading the EntitySpec.
	 */
	this->leaderPunk = AnimatedEntity::safeCast(Stage::spawnChildEntity(this->stage, (const PositionedEntity* const)&positionedEntity, false));
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::createSlavePunk(uint16 input)
{
	if(isDeleted(this->leaderPunk))
	{
		return;
	}

	char* childPunkName = NULL;
	Vector3D childPunkPosition = Vector3D::zero();
	Rotation rotation = *AnimatedEntity::getRotation(this->leaderPunk);

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
		AnimatedEntity childPunk = AnimatedEntity::safeCast(AnimatedEntity::getChildByName(this->leaderPunk, childPunkName, false));

		if(NULL != childPunk)
		{
			AnimatedEntity::deleteMyself(childPunk);
		}
		else
		{
			extern EntitySpec PunkEntitySpec;

			PositionedEntity positionedEntity = 
			{
					&PunkEntitySpec, 
					{__METERS_TO_PIXELS(childPunkPosition.x), __METERS_TO_PIXELS(childPunkPosition.y), __METERS_TO_PIXELS(childPunkPosition.z)},
					{0, 0, 0},
					{1, 1, 1},
					0,
					childPunkName,
					NULL,
					NULL,
					false
			};

			AnimatedEntity::spawnChildEntity(this->leaderPunk, &positionedEntity);
		}
	}
}
//---------------------------------------------------------------------------------------------------------
void EntitiesState::movePunks()
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
		AnimatedEntity::translate(this->leaderPunk, &translation);

		// Make it to face left or right by rotating it around its Y axis
		AnimatedEntity::setLocalRotation(this->leaderPunk, &localRotation);
	}
}
//---------------------------------------------------------------------------------------------------------
