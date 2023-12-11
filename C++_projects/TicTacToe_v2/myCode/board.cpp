/*
 * board.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#include <iostream>
#include "board.h"

using namespace std;

/*!
 * Constructor to initialise Board for any Board game
 * @param uint16_t row=3, uint16_t col=3 - IN Row and column information passed as
 * parameter during object creation. It is set to 3X3 as default
 * @return none
 */
board::board(uint16_t max_row, uint16_t max_col)
{
	if(max_row>0 || max_col>0)
	{
		m_MaxRow= max_row;
		m_MaxCol=max_col;
		m_MaxIndex= max_row*max_col;
		m_pBoard= new Field_t[m_MaxIndex];
		for (int i=0;i<m_MaxIndex;i++)
		{
			m_pBoard[i] = EMPTY;
		}
	}
	else
	{
		cerr<<"Board creation: Row and Column value must be non zero";
	}
}

/*!
 * Calculating Index of a position using row and col info in the board
 * @param uint16_t row, uint16_t col- IN Row and column information at the position
 * @return uint16_t- returns calculated index
 */
uint16_t board::calculateIndex(uint16_t row, uint16_t col)
{
	uint16_t result=0;
	result= row * m_MaxCol + col;
	return result;
}

/*!
 * Calculating Row and Column using Index info of a position in the board
 * @param uint16_t Index - IN Index of the position in the board
 * @param uint16_t& row, uint16_t& col- OUT Calculated Row and column
 * @return RC_SUCCESS if all okay
 */
RC_t board::calculateRowCol(uint16_t Index, uint16_t &row, uint16_t &col)
{
	if(m_MaxCol==0)
	{
		return RC_ERROR;
	}
	row= Index / m_MaxCol;
	col= Index % m_MaxRow;
	return RC_SUCCESS;
}

/*!
 * Set the field in the board
 * @param uint16_t index - IN Index of the Board
 * @param Field_t state - IN Value to be set
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t board::SetFieldState(uint16_t index, Field_t state)
{
	if(index >=0 && index<m_MaxIndex)
	{
		m_pBoard[index]= state;
	}

	return RC_SUCCESS;
}

/*!
 * Returns the state of the field based on the index of the board
 * @param uint16_t index - IN Index of the Board
 * @return Field_t - return the state of the field
 */
Field_t board::GetFieldState(uint16_t index)
{
	if(index >=0 && index<m_MaxIndex)
	{
		return m_pBoard[index];
	}
	else
	{
		return EMPTY;
	}
}

/*!
 * Returns the max row and col value of the board
 * @param uint16_t& row, uint16_t& col- OUT Row and column value
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t board::GetMaxRowCol(uint16_t &row, uint16_t &col)
{
	row= m_MaxRow;
	col=m_MaxCol;
	return RC_SUCCESS;
}

/*!
 * Returns the max Index of the board
 * @param none
 * @return uint16_t - return MaxIndex value
 */
uint16_t board::GetMaxIndex()
{
	return m_MaxIndex;
}

/*!
 * Destructor for the Board class
 * @param none
 * @return none
 */
board::~board()
{
	// TODO Auto-generated destructor stub
	delete[] m_pBoard;
}
