#ifndef __BOARD_H__
#define __BOARD_H__

#include <cstddef> // size_t
#include <iostream> // cin, cout
#include <cstring> // memset

#include "myDefs.hpp"
#include "uncopyable.hpp"


namespace fourInARow_Game{

class Board: public UnCopyable{

public:
	friend class fourInARow; // grant class Game=fourInARow access to private area, so can use setBoardCellVal() and setColumnCounter()
	
	Board();	
	virtual ~Board();
	
	inline size_t getBoardCellVal(size_t _col, size_t _row)const { return board[_col][_row]; }; // return is the value in the board cell [i,j]
	
private: 
	void setBoardCellVal(size_t _col, size_t _row, size_t _valToUpdate);
	void setColumnCounter(size_t _col);
	
	Board(const Board& _Board);				/* not allowed. and even so class Game=fourInARow has access,
												it will still wont be possible to copyCTOR or assignment operator 
												because of Board is a derived from class UnCopyable */
	Board& operator=(const Board& _Board);	// not allowed. the same^
	
private:
	size_t board[NUM_OF_COLUMNS][NUM_OF_ROWS];
	
};


} //namespace fourInARow_Game

#endif //__BOARD_H__




