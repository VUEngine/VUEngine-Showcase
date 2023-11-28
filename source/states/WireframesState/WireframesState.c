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

#include <WireframesState.h>

#include <Camera.h>
#include <CameraEffectManager.h>
#include <DirectDraw.h>
#include <Printing.h>
#include <WireframeManager.h>

#include <debugConfig.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

/*
 * Check assets/stage/WireframesStageSpec.c
 */
extern StageROMSpec WireframesStage;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void WireframesState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&WireframesStage;
}

// class's destructor
void WireframesState::destructor()
{
	// destroy base
	Base::destructor();
}

void WireframesState::execute(void* owner __attribute__((unused)))
{
	if(this->showDetails)
	{
		WireframeManager::print(WireframeManager::getInstance(), 1, 20);
		DirectDraw::print(DirectDraw::getInstance(), 27, 20);
	}
	else
	{
		Printing::text(Printing::getInstance(), "CAMERA ", 1, 20, NULL);
		Printing::text(Printing::getInstance(), "Position: ", 1, 22, NULL);
		Printing::text(Printing::getInstance(), "Rotation: ", 38, 22, NULL);
		Vector3D::print(Camera::getPosition(Camera::getInstance()), 1, 24);
		Rotation::print(Camera::getRotation(Camera::getInstance()), 38, 24);
	}
}

void WireframesState::processUserInput(const UserInput* userInput)
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

	Camera camera = Camera::getInstance();
	Camera::translate(camera, translation, false);
	Camera::rotate(camera, rotation);

	return Base::processUserInput(this, userInput);
}

void WireframesState::showDetails()
{
	Printing::clear(Printing::getInstance());

	WireframesState::printHeader(this);
}
