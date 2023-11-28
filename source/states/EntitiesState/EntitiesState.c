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

	if(this->showDetails)
	{
	}
	else
	{
	}
}

void EntitiesState::processUserInput(const UserInput* userInput)
{
	Vector3D translation = {0, 0, 0};
	Rotation rotation = Rotation::zero();

	if(K_LU & userInput->holdKey)
	{
		translation.z = __PIXELS_TO_METERS(8);
	}

	if(K_LD & userInput->holdKey)
	{
		translation.z = -__PIXELS_TO_METERS(8);
	}

	if(K_LL & userInput->holdKey)
	{
		rotation.y = -__I_TO_FIX10_6(2);
	}

	if(K_LR & userInput->holdKey)
	{
		rotation.y = __I_TO_FIX10_6(2);
	}

	if(K_RL & userInput->holdKey)
	{
		translation.x = -__PIXELS_TO_METERS(8);
	}

	if(K_RR & userInput->holdKey)
	{
		translation.x = __PIXELS_TO_METERS(8);
	}

	translation = Vector3D::rotate(translation, *_cameraRotation);

	/*
	 * The engine doesn't implement quaterions because of obvious performance reasons.
	 * So, moving the camera around the X axis will cause gimbal lock related issues
	 * when rotations on the othe axis are applied too.
	 */
	if(K_RU & userInput->holdKey)
	{
		rotation.x = __I_TO_FIX10_6(2);
	}

	if(K_RD & userInput->holdKey)
	{
		rotation.x = -__I_TO_FIX10_6(2);
	}

	return Base::processUserInput(this, userInput);
}

void EntitiesState::showStuff()
{
	// Check the specification in assets/images/Punk/Spec/PunkSpec.c
	extern EntitySpec Punk;
	PositionedEntity positionedEntity = {&Punk, {0, 0, 16, 0}, 0, NULL, NULL, NULL, false};

	/*
	 * This is how you add entities to the stage. Notice that we don't creates sprites nor animate them
	 * directly anymore. Now, the engine takes of all that by ready the EntitySpec.
	 */
	AnimatedEntity punk = Stage::addChildEntity(this->stage, (const PositionedEntity* const)&positionedEntity, false);

}

void EntitiesState::showDetails()
{
}
