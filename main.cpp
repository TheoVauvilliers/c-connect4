#include <iostream>

#include "lib/Boardgame/Boardgame.h"

using namespace std;

int main()
{
    cout << "Welcome to Connect Four!" << endl << endl;
    Boardgame boardgame;

    // TODO: Create user interaction
    boardgame.showBoardgame();

    boardgame.dropToken(2, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    
    boardgame.dropToken(3, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    boardgame.dropToken(3, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }

    boardgame.dropToken(4, 2);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    boardgame.dropToken(4, 2);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    boardgame.dropToken(4, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }

    boardgame.dropToken(5, 2);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    boardgame.dropToken(5, 2);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    boardgame.dropToken(5, 2);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    boardgame.dropToken(5, 1);
    boardgame.showBoardgame();
    if (boardgame.areFourConnected()) {
        cout << "It's win !" << endl;
    }
    
    return 1;
};
