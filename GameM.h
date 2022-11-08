#pragma once
#include <iostream>
#include "Board.h"
class Game {
	public:
	Game();
	virtual ~Game() = default;
	void PlayTest();
	
	private:
	Board board;

};