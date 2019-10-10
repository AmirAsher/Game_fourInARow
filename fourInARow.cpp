#include "fourInARow.hpp"


using namespace fourInARow_Game;

fourInARow::fourInARow()
{
	m_board = new Board;
}

fourInARow::~fourInARow()
{
	delete m_board;
}

void fourInARow::setParms()
{
	std::cout << K_L_GRN << K_BG_BLUE << "Hello and welcome to Four In A Row" << KNRM << std::endl; 
	
	m_ParmsArr[0] = NUM_OF_COLUMNS;
	m_ParmsArr[1] = NUM_OF_ROWS;
}

void fourInARow::setMovesCount(int _val)
{
	m_movesCount += _val;
}

void fourInARow::Run()
{
	setParms();
	
	for (size_t i = 0; i < NUM_OF_PLAYERS; ++i)
	{
		m_playerArr[i] = new Player();
	}
	
	size_t boardSize = getParms(0) * (getParms(1) -1);
	size_t columnsNum = getParms(0); 	// NUM_OF_COLUMNS
	size_t rowsNum = getParms(1); 		// NUM_OF_ROWS
	
	m_print->printBoard(m_board, columnsNum, rowsNum); 
		
	while (getMovesCount() < boardSize)
	{
		size_t playerTurn = getMovesCount() % 2;
		bool validMoveFlag = false;
		
		size_t tmpNextRowToFill = 0;
		size_t tmpPlayerColumnChoice = 0;
		
		// validation loop - choose col until the chosen col is valid
		while (! validMoveFlag)
		{
			// call player Run()
			m_print->printTurn(getMovesCount());
			m_playerArr[playerTurn]->Player::Run();
			
			tmpPlayerColumnChoice 	= m_playerArr[playerTurn]->getPlayerMove();
			tmpNextRowToFill 		= (m_board->getBoardCellVal(m_playerArr[playerTurn]->getPlayerMove(), rowsNum-1));
			
			if ((m_board->getBoardCellVal(tmpPlayerColumnChoice, tmpNextRowToFill) < rowsNum-1) && tmpPlayerColumnChoice != UN_VALID_MOVE)
			{
				validMoveFlag = true;
				continue;
			}
			else
			{
				// message: not a valid move
				std::cout << K_L_GRN << K_BG_BLUE << "Not a valid move - try again, choose another column" << KNRM << std::endl;
			}
		} // end while
		
		// add the disks to the board & mark the board
		tmpPlayerColumnChoice 	= m_playerArr[playerTurn]->getPlayerMove();
		tmpNextRowToFill 		= (m_board->getBoardCellVal(m_playerArr[playerTurn]->getPlayerMove(), rowsNum-1));
		
		m_board->setBoardCellVal(tmpPlayerColumnChoice, tmpNextRowToFill, (playerTurn + 1)); // red == 1, yellow == 2
		
		// update the column fill counter
		m_board->setColumnCounter(tmpPlayerColumnChoice);
		
		setMovesCount(1);
		
		// check & update Sequences -- is their a winner ?
		if (! m_status->checkForSequence(m_board, (getMovesCount() % 2), columnsNum, rowsNum))
		{
			m_print->printBoard(m_board, columnsNum, rowsNum);
			return; // end of game
		}
		
		// check if the board is full and no winner
		if (getMovesCount() == boardSize)
		{
			// message: draw
			std::cout << K_L_GRN << "Draw - game ended no more free slots" << KNRM << std::endl;
			m_print->printBoard(m_board, columnsNum, rowsNum);
			return; // end of game
		}
		
		// message: keep playing
		std::cout << KBLK << K_BG_GREY << "Still no winner - keep playing" << KNRM << std::endl;
		
		m_print->printBoard(m_board, columnsNum, rowsNum);
		
	} // end while
	m_print->printBoard(m_board, columnsNum, rowsNum); 
	return;
}



