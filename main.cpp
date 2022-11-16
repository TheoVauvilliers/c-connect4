#include <iostream>

#include "lib/Boardgame/Boardgame.h"

using namespace std;

int main()
{
    cout << "Welcome to Connect Four!" << endl << endl;
    Boardgame boardgame;

    // TODO: Create user interaction
    boardgame.dropToken(0, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }

    boardgame.dropToken(0, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }

    boardgame.dropToken(0, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }

    return 1;
};
