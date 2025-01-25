/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_H_
#define PONG_H_

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// INCLUDES
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include <ListenerObject.h>

#include <KeypadManager.h>
#include <PongBall.h>
#include <Stage.h>
#include <VirtualList.h>

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' MACROS
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#define PONG_BALL_NAME "PongBL"
#define PADDLE_LEFT_NAME  "LeftPD"
#define PADDLE_RIGHT_NAME "RightPD"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Possible number of players
/// @memberof Pong
enum PlayerNumbers
{
	kPlayerAlone = 0,
	kPlayerOne,
	kPlayerTwo
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class Pong
///
/// Inherits from ListenerObject
///
/// Implements the logic of a simple pong game.
singleton class Pong : ListenerObject
{
	/// The pong ball
	PongBall pongBall;

	/// List of paddles
	VirtualList playerPaddles;

	/// List of opponent's paddles
	VirtualList opponentPaddles;

	/// Score for the left player
	uint32 leftScore;

	/// Score for the right player
	uint32 rightScore;

	/// This game instance's player number
	int playerNumber;

	/// Message to send to the other system
	uint32 messageForRemote;

	/// True if the state is in versus mode; false otherwise
	bool isVersusMode;

	/// Flag to allor/prevent the movement of the paddle
	bool allowPaddleMovement;

	/// Keypad combiation hold by the remote player
	uint16 remoteHoldKey;

	/// Process an event that the instance is listen for.
	/// @param eventFirer: ListenerObject that signals the event
	/// @param eventCode: Code of the firing event
	/// @return False if the listener has to be removed; true to keep it
	override bool onEvent(ListenerObject eventFirer, uint16 eventCode);

	/// Make the pong game ready to start.
	/// @param stage: Current state on which the pong game is played
	/// @param isVersusMode: If true, communications with another system are up
	void getReady(Stage stage, bool isVersusMode);

	/// Check if the game state is in versus mode.
	/// @return True if the state is in versus mode; false otherwise
	bool isVersusMode();

	/// Process the provided user input.
	/// @param userInput: Struct with the current user input information
	void processUserInput(const UserInput* userInput);

	/// Retrieve the player number of this instance.
	/// @return The player number of this game instance
	int getPlayerNumber();

	/// Printer the current score.
	void printScore();
}

#endif
