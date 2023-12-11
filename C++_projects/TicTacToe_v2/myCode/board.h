/*
 * board.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "global.h"

//! ENUM type which defines the Board position states
typedef enum{
	EMPTY,
	PLAYER1,
	PLAYER2,
	VALID,
}Field_t;

/*!
 * Class created to encapsulate all data and functions related to
 * Board model for any Board game
 * Eg. calculateIndex()
 */
class board
{
private:
	Field_t *m_pBoard;
protected:
	uint16_t m_MaxRow;
	uint16_t m_MaxCol;
	uint16_t m_MaxIndex;
public:
	/*!
	 * Constructor to initialise Board for any Board game
	 * @param uint16_t row=3, uint16_t col=3 - IN Row and column information passed as
	 * parameter during object creation. It is set to 3X3 as default
	 * @return none
	 */
	board(uint16_t row=3, uint16_t col=3);

	/*!
	 * Calculating Index of a position using row and col info in the board
	 * @param uint16_t row, uint16_t col- IN Row and column information at the position
	 * @return uint16_t- returns calculated index
	 */
	uint16_t calculateIndex(uint16_t row, uint16_t col);

	/*!
	 * Calculating Row and Column using Index info of a position in the board
	 * @param uint16_t Index - IN Index of the position in the board
	 * @param uint16_t& row, uint16_t& col- OUT Calculated Row and column
	 * @return RC_SUCCESS if all okay
	 */
	RC_t calculateRowCol(uint16_t Index, uint16_t& row, uint16_t& col);

	/*!
	 * Set the field in the board
	 * @param uint16_t index - IN Index of the Board
	 * @param Field_t state - IN Value to be set
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t SetFieldState(uint16_t index, Field_t state);

	/*!
	 * Returns the state of the field based on the index of the board
	 * @param uint16_t index - IN Index of the Board
	 * @return Field_t - return the state of the field
	 */
	Field_t GetFieldState(uint16_t index);

	/*!
	 * Returns the max row and col value of the board
	 * @param uint16_t& row, uint16_t& col- OUT Row and column value
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t GetMaxRowCol(uint16_t& row, uint16_t& col);

	/*!
	 * Returns the max Index of the board
	 * @param none
	 * @return uint16_t - return MaxIndex value
	 */
	uint16_t GetMaxIndex();

	/*!
	 * Destructor for the Board class
	 * @param none
	 * @return none
	 */
	virtual ~board();
};

#endif /* BOARD_H_ */
