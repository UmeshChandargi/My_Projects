/*
 * humanPlayer.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "player.h"

/*!
 * Class created to encapsulate all data and functions related to
 * human player of TicTacToe game
 * Eg. logic()
 */
class humanPlayer : public player
{
public:
	/*!
	 * Constructor to initialise the board pointer
	 * created in game (Association relation)
	 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
	 * @return none
	 */
	humanPlayer(tictactoeBoard *pBoard);

	/*!
	 * Destructor to de-initialise humanPlayer class
	 * @param none
	 * @return none
	 */
	virtual ~humanPlayer();

	/*!
	 * Method which implements logic needed for Human Player type of the game
	 * @param uint16_t index - IN index of the board where player has to play
	 * @param Field_t Player - IN Consider the player info to check
	 * @return none
	 */
	void logic(uint16_t index, Field_t player);
};

#endif /* HUMANPLAYER_H_ */
