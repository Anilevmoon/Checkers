#include "GameAction.h"

Action::Action(int a) {
	m_intStandart = a;
}

void Action::ActiveTurn(Board& board, Player& first, Player& second) {
	char key = _getch();
	int selectBtnX = board.m_selectXposition;
	int selectBtnY = board.m_selectYposition;

	if(true) {
		switch(key) {
			case 'w': case 'W':
				if(selectBtnY>0) {
					board.m_selectYposition = (selectBtnY - 1);
				}
				break;
			case 's': case 'S':
				if(selectBtnY<7) {
					board.m_selectYposition = (selectBtnY + 1);
				}
				break;
			case 'a': case 'A':
				if(selectBtnX>0) {
					board.m_selectXposition = (selectBtnX - 1);
				}
				break;
			case 'd': case 'D':
				if(selectBtnX<7) {
					board.m_selectXposition = (selectBtnX + 1);
				}

				break;

			case 'q': case 'Q':
				{
					char choosenUnit = board.m_MapVector[selectBtnY][selectBtnX];
					if(m_IsPlayerOneTurn) {
						switch(choosenUnit) {
							case ' ':
								board.MapClear();
								board.m_isChoosen = false;
								break;
							case 'X':
								board.MapClear();
								board.m_isChoosen = false;
								break;
							case 'O':
								if(!board.m_isChoosen) {
									board.m_choosenYpos = selectBtnY;
									board.m_choosenXpos = selectBtnX;
									board.m_isChoosen = true;
									break;
								} else {
									board.MapClear();
									board.m_isChoosen = false;
									break;
								}
								break;
								case char(176):
									std::cout<<"Mdaaa"<<std::endl;
									//MakeMove(board);
									break;
								default:
									board.m_isChoosen = false;
									break;
						}
					}
				}
				break;

			case 'k': case 'K':
				second.m_unitsExist[5]->m_x = 1;
				second.m_unitsExist[5]->m_y = 3;
				second.m_unitsExist[5]->m_uni = 'D';
				first.m_unitsExist[5]->SetDead();
				break;

			case 'E': case 'e':
				MakeMove(board, first, second, selectBtnX, selectBtnY);
				break;
			default:
				break;
		}
	}
}

void Action::DetectMove() {
	
}

void Action::MakeMove(Board& board, Player& first, Player& second, int selectX, int selectY) {
	if(board.m_isChoosen) {
		board.m_moveXpos = selectX;
		board.m_moveYpos = selectY;
		auto i = 0;
		int8_t unitHasFound = -1;
			do {
				
				if(board.m_choosenXpos == first.m_unitsExist[i]->m_x && board.m_choosenYpos == first.m_unitsExist[i]->m_y) {
				unitHasFound = i; 
				}
				i++;
			
			} while(unitHasFound<0);
			first.m_unitsExist[unitHasFound]->m_x = board.m_moveXpos;
			first.m_unitsExist[unitHasFound]->m_y = board.m_moveYpos;
			board.m_moveXpos = -1;
			board.m_moveYpos = -1;
			board.m_isChoosen = false;
			board.MapClear();
	}
}




