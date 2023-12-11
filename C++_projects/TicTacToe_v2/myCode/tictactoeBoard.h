/*
 * tictactoeBoard.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef TICTACTOEBOARD_H_
#define TICTACTOEBOARD_H_

#include "board.h"
/*!
 * Class created to encapsulate all data and functions related to
 * Tictactoe Board inherited from the board class
 * Eg. TTTBoard_Trace()
 */
class tictactoeBoard: public board
{
private:
	Field_t m_ActivePlayer;
	Field_t m_OppositePlayer;
public:
	/*!
	 * Constructor to initialise tictactoeBoard
	 * @param none
	 * @return none
	 */
	tictactoeBoard();

	/*!
	 * Destructor to de-initialise tictactoeBoard
	 * @param none
	 * @return none
	 */
	virtual ~tictactoeBoard();

	/*!
	 * TicTacToe Board specific method. It will trace right or up, diagonal_v1 and diagonal_v2
	 * based on the parameters given
	 * @param Field_t Player - Consider the player info to trace the board
	 * @param uint16_t start_index- Start tracing from this index value
	 * @param sint8_t row_delta, sint8_t col_delta- row/col increment/decrement to trace right or up
	 * Eg. 0,1 means row is unchanged and col is increased by 1 making the tracing to move right.
	 * Expected values are: 0,1 - Right; 1,0 - Up;
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TTTBoard_Trace(Field_t Player, uint16_t start_index, sint8_t row_delta, sint8_t col_delta);

	/*!
	 * Method which queries the board to count the winning condition
	 * @param Field_t Player - Consider the player info to check
	 * @return int - return 1 if the m_ActivePlayer wins
	 * return 0 when all places are filled with non EMPTY field (Draw condition)
	 */
	int TTTBoard_CountWin(Field_t Player);

	/*!
	 * Set the Active Player of the game
	 * @param PLAYER_t player - IN Player type to be set
	 * @return RC_SUCCESS returned if all okay
	 */
	RC_t setActivePlayer(Field_t player);

	/*!
	 * Get the Active Player of the game
	 * @param PLAYER_t player[2] - OUT read the activeplayer info
	 * @return RC_SUCCESS returned if all okay
	 */
	RC_t getActivePlayer(Field_t player[2]);
};

#endif /* TICTACTOEBOARD_H_ */
