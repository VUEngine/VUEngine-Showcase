/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_H_
#define PONG_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ListenerObject.h>

#include <KeypadManager.h>
#include <PongBall.h>
#include <Stage.h>
#include <VirtualList.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S ENUMS
//---------------------------------------------------------------------------------------------------------

enum PlayerNumbers
{
	kPlayerAlone = 0,
	kPlayerOne,
	kPlayerTwo
};

typedef struct CondensedUserInput
{
	/// Currently pressed key(s)
	uint16 pressedKey;
	/// Released key(s)
	uint16 releasedKey;
	/// Held key(s)
	uint16 holdKey;

} CondensedUserInput;


typedef struct RemotePlayerData
{
	uint32 command;

	//Vector3D ballLocalPosition;
	CondensedUserInput condensedUserInput;

} RemotePlayerData;

//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class Pong : ListenerObject
{
	PongBall pongBall;
	VirtualList playerPaddles;
	VirtualList opponentPaddles;
	uint32 leftScore;
	uint32 rightScore;
	int playerNumber;
	uint32 messageForRemote;

	static Pong getInstance();

	void processUserInput(const UserInput* userInput);
	void printScore();
	int getPlayerNumber();
	void getReady(Stage stage, bool isVersusMode);
}



#endif
