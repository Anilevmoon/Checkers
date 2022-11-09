#pragma once
#include "Player.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Board.h"


class Action {
	public:
	bool m_IsPlayerOneTurn = 1;
	int m_intStandart;
	Action(int a);
	void ActiveTurn(Board& board, Player& first, Player& second);
	void MakeMove(Board& board, Player& first, Player& second, int selectX, int selectY);
	void DetectMove();
	virtual ~Action() = default;

	private:

};
