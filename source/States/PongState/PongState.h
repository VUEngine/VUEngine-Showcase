/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_STATE_H_
#define PONG_STATE_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ShowcaseState.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

typedef struct ResumedUserInput
{
	/// Currently pressed key(s)
	uint16 pressedKey;
	/// Released key(s)
	uint16 releasedKey;
	/// Held key(s)
	uint16 holdKey;

} ResumedUserInput;


typedef struct DataToTransmit
{
	//Vector3D ballLocalPosition;
	ResumedUserInput resumedUserInput;

} DataToTransmit;

singleton class PongState : ShowcaseState
{
	DataToTransmit opponentData;
	bool isVersusMode;

	static PongState getInstance();

	void setVersusMode(bool value);
	bool getVersusMode();

	override bool isVersusMode();
	override void enter(void* owner);
	override void exit(void* owner);
	override void processUserInput(const UserInput* userInput);
	override bool processUserInputRegardlessOfInput();

	ResumedUserInput getOpponentInput();
}



#endif
