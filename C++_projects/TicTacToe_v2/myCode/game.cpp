/*
 * game.cpp
 *
 *  Created on: 28-Nov-2023
 *      Author: umesh
 */

#include "game.h"
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"

/*!
 * Constructor to initialise the game class and screen board pointer
 * @param none
 * @return none
 */
game::game() : m_screen(&m_board)
{
	// TODO Auto-generated constructor stub

	m_GamePlayer1= NOPLAYER;
	m_GamePlayer2= NOPLAYER;
}

/*!
 * Method to run Tictactoe game in a infinite loop
 * @param none
 * @return none
 */
void game::run()
{
	uint16_t select[2];

	m_screen.PrintMessage("Select Player: 1(1- human, 2- Computer)");
	m_screen.ReadNum(select[0]);

	m_screen.PrintMessage("Select Player: 2(1- human, 2- Computer)");
	m_screen.ReadNum(select[1]);

	setPlayers(select);
	m_screen.PrintBoard();

	while(1)
	{
		GamePlayer1(m_GamePlayer1);
		m_screen.PrintBoard();
		if(GameLogicCheckWinCondition()== true)
		{
			break;
		}

		GamePlayer2(m_GamePlayer2);
		m_screen.PrintBoard();
		if(GameLogicCheckWinCondition()== true)
		{
			break;
		}
	}
}

/*!
 * Check if the game is WON or DRAWN
 * @param none
 * @return bool - returns true if the game is WON or DRAW
 */
bool game::GameLogicCheckWinCondition()
{
	Field_t activeplayer[2];
	std::string message;
	m_board.getActivePlayer(activeplayer);
	int ret = m_board.TTTBoard_CountWin(activeplayer[0]);
	if(ret== 1)
	{
		message = "Player"+ std::to_string(activeplayer[0])+ " wins!!";
		m_screen.PrintMessage(message);
		return true;
	}
	if(ret==-1)
	{
		m_screen.PrintMessage("Match Drawn");
		return true;
	}
	else
	{
		return false;
	}
}

/*!
 * Method which implements polymorphism where the pointer of the base class
 * player is assigned child class humanPlayer or computerPlayer based on the
 * user selection.It also saves player info in members m_GamePlayer1 and m_GamePlayer2
 * @param uint16_t val[2] - IN user selection info
 * containing which set of players are selected
 * @return none
 */
void game::setPlayers(uint16_t val[2])
{
	if(val[0]==1)
	{
		m_screen.PrintMessage("Player1 : Human Selected");
		m_GamePlayers[0]= new humanPlayer(&m_board);
		m_GamePlayer1= HUMAN;
	}
	else if(val[0]==2)
	{
		m_screen.PrintMessage("Player1 : Computer Selected");
		m_GamePlayers[0]= new computerPlayer(&m_board);
		m_GamePlayer1= COMPUTER;
	}
	if(val[1]==1)
	{
		m_screen.PrintMessage("Player2 : Human Selected");
		m_GamePlayers[1]= new humanPlayer(&m_board);
		m_GamePlayer2= HUMAN;
	}
	else if(val[1]==2)
	{
		m_screen.PrintMessage("Player2 : Computer Selected");
		m_GamePlayers[1]= new computerPlayer(&m_board);
		m_GamePlayer2= COMPUTER;
	}
}

/*!
 * Play the game for Player1. Depending on Human or Computer player, it calls
 * the logic of the respective player.
 * @param GAMEPlayer_t player - IN Contains Human or Computer player info
 * @return none
 */
void game::GamePlayer1(GAMEPlayer_t player)
{
	uint16_t index=0;
	m_board.setActivePlayer(PLAYER1);
	if(player == HUMAN)
	{
		GameReadIndex(index);
		m_GamePlayers[0]->logic(index,PLAYER1);
	}
	else if(player == COMPUTER)
	{
		m_screen.PrintMessage("Computer Player1: Playing...");
		m_GamePlayers[0]->logic(index,PLAYER1);
	}
}

/*!
 * Play the game for Player2. Depending on Human or Computer player, it calls
 * the logic of the respective player.
 * @param GAMEPlayer_t player - IN Contains Human or Computer player info
 * @return none
 */
void game::GamePlayer2(GAMEPlayer_t player)
{
	uint16_t index=0;
	m_board.setActivePlayer(PLAYER2);
	if(player == HUMAN)
	{
		GameReadIndex(index);

		m_GamePlayers[1]->logic(index,PLAYER2);
	}
	else if(player == COMPUTER)
	{
		m_screen.PrintMessage("Computer Player2: Playing...");
		m_GamePlayers[1]->logic(index,PLAYER2);
	}
}

/*!
 * Read the index from human player. Also contains the error handling if human
 * enters index where player is already present
 * @param uint16_t& index - OUT index info which is read from the human
 * @return none
 */
void game::GameReadIndex(uint16_t& index)
{
	Field_t activeplayer[2];
	std::string message;
	m_board.getActivePlayer(activeplayer);
	message = "Player"+ std::to_string(activeplayer[0])+
			": Enter position index: ";
	do{

		m_screen.PrintMessage(message);
		m_screen.ReadNum(index);
		if(m_board.GetFieldState(index)!=EMPTY)
		{
			m_screen.PrintMessage("Index already contains a player."
					"Please enter correct index again");
		}
	}while(m_board.GetFieldState(index)!=EMPTY);
}

/*!
 * Destructor for the game class
 * @param none
 * @return none
 */
game::~game()
{
	// TODO Auto-generated destructor stub
}
