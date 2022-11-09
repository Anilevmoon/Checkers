#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
#include "Units.h"

class Player {
	public:
	
	Player();
	Player(int wichPlay);
	virtual ~Player() = default;

	COORD unitCoord = {-1, -1};
	int m_playerNumber;
	std::vector<Units*>m_unitsExist;

	COORD getUnitPos();
	private:

};