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
	// construct base
	Base::constructor((EntitySpec*)&cogWheelSpec->entitySpec, internalId, name);

	this->update = true;
}
//---------------------------------------------------------------------------------------------------------
void CogWheel::destructor()
{
	// destroy the super object
	// must always be called at the end of the destructor
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
