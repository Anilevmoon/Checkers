#include "GameM.h"
#include "CONSTANTS.h"
Game::Game() {}

void Game::PlayTest() {
	board.BoardDraw(constants::s_iHeight, constants::s_iWidth);
}
