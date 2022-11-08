#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#pragma once
class Board {
	public:
	Board();
	virtual ~Board() = default;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool newGame = 1;
	void ColoredCells(int x, int y, int colorR, int colorY);

	std::vector<std::vector<char>>CreateStartMap(int W, int	H);
	
	void DrawStartMap(HANDLE hConsol, int Width, int Height, std::vector<std::vector<char>> startMap);
	void BoardDraw(int Width, int Height);
	protected:



};