/*
 * computerPlayer.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */
#include <iostream>
#include "computerPlayer.h"
using namespace std;

/*!
 * Constructor to initialise the board pointer
 * created in game (Association relation)
 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
 * @return none
 */
computerPlayer::computerPlayer(tictactoeBoard *pBoard): player(pBoard)
{
	// TODO Auto-generated constructor stub
}

/*!
 * Destructor to de-initialise computerPlayer class
 * @param none
 * @return none
 */
computerPlayer::~computerPlayer()
{
	// TODO Auto-generated destructor stub
}

/*!
 * Method which implements logic needed for Computer Player type of the game
 * @param uint16_t index - IN index will be calculated by the
 * minimax algorithm. Therefore dummy param created in order to be consistent
 * with the pure virtual method created in the base class
 * @param Field_t Player - IN Consider the player info to check
 * @return none
 */
void computerPlayer::logic(uint16_t index, Field_t player)
{
	index= MinMaxOptimalPosition(player);
	m_pBoard->SetFieldState(index, player);
}


/*!
 * Method to find the best position for the computer player
 * while playing tictactoe game. It uses the Man MiniMax algorithm
 * @param Field_t Player - IN Player info needed to calculate score
 * @return uint16_t- returns the best position(Winning or defending)
 * index of the tictactoe board
 */
uint16_t computerPlayer::MinMaxOptimalPosition(Field_t player)
{
	int oldval=-1000;
	int best=0;
	uint16_t idx=0;
	for(int i=0;i<m_pBoard->GetMaxIndex();i++)
	{
		if(m_pBoard->GetFieldState(i)== EMPTY)
		{
			m_pBoard->SetFieldState(i,player);

			best = MinMaxAlgo(player, false);

			//!undo the move
			m_pBoard->SetFieldState(i,EMPTY);
			if(best > oldval)
			{
				idx=i;
				oldval= best;
			}
		}
	}
	return idx;
}

/*!
 * Main MinMax Algorithm implementation
 * @param Field_t Player - IN Player info needed to calculate score
 * @param bool MaxPl- IN Selecting between Maximizing or minimizing player
 * @return int- returns max or min score
 */
int computerPlayer::MinMaxAlgo(Field_t Player, bool MaxPl)
{
	int score = MinMaxGetScore(Player);

	if(score!=0)
	{
		//Game win
		return score;
	}

	//Draw game
	if(m_pBoard->TTTBoard_CountWin(Player)== -1)
	{
		return 0;
	}

	Field_t readActivePlayer[2];
	m_pBoard->getActivePlayer(readActivePlayer);

	if(MaxPl)
	{
		int best =-1000;
		Player= readActivePlayer[0];
		for(int i=0;i<m_pBoard->GetMaxIndex();i++)
		{
			if(m_pBoard->GetFieldState(i)== EMPTY)
			{
				m_pBoard->SetFieldState(i,Player);
				best = max(best, MinMaxAlgo(Player, !MaxPl));
				//!undo the move
				m_pBoard->SetFieldState(i,EMPTY);
			}
		}
		return best;
	}
	else
	{
		int best =1000;
		Player= readActivePlayer[1];
		for(int i=0;i<m_pBoard->GetMaxIndex();i++)
		{
			if(m_pBoard->GetFieldState(i)== EMPTY)
			{
				m_pBoard->SetFieldState(i,Player);
				best = min(best, MinMaxAlgo(Player, !MaxPl));
				//!undo the move
				m_pBoard->SetFieldState(i,EMPTY);
			}
		}
		return best;
	}
}

/*!
 * Calculates score based on Game state. WIN and ActivePlayer will get 10 points
 * WIN and OppositePlayer gets -10 points. otherwise the score will be 0
 * @param Field_t Player- IN player info
 * @return int - returns calculated score (0,10,-10)
 */
int computerPlayer::MinMaxGetScore(Field_t Player)
{
	int ret = m_pBoard->TTTBoard_CountWin(Player);
	if(ret== 1)
	{
		Field_t readActivePlayer[2];
		m_pBoard->getActivePlayer(readActivePlayer);
		if(Player== readActivePlayer[1])
		{
			return -10;
		}
		if(Player== readActivePlayer[0])
		{
			return 10;
		}
	}
	return 0;
}



