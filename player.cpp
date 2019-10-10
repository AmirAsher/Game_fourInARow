#include "player.hpp"


using namespace fourInARow_Game;


Player::Player()
{}

Player::~Player()
{}

void Player::Run()
{
	std::cout << K_L_GRN << K_BG_BLUE << "In which column do you want to insert (1-7) ?" << KNRM << std::endl;
	char tmpInput = 0;
	std::cin >> tmpInput;
	int tmpMove = (int)tmpInput - '0';
	
	if (tmpMove >= 1 && tmpMove <= NUM_OF_COLUMNS && std::isdigit(tmpInput)) // VALID MOVE
	{
		m_playerMove = tmpMove-1;
	}
	
	else // NOT VALID MOVE
	{
		m_playerMove = UN_VALID_MOVE;
	}
	// getchar();
}



