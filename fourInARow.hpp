#ifndef __FOUR_IN_A_ROW_H__
#define __FOUR_IN_A_ROW_H__

#include <iostream> // cin, cout
#include <array>

#include "Igame.hpp"
#include "board.hpp"
#include "status.hpp"
#include "player.hpp"
#include "myPrint.hpp"
#include "myDefs.hpp"


namespace fourInARow_Game{
	
class fourInARow: public IGame{

public:
	fourInARow();	
	virtual ~fourInARow(); // DTOR is virtual for future derived class -> guarantee proper destruction - call both base and derived DTOR's
	void Run();
	inline size_t getMovesCount()const { return m_movesCount; };
	inline size_t getParms(size_t _loc)const { return m_ParmsArr[_loc]; };
	
private: 
	void setParms();
	void setMovesCount(int _val);
	
	fourInARow(const fourInARow& _fourInARow);				// not allowed
	fourInARow& operator=(const fourInARow& _fourInARow);	// not allowed
	
private:
	size_t m_movesCount;
	
	Board* m_board;
	Status* m_status;
	Print* m_print;
	
	std::array<Player*, 2> m_playerArr;
	std::array<int, 2> m_ParmsArr; // [0] = number of column, [1] = number of rows
	
};


} //namespace fourInARow_Game

#endif //__FOUR_IN_A_ROW_H__




