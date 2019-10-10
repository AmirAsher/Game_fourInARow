#include <iostream> // cin, cout

#include "fourInARow.hpp"
#include "board.hpp"

using namespace fourInARow_Game;


int main()
{
	fourInARow* myGame = new fourInARow;
	myGame->Run();
	
	return 0;
}



