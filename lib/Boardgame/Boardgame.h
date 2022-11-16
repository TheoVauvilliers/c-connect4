// Boardgame.h
#ifndef BOARDGAME_H
#define BOARDGAME_H

/**
 * @brief The Boardgame class
 * 
 * 0 = empty
 * 1 = player 1 (red)
 * 2 = player 2 (yellow)
 */
class Boardgame
{
    protected:
        /* BOARDGAME INFO */
        const static int ROWS = 6;
        const static int COLUMNS = 7;
        /* PIECES INFO */
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
        bool canDropPiece(int column);
    public:
        Boardgame();
        void showBoardgame();
        bool dropPiece(int column, int player);
};

#endif
