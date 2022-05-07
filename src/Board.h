//
// Created by Juan Diego Castro Padilla on 6/05/22.
//

#ifndef CS2013_PROJECT_BOARD_H
#define CS2013_PROJECT_BOARD_H

#include "definitions.h"

class Board {

private:

    static int direct[6][2];
    static char white;
    static char black;
    static char empty;
    int size;
    std::string line;
    std::vector<std::vector<char>> board;

private:

    bool inBoard(int x, int y);
    void borders(int x, int y, std::vector<bool>& condition, char side);
    void bfsSearch(std::vector<std::pair<int,int>>& start, std::vector<bool>& condition);

public:

    Board(){}
    Board(int size):size(size),board(size,std::vector<char>(size,'+'))
    {
        line = "\\";                   // easier to follow paths
        for(int i = 1; i < size; i++)
            line += " / \\";
    } // matrix presentation looks best for this game

    bool place(int x, int y, Player p);
    bool badMove(int x, int y);
    std::vector<std::pair<int,int>> getEmpty();
    bool win(int x, int y);
    Player winner();
    void printBoard();

};


#endif //CS2013_PROJECT_BOARD_H
