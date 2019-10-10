#ifndef __PRINT_H__
#define __PRINT_H__

#include <cstddef> // size_t
#include <iostream> // cin, cout

#include "board.hpp"
#include "myDefs.hpp"


namespace fourInARow_Game{

class Print{

public:
	Print();	
	virtual ~Print();
	
	void printBoard(const Board* _board, size_t _columnsNum, size_t _rowsNum)const;
	void printTurn(size_t _movesCount)const;
	
};


} //namespace fourInARow_Game

#endif //__PRINT_H__



