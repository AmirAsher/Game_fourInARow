#ifndef __STATUS_H__
#define __STATUS_H__

#include <cstddef> // size_t
#include <iostream> // cin, cout

#include "board.hpp"
#include "myDefs.hpp"


namespace fourInARow_Game{

class Status{

public:
	Status();	
	virtual ~Status();  
	
	bool checkForSequence(const Board* _board, size_t _playerID, size_t _columnsNum, size_t _rowsNum)const;

private: 
	Status(const Status& _Status);				// not allowed
	Status& operator=(const Status& _Status);	// not allowed
	
};


} //namespace fourInARow_Game

#endif //__STATUS_H__




