#include "status.hpp"


using namespace fourInARow_Game;


#define IS_A_SEQUENCE(S) ((S) == SEQUENCE_FOR_WIN)

// helper function
void printWinner(size_t _playerID)
{
	std::cout << WINNER_TROPY << WINNER_TROPY << WINNER_TROPY << std::endl; 
	if (_playerID == 1)
	{
		std::cout << KRED << "The winner is player number: " << _playerID << RED_CIRCLE << KNRM << std::endl; 
	}
	else
	{
		std::cout << KYEL << "The winner is player number: " << _playerID << YELLOW_CIRCLE << KNRM << std::endl; 
	}
}

Status::Status()
{}

Status::~Status()
{}  

bool Status::checkForSequence(const Board* _board, size_t _playerID, size_t _columnsNum, size_t _rowsNum)const
{
	if (! _board)
	{
		return ! WINNER; // no winner - keep playing or error... no board
	}
	
	size_t correctedPlayerID = !_playerID ? 2 : _playerID;
	size_t tmpCounter = 0;
	size_t columnsNum = _columnsNum;
	size_t rowsNum = _rowsNum;
	
	// check vertically
	for (size_t col = 0; col < columnsNum; ++col) // col
	{
		for (size_t row = 0; row < rowsNum-1; ++row) // row
		{
			if (_board->getBoardCellVal(col,row) == correctedPlayerID)
			{
				++tmpCounter;
				if (IS_A_SEQUENCE(tmpCounter)) // macro
				{
					printWinner(correctedPlayerID);
					return WINNER;
				}
				else if(row == rowsNum - 2) // zeroing counter in case you do have a sequence but not of 4=win, and it ended at the last row/column
				{
					tmpCounter = 0;
				}
			}
			else
			{
				tmpCounter = 0;
			}
		}
	}
	
	// check horizontally
	tmpCounter = 0;
	for (size_t row = 0; row < rowsNum-1; ++row) // row
	{
		for (size_t col = 0; col < columnsNum; ++col) // col
		{
			if (_board->getBoardCellVal(col, row) == correctedPlayerID)
			{
				++tmpCounter;
				if (IS_A_SEQUENCE(tmpCounter))
				{
					printWinner(correctedPlayerID);
					return WINNER;
				}
				else if(col == columnsNum - 1) // zeroing counter in case you do have a sequence but not of 4=win, and it ended at the last row/column
				{
					tmpCounter = 0;
				}
			}
			else
			{
				tmpCounter = 0;
			}
		}
	}
	
	// check diagonally
	// from right to left, bottom part
	tmpCounter = 0;
	for (size_t i = 0; i < columnsNum; ++i)
	{
		size_t row = 0;
		size_t col = i;
		for (row = 0, col = i; row < rowsNum-1 && col < columnsNum; ++row, ++col) 
		{
			if (_board->getBoardCellVal(col, row) == correctedPlayerID)
			{
				++tmpCounter;
				if (IS_A_SEQUENCE(tmpCounter))
				{
					printWinner(correctedPlayerID);
					return WINNER;
				}
				else if(row == rowsNum - 2 || col == columnsNum - 1) // zeroing counter in case you do have a sequence but not of 4=win, and it ended at the last row/column
				{
					tmpCounter = 0;
				}
			}
			else
			{
				tmpCounter = 0;
			}
		}
	}
	
	// from right to left, upper part
	tmpCounter = 0;
	for (size_t i = 0; i < rowsNum-1; ++i)
	{
		size_t row = 0;
		size_t col = i;
		for (row = i, col = 0; row < rowsNum-1 && col < columnsNum; ++row, ++col) 
		{
			if (_board->getBoardCellVal(col, row) == correctedPlayerID)
			{
				++tmpCounter;
				if (IS_A_SEQUENCE(tmpCounter))
				{
					printWinner(correctedPlayerID);
					return WINNER;
				}
				else if(row == rowsNum - 2)
				{
					tmpCounter = 0;
				}
			}
			else
			{
				tmpCounter = 0;
			}
		}
	}
	
	// from left to right, bottom part
	tmpCounter = 0;
	for (int i = (int)columnsNum-1; i >= 0; --i) // int i for the comparison (i >= 0)
	{
		size_t row = 0;
		int col = i; // int col for the comparison (col >= 0)
		for (row = 0, col = i; row < rowsNum-1 && col >= 0; ++row, --col) 
		{
			if (_board->getBoardCellVal(col, row) == correctedPlayerID)
			{
				++tmpCounter;
				if (IS_A_SEQUENCE(tmpCounter))
				{
					printWinner(correctedPlayerID);
					return WINNER;
				}
				else if(row == rowsNum - 2 || col == 0)
				{
					tmpCounter = 0;
				}
			}
			else
			{
				tmpCounter = 0;
			}
		}
	}
	
	// from left to right, upper part
	tmpCounter = 0;
	for (size_t i = 0; i < rowsNum-1; ++i)
	{
		size_t row = 0;
		int col = (int)i; // int col for the comparison (col >= 0)
		for (row = i, col = (int)columnsNum-1; row < rowsNum-1 && col >= 0; ++row, --col)
		{
			if (_board->getBoardCellVal(col, row) == correctedPlayerID)
			{
				++tmpCounter;
				if (IS_A_SEQUENCE(tmpCounter))
				{
					printWinner(correctedPlayerID);
					return WINNER;
				}
				else if(row == rowsNum - 2)
				{
					tmpCounter = 0;
				}
			}
			else
			{
				tmpCounter = 0;
			}
		}
	}
	return ! WINNER; // no winner - keep playing
} // end of checkForSequence()





