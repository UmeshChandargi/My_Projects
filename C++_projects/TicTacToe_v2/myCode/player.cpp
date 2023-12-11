/*
 * player.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#include "player.h"

/*!
 * Destructor to de-initialise player and
 * also the child classes created from this class
 * @param none
 * @return none
 */
player::~player()
{
	// TODO Auto-generated destructor stub
}

/*!
 * Constructor to initialise the board pointer
 * created in game (Association relation)
 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
 * @return none
 */
player::player(tictactoeBoard *pBoard)
{
	m_pBoard= pBoard;
}
