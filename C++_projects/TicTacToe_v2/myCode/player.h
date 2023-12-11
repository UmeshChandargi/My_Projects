/*
 * player.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "global.h"
#include "tictactoeBoard.h"
/*!
 * Class created to encapsulate all data and functions related to
 * Players of TicTacToe game
 * Eg. logic()
 */
class player
{
protected:
	tictactoeBoard *m_pBoard;
public:
	/*!
	 * Constructor to initialise the board pointer
	 * created in game (Association relation)
	 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
	 * @return none
	 */
	player(tictactoeBoard *pBoard);

	/*!
	 * Destructor to de-initialise player and
	 * also the child classes created from this class
	 * @param none
	 * @return none
	 */
	virtual ~player();

	/*!
	 * Pure Virtual Method which implements logic needed for Player type of the game
	 * @param uint16_t index - IN index of the board where player has to play
	 * @param Field_t Player - IN Consider the player info to check
	 * @return none
	 */
	virtual void logic(uint16_t index, Field_t player)=0;

};

#endif /* PLAYER_H_ */
