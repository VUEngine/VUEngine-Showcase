/*
 * VUEngine Showcase
 *
 * © Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <c.radke@posteo.de>
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef PONG_MANAGER_H_
#define PONG_MANAGER_H_

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

#define PONG_BALL_NAME	  "PongBL"
#define PADDLE_LEFT_NAME  "LeftPD"
#define PADDLE_RIGHT_NAME "RightPD"

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DATA
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Possible number of players
/// @memberof PongManager
enum PlayerNumbers
{
	kPlayerAlone = 0,
	kPlayerOne,
	kPlayerTwo
};

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
// CLASS' DECLARATION
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

/// Class PongManager
///
/// Inherits from ListenerObject
///
/// Implements the logic of a simple pong game.
class PongManager : ListenerObject
{
	/// The game stage
	Stage stage;

	/// Score for the left player
	uint32 leftScore;

	/// Score for the right player
	uint32 rightScore;

	/// This game instance's player number
	int playerNumber;

	/// Message to send to the other system
	uint32 messageForRemote;

	/// Flag to allor/prevent the movement of the paddle
	bool allowPaddleMovement;

	/// Keypad combiation hold by the remote player
	uint16 remoteHoldKey;

	/// Class' constructor
	/// @param stage: The stage where the actors are instantiated
	void constructor(Stage stage);

	/// Process an event that the instance is listen for.
	/// @param eventFirer: ListenerObject that signals the event
	/// @param eventCode: Code of the firing event
	/// @return False if the listener has to be removed; true to keep it
	override bool onEvent(ListenerObject eventFirer, uint16 eventCode);

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
