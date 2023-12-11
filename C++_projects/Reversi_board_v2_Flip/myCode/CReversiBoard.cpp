/*
 * CReversiBoard.cpp
 *
 *  Created on: 02-Nov-2023
 *      Author: umesh
 */

#include "CReversiBoard.h"
#include <iostream>
using namespace std;

/*!
 * Constructor for the class CReversiBoard to Initialize the members
 * @param none
 * @return none
 */
CReversiBoard::CReversiBoard()
{
	//!Initialize the ReversiBoard
	for(uint8_t i=0; i<8;i++)
	{
		for(uint8_t j=0; j<8;j++)
		{
			m_Board[i][j]= EMPTY;
		}
	}
	m_Board[3][3]= PLAYER1;
	m_Board[3][4]= PLAYER2;
	m_Board[4][3]= PLAYER2;
	m_Board[4][4]= PLAYER1;

	/***************   Test cases end ****************/
	//!Initialize Index
	m_index=0;
	m_ActivePlayer= EMPTY;
	m_OppositePlayer = EMPTY;
	m_GAMEOVER_Flag=0;
}


/*!
 * Method which queries the board to find where to put the next piece
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::GameLogicQueryNextPiece()
{
	uint8_t row=0,col=0;
	uint8_t Valid_col=0;
	uint8_t Flip_col=0;
	uint8_t Valid_row=0;
	uint8_t Flip_row=0;
	m_GAMEOVER_Flag=1;
	while(FindActivePlayerPawn(row,col,row,col)==RC_SUCCESS)
	{
		//!got row and col value where Activeplayer is present
		//!start tracing left, up,down
		//!set state to valid when trace is complete

		//!/***************   Start tracing right ****************/
		if(TraceRight(row, col, &Valid_col,&Flip_col)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(row,Valid_col, VALID);
		}


		/***************   End tracing right ****************/

		//!/***************   Start tracing left ****************/
		if(TraceLeft(row, col, &Valid_col,&Flip_col)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(row,Valid_col, VALID);
		}
		//!/***************   End tracing left ****************/

		/***************   Start tracing down ****************/
		if(TraceDown(row, col, &Valid_row,&Flip_row)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(Valid_row,col, VALID);
		}
		/***************   End tracing down ****************/

		/***************   Start tracing up ****************/
		if(TraceUp(row, col, &Valid_row,&Flip_row)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(Valid_row,col, VALID);
		}
		/***************   End tracing up ****************/

		/***************   Start tracing Diagonal down ****************/
		if(TraceDiagonalDown(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(Valid_row,Valid_col, VALID);
		}
		/***************   End tracing Diagonal down ****************/

		/***************   Start tracing Diagonal up ****************/
		if(TraceDiagonalUp(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(Valid_row,Valid_col, VALID);
		}
		/***************   End tracing Diagonal up ****************/

		/***************   Start tracing Diagonal down v2 ****************/
		if(TraceDiagonalDown_v2(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(Valid_row,Valid_col, VALID);
		}
		/***************   End tracing Diagonal down v2 ****************/

		/***************   Start tracing Diagonal UP v2 ****************/
		if(TraceDiagonalUp_v2(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_VALID)
		{
			m_GAMEOVER_Flag=0;
			SetFieldState(Valid_row,Valid_col, VALID);
		}
		/***************   End tracing Diagonal UP v2 ****************/

		col++;
	}

	return RC_SUCCESS;
}


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
RC_t CReversiBoard::GameLogicFlipState(uint8_t row, uint8_t col)
{
	uint8_t Valid_row=0;
	uint8_t Valid_col=0;
	uint8_t Flip_col=0;
	uint8_t Flip_row=0;
	if(row>7 || col>7)
	{
		cout<<"Row and Column value exceeding the boundary of the board"<<endl;
		return RC_BADPARAM;
	}
	if(m_Board[row][col]!= VALID)
	{
		cout<<"Invalid Position! Please play again"<<endl;
		return RC_ERROR;
	}
	if(m_Board[row][col]== VALID)
	{
		//!Position is Valid
		cout<<"Position Valid!!. Flipping Position acc to game rules"<<endl;


		//!/***************   Start Flipping right ****************/
		if(TraceRight(row, col,&Valid_col,&Flip_col)== RC_FLIP)
		{
			for(uint8_t i=col;i<=Flip_col;i++)
			{
				m_Board[row][i]= m_ActivePlayer;
			}
		}
		//!/***************   End Flipping right ****************/

		//!/***************   Start Flipping Left ****************/
		if(TraceLeft(row, col,&Valid_col,&Flip_col)== RC_FLIP)
		{
			for(uint8_t i=Flip_col;i<=col;i++)
			{
				m_Board[row][i]= m_ActivePlayer;
			}
		}
		//!/***************   End Flipping Left ****************/

		//!/***************   Start Flipping Down ****************/
		if(TraceDown(row, col,&Valid_row,&Flip_row)== RC_FLIP)
		{
			for(uint8_t i=row;i<=Flip_row;i++)
			{
				m_Board[i][col]= m_ActivePlayer;
			}
		}
		//!/***************   End Flipping Down ****************/

		//!/***************   Start Flipping Upwards ****************/
		if(TraceUp(row, col,&Valid_row,&Flip_row)== RC_FLIP)
		{
			for(uint8_t i=Flip_row;i<=row;i++)
			{
				m_Board[i][col]= m_ActivePlayer;
			}
		}
		//!/***************   End Flipping Upwards ****************/

		//!/***************   Start Flipping Diagonal Down ****************/
		if(TraceDiagonalDown(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_FLIP)
		{
			uint8_t j= col;
			for(uint8_t i=row;i<=Flip_row;i++)
			{
				m_Board[i][j]= m_ActivePlayer;
				j++;
			}
		}
		//!/***************   End Flipping Diagonal Down ****************/

		//!/***************   Start Flipping Diagonal Upwards ****************/
		if(TraceDiagonalUp(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_FLIP)
		{
			uint8_t j= Flip_col;
			for(uint8_t i=Flip_row;i<=row;i++)
			{
				m_Board[i][j]= m_ActivePlayer;
				j++;
			}
		}
		//!/***************   End Flipping Diagonal Upwards ****************/

		//!/***************   Start Flipping Diagonal Down_v2 ****************/
		if(TraceDiagonalDown_v2(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_FLIP)
		{
			uint8_t j= col;
			for(uint8_t i=row;i<=Flip_row;i++)
			{
				m_Board[i][j]= m_ActivePlayer;
				j--;
			}
		}
		//!/***************   End Flipping Diagonal Down_v2 ****************/

		//!/***************   Start Flipping Diagonal Upwards_v2 ****************/
		if(TraceDiagonalUp_v2(row, col,&Valid_row, &Valid_col, &Flip_row, &Flip_col)== RC_FLIP)
		{
			uint8_t j= Flip_col;
			for(uint8_t i=Flip_row;i<=row;i++)
			{
				m_Board[i][j]= m_ActivePlayer;
				j--;
			}
		}
		//!/***************   End Flipping Diagonal Upwards_v2 ****************/

		//!/***************   Clear All VALID Places to EMPTY ****************/
		for(uint8_t i=0; i<8;i++)
		{
			for(uint8_t j=0; j<8;j++)
			{
				if(m_Board[i][j]== VALID)
				{
					m_Board[i][j]= EMPTY;
				}
			}
		}

	}
	return RC_SUCCESS;
}

/*!
 * Method contains the logic when the Reversi game over condition occurs
 * @param none
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::GameLogicGameOver()
{
	uint8_t Player1_count=0, Player2_count=0;
	for(uint8_t i=0; i<8;i++)
	{
		for(uint8_t j=0; j<8;j++)
		{

			switch(m_Board[i][j])
			{
			case PLAYER1:
			{
				Player1_count++;
			}
			break;
			case PLAYER2:
			{
				Player2_count++;
			}
			break;
			default:
			{
				//do nothing
			}
			}
		}
	}

	if(Player1_count> Player2_count)
	{
		cout<<"Player1 wins";
	}
	else if(Player1_count== Player2_count)
	{
		cout<<"Draw";
	}
	else
	{
		cout<<"Player2 wins";
	}

	return RC_SUCCESS;
}

/*!
 * Set the field in the board
 * @param uint8_t row, uint8_t col - IN Row and Column of the Reversi Board
 * @raram Field_t state - IN Value to be set
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::SetFieldState(uint8_t row, uint8_t col, Field_t state)
{
	if(row<8 && col<8)
	{
		m_Board[row][col]= state;
	}

	return RC_SUCCESS;
}

/*!
 * Returns the state of the field based on the index of the board
 * @param uint8_t index - IN Index of the Reversi Board
 * @return Field_t - return the state of the field
 */
Field_t CReversiBoard::GetFieldState(uint8_t index)
{
	if(index >=0 && index<64)
	{
		uint8_t row = index / 8;
		uint8_t col = index % 8;

		return m_Board[row][col];
	}
	else
	{
		return EMPTY;
	}

}

/*!
 * Returns the the GameOver flag value of the Reversi board
 * @param none
 * @return bool - return the GameOver flag value
 */
bool CReversiBoard::GetGameOverFlag()
{
	return m_GAMEOVER_Flag;
}

/*!
 * Sets the active Player(AP) and Opposite player(OP) of the game
 * @param Field_t Player - IN Player to be set
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::SetActivePlayer(Field_t Player)
{
	if(Player== PLAYER1)
	{
		m_ActivePlayer= PLAYER1;
		m_OppositePlayer = PLAYER2;
	}
	else if (Player== PLAYER2)
	{
		m_ActivePlayer= PLAYER2;
		m_OppositePlayer = PLAYER1;
	}
	else
	{
		//Invalid Player info
		return RC_BADPARAM;
	}

	return RC_SUCCESS;
}

/************************************ Helper functions ************************************/
/*!
 * Traverse the board to find Active player pawn
 * @param uint8_t startrow, uint8_t startcol- IN Start traversing the board from these values
 * @param uint8_t& row, uint8_t& col - OUT Row and Column info of the encountered Active Player
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::FindActivePlayerPawn(uint8_t startrow, uint8_t startcol, uint8_t& row, uint8_t& col)
{
	static uint8_t flag=0;
	if(startcol>7)
	{
		startrow++;
		startcol=0;
	}

	for(uint8_t i=startrow; i<8;i++)
	{
		for(uint8_t j=0; j<8;j++)
		{
			if(flag==0)
			{
				j+=startcol;
				flag=1;
			}
			if(m_Board[i][j]== m_ActivePlayer)
			{
				row=i;
				col=j;
				flag=0;
				return RC_SUCCESS;
			}
		}
	}

	flag=0;
	return RC_ERROR;
}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the right direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_col - OUT Column index which can be used to set the VALID state
 * @param uint8_t* Flip_col=0 - OUT (Optional Parameter) Column index which can be used for the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceRight(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_col, uint8_t* Flip_col)
{

	if(AP_col==7|| m_Board[AP_row][AP_col+1]== m_ActivePlayer || m_Board[AP_row][AP_col+1]== EMPTY)
	{
		//!skip tracing right
	}
	else if(m_Board[AP_row][AP_col+1]== m_OppositePlayer)
	{

		for(int i=AP_col+1; i<8;i++)
		{

			if(m_Board[AP_row][i]== EMPTY || m_Board[AP_row][i]== VALID)
			{
				//SetFieldState(AP_row,i, VALID);
				*Valid_col = i;

				return RC_VALID;
				//break;
			}
			else if(m_Board[AP_row][i]== m_ActivePlayer)
			{

				//printf("skipped tracing right v2: %d, %d\n", AP_row,i);
				*Flip_col= i;

				return RC_FLIP;
				//break;
			}
		}
	}

	return RC_EMPTYBUFFER;
}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the left direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_col - OUT Column index which can be used to set the VALID state
 * @param uint8_t* Flip_col=0 - OUT (Optional Parameter) Column index which can be used for the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceLeft(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_col, uint8_t* Flip_col)
{
	if(AP_col==0 || m_Board[AP_row][AP_col-1]== m_ActivePlayer || m_Board[AP_row][AP_col-1]== EMPTY)
	{
		//!skip tracing left
		//printf("skipped tracing left %d, %d\n", AP_row,AP_col-1);
	}
	else if(m_Board[AP_row][AP_col-1]== m_OppositePlayer)
	{
		for(int i=AP_col-1; i>=0;i--)
		{
			//printf("\n left loop %d", i);
			if(m_Board[AP_row][i]== EMPTY || m_Board[AP_row][i]== VALID)
			{
				//SetFieldState(AP_row,i, VALID);
				*Valid_col = i;
				return RC_VALID;
				//break;
			}
			else if(m_Board[AP_row][i]== m_ActivePlayer)
			{
				//printf("skipped tracing left v2: %d, %d\n", AP_row,i);
				*Flip_col= i;

				return RC_FLIP;
				//break;
			}
		}
	}
	return RC_SUCCESS;
}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the down direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_row - OUT Row index which can be used to set the VALID state
 * @param uint8_t* Flip_row - OUT Row index which that should be used for the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceDown(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Flip_row)
{
	if(AP_row==7 || m_Board[AP_row+1][AP_col]== m_ActivePlayer || m_Board[AP_row+1][AP_col]== EMPTY)
	{
		//!skip tracing down
	}
	else if(m_Board[AP_row+1][AP_col]== m_OppositePlayer)
	{
		for(int i=AP_row+1; i<8;i++)
		{
			if(m_Board[i][AP_col]== EMPTY || m_Board[i][AP_col]== VALID)
			{
				*Valid_row= i;
				return RC_VALID;
			}
			else if(m_Board[i][AP_col]== m_ActivePlayer)
			{
				*Flip_row= i;
				return RC_FLIP;
			}
		}
	}
	return RC_SUCCESS;
}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the Upward direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_row - OUT Row index which can be used to set the VALID state
 * @param uint8_t* Flip_row - OUT Row index which that should be used for the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceUp(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Flip_row)
{
	if(AP_row==0 || m_Board[AP_row-1][AP_col]== m_ActivePlayer || m_Board[AP_row-1][AP_col]== EMPTY)
	{
		//!skip tracing up
	}
	else if(m_Board[AP_row-1][AP_col]== m_OppositePlayer)
	{
		for(int i=AP_row-1; i>=0;i--)
		{
			if(m_Board[i][AP_col]== EMPTY || m_Board[i][AP_col]== VALID)
			{
				*Valid_row= i;
				return RC_VALID;
			}
			else if(m_Board[i][AP_col]== m_ActivePlayer)
			{
				*Flip_row= i;
				return RC_FLIP;
			}
		}
	}
	return RC_SUCCESS;

}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the Diagonal Down direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceDiagonalDown(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Valid_col,
		uint8_t* Flip_row, uint8_t* Flip_col)
{
	if(AP_row==7 || AP_col==7 || m_Board[AP_row+1][AP_col+1]== m_ActivePlayer
			|| m_Board[AP_row+1][AP_col+1]== EMPTY)
	{
		//!skip tracing DiagonalDown
	}
	else if(m_Board[AP_row+1][AP_col+1]== m_OppositePlayer)
	{
		for(int i=AP_row+1; i<8;i++)
		{
			AP_col++;
			if(AP_col>7)
			{
				break;
			}
			if(m_Board[i][AP_col]== EMPTY || m_Board[i][AP_col]== VALID)
			{
				*Valid_row= i;
				*Valid_col= AP_col;
				return RC_VALID;
			}
			else if(m_Board[i][AP_col]== m_ActivePlayer)
			{
				*Flip_row= i;
				*Flip_col= AP_col;
				return RC_FLIP;
			}
		}
	}
	return RC_SUCCESS;

}


/*!
 * After finding active player pawn,
 * this method is used to trace the board in the Diagonal Upward direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceDiagonalUp(uint8_t AP_row, uint8_t AP_col, uint8_t* Valid_row, uint8_t* Valid_col,
		uint8_t* Flip_row, uint8_t* Flip_col)
{
	if(AP_row==0 || AP_col==0 || m_Board[AP_row-1][AP_col-1]== m_ActivePlayer
			|| m_Board[AP_row-1][AP_col-1]== EMPTY)
	{
		//!skip tracing DiagonalUp
	}
	else if(m_Board[AP_row-1][AP_col-1]== m_OppositePlayer)
	{
		for(int i=AP_row-1; i>=0;i--)
		{
			if(AP_col==0)
			{
				break;
			}
			AP_col--;
			if(m_Board[i][AP_col]== EMPTY || m_Board[i][AP_col]== VALID)
			{
				*Valid_row= i;
				*Valid_col= AP_col;
				return RC_VALID;
			}
			else if(m_Board[i][AP_col]== m_ActivePlayer)
			{
				*Flip_row= i;
				*Flip_col= AP_col;
				return RC_FLIP;
			}
		}
	}
	return RC_SUCCESS;

}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the Diagonal Down direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceDiagonalDown_v2(uint8_t AP_row, uint8_t AP_col,
		uint8_t *Valid_row, uint8_t *Valid_col, uint8_t *Flip_row,
		uint8_t *Flip_col)
{
	if(AP_row==7 || AP_col==0 || m_Board[AP_row+1][AP_col-1]== m_ActivePlayer
			|| m_Board[AP_row+1][AP_col-1]== EMPTY)
	{
		//!skip tracing DiagonalDown_v2
	}
	else if(m_Board[AP_row+1][AP_col-1]== m_OppositePlayer)
	{
		for(int i=AP_row+1; i<8;i++)
		{
			if(AP_col==0)
			{
				break;
			}
			AP_col--;
			if(m_Board[i][AP_col]== EMPTY || m_Board[i][AP_col]== VALID)
			{
				*Valid_row= i;
				*Valid_col= AP_col;
				return RC_VALID;
			}
			else if(m_Board[i][AP_col]== m_ActivePlayer)
			{
				*Flip_row= i;
				*Flip_col= AP_col;
				return RC_FLIP;
			}
		}
	}
	return RC_SUCCESS;

}

/*!
 * After finding active player pawn,
 * this method is used to trace the board in the Diagonal Upward direction
 * to find valid position for the active player
 * @param uint8_t AP_row, uint8_t AP_col - IN Row and Column position of Active Player
 * @param uint8_t* Valid_row, uint8_t* Valid_col - OUT Row and column index which need to be a VALID state
 * @param uint8_t* Flip_row, uint8_t* Flip_col  - OUT Row and column index which can be used the Flip logic
 * @return RC_SUCCESS - return RC_SUCCESS if all okay
 */
RC_t CReversiBoard::TraceDiagonalUp_v2(uint8_t AP_row, uint8_t AP_col,
		uint8_t *Valid_row, uint8_t *Valid_col, uint8_t *Flip_row,
		uint8_t *Flip_col)
{
	if(AP_row==0 || AP_col==7 || m_Board[AP_row-1][AP_col+1]== m_ActivePlayer
			|| m_Board[AP_row-1][AP_col+1]== EMPTY)
	{
		//!skip tracing DiagonalUp_v2
	}
	else if(m_Board[AP_row-1][AP_col+1]== m_OppositePlayer)
	{
		for(int i=AP_row-1; i>=0;i--)
		{
			AP_col++;
			if(AP_col>7)
			{
				break;
			}
			if(m_Board[i][AP_col]== EMPTY || m_Board[i][AP_col]== VALID)
			{
				*Valid_row= i;
				*Valid_col= AP_col;
				return RC_VALID;
			}
			else if(m_Board[i][AP_col]== m_ActivePlayer)
			{
				*Flip_row= i;
				*Flip_col= AP_col;
				return RC_FLIP;
			}
		}
	}
	return RC_SUCCESS;
}
