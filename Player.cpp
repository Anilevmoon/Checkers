#include "Player.h"

Player::Player() {}

Player::Player(int wichPlay) : m_playerNumber(wichPlay) {
	if(wichPlay == 1) {
		Units* unit1 = new Units(1, 0, 1);
		m_unitsExist.push_back(unit1);
		m_unitsExist.push_back(new Units(3, 0, 1));
		m_unitsExist.push_back(new Units(5, 0, 1));
		m_unitsExist.push_back(new Units(7, 0, 1));
		m_unitsExist.push_back(new Units(0, 1, 1));
		m_unitsExist.push_back(new Units(2, 1, 1));
		m_unitsExist.push_back(new Units(1, 4, 1)); //4, 1, 1
		m_unitsExist.push_back(new Units(6, 1, 1));
		m_unitsExist.push_back(new Units(1, 2, 1));
		m_unitsExist.push_back(new Units(3, 2, 1));
		m_unitsExist.push_back(new Units(5, 2, 1));
		m_unitsExist.push_back(new Units(7, 2, 1));
		//Units &c2 = unit1;
		//unitsExist.reserve(12);

		//unitsExist[1] = new Units(11, 23, true);
	}
	if(wichPlay == 2) {
		Units* unit2 = new Units(0, 7, 0);
		m_unitsExist.push_back(unit2);
		m_unitsExist.push_back(new Units(2, 7, 0));
		m_unitsExist.push_back(new Units(4, 7, 0));
		m_unitsExist.push_back(new Units(6, 7, 0));
		m_unitsExist.push_back(new Units(1, 6, 0));
		m_unitsExist.push_back(new Units(3, 6, 0));
		//m_unitsExist.push_back(new Units(5, 6, 0));
		//m_unitsExist.push_back(new Units(7, 6, 0));
		m_unitsExist.push_back(new Units(0, 5, 0));
		m_unitsExist.push_back(new Units(2, 5, 0));
		m_unitsExist.push_back(new Units(4, 5, 0));
		m_unitsExist.push_back(new Units(6, 5, 0));
	}

}

