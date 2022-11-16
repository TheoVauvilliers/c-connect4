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

    cout << endl;
};

bool Boardgame::canDropPiece(int column)
{
    return this->boardgame[0][column] == Boardgame::EMPTY;
};

bool Boardgame::dropPiece(int column, int player)
{
    if (!this->canDropPiece(column))
    {
        cout << "Piece not dropped!" << endl;
        return false;
    }

    for (int currentRow = Boardgame::ROWS - 1; currentRow >= 0; currentRow--)
    {
        if (this->boardgame[currentRow][column] == Boardgame::EMPTY)
        {
            this->lastPlayer = player;
            this->lastColumn = column;
            this->lastRow = currentRow;

            this->boardgame[currentRow][column] = player;
            cout << "Piece dropped at row " << currentRow << " and column " << column << endl;
            return true;
        }
    }

    cout << "DEBUG: We should never get here!" << endl << __FILE__ << " : " << __LINE__ << endl;
    return false;
};

bool Boardgame::areFourConnected()
{
    // TODO: Implementare

    // Connected horizontally

    // Connected vertically

    // Connected diagonally

    return false;
};
