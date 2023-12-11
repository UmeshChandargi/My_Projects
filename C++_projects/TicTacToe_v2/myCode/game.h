/*
 * game.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef GAME_H_
#define GAME_H_

#include "tictactoeBoard.h"
#include "player.h"
#include "screen.h"

//!ENUM defined to mention Game players of the TicTacToe game
typedef enum{
	NOPLAYER,
	HUMAN,
	COMPUTER
}GAMEPlayer_t;

/*!
 * Class created to encapsulate all data and functions related to
 * TicTacToe game logic
 * Eg. run()
 */
class game
{
private:
	tictactoeBoard m_board;
	player* m_GamePlayers[2];
	screen m_screen;
	GAMEPlayer_t m_GamePlayer1;
	GAMEPlayer_t m_GamePlayer2;
public:
	/*!
	 * Constructor to initialise the game class and screen board pointer
	 * @param none
	 * @return none
	 */
	game();

	/*!
	 * Method to run Tictactoe game in a infinite loop
	 * @param none
	 * @return none
	 */
	void run();

	/*!
	 * Destructor for the game class
	 * @param none
	 * @return none
	 */
	virtual ~game();
private:
	/*!
	 * Check if the game is WON or DRAWN
	 * @param none
	 * @return bool - returns true if the game is WON or DRAW
	 */
	bool GameLogicCheckWinCondition();

	/*!
	 * Method which implements polymorphism where the pointer of the base class
	 * player is assigned child class humanPlayer or computerPlayer based on the
	 * user selection.It also saves player info in members m_GamePlayer1 and m_GamePlayer2
	 * @param uint16_t val[2] - IN user selection info
	 * containing which set of players are selected
	 * @return none
	 */
	void setPlayers(uint16_t val[2]);

	/*!
	 * Play the game for Player1. Depending on Human or Computer player, it calls
	 * the logic of the respective player.
	 * @param GAMEPlayer_t player - IN Contains Human or Computer player info
	 * @return none
	 */
	void GamePlayer1(GAMEPlayer_t player);

	/*!
	 * Play the game for Player2. Depending on Human or Computer player, it calls
	 * the logic of the respective player.
	 * @param GAMEPlayer_t player - IN Contains Human or Computer player info
	 * @return none
	 */
	void GamePlayer2(GAMEPlayer_t player);

	/*!
	 * Read the index from human player. Also contains the error handling if human
	 * enters index where player is already present
	 * @param uint16_t& index - OUT index info which is read from the human
	 * @return none
	 */
	void GameReadIndex(uint16_t& index);


};

#endif /* GAME_H_ */
