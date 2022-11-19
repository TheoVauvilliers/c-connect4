#include <iostream>
#include <vector>
#include <algorithm>

#include "Boardgame.h"

using namespace std;

Boardgame::Boardgame()
{
    for (int i = 0; i < Boardgame::ROWS; i++) {
        vector<int> column;

        for (int j = 0; j < Boardgame::COLUMNS; j++) {
            column.push_back(0);
        }

        this->boardgame.push_back(column);
    }
};

/**
 * @brief Boardgame::showBoardgame
 */
void Boardgame::showBoardgame()
{
    for (int i = 0; i < this->boardgame.size(); i++) {
        for (int j = 0; j < this->boardgame[i].size(); j++) {
            cout << this->humanToken(this->boardgame[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
};

/**
 * @brief Boardgame::humanToken
 * 
 * @param int token value
 * 
 * @return char - transform int to char for UI
 */
char Boardgame::humanToken(int value) {
    char token;

    switch (value) {
        case Boardgame::EMPTY:
        default:
            token = '-';
            break;
        case Boardgame::PLAYER_1:
            token = 'R';
            break;
        case Boardgame::PLAYER_2:
            token = 'Y';
            break;
    }

    return token;
}

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

bool Boardgame::inArray(vector<int> needle, vector<vector<int>> haystack) {
    return find(begin(haystack), end(haystack), needle) != end(haystack);
}

/**
 * @brief Boardgame::areFourConnectedDiagonallyTopLeft
 * 
 * @return bool - true if four tokens are connected diagonally, false otherwise
 */
bool Boardgame::areFourConnectedDiagonallyTopLeft() {
    const vector<vector<int>> EXCLUDED_POSITION = {{0, 5}, {0, 4}, {0, 3}, {1, 5}, {1, 4}, {2, 5}, {4, 0}, {5, 0}, {5, 1}, {6, 0}, {6, 1}, {6, 2}};

    if (!this->inArray(vector<int> {this->lastColumn, this->lastRow}, EXCLUDED_POSITION)) {
        int diff;

        if (this->lastColumn > this->lastRow) {
            diff = this->lastRow;
        } else {
            diff = this->lastColumn;
        }

        int x = this->lastColumn - diff;
        int y = this->lastRow - diff;
        int lastState = Boardgame::EMPTY;
        int counter = 0;

        while ((x < Boardgame::COLUMNS) && (y < Boardgame::ROWS)) {
            if (this->boardgame[y][x] == Boardgame::EMPTY) {
                counter = 0;
            } else {
                if (this->boardgame[y][x] == lastState) {
                    counter++;
                    if (counter == 4) return true;
                } else {
                    lastState = this->boardgame[y][x];
                    counter = 1;
                }
            }

            x++;
            y++;
        }
    }

    return false;
}

/**
 * @brief Boardgame::areFourConnectedDiagonallyTopRight
 * 
 * @return bool - true if four tokens are connected diagonally, false otherwise
 */
bool Boardgame::areFourConnectedDiagonallyTopRight() {
    const vector<vector<int>> EXCLUDED_POSITION = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {2, 0}, {4, 5}, {5, 4}, {5, 5}, {6, 5}, {6, 4}, {6, 3}};

    if (!this->inArray(vector<int> {this->lastColumn, this->lastRow}, EXCLUDED_POSITION)) {
        int diff;

        if (this->lastColumn > (Boardgame::ROWS - 1) - this->lastRow) {
            diff = (Boardgame::ROWS - 1) - this->lastRow;
        } else {
            diff = this->lastColumn;
        }

        int x = this->lastColumn - diff;
        int y = this->lastRow + diff;
        int lastState = Boardgame::EMPTY;
        int counter = 0;

        while ((x < Boardgame::COLUMNS) && (y >= 0)) {
            if (this->boardgame[y][x] == Boardgame::EMPTY) {
                counter = 0;
            } else {
                if (this->boardgame[y][x] == lastState) {
                    counter++;
                    if (counter == 4) return true;
                } else {
                    lastState = this->boardgame[y][x];
                    counter = 1;
                }
            }

            x++;
            y--;
        }
    }

    return false;
}
