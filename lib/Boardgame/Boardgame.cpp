#include <iostream>

#include "Boardgame.h"
#include "../Helper/function.h"

using namespace std;

Boardgame::Boardgame()
{
    for (int i = 0; i < Boardgame::ROWS; i++) {
        for (int j = 0; j < Boardgame::COLUMNS; j++) {
            this->boardgame[i][j] = 0;
        }
    }
};

/**
 * @brief Boardgame::showBoardgame
 */
void Boardgame::showBoardgame()
{
    for (int i = 0; i < Boardgame::ROWS; i++) {
        for (int j = 0; j < Boardgame::COLUMNS; j++) {
            char state;

            switch (this->boardgame[i][j]) {
                case Boardgame::EMPTY:
                default:
                    state = '-';
                    break;
                case Boardgame::PLAYER_1:
                    state = 'R';
                    break;
                case Boardgame::PLAYER_2:
                    state = 'Y';
                    break;
            }
            cout << state << " ";
        }
        cout << endl;
    }
    cout << endl;
};

/**
 * @brief Boardgame::dropToken
 * 
 * @param int column
 * 
 * @return bool - true if the token can be drop, false otherwise
 */
bool Boardgame::canDropToken(int column)
{
    return this->boardgame[0][column] == Boardgame::EMPTY;
};

/**
 * @brief Boardgame::dropToken
 * 
 * @param int column
 * @param int player
 * 
 * @return bool - true if the token has been dropped, false otherwise
 */
bool Boardgame::dropToken(int column, int player)
{
    if (!this->canDropToken(column)) {
        cout << "Token not dropped!" << endl;
        return false;
    }

    for (int currentRow = Boardgame::ROWS - 1; currentRow >= 0; currentRow--) {
        if (this->boardgame[currentRow][column] == Boardgame::EMPTY) {
            this->lastPlayer = player;
            this->lastColumn = column;
            this->lastRow = currentRow;
            this->boardgame[currentRow][column] = player;
            cout << "Token dropped at row " << currentRow << " and column " << column << endl;
            return true;
        }
    }

    cout << "DEBUG: We should never get here!" << endl << __FILE__ << " : " << __LINE__ << endl;
    return false;
};

/**
 * @brief Boardgame::areFourConnected
 * 
 * @return bool - true if four tokens are connected, false otherwise
 */
bool Boardgame::areFourConnected()
{
    const bool HORIZONTALLY = this->areFourConnectedHorizontally();
    const bool VERTICALLY = this->areFourConnectedVertically();
    const bool DIAGONALLY = this->areFourConnectedDiagonnaly();

    return HORIZONTALLY || VERTICALLY || DIAGONALLY;
};

/**
 * @brief Boardgame::areFourConnectedHorizontally
 * 
 * @return bool - true if four tokens are connected horizontally, false otherwise
 */
bool Boardgame::areFourConnectedHorizontally() {
    int lastState, counter;

    for (int i = 0; i < Boardgame::COLUMNS; i++) {
        if (this->boardgame[this->lastRow][i] == Boardgame::EMPTY) {
            counter = 0;
        } else if (i == 0) {
            lastState = this->boardgame[this->lastRow][i];
            counter = 1;
        } else {
            if (this->boardgame[this->lastRow][i] == lastState) {
                counter++;
                if (counter == 4) return true;
            } else {
                lastState = this->boardgame[this->lastRow][i];
                counter = 1;
            }
        }
    }

    return false;
}

/**
 * @brief Boardgame::areFourConnectedVertically
 * 
 * @return bool - true if four tokens are connected vertically, false otherwise
 */
bool Boardgame::areFourConnectedVertically() {
    int lastState, counter;

    for (int i = 0; i < Boardgame::ROWS; i++) {
        if (this->boardgame[i][this->lastColumn] == Boardgame::EMPTY) {
            counter = 0;
        } else if (i == 0) {
            lastState = this->boardgame[i][this->lastColumn];
            counter = 1;
        } else {
            if (this->boardgame[i][this->lastColumn] == lastState) {
                counter++;
                if (counter == 4) return true;
            } else {
                lastState = this->boardgame[i][this->lastColumn];
                counter = 1;
            }
        }
    }

    return false;
}

/**
 * @brief Boardgame::areFourConnectedDiagonnaly
 * 
 * @return bool - true if four tokens are connected diagonally, false otherwise
 */
bool Boardgame::areFourConnectedDiagonnaly() {
    return this->areFourConnectedDiagonallyTopLeft() || this->areFourConnectedDiagonallyTopRight();
}

/**
 * @brief Boardgame::areFourConnectedDiagonallyTopLeft
 * 
 * @return bool - true if four tokens are connected diagonally, false otherwise
 */
bool Boardgame::areFourConnectedDiagonallyTopLeft() {
    return false;
}

/**
 * @brief Boardgame::areFourConnectedDiagonallyTopRight
 * 
 * @return bool - true if four tokens are connected diagonally, false otherwise
 */
bool Boardgame::areFourConnectedDiagonallyTopRight() {
    return false;
}
