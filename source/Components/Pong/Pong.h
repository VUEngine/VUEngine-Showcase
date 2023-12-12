/**
 * SPONG
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PLAYER_H_
#define PLAYER_H_


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <ListenerObject.h>
#include <PongBall.h>
#include <Stage.h>


//---------------------------------------------------------------------------------------------------------
//											CLASS'S ENUMS
//---------------------------------------------------------------------------------------------------------

enum PlayerNumbers
{
	kPlayerAlone = 0,
	kPlayerOne,
	kPlayerTwo
};


//---------------------------------------------------------------------------------------------------------
//											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class Pong : ListenerObject
{
	/* spec pointer */
	PongBall pongBall;
	VirtualList playerPaddles;
	VirtualList opponentPaddles;
	uint32 leftScore;
	uint32 rightScore;
	int playerNumber;

	static Pong getInstance();

	void printScore();
	int getPlayerNumber();
	void getReady(Stage stage);
}



#endif
