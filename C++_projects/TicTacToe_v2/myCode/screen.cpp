/*
 * screen.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */
#include <iostream>
#include "screen.h"
using namespace std;
/*!
 * Constructor to initialise the board pointer
 * created in game (Association relation)
 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
 * @return none
 */
screen::screen(tictactoeBoard *pBoard)
{
	m_pBoard= pBoard;
}


/*!
 * Print the TicTacToe board on the Console
 * @param none
 * @return none
 */
void screen::PrintBoard()
{
	uint16_t index=0,maxRow=0, maxCol=0;
	Field_t state= EMPTY;

	m_pBoard->GetMaxRowCol(maxRow,maxCol);

	for(int i =0; i<maxRow;i++)
	{
		for(int j=0; j<maxCol; j++)
		{
			index= m_pBoard->calculateIndex(i,j);
			state= m_pBoard->GetFieldState(index);
			switch(state)
			{
			case EMPTY:
			{
				cout<<". ";
			}
			break;

			case PLAYER1:
			{
				cout<<"x ";
			}
			break;

			case PLAYER2:
			{
				cout<<"o ";
			}
			break;

			case VALID:
			{
				cout<<"v ";
			}
			break;
			}
		}
		cout<<endl;

	}
}

/*!
 * Print any message on the Console
 * @param string message - IN message string to be printed on the console
 * @return none
 */
void screen::PrintMessage(std::string message)
{
	cout<<message<<endl;
}

/*!
 * Read any uint16_t number from the Console
 * @param uint16_t& number - OUT number read from the console
 * @return none
 */
void screen::ReadNum(uint16_t &number)
{
	cin>>number;
}
