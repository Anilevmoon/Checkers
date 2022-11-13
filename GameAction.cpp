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
			case 'I': case'i':
				if(m_IsPlayerOneTurn) {
					m_IsPlayerOneTurn = 0;
				} else {
					m_IsPlayerOneTurn = 1;
				}
				break;
			case 'q': case 'Q':
				{
					char choosenUnit = board.m_MapVector[selectBtnY][selectBtnX];
					switch(choosenUnit) {
						case ' ':
							board.MapClear();
							board.m_isChoosen = false;
							break;
						case 'X':
							if(!board.m_isChoosen && !m_IsPlayerOneTurn) {
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
						case 'O':
							if(!board.m_isChoosen && m_IsPlayerOneTurn) {
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
						default:
							board.m_isChoosen = false;
							break;
					}
				}
				break;

			case 'k': case 'K':
				DevKil(board, first, second, 1);
				break;

			case 'E': case 'e':
				{
					board.m_moveXpos = selectBtnX;
					board.m_moveYpos = selectBtnY;

					char moveToCell = board.m_MapVector[selectBtnY][selectBtnX];
					switch(moveToCell) {
						case ' ':
							board.MapClear();
							board.m_isChoosen = false;
							break;

						case 'X':
							board.MapClear();
							board.m_isChoosen = false;
							break;

						case 'O':
							board.MapClear();
							board.m_isChoosen = false;
							break;

							case char(254):
								if(!board.m_possibleKill) {
									MakeMove(board, first, second, selectBtnX, selectBtnY);
									board.m_moveXpos = -1;
									board.m_moveYpos = -1;
									board.MapClear();

									if(m_IsPlayerOneTurn) {
										m_IsPlayerOneTurn = 0;
									} else {
										m_IsPlayerOneTurn = 1;
									}
								}
							break;

							case char(219):
								MakeMove(board, first, second, selectBtnX, selectBtnY);
								DevKil(board, first, second, 0);

								board.m_choosenYpos = selectBtnY;
								board.m_choosenXpos = selectBtnX;

								board.m_possibleKill = IsBeatPossible(board);
								if(!board.m_possibleKill) {

									if(m_IsPlayerOneTurn) {
										m_IsPlayerOneTurn = 0;
									} else {
										m_IsPlayerOneTurn = 1;
									}

								}
								board.m_possibleKill = false;
								board.m_moveXpos = -1;
								board.m_moveYpos = -1;
								board.MapClear();
								break;
							default:
								break;
					}
					break;
				}
			default:
				break;
		}
	}

}

int Action::DetectEnd(Player& player) {
	for(auto i = 0; i != player.m_unitsExist.size(); i++) {
		if(player.m_unitsExist[i]->m_alive == 1) {
			return true;
		}
	}
	return false;
}

bool Action::isBeatPossibleConstruct(Board& board, SHORT x, SHORT y) {
	char aCase = 'U';
	if(board.MoveAbilitiCheck(board.m_moveYpos + y, board.m_moveXpos + x)) {
		aCase = board.m_MapVector[board.m_moveYpos+y][board.m_moveXpos +x];
		if(m_IsPlayerOneTurn) {
			if(aCase == 'X' && board.MoveAbilitiCheck(board.m_moveYpos + (2*y), board.m_moveXpos + (2*x))) {
				if(board.m_MapVector[board.m_moveYpos + (2*y)][board.m_moveXpos + (2*x)] == ' ') {
					return true;
				} else {
					return false;
				}
			}
		} else {
			if(aCase == 'O' && board.MoveAbilitiCheck(board.m_moveYpos + (2*y), board.m_moveXpos + (2*x))) {
				if(board.m_MapVector[board.m_moveYpos + (2*y)][board.m_moveXpos + (2*x)] == ' ') {
					return true;
				} else {
					return false;
				}
			}
		}
	}
	return false;
}

bool Action::IsBeatPossible(Board& board) {
	if(isBeatPossibleConstruct(board, -1, -1) || isBeatPossibleConstruct(board, 1, -1) || isBeatPossibleConstruct(board, -1, 1) || isBeatPossibleConstruct(board, 1, 1)) {
		return true;
	}
	return false;
}

void Action::MakeMove(Board& board, Player& first, Player& second, int selectX, int selectY) {
	if(board.m_isChoosen) {
		auto i = 0;
		int8_t unitHasFound = -1;
		do {
			if(m_IsPlayerOneTurn) {
				if(board.m_choosenXpos == first.m_unitsExist[i]->m_x && board.m_choosenYpos == first.m_unitsExist[i]->m_y) {
					unitHasFound = i;
				}
			}

			if(!m_IsPlayerOneTurn) {
				if(board.m_choosenXpos == second.m_unitsExist[i]->m_x && board.m_choosenYpos == second.m_unitsExist[i]->m_y) {
					unitHasFound = i;
				}
			}

			i++;

		} while(unitHasFound<0);
		if(m_IsPlayerOneTurn) {
			first.m_unitsExist[unitHasFound]->m_x = board.m_moveXpos;
			first.m_unitsExist[unitHasFound]->m_y = board.m_moveYpos;
		} else {
			second.m_unitsExist[unitHasFound]->m_x = board.m_moveXpos;
			second.m_unitsExist[unitHasFound]->m_y = board.m_moveYpos;
		}

		board.m_isChoosen = false;
		//board.MapClear();
	}
}


void Action::DevKil(Board& board, Player& first, Player& second, bool Dev, int x, int y) {
	int16_t unitHasFound = -1;
	char killedUnit;
	int xDeadKord;
	int yDeadKord;
	if(Dev) {
		killedUnit = board.m_MapVector[board.m_selectYposition][board.m_selectXposition];
		if(killedUnit == ' ') return;
	} else {
		xDeadKord = board.m_choosenXpos + ((board.m_moveXpos - board.m_choosenXpos)/2);
		yDeadKord = board.m_choosenYpos + ((board.m_moveYpos - board.m_choosenYpos)/2);
		killedUnit = board.m_MapVector[yDeadKord][xDeadKord];
		//if(killedUnit == ' ') return;
	}
	//killedUnit = board.m_MapVector[3][4];
	if(Dev) {
		if(killedUnit == 'O') {
			for(int16_t i = 0; i < first.m_unitsExist.size(); i++) {
				if(board.m_selectXposition == first.m_unitsExist[i]->m_x && board.m_selectYposition == first.m_unitsExist[i]->m_y) {
					unitHasFound = i;
					break;
				}
			}
		} else {
			for(int16_t i = 0; i < second.m_unitsExist.size(); i++) {
				if(board.m_selectXposition == second.m_unitsExist[i]->m_x && board.m_selectYposition == second.m_unitsExist[i]->m_y) {
					unitHasFound = i;
					break;
				}
			}
		}
	} else {
		if(killedUnit == 'O') {
			for(int16_t i = 0; i < first.m_unitsExist.size(); i++) {
				if(xDeadKord == first.m_unitsExist[i]->m_x && yDeadKord == first.m_unitsExist[i]->m_y) {
					unitHasFound = i;
					break;
				}
			}
		} else {
			for(int16_t i = 0; i < second.m_unitsExist.size(); i++) {
				if(xDeadKord == second.m_unitsExist[i]->m_x && yDeadKord == second.m_unitsExist[i]->m_y) {
					unitHasFound = i;
					break;
				}
			}
		}
	}


	if(killedUnit == 'O') {
		first.m_unitsExist[unitHasFound]->SetDead();
	} else {
		second.m_unitsExist[unitHasFound]->SetDead();
	}

	if(Dev) {
		board.MapClear();
	}
}






