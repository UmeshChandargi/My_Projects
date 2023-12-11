/*
 * CReversiConsoleView.cpp
 *
 *  Created on: 02-Nov-2023
 *      Author: umesh
 */

#include "CReversiConsoleView.h"
#include <iostream>
using namespace std;

/*!
 * Constructor for the class CReversiConsoleView to Initialize the members
 * @param CReversiBoard* ReversiBoard- [IN] pointer to an instance of ReversiBoard
 * @return none
 */
CReversiConsoleView::CReversiConsoleView(CReversiBoard *ReversiBoard)
{
	m_ReversiBoard = ReversiBoard;
}


/*!
 * Method Gets the state of the field of the Reversi board
 * and prints the board to the console
 * @param none
 * @return bool- returns 1 when GameOver condition occurs else return value is 0
 */
bool CReversiConsoleView::print()
{
	Field_t field;

	if(m_ReversiBoard->GetGameOverFlag()==1)
	{
		cout<<"Game Over!!"<<endl;
		m_ReversiBoard->GameLogicGameOver();
		return 1;
	}

	else
	{
		for(uint8_t i=0; i<8;i++)
		{
			for(uint8_t j=0; j<8;j++)
			{
				//Calculate Index
				uint8_t index = i*8 + j;

				field = m_ReversiBoard->GetFieldState(index);
				switch(field)
				{
				case EMPTY:
				{
					cout<<".	";
				}
				break;
				case PLAYER1:
				{
					cout<<"B	";
				}
				break;
				case PLAYER2:
				{
					cout<<"W	";
				}
				break;
				case VALID:
				{
					cout<<"x	";
				}
				break;
				}

			}
			cout<<endl;
		}
		return 0;
	}


}
