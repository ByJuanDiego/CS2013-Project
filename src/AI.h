//
// Created by Juan Diego Castro Padilla on 6/05/22.
//

#ifndef CS2013_PROJECT_AI_H
#define CS2013_PROJECT_AI_H

#include "Board.h"

class AI{// based on montecarlo simulation, more below
public:
    static double getWins(Board& board, Player p);
    virtual std::pair <int, int> next(Board& board, Player p);
};

#endif //CS2013_PROJECT_AI_H
