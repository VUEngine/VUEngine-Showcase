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


#include <Camera.h>
#include <CameraEffectManager.h>
#include <I18n.h>
#include <Languages.h>
#include <Mesh.h>
#include <Printing.h>
#include <WireframesState.h>
#include <VUEngine.h>

#include <debugConfig.h>
#include <string.h>

//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

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

void WireframesState::showStuff()
{
}

void WireframesState::processUserInput(UserInput userInput)
{
//	Stage::showStreamingProfiling(this->stage, 1, 1);

	if(K_SEL & userInput.releasedKey)
	{
		static bool interlaced = false;

		interlaced = !interlaced;

		if(interlaced)
		{
			Mesh::mutateMethod(draw, Mesh::draw);
		}
		else
		{
			Mesh::mutateMethod(draw, Mesh::drawInterlaced);
		}
	}
	else
	{
		Vector3D translation = {0, 0, 0};

		if(K_LU & userInput.holdKey)
		{
			translation.z = __PIXELS_TO_METERS(8);
		}

		if(K_LD & userInput.holdKey)
		{
			translation.z = -__PIXELS_TO_METERS(8);
		}

		if(K_LL & userInput.holdKey)
		{
			translation.x = -__PIXELS_TO_METERS(8);
		}

		if(K_LR & userInput.holdKey)
		{
			translation.x = __PIXELS_TO_METERS(8);
		}

		translation = Vector3D::rotate(translation, *_cameraRotation);

		Rotation rotation = Rotation::zero();

		if(K_RL & userInput.holdKey)
		{
			rotation.y = __I_TO_FIX10_6(2);
		}

		if(K_RR & userInput.holdKey)
		{
			rotation.y = -__I_TO_FIX10_6(2);
		}

		if(K_RU & userInput.holdKey)
		{
			rotation.x = __I_TO_FIX10_6(2);
		}

		if(K_RD & userInput.holdKey)
		{
			rotation.x = -__I_TO_FIX10_6(2);
		}

		Camera camera = Camera::getInstance();
		Camera::translate(camera, translation, false);
		Camera::rotate(camera, rotation);
	}
}

