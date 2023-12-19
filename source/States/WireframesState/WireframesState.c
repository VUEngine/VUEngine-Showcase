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
#include <DirectDraw.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <WireframeManager.h>

#include <DebugConfig.h>
#include <string.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void WireframesState::constructor()
{
	Base::constructor();

	/*
	 * Check assets/stage/WireframesStageSpec.c
	 */
	extern StageROMSpec WireframesStageSpec;
	this->stageSpec = (StageSpec*)&WireframesStageSpec;
}

// class's destructor
void WireframesState::destructor()
{
	// destroy base
	Base::destructor();
}

void WireframesState::enter(void* owner __attribute__((unused)))
{
	Base::enter(this, owner);
	
	/*
	 * I need to register both released and hold buttons
	 */
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_RELEASED | __KEY_HOLD);
}

void WireframesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);
	
	if(this->showAdditionalDetails)
	{
		WireframesState::showAdditionalDetails(this);
	}
}

void WireframesState::processUserInput(const UserInput* userInput)
{
	WireframesState::playSoundEffects(this, userInput, false);

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
	/*
	if(K_RU & userInput->holdKey)
	{
		rotation.x = __I_TO_FIX10_6(2);
	}

	if(K_RD & userInput->holdKey)
	{
		rotation.x = -__I_TO_FIX10_6(2);
	}
	*/

	Camera camera = Camera::getInstance();
	Camera::translate(camera, translation, false);
	Camera::rotate(camera, rotation);

	Base::processUserInput(this, userInput);
}

void WireframesState::showControls()
{
	Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_R_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_R_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 8, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 9, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 10, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 11, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

void WireframesState::showExplanation()
{
	int16 y = 3;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "Debug");
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringCameraControlLabel), 2, y++, NULL);
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringWireframesLabel), 2, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "Debug");
	Printing::text(Printing::getInstance(), "Camera", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "DirectDraw", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Mesh", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "Wireframe", 2, y++, NULL);
	Printing::text(Printing::getInstance(), "WireframeManager", 2, y++, NULL);

	y = 3;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "WireframesState", 26, y++, NULL);
	Printing::text(Printing::getInstance(), " processUserInput", 26, y++, NULL);

	y++;
	Printing::text(Printing::getInstance(), I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 26, y++, "Debug");
	Printing::text(Printing::getInstance(), "Pyramid", 26, y++, NULL);
	Printing::text(Printing::getInstance(), "WireframesStage", 26, y++, NULL);
}

void WireframesState::showAdditionalDetails()
{

	WireframeManager::print(WireframeManager::getInstance(), 1, 3);
	DirectDraw::print(DirectDraw::getInstance(), 1, 9);
	Camera::print(Camera::getInstance(), 31, 3, false);
}
