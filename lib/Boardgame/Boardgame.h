// Boardgame.h
#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <vector>
#include <string>

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
        /* VARIABLE DECLARATION */
        vector<vector<int>> boardgame;
        int lastPlayer;
        int lastColumn;
        int lastRow;
        bool gameOver = false;
        /* PROTECTED METHOD */
        char humanToken(int value);
        bool canDropToken(int column);
        bool areFourConnected();
        bool areFourConnectedLoop(int x, int y, string direction);
        bool areFourConnectedDiagonally(string direction);

        bool inArray(vector<int> needle, vector<vector<int>> haystack);
    public:
        /* TOKENS INFO */
        const static int PLAYER_1 = 1;
        const static int PLAYER_2 = 2;
        /* PUBLIC METHOD */
        Boardgame();
        ~Boardgame();
        void showBoardgame();
        bool dropToken(int column, int player);
        bool isGameOver();
};

#endif
