/*
 * CReversiConsoleView.h
 *
 *  Created on: 02-Nov-2023
 *      Author: umesh
 */

#ifndef CREVERSICONSOLEVIEW_H_
#define CREVERSICONSOLEVIEW_H_
#include "CReversiBoard.h"
class CReversiConsoleView
{
private:
	CReversiBoard* m_ReversiBoard;
public:
	/*!
	 * Constructor for the class CReversiConsoleView to Initialize the members
	 * @param CReversiBoard* ReversiBoard- [IN] pointer to an instance of ReversiBoard
	 * @return none
	 */
	CReversiConsoleView(CReversiBoard* ReversiBoard);

	/*!
	 * Method Gets the state of the field of the Reversi board
	 * and prints the board to the console
	 * @param none
	 * @return bool- returns 1 when GameOver condition occurs else return value is 0
	 */
	bool print();
};

#endif /* CREVERSICONSOLEVIEW_H_ */
