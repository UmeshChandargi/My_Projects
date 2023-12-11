// Standard (system) header files
#include <iostream>
#include <cstdlib>


using namespace std;

// Add your project's header files here

#include "CReversiConsoleView.h"

// Main program
int main ()
{
	//! CReversiBoard object creation
	CReversiBoard b1;

	//! CReversiConsoleView object creation
	CReversiConsoleView c1(&b1);

	cout<<"Welcome to Reversi Game"<<endl;
	b1.SetActivePlayer(PLAYER1);
	c1.print();

	//! Infinite loop
	while(1)
	{
		//! Player 1
		cout<<"Valid states for Player1"<<endl;
		//! QueryNextPiece
		b1.GameLogicQueryNextPiece();

		//! print board on the console
		if(c1.print()==1)
		{
			//! end the loop when game over condition occurs
			break;
		}

		uint16_t row,col;
		cout<<"Player1: Enter Board row, col: ";
		cin>>row>>col;

		//! Flipping Player2 pawns
		b1.GameLogicFlipState(row,col);
		c1.print();

		//! Player 2
		cout<<"Player2 plays now"<<endl;
		b1.SetActivePlayer(PLAYER2);

		cout<<"Valid states for Player2"<<endl;
		//! QueryNextPiece
		b1.GameLogicQueryNextPiece();

		//! print board on the console
		if(c1.print()==1)
		{
			//! end the loop when game over condition occurs
			break;
		}

		cout<<"Player2: Enter Board row, col: ";
		cin>>row>>col;

		//! Flipping Player1 pawns
		b1.GameLogicFlipState(row,col);
		c1.print();

		cout<<"Player1 plays now"<<endl;
		b1.SetActivePlayer(PLAYER1);

	}
	return 0;
}


