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

#include <Camera.h>
#include <DebugConfig.h>
#include <DirectDraw.h>
#include <I18n.h>
#include <Languages.h>
#include <Printing.h>
#include <VIPManager.h>
#include <WireframeManager.h>

#include "WireframesState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::enter(void* owner __attribute__((unused))) 
{
	Base::enter(this, owner);
	
	/*
	 * I need to register both released and hold buttons
	 */
	KeypadManager::registerInput(__KEY_RELEASED | __KEY_HOLD);

	// Drawing wireframes is heavy, let's make it easier on the poor VB
	WireframesState::changeFramerate(this, 25, -1);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);
	
	if(this->showAdditionalDetails)
	{
		WireframesState::showAdditionalDetails(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::resume(void* owner)
{
	Base::resume(this, owner);

	// Drawing wireframes is heavy, let's make it easier on the poor VB
	WireframesState::changeFramerate(this, 25, -1);

	// Make sure that no interrupts take place during rendering or drawing
	VIPManager::enableMultiplexedInterrupts(kVIPNoMultiplexedInterrupts);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::processUserInput(const UserInput* userInput)
{
	WireframesState::playSoundEffects(this, userInput, false);

	Vector3D translation = {0, 0, 0};
	Rotation rotation = Rotation::zero();

	if(K_LU & userInput->holdKey) {
		translation.z = __PIXELS_TO_METERS(8 << 1);
	}

	if(K_LD & userInput->holdKey)
	{
		translation.z = -__PIXELS_TO_METERS(8 << 1);
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
		translation.x = -__PIXELS_TO_METERS(8 << 1);
	}

	if(K_RR & userInput->holdKey)
	{
		translation.x = __PIXELS_TO_METERS(8 << 1);
	}

	translation = Vector3D::rotate(translation, *_cameraRotation);

	/*
	 * The engine doesn't implement quaternions due to obvious performance reasons.
	 * So, moving the Camera around the X axis will cause gimbal lock related issues
	 * when rotations on the other axis are applied too.
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

	Camera::translate(translation, false);
	Camera::rotate(rotation);

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::showControls()
{
	Printing::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_R_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_R_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);

	Printing::text(__CHAR_L_D_PAD_DOWN, __SCREEN_WIDTH_IN_CHARS - 8, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_UP, __SCREEN_WIDTH_IN_CHARS - 9, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 10, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 11, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::showExplanation()
{
	int16 y = 3;
	Printing::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
	Printing::text(I18n::getText(I18n::getInstance(), kStringCameraControlLabel), 2, y++, NULL);
	Printing::text(I18n::getText(I18n::getInstance(), kStringWireframesLabel), 2, y++, NULL);

	y++;
	Printing::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
	Printing::text("Camera", 2, y++, NULL);
	Printing::text("DirectDraw", 2, y++, NULL);
	Printing::text("Mesh", 2, y++, NULL);
	Printing::text("Wireframe", 2, y++, NULL);
	Printing::text("WireframeManager", 2, y++, NULL);

	y = 3;
	Printing::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 26, y++, "DefaultBold");
	Printing::text("WireframesState", 26, y++, NULL);
	Printing::text("::processUserInput", 26, y++, NULL);

	y++;
	Printing::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 26, y++, "DefaultBold");
	Printing::text("PyramidActorSpec", 26, y++, NULL);
	Printing::text("WireframesStageSpec", 26, y++, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::showAdditionalDetails()
{

	WireframeManager::print(1, 3);
	DirectDraw::print(1, 9);
	Camera::print(31, 3, false);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::constructor(){
	
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/WireframesStageSpec.c
	 */
	extern StageROMSpec WireframesStageSpec;
	this->stageSpec = (StageSpec*)&WireframesStageSpec;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void WireframesState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
