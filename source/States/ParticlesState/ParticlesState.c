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

#include <I18n.h>
#include <Languages.h>
#include <Printer.h>
#include <Singleton.h>
#include <Stage.h>

#include "ParticlesState.h"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

enum ParticleTypes
{
	kParticleNoTypeStart = 0,
	kParticleNormal,
	kParticlePhysical,
	kParticleSolid,

	kParticleNoTypeEnd
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PUBLIC METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/*
 * The StateMachine calls State::execute when updated. It is called once per game frame.
 */
void ParticlesState::execute(void* owner)
{
	Base::execute(this, owner);

	// Don't print stuff every game cycle, it is a heavy process. This is just an example!
	if(this->showAdditionalDetails)
	{
		ParticlesState::showAdditionalDetails(this);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::processUserInput(const UserInput* userInput)
{
	ParticlesState::playSoundEffects(this, userInput);

	if(K_LL & userInput->releasedKey)
	{
		if(kParticleNoTypeStart >= --this->particlesType)
		{
			this->particlesType = kParticleNoTypeEnd - 1;
		}

		ParticlesState::show(this, true);
	}
	else if(K_LR & userInput->releasedKey)
	{
		if(kParticleNoTypeEnd <= ++this->particlesType)
		{
			this->particlesType = kParticleNoTypeStart + 1;
		}

		ParticlesState::show(this, true);
	}

	Base::processUserInput(this, userInput);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::showControls()
{
	Printer::text(__CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printer::text(__CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printer::text(__CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::showStuff()
{
	ParticlesState::loadParticles(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::showExplanation()
{
	if(!isDeleted(this->particleSystem))
	{
		int16 y = 3;
		Printer::text(I18n::getText(I18n::getInstance(), kStringConceptsSubtitle), 2, y++, "DefaultBold");
		Printer::text(I18n::getText(I18n::getInstance(), kStringParticleSystemsLabel), 2, y++, NULL);
		Printer::text(I18n::getText(I18n::getInstance(), kStringParticleTypesLabel), 2, y++, NULL);
		y++;
		Printer::text(I18n::getText(I18n::getInstance(), kStringClassesSubtitle), 2, y++, "DefaultBold");
		Printer::text("Particle", 2, y++, NULL);
		Printer::text("ParticleSystem", 2, y++, NULL);
		Printer::text("PhysicalParticle", 2, y++, NULL);
		Printer::text("SolidParticle", 2, y++, NULL);
		y++;
		Printer::text(I18n::getText(I18n::getInstance(), kStringMethodsSubtitle), 2, y++, "DefaultBold");
		Printer::text("ParticlesState", 2, y++, NULL);
		Printer::text("::loadParticles", 2, y++, NULL);
		Printer::text("::processUserInput", 2, y++, NULL);
		y++;
		Printer::text(I18n::getText(I18n::getInstance(), kStringSpecsSubtitle), 2, y++, "DefaultBold");
		Printer::text("StarParticle*Spec", 2, y++, NULL);
		Printer::text("StarsParticleSystem*Spec", 2, y++, NULL);

		y = 3;
		Printer::text(I18n::getText(I18n::getInstance(), kStringParticlesSubtitle), 28, y++, "DefaultBold");

		switch(this->particlesType)
		{
			case kParticleNormal:

				Printer::text("Particle", 28, y, NULL);
				break;

			case kParticlePhysical:

				Printer::text("PhysicalParticle", 28, y, NULL);
				break;

			case kParticleSolid:

				Printer::text("SolidParticle", 28, y, NULL);
				break;
		}
	}	
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::showAdditionalDetails()
{
	if(!isDeleted(this->particleSystem))
	{
		ParticleSystem::print(this->particleSystem, 1, 3);
	}
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' PRIVATE METHODS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::constructor()
{
	// Always explicitly call the base's constructor 
	Base::constructor();

	/*
	 * Check assets/stage/ParticlesStageSpec.c
	 */
	extern StageROMSpec ParticlesStageSpec;
	this->stageSpec = (StageSpec*)&ParticlesStageSpec;
	this->particleSystem = NULL;
	this->particlesType = kParticleNoTypeStart + 1;
	this->validSuboptionKeys = K_LL | K_LR;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::destructor()
{
	// Always explicitly call the base's destructor 
	Base::destructor();
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void ParticlesState::loadParticles()
{
	// Check these specifications in assets/ParticleSystem/Stars/StarsSpec.c		
	extern ParticleSystemSpec StarsParticleSystemNormalSpec;
	extern ParticleSystemSpec StarsParticleSystemPhysicalSpec;
	extern ParticleSystemSpec StarsParticleSystemSolidSpec;

	ParticleSystemSpec* particleSystemActorSpec = NULL;
	int16 yPosition = 0;

	switch(this->particlesType)
	{
		case kParticleNormal:

			particleSystemActorSpec = &StarsParticleSystemNormalSpec;
			yPosition = -16;
			break;

		case kParticlePhysical:

			particleSystemActorSpec = &StarsParticleSystemPhysicalSpec;
			yPosition = 0;
			break;

		case kParticleSolid:

			particleSystemActorSpec = &StarsParticleSystemSolidSpec;
			yPosition = -4;
			break;
	}

	// Retrieve the particle system from the stage
	this->particleSystem = ParticleSystem::safeCast(Stage::getChildByName(this->stage, "Stars", false));

	NM_ASSERT(!isDeleted(this->particleSystem), "ParticlesState::loadParticles: stars not found");

	if(!isDeleted(this->particleSystem))
	{
		ParticleSystem::setSpec(this->particleSystem, particleSystemActorSpec);

		Vector3D position = Vector3D::getFromPixelVector((PixelVector){__HALF_SCREEN_WIDTH / 2, yPosition, 16, 0});
		ParticleSystem::setLocalPosition(this->particleSystem, &position);

		ParticleSystem::start(this->particleSystem);
	}

	ParticlesState::showHeader(this);
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
