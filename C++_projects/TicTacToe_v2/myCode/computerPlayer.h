/*
 * computerPlayer.h
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_
#include "player.h"

/*!
 * Class created to encapsulate all data and functions related to
 * computer player of TicTacToe game
 * Eg. logic()
 */
class computerPlayer: public player
{
public:
	/*!
	 * Constructor to initialise the board pointer
	 * created in game (Association relation)
	 * @param tictactoeBoard *pBoard - IN Address of the TicTacToe board
	 * @return none
	 */
	computerPlayer(tictactoeBoard *pBoard);

	/*!
	 * Destructor to de-initialise computerPlayer class
	 * @param none
	 * @return none
	 */
	virtual ~computerPlayer();

	/*!
	 * Method which implements logic needed for Computer Player type of the game
	 * @param uint16_t index - IN index will be calculated by the
	 * minimax algorithm. Therefore dummy param created in order to be consistent
	 * with the pure virtual method created in the base class
	 * @param Field_t Player - IN Consider the player info to check
	 * @return none
	 */
	void logic(uint16_t index, Field_t player);

	/*!
	 * Method to find the best position for the computer player
	 * while playing tictactoe game. It uses the Man MiniMax algorithm
	 * @param Field_t Player - IN Player info needed to calculate score
	 * @return uint16_t- returns the best position(Winning or defending)
	 * index of the tictactoe board
	 */
	uint16_t MinMaxOptimalPosition(Field_t player);

	/*!
	 * Main MinMax Algorithm implementation
	 * @param Field_t Player - IN Player info needed to calculate score
	 * @param bool MaxPl- IN Selecting between Maximizing or minimizing player
	 * @return int- returns max or min score
	 */
	int MinMaxAlgo(Field_t Player, bool MaxPl);

	/*!
	 * Calculates score based on Game state. WIN and ActivePlayer will get 10 points
	 * WIN and OppositePlayer gets -10 points. otherwise the score will be 0
	 * @param Field_t Player- IN player info
	 * @return int - returns calculated score (0,10,-10)
	 */
	int MinMaxGetScore(Field_t Player);


};

#endif /* COMPUTERPLAYER_H_ */
