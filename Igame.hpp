#ifndef __I_GAME_H__
#define __I_GAME_H__


#include "Irunnable.hpp"


namespace fourInARow_Game{

class IGame:public Runnable{

public:
	IGame(){};
	virtual ~IGame(){}; 

	virtual void Run() = 0;
	
};

} //namespace fourInARow_Game

#endif //__I_GAME_H__



