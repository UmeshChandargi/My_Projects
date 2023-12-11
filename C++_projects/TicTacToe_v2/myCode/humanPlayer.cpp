/*
 * humanPlayer.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */
#include <iostream>
#include "humanPlayer.h"
using namespace std;

/*!
 * Constructor to initialise the board pointer
 * created in game (Association relation)
 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
 * @return none
 */
humanPlayer::humanPlayer(tictactoeBoard *pBoard): player(pBoard)
{
	// TODO Auto-generated constructor stub
}

/*!
 * Destructor to de-initialise humanPlayer class
 * @param none
 * @return none
 */
humanPlayer::~humanPlayer()
{
	// TODO Auto-generated destructor stub
}

/*!
 * Method which implements logic needed for Human Player type of the game
 * @param uint16_t index - IN index of the board where player has to play
 * @param Field_t Player - IN Consider the player info to check
 * @return none
 */
void humanPlayer::logic(uint16_t index, Field_t player)
{
	m_pBoard->SetFieldState(index, player);
}
