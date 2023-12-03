/**
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ParticlesState.h>

#include <Printing.h>
#include <Stage.h>

#include <debugUtilities.h>
#include <string.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec ParticlesStage;

enum ParticleTypes
{
	kParticleNoTypeStart = 0,
	kParticleNormal,
	kParticlePhysical,
	kParticleSolid,

	kParticleNoTypeEnd
};


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DEFINITION
//---------------------------------------------------------------------------------------------------------

// class's constructor
void ParticlesState::constructor()
{
	Base::constructor();

	this->stageSpec = (StageSpec*)&ParticlesStage;
	this->particleSystem = NULL;
	this->particlesType = kParticleNoTypeStart + 1;
}

// class's destructor
void ParticlesState::destructor()
{
	// destroy base
	Base::destructor();
}

/*
 * The StateMachine calls State::execute when updated.
 * It is called once per game frame.
 */
void ParticlesState::execute(void* owner __attribute__((unused)))
{
	Base::execute(this, owner);

	// Don't print stuff every game cycle, it is a heavy process. This is just an example!
	if(this->showAdditionalDetails)
	{
		ParticlesState::showAdditionalDetails(this);
	}
}

void ParticlesState::processUserInput(const UserInput* userInput)
{
	// Check for UserInput and key definitions in KeypadManager.h
	if(!(K_PWR & userInput->releasedKey))
	{
		if(K_LL & userInput->releasedKey)
		{
			if(kParticleNoTypeStart >= --this->particlesType)
			{
				this->particlesType = kParticleNoTypeEnd - 1;
			}

			ParticlesState::show(this, true);
			
			return;
		}
		else if(K_LR & userInput->releasedKey)
		{
			if(kParticleNoTypeEnd <= ++this->particlesType)
			{
				this->particlesType = kParticleNoTypeStart + 1;
			}

			ParticlesState::show(this, true);

			return;
		}
	}

	Base::processUserInput(this, userInput);
}

void ParticlesState::showControls()
{
	Printing::text(Printing::getInstance(), __CHAR_SELECT_BUTTON, __SCREEN_WIDTH_IN_CHARS - 1, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_RIGHT, __SCREEN_WIDTH_IN_CHARS - 4, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
	Printing::text(Printing::getInstance(), __CHAR_L_D_PAD_LEFT, __SCREEN_WIDTH_IN_CHARS - 5, __SCREEN_HEIGHT_IN_CHARS - 1, NULL);
}

void ParticlesState::showStuff()
{
	ParticlesState::loadParticles(this);
}

void ParticlesState::showExplanation()
{
	if(!isDeleted(this->particleSystem))
	{
		int16 y = 3;
		Printing::text(Printing::getInstance(), "CONCEPTS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "Particle systems", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "Particle types", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "Particle specs", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "CLASSES", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "Particle", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "ParticleSystem", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "PhysicalParticle", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "SolidParticle", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "METHODS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "ParticlesState", 1, y++, NULL);
		Printing::text(Printing::getInstance(), " loadParticles", 1, y++, NULL);
		Printing::text(Printing::getInstance(), " processUserInput", 1, y++, NULL);
		y++;
		Printing::text(Printing::getInstance(), "SPECS", 1, y++, "Debug");
		Printing::text(Printing::getInstance(), "*StarParticle", 1, y++, NULL);
		Printing::text(Printing::getInstance(), "*StarsParticleSystem*", 1, y++, NULL);

		y = 3;
		Printing::text(Printing::getInstance(), __GET_CLASS_NAME(this->particleSystem), 28, y++, NULL);

		switch(this->particlesType)
		{
			case kParticleNormal:

				Printing::text(Printing::getInstance(), "Type: Normal", 28, y, NULL);
				break;

			case kParticlePhysical:

				Printing::text(Printing::getInstance(), "Type: Physical", 28, y, NULL);
				break;

			case kParticleSolid:

				Printing::text(Printing::getInstance(), "Type: Solid", 28, y, NULL);
				break;
		}
	}	
}

void ParticlesState::showAdditionalDetails()
{
	ParticlesState::showParticleDetails(this);
}

void ParticlesState::showParticleDetails()
{
	if(!isDeleted(this->particleSystem))
	{
		ParticleSystem::print(this->particleSystem, 1, 3);
	}
}

void ParticlesState::loadParticles()
{
	// Check these specifications in assets/images/CogWheel/Spec/CogWheelSpec.c		
	extern ParticleSystemSpec NormalStarsParticleSystem;
	extern ParticleSystemSpec PhysicalStarsParticleSystem;
	extern ParticleSystemSpec SolidStarsParticleSystem;

	ParticleSystemSpec* particleSystemEntitySpec = NULL;
	int16 yPosition = 0;

	switch(this->particlesType)
	{
		case kParticleNormal:

			particleSystemEntitySpec = &NormalStarsParticleSystem;
			yPosition = -16;
			break;

		case kParticlePhysical:

			particleSystemEntitySpec = &PhysicalStarsParticleSystem;
			yPosition = -8;
			break;

		case kParticleSolid:

			particleSystemEntitySpec = &SolidStarsParticleSystem;
			yPosition = -8;
			break;
	}

	// Don't create Particles directly
	this->particleSystem = ParticleSystem::safeCast(Stage::getChildByName(this->stage, "Stars", false));

	NM_ASSERT(!isDeleted(this->particleSystem), "ParticlesState::loadParticles: stars not found");

	if(!isDeleted(this->particleSystem))
	{
		ParticleSystem::setParticleSystemSpec(this->particleSystem, particleSystemEntitySpec, true);

		Vector3D position = Vector3D::getFromPixelVector((PixelVector){__HALF_SCREEN_WIDTH / 2, yPosition, 16, 0});
		ParticleSystem::setLocalPosition(this->particleSystem, &position);

		ParticleSystem::start(this->particleSystem);
	}

	ParticlesState::showHeader(this);
}

