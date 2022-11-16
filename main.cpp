#include <iostream>

#include "lib/Boardgame/Boardgame.h"

using namespace std;

int main()
{
    Boardgame boardgame;

    cout << "Welcome to Connect Four!" << endl;

    cout << "Initial boardgame:" << endl;
    boardgame.showBoardgame();
    
    boardgame.dropPiece(2, 1);
    boardgame.showBoardgame();

    

    return 1;
};
