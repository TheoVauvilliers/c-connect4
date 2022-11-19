// Boardgame.h
#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <vector>

using namespace std;

/**
 * @brief The Boardgame class
 * 
 * The game ends when a player aligns 4 tokens in a row.
 * The player 1 has red token.
 * The player 2 has yellow token.
 */
class Boardgame
{
    protected:
        /* BOARDGAME INFO */
        const static int ROWS = 6;
        const static int COLUMNS = 7;
        /* TOKENS INFO */
        const static int EMPTY = 0;
        const static int PLAYER_1 = 1;
        const static int PLAYER_2 = 2;
        /* VARIABLE DECLARATION */
        // vector<int> boardgame[Boardgame::ROWS][Boardgame::COLUMNS];
        vector<vector<int>> boardgame;
        int lastPlayer;
        int lastColumn;
        int lastRow;
        bool gameOver = false;
        /* PROTECTED METHOD */
        char humanToken(int value);
        bool canDropToken(int column);
        bool areFourConnectedHorizontally();
        bool areFourConnectedVertically();
        bool areFourConnectedDiagonnaly();
        bool inArray(vector<int> needle, vector<vector<int>> haystack);
        bool areFourConnectedDiagonallyTopLeft();
        bool areFourConnectedDiagonallyTopRight();
    public:
        Boardgame();
        // TODO: Create destructor method
        void showBoardgame();
        bool dropToken(int column, int player);
        bool areFourConnected();
};

#endif
