// Boardgame.h
#ifndef BOARDGAME_H
#define BOARDGAME_H

/**
 * @brief The Boardgame class
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
        int boardgame[Boardgame::ROWS][Boardgame::COLUMNS];
        int lastPlayer;
        int lastColumn;
        int lastRow;
        bool gameOver = false;
        /* PROTECTED METHOD */
        bool canDropToken(int column);
    public:
        Boardgame();
        void showBoardgame();
        bool dropToken(int column, int player);
        bool areFourConnected();
        bool areFourConnectedHorizontally();
        bool areFourConnectedVertically();
};

#endif
