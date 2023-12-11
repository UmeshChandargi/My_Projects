/*
 * screen.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include "tictactoeBoard.h"

/*!
 * Class created to encapsulate all data and functions related to
 * Display of the game
 * Eg. PrintBoard()
 */
class screen
{
private:
	tictactoeBoard *m_pBoard;
public:
	/*!
	 * Constructor to initialise the board pointer
	 * created in game (Association relation)
	 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
	 * @return none
	 */
	screen(tictactoeBoard *pBoard);

	/*!
	 * Print the TicTacToe board on the Console
	 * @param none
	 * @return none
	 */
	void PrintBoard();

	/*!
	 * Print any message on the Console
	 * @param string message - IN message string to be printed on the console
	 * @return none
	 */
	void PrintMessage(std::string message);

	/*!
	 * Read any uint16_t number from the Console
	 * @param uint16_t& number - OUT number read from the console
	 * @return none
	 */
	void ReadNum(uint16_t& number);
};

#endif /* SCREEN_H_ */
