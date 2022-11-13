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
	int killedUnit = -1;
	Action(int a);

	
	void ActiveTurn(Board& board, Player& first, Player& second);
	void MakeMove(Board& board, Player& first, Player& second, int selectX, int selectY);

	void DevKil(Board& board, Player& first, Player& second, bool Dev = 0, int x = -1, int y = -1);
	
	bool isBeatPossibleConstruct(Board& board, SHORT x, SHORT y);
	bool IsBeatPossible(Board& board);
	int DetectEnd(Player& first);
	virtual ~Action() = default;

	private:

};
