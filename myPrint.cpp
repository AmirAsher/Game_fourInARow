#include "myPrint.hpp"


using namespace fourInARow_Game;

Print::Print()
{}	

Print::~Print()
{}	
	
void Print::printTurn(size_t _movesCount)const
{
	if (_movesCount % 2 + 1 == 1)
	{
		std::cout << K_BG_BLUE << KRED << "Player " << RED_CIRCLE << " what will be your next move ?" << KNRM << std::endl;
	}
	else if (_movesCount % 2 + 1 == 2)
	{
		std::cout << K_BG_BLUE << KYEL << "Player " << YELLOW_CIRCLE << " what will be your next move ?" << KNRM << std::endl;
	}
}

void Print::printBoard(const Board* _board, size_t _columnsNum, size_t _rowsNum)const
{
	if (! _board)
	{
		return;
	}
	
	size_t rowsNum = _rowsNum;
	size_t columnsNum = _columnsNum;
	
	for (size_t row = rowsNum-1; row > 0; --row) // row
	{
		for (size_t col = 0; col < columnsNum; ++col) // col
		{
			if (_board->getBoardCellVal(col, row-1) == 0)
			{
				std::cout << WHITE_CIRCLE;
			}
			else if (_board->getBoardCellVal(col, row-1) == 1)
			{
				std::cout << RED_CIRCLE;
			}
			else if (_board->getBoardCellVal(col, row-1) == 2)
			{
				std::cout << YELLOW_CIRCLE;
			}
			else
			{
				std::cout << _board->getBoardCellVal(col, row-1);
			}
		}
		std::cout << "" << K_L_BLUE << std::endl;
	}
	
	for (size_t i = 0; i < columnsNum; ++i)
	{
		std::cout << " " << i+1;
	}
	std::cout << "" << KNRM << std::endl << std::endl;
}


