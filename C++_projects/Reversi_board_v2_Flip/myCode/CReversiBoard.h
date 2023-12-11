/*
 * CReversiBoard.h
 *
 *  Created on: 02-Nov-2023
 *      Author: umesh
 */

#ifndef CREVERSIBOARD_H_
#define CREVERSIBOARD_H_
#include "global.h"

//####################### Enumerations  #######################//
/**
 * Represents the state of the board, i.e. which fields are empty,
 * occupied with a piece with player 1 color up or occupied with player 2 color up
 */
typedef enum{
	EMPTY,
	PLAYER1,
	PLAYER2,
	VALID,
}Field_t;


class CReversiBoard
{
private:
	Field_t m_Board[8][8];
	uint8_t m_index;
	Field_t m_ActivePlayer;
	Field_t m_OppositePlayer;
	bool m_GAMEOVER_Flag;
public:
	/*!
	 * Constructor for the class CReversiBoard to Initialize the members
	 * @param none
	 * @return none
	 */
	CReversiBoard();

	/*!
	 * Method which queries the board to find where to put the next piece
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t GameLogicQueryNextPiece();

	/*!
	 * Method used for flipping the player pawn based on game logic,
	 *  i.e. putting a new piece on the board.
	 * This method must check that the move is valid
	 * (the piece may be put at the given location)
	 * and update the state of the board ("turn over" other pieces as required by the rules).
	 * @param uint8_t row, uint8_t col - IN Row and Column of the Reversi Board
	 * @raram Field_t state - IN Value to be set
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t GameLogicFlipState(uint8_t row, uint8_t col);

	/*!
	 * Method contains the logic when the Reversi game over condition occurs
	 * @param none
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t GameLogicGameOver();

	/*!
	 * Set the field in the board
	 * @param uint8_t row, uint8_t col - IN Row and Column of the Reversi Board
	 * @raram Field_t state - IN Value to be set
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t SetFieldState(uint8_t row, uint8_t col, Field_t state);

	/*!
	 * Returns the state of the field based on the index of the board
	 * @param uint8_t index - IN Index of the Reversi Board
	 * @return Field_t - return the state of the field
	 */
	Field_t GetFieldState(uint8_t index);

	/*!
	 * Returns the the GameOver flag value of the Reversi board
	 * @param none
	 * @return bool - return the GameOver flag value
	 */
	bool GetGameOverFlag();

	/*!
	 * Sets the active Player(AP) and Opposite player(OP) of the game
	 * @param Field_t Player - IN Player to be set
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t SetActivePlayer(Field_t Player);


	//!************************************ Helper functions ************************************/
	/*!
	 * Traverse the board to find Active player pawn
	 * @param uint8_t startrow, uint8_t startcol- IN Start traversing the board from these values
	 * @param uint8_t& row, uint8_t& col - OUT Row and Column info of the encountered Active Player
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t FindActivePlayerPawn(uint8_t startrow, uint8_t startcol, uint8_t& row, uint8_t& col);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the right direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_col - OUT Column index which can be used to set the VALID state
	 * @param uint8_t* Flip_col=0 - OUT (Optional Parameter) Column index which can be used for the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceRight(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_col, uint8_t* Flip_col=0);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the left direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_col - OUT Column index which can be used to set the VALID state
	 * @param uint8_t* Flip_col=0 - OUT (Optional Parameter) Column index which can be used for the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceLeft(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_col, uint8_t* Flip_col=0);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the down direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_row - OUT Row index which can be used to set the VALID state
	 * @param uint8_t* Flip_row - OUT Row index which that should be used for the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceDown(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Flip_row);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the Upward direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_row - OUT Row index which can be used to set the VALID state
	 * @param uint8_t* Flip_row - OUT Row index which that should be used for the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceUp(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Flip_row);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the Diagonal Down direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
	 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceDiagonalDown(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Valid_col,
			uint8_t* Flip_row, uint8_t* Flip_col);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the Diagonal Upward direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
	 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceDiagonalUp(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Valid_col,
			uint8_t* Flip_row, uint8_t* Flip_col);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the Diagonal Down direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
	 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceDiagonalDown_v2(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Valid_col,
			uint8_t* Flip_row, uint8_t* Flip_col);

	/*!
	 * After finding active player pawn,
	 * this method is used to trace the board in the Diagonal Upward direction
	 * to find valid position for the active player
	 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
	 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
	 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
	 * @return RC_SUCCESS - return RC_SUCCESS if all okay
	 */
	RC_t TraceDiagonalUp_v2(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Valid_col,
			uint8_t* Flip_row, uint8_t* Flip_col);


};

#endif /* CREVERSIBOARD_H_ */
