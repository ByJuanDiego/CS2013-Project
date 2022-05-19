//
// Created by Juan Diego Castro Padilla on 6/05/22.
//

#ifndef CS2013_PROJECT_GAME_H
#define CS2013_PROJECT_GAME_H

#include "AI.h"

class Game {

private:
    Player computer;
    Player player;
    AI robotAI;
    Board board;

public:
    Game(){}
    Game(AI& robotAI): robotAI(robotAI){}
    void play();

private:
    void setup();
    void choose();
    bool computerTurn();
    bool playerTurn();

};

#endif //CS2013_PROJECT_GAME_H
