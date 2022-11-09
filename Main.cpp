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

    for(;;) {
        board.boardDraw(player, player2, hConsole);
        actions.ActiveTurn(board, player, player2);
    }
    std::cout << "Hello World!\n";
}
