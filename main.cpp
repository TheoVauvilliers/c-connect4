#include <iostream>

#include "lib/Boardgame/Boardgame.h"

using namespace std;

int main()
{
    Boardgame boardgame;

    cout << "Welcome to Connect Four!" << endl << endl;

    // for (int i = 0; i < 4; i++) {
    //     boardgame.dropToken(i, 1);
    //     boardgame.showBoardgame();

    //     if (boardgame.areFourConnected()) {
    //         cout << "It's win !" << endl;
    //         break;
    //     }
    // }

    boardgame.dropToken(0, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }

    return 1;
};
