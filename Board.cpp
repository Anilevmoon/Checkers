#include "Board.h"
#include "GameAction.h"

Board::Board() {
}

Board::Board(Player& a, Player& b) : m_MapVector(8, std::vector<char>(8, ' ')) {
	int First = a.m_unitsExist[0]->m_x;
	int Second = b.m_unitsExist[0]->m_x;
}

void Board::CheckRules() {
	SetConsoleCursorPosition(m_hConsole, {16, 8});
	std::cout<<"   USE W+S+A+D TO MOVE COURSORE.\n           Q = CHOOSE THE UNIT, E = MOVE COOSEN UNIT HERE.\n           (DEVTOOLS: K = DEVKILL, I = CHANGE PLAYER TURN)\n"<<std::endl;
	system("pause");
    system("cls");
}

void Board::ColoredCells(int x, int y, HANDLE hConsole, int colorR, int colorY) {
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

void Board::TakePositions(Player& a, Player& b) {
	for(auto index = 0; index<a.m_unitsExist.size(); index++) {
		int x = a.m_unitsExist[index]->m_x;
		int y = a.m_unitsExist[index]->m_y;
		bool isAlive = a.m_unitsExist[index]->m_alive;
		if(isAlive == true) {
			m_MapVector[y][x] = a.m_unitsExist[index]->m_uni;
		}
	}

	for(auto index = 0; index < b.m_unitsExist.size(); index++) {
		int x = b.m_unitsExist[index]->m_x;
		int y = b.m_unitsExist[index]->m_y;

		bool isAlive = b.m_unitsExist[index]->m_alive;
		if(isAlive == true) {
			m_MapVector[y][x] = b.m_unitsExist[index]->m_uni;
		}
	}
}

void Board::JustDrawMAP(HANDLE hCons, Player& black) {
	for(auto i = 0; i < m__height; i++) {
		SetConsoleCursorPosition(hCons, {4, (SHORT)(i + 4)});
		for(int16_t j = 0; j < m_width; j++) {
			if(i == m_choosenYpos && j == m_choosenXpos && m_isChoosen) {
				SetConsoleTextAttribute(hCons, 178);
				std::cout<<m_MapVector[m_choosenYpos][m_choosenXpos];
			} else {
				ColoredCells(j, i, hCons, 126, 128); //133/135/ 128-black 139-blue
				std::cout <<m_MapVector[i][j];
			}
		}
	}
}

void Board::MapClear() {
	for(auto i = 0; i < m__height; i++) {
		for(auto j = 0; j < m_width; j++) {
			m_MapVector[i][j] = ' ';
		}
	}
}

void Board::colorSelectPos(int x, int y, HANDLE hCons) {
	SetConsoleCursorPosition(hCons, {(SHORT)(x + 4), (SHORT)(y + 4)});
	SetConsoleTextAttribute(hCons, 156);
	if(MoveAbilitiCheck(x, y)) {
		std::cout<<m_MapVector[y][x];
	}
}

void Board::colorAbleMoves(HANDLE hCons, bool isPlayerone) {
	if(m_isChoosen) {
		CheckAbleMoves(hCons, -1, 1, isPlayerone);
		CheckAbleMoves(hCons, -1, -1, isPlayerone);
		CheckAbleMoves(hCons, 1, -1, isPlayerone);
		CheckAbleMoves(hCons, 1, 1, isPlayerone);

	}

}

void Board::CheckAbleMoves(HANDLE hCons, int xMove, int yMove, bool isPlayerOne) {
	
	char aCase = 'U';
	if(MoveAbilitiCheck(m_choosenYpos + yMove, m_choosenXpos + xMove)) {
		aCase = m_MapVector[m_choosenYpos+yMove][m_choosenXpos+xMove];

		switch(aCase) {
			case ' ':
				if(yMove == 1 && isPlayerOne) {
					SetConsoleCursorPosition(hCons, {(SHORT)(m_choosenXpos + 4 + xMove), (SHORT)(m_choosenYpos + 4 + yMove)});
					SetConsoleTextAttribute(hCons, 160);
					m_MapVector[m_choosenYpos + yMove][m_choosenXpos + xMove] = char(254);
					std::cout<<char(254)<<std::endl;
				}

				if(yMove == -1 && !isPlayerOne) {
					SetConsoleCursorPosition(hCons, {(SHORT)(m_choosenXpos + 4 + xMove), (SHORT)(m_choosenYpos + 4 + yMove)});
					SetConsoleTextAttribute(hCons, 160);
					m_MapVector[m_choosenYpos + yMove][m_choosenXpos + xMove] = char(254);
					std::cout<<char(254)<<std::endl;
				}
				break;

			case 'X':
				if(isPlayerOne) {
					if(MoveAbilitiCheck(m_choosenYpos+(yMove*2), m_choosenXpos + (xMove*2))) {
						if(m_MapVector[m_choosenYpos+(yMove*2)][m_choosenXpos + (xMove*2)] == ' ') {

							SetConsoleCursorPosition(hCons, {(SHORT)(m_choosenXpos + 4 + xMove), (SHORT)(m_choosenYpos + 4 + yMove)});
							SetConsoleTextAttribute(hCons, 139);

							std::cout<<m_MapVector[m_choosenYpos + yMove][m_choosenXpos + xMove]<<std::endl;

							SetConsoleCursorPosition(hCons, {(SHORT)(m_choosenXpos + 4 + (xMove*2)), (SHORT)(m_choosenYpos + 4 + (yMove*2))});
							SetConsoleTextAttribute(hCons, 160);
							m_MapVector[m_choosenYpos+(yMove*2)][m_choosenXpos + (xMove*2)] = char(219);
							
							std::cout<<char(219)<<std::endl;
							m_possibleKill = true;
						}
					}
				}
				
				break;

			case 'O':
				if(!isPlayerOne) {
					if(MoveAbilitiCheck(m_choosenYpos+(yMove*2), m_choosenXpos + (xMove*2))) {
						if(m_MapVector[m_choosenYpos+(yMove*2)][m_choosenXpos + (xMove*2)] == ' ') {
							
							SetConsoleCursorPosition(hCons, {(SHORT)(m_choosenXpos + 4 + xMove), (SHORT)(m_choosenYpos + 4 + yMove)});
							SetConsoleTextAttribute(hCons, 139);
							
							std::cout<<m_MapVector[m_choosenYpos + yMove][m_choosenXpos + xMove]<<std::endl;

							SetConsoleCursorPosition(hCons, {(SHORT)(m_choosenXpos + 4 + (xMove*2)), (SHORT)(m_choosenYpos + 4 + (yMove*2))});
							SetConsoleTextAttribute(hCons, 160);
							
							m_MapVector[m_choosenYpos+(yMove*2)][m_choosenXpos + (xMove*2)] = char(219);
							std::cout<<char(219)<<std::endl;
							m_possibleKill = true;
						}
					}
				}
				break;
			default:
				break;
		}
	}
}



bool Board::MoveAbilitiCheck(int x, int y) {
	if((x>7 || x<0) || (y>7 || y<0)) {
		return 0;
	}
	return 1;
}


void Board::boardDraw(Player& a, Player& b, HANDLE hCons, bool isPlayerOne) {
	TakePositions(a, b);
	JustDrawMAP(hCons, b);
	colorSelectPos(m_selectXposition, m_selectYposition, hCons);
	if(m_isChoosen) {
		colorAbleMoves(hCons, isPlayerOne);
	}

}