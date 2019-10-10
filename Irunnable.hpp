#ifndef __RUNNABLE_H__
#define __RUNNABLE_H__


#include "uncopyable.hpp"


namespace fourInARow_Game{

class Runnable:private UnCopyable{

public:
	Runnable(){}	
	virtual~Runnable(){}  
	
	virtual void Run() = 0; 
};
 

} //namespace fourInARow_Game

#endif //__RUNNABLE_H__



