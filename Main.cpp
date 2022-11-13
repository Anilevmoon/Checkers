#include <iostream>
#include "Units.h"
#include "Player.h"
#include "Board.h"
#include "GameAction.h"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Player player(1);
    Player player2(2);
    //Player& p1 = player;
    //Player& p2 = player2;
    Action actions(2);
    Board board(player, player2);

    board.CheckRules();
    system("pause");
    system("cls");

    for(;;) {
        board.boardDraw(player, player2, hConsole, bool(actions.m_IsPlayerOneTurn));
        actions.ActiveTurn(board, player, player2);

        if(actions.DetectEnd(player) && actions.DetectEnd(player2)) {
            continue;
        } else if(actions.DetectEnd(player) && !actions.DetectEnd(player2)){
            system("cls");
            system("color 1");
            for(auto i = 0; i<30; i++) { std::cout<<"               PLAYER ONE WINS\n"<<std::endl; }
            system("pause");
            return 0;
        } else {
            system("cls");
            system("color 1");
            for(auto i = 0; i<30; i++){ std::cout<<"               PLAYER TWO WINS\n"<<std::endl;}
            system("pause");
            return 0;
        }
    }
}
