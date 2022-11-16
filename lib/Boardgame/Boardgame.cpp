#include <iostream>

#include "Boardgame.h"

using namespace std;

Boardgame::Boardgame()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            this->boardgame[i][j] = 0;
        }
    }
};

/**
 * @brief Boardgame::showBoardgame
 *  
 * 0 = empty
 * 1 = player 1 (red)
 * 2 = player 2 (yellow)
 */
void Boardgame::showBoardgame()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            char state;

            switch (this->boardgame[i][j])
            {
                case 0:
                default:
                    state = '-';
                    break;
                case 1:
                    state = 'R';
                    break;
                case 2:
                    state = 'Y';
                    break;
            }

            cout << state << " ";
        }
        cout << endl;
    }
};
