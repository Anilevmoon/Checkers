#include "Board.h"
#include <vector>
#include "CONSTANTS.h"





void Board::ColoredCells(int x, int y, int colorR, int colorY) {
	if(x % 2 != 0) {
		if(y % 2 != 0)
			SetConsoleTextAttribute(hConsole, colorR);
		else
			SetConsoleTextAttribute(hConsole, colorY);
	} else {
		if(y % 2 != 0)
			SetConsoleTextAttribute(hConsole, colorY);
		else
			SetConsoleTextAttribute(hConsole, colorR);
	}
}

std::vector<std::vector<char>> Board::CreateStartMap(int W, int	H) {

	std::vector<std::vector<char>> ClearMap(W, std::vector<char>(H, ' '));

	for(auto y = 0; y < H; y++) {
		for(auto x = 0; x < W; x++) {
			if(x % 2 != 0) {
				if(y % 2 != 0)
					//ClearMap.push_back(' ');
					ClearMap[x][y] = ' ';
				else
					ClearMap[x][y] = 'X';
			} else {
				if(y % 2 != 0)
					ClearMap[x][y] = 'X';
				else
					ClearMap[x][y] = ' ';
			}

		}
	}
	return(ClearMap);
}

void Board::DrawStartMap(HANDLE hConsol, int width, int height, std::vector<std::vector<char>> startMap) {
	for(auto i = 0; i < height; i++) {
		SetConsoleCursorPosition(hConsol, {4, (SHORT)(i + 4)});
		for(unsigned j = 0; j < width; j++) {
			ColoredCells(j, i, 126, 132);
			std::cout <<startMap[i][j];
		}
	}
}


Board::Board() {}

void Board::BoardDraw(int Width, int Height) {
	if(newGame) {
		std::vector<std::vector<char>> StartMap = CreateStartMap(Width, Height);
		DrawStartMap(hConsole, Width, Height, StartMap);
	}

}


