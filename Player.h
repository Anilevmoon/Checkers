#pragma once
#include <iostream>
#include <vector>
#include "Units.h"


class Player {
	public:
	Player(int wich);
	virtual ~Player() = default;
	std::vector<std::vector<char>> units;
	private:

};


