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

#include "CogWheel.h"


//=========================================================================================================
// CLASS' PUBLIC METHODS
//=========================================================================================================

//---------------------------------------------------------------------------------------------------------
void CogWheel::constructor(CogWheelSpec* cogWheelSpec, int16 internalId, const char* const name)
{
	// Always explicitly call the base's constructor 
	Base::constructor((EntitySpec*)&cogWheelSpec->entitySpec, internalId, name);

	this->update = true;
}
//---------------------------------------------------------------------------------------------------------
void CogWheel::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}
//---------------------------------------------------------------------------------------------------------
void CogWheel::update()
{
	Rotation localRotation = this->localTransformation.rotation;
	localRotation.z += __I_TO_FIXED(1);

	CogWheel::setLocalRotation(this, &localRotation);
}
//---------------------------------------------------------------------------------------------------------
