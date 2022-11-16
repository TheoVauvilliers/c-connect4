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
        int boardgame[6][7];

    public:
        Boardgame();
        void showBoardgame();
};

#endif
