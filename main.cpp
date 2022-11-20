#include <iostream>

#include "lib/Boardgame/Boardgame.h"

using namespace std;

int main()
{
    cout << "Welcome to Connect Four!" << endl << endl;
    Boardgame boardgame;

    boardgame.showBoardgame();
    cout << "The game start!" << endl << endl;

    int player = Boardgame::PLAYER_1;
    do
    {
        int column;

        cout << "In which column do you want to drop a token? ";
        cin >> column;

        if (boardgame.dropToken(column, player)) {
            player = (player == Boardgame::PLAYER_1) ? Boardgame::PLAYER_2 : Boardgame::PLAYER_1;
        }

        boardgame.showBoardgame();
        
    } while (!boardgame.isGameOver());
    
    return 1;
};
