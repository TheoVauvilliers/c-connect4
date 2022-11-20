#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
    const bool HORIZONTALLY = this->areFourConnectedLoop(0, this->lastRow, "horizontally");
    const bool VERTICALLY = this->areFourConnectedLoop(this->lastColumn, Boardgame::ROWS - 1, "vertically");
    const bool DIAGONALLY = this->areFourConnectedDiagonally("topLeft") || this->areFourConnectedDiagonally("bottomLeft");

    return HORIZONTALLY || VERTICALLY || DIAGONALLY;
};

/**
 * @brief Boardgame::areFourConnectedDiagonally
 * 
 * @param string direction - direction to verify that tokens are connected
 * 
 * @return bool - true if four tokens are connected diagonally, false otherwise
 */
bool Boardgame::areFourConnectedDiagonally(string direction) {
    vector<vector<int>> excludedPosition;

    if (direction == "topLeft") excludedPosition = {{0, 5}, {0, 4}, {0, 3}, {1, 5}, {1, 4}, {2, 5}, {4, 0}, {5, 0}, {5, 1}, {6, 0}, {6, 1}, {6, 2}};
    else excludedPosition = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {2, 0}, {4, 5}, {5, 4}, {5, 5}, {6, 5}, {6, 4}, {6, 3}};

    if (!this->inArray(vector<int> {this->lastColumn, this->lastRow}, excludedPosition)) {
        int diff, x, y;

        if (direction == "topLeft") {
            diff = (this->lastColumn > this->lastRow) ? diff = this->lastRow : diff = this->lastColumn;
            y = this->lastRow - diff;
        } else {
            diff = (this->lastColumn > (Boardgame::ROWS - 1) - this->lastRow) ? diff = (Boardgame::ROWS - 1) - this->lastRow : diff = this->lastColumn;
            y = this->lastRow + diff;
        }

        return this->areFourConnectedLoop(this->lastColumn - diff, y, direction);
    }

    return false;
}

/**
 * @brief Boardgame::areFourConnectedLoop
 * 
 * @param int x - initial position for x
 * @param int y - initial position for y
 * @param string direction - direction to verify that tokens are connected
 * 
 * @return bool - true if four tokens are connected, false otherwise
 */
bool Boardgame::areFourConnectedLoop(int x, int y, string direction) {
    char lastState = Boardgame::EMPTY;
    int counter = 0;

    while ((direction == "horizontally"  && (x < Boardgame::COLUMNS)) ||
           (direction == "vertically" && (y >= 0)) ||
           (direction == "topLeft"  && ((x < Boardgame::COLUMNS) && (y < Boardgame::ROWS))) ||
           (direction == "bottomLeft" && ((x < Boardgame::COLUMNS) && (y >= 0)))) {
        if (this->boardgame[y][x] == lastState && lastState != Boardgame::EMPTY) {
            counter++;
            if (counter == 4) return true;
        } else {
            lastState = this->boardgame[y][x];
            counter = 1;
        }

        if (direction == "horizontally" || direction == "topLeft" || direction == "bottomLeft") x++;
        if (direction == "vertically" || direction == "bottomLeft") y--;
        if (direction == "topLeft") y++;
    }

    return false;
}

/**
 * @brief Boardgame::inArray
 * 
 * @param vector<int> needle
 * @param vector<vector<int>> haystack
 * 
 * @return bool - true if the needle is found at least once in the haystack, false otherwise
 */
bool Boardgame::inArray(vector<int> needle, vector<vector<int>> haystack) {
    return find(begin(haystack), end(haystack), needle) != end(haystack);
}
