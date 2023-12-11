/*
 * tictactoeBoard.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#include "tictactoeBoard.h"

/*!
 * Constructor to initialise tictactoeBoard
 * @param none
 * @return none
 */
tictactoeBoard::tictactoeBoard(): board(3,3)
{
	// TODO Auto-generated constructor stub
	m_ActivePlayer = EMPTY;
	m_OppositePlayer = EMPTY;

}

/*!
 * Destructor to de-initialise tictactoeBoard
 * @param none
 * @return none
 */
tictactoeBoard::~tictactoeBoard()
{
	// TODO Auto-generated destructor stub
}


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
RC_t tictactoeBoard::TTTBoard_Trace(Field_t Player, uint16_t start_index, sint8_t row_delta,
		sint8_t col_delta)
{
	uint16_t row=0,col=0;
	uint16_t count=0;
	calculateRowCol(start_index, row, col);

	while(col<m_MaxCol && row<m_MaxRow)
	{
		uint16_t idx= calculateIndex(row, col);
		if(GetFieldState(idx)==Player)
		{
			count++;
		}
		if(count==m_MaxCol)
		{
			return RC_VALID;
		}
		row+=row_delta;
		col+=col_delta;

	}
	return RC_SUCCESS;
}

/*!
 * Method which queries the board to count the winning condition
 * @param Field_t Player - Consider the player info to check
 * @return int - return 1 if the m_ActivePlayer wins
 * return 0 when all places are filled with non EMPTY field (Draw condition)
 */
int tictactoeBoard::TTTBoard_CountWin(Field_t Player)
{
	for(uint16_t index=0;index<m_MaxIndex;index++)
	{
		//!/********** Trace each row    ****************/
		if(TTTBoard_Trace(Player,index, 0, 1)==RC_VALID)
		{
			return 1;
		}

		//!/********** Trace each column    ****************/
		if(TTTBoard_Trace(Player,index, 1, 0)==RC_VALID)
		{
			return 1;
		}

		//!/********** Trace each Diagonal    ****************/
		if(TTTBoard_Trace(Player,index, 1, 1)==RC_VALID)
		{
			return 1;
		}

		//!/********** Trace each Diagonal_v2    ****************/
		if(TTTBoard_Trace(Player,index, 1, -1)==RC_VALID)
		{
			return 1;
		}
	}

	//!/********** draw condition  ****************/
	for(int i=0;i<m_MaxIndex;i++)
	{
		if(GetFieldState(i)==EMPTY)
		{
			break;
		}
		if(i==m_MaxIndex-1)
			return -1;
	}

	return 0;
}

/*!
 * Set the Active Player of the game
 * @param PLAYER_t player - IN Player type to be set
 * @return RC_SUCCESS returned if all okay
 */
RC_t tictactoeBoard::setActivePlayer(Field_t player)
{
	if(player == PLAYER1)
	{
		m_ActivePlayer= PLAYER1;
		m_OppositePlayer= PLAYER2;
	}
	else if(player == PLAYER2)
	{
		m_ActivePlayer= PLAYER2;
		m_OppositePlayer= PLAYER1;
	}
	return RC_SUCCESS;
}

/*!
 * Get the Active Player of the game
 * @param PLAYER_t player[2] - OUT read the activeplayer info
 * @return RC_SUCCESS returned if all okay
 */
RC_t tictactoeBoard::getActivePlayer(Field_t player[2])
{
	player[0]= m_ActivePlayer;
	player[1]= m_OppositePlayer;

	return RC_SUCCESS;
}
