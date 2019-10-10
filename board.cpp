#include "board.hpp"


using namespace fourInARow_Game;


Board::Board()
{
	std::memset(board, 0, sizeof(board[0][0]) * NUM_OF_COLUMNS* NUM_OF_ROWS);
}

Board::~Board()
{}

void Board::setBoardCellVal(size_t _col, size_t _row, size_t _valToUpdate)
{
	board[_col][_row] = _valToUpdate;
}

void Board::setColumnCounter(size_t _col)
{
	++board[_col][NUM_OF_ROWS - 1];
}



