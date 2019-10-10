#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream> // cin, cout

#include "board.hpp"
#include "myDefs.hpp"


namespace fourInARow_Game{

class Player{

public:
	Player();	
	virtual ~Player();  
	
	void Run(); // play
	inline size_t getPlayerMove()const { return m_playerMove; }; // return is column number
	
private:
	size_t m_playerMove;

};


} //namespace fourInARow_Game

#endif //__PLAYER_H__




