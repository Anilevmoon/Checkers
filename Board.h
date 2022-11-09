#pragma once
#include "Player.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
class Board {
	public:

	bool m_isChoosen = false;
	int m_choosenXpos = -1;
	int m_choosenYpos = -1;

	int m_moveXpos = -1;
	int m_moveYpos = -1;

	std::vector<std::vector<char>> m_MapVector;
	int m_selectXposition = 0;
	int m_selectYposition = 0;
    HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Board();
	Board(Player& a, Player& b);
	
	void boardDraw(Player& a, Player& b, HANDLE hCons);
	void ColoredCells(int x, int y, HANDLE hConsole, int colorR = 126, int colorY = 132);

	void TakePositions(Player& a, Player& b);
	void JustDrawMAP(HANDLE hCons, Player& black);
	void MapClear();

	void colorSelectPos(int x, int y, HANDLE hCons);
	bool MoveAbilitiCheck(int x, int y);
	void colorAbleMoves(HANDLE hCons);
	void CheckAbleMoves(HANDLE hCons, int xMove, int yMove);

	virtual ~Board() = default;

	private:
	int m_width = 8;
	int m__height = 8;
};

