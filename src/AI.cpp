//
// Created by Juan Diego Castro Padilla on 6/05/22.
//

#include "../include/AI.h"

// helper for next()
// all  empty spots on board stored on  permutation
// then rand. empty spot picked and played off of,
// wins are tracked and the win value is then returned.
double AI::getWins(Board &board, Player player){
    auto blank = board.getEmpty();
    int winCount = 0;
    std::vector<int> perm(blank.size());
    for (int i=0; i<perm.size(); i++)
        perm[i] = i;
    for (int n=0; n<1000; n++)
    {
        int turn = (player == Player::BLACK ? 0 : 1);
        for (int i=perm.size(); i>1; i--)
        {
            int swap = rand() % i;
            int temp = perm[i-1];
            perm[i-1] = perm[swap];
            perm[swap] = temp; // prand the permutation
        }
        for (int i=0; i<perm.size(); i++)
        {
            turn = !turn; //easy bool turn tracking
            int x = blank[perm[i]].first;
            int y = blank[perm[i]].second;
            if (turn)
            {
                board.place(x, y, Player::WHITE);
            }
            else
            {
                board.place(x, y, Player::BLACK);
            }
        }
        if (board.winner() == player)
            winCount++;

        for (auto itr = blank.begin(); itr != blank.end(); ++itr)
            board.badMove(itr->first, itr->second); // take back rand moves
    }
    return static_cast<double>(winCount) / 1000;
}

// montecarlo simulation, with getWins() it finds the
// value of moves by making random permutations and doing simulation moves
// on each and tracks no. wins. The moves are given the no.wins as a move
// value, the best value is the best move.
std::pair<int, int> AI::next(Board &board, Player p){
    auto blank = board.getEmpty();
    double bestMove = 0;
    std::pair<int, int> move = blank[0];

    for (int i=0; i<blank.size(); i++){
        int x = blank[i].first;
        int y = blank[i].second;
        board.place(x, y, p);

        double moveValue = getWins(board, p);
        if (moveValue > bestMove)
        {
            move = blank[i];
            bestMove = moveValue;
        }

        board.badMove(x, y);
    }
    return move;
}
