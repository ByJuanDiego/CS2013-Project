//
// Created by Juan Diego Castro Padilla on 6/05/22.
//

#include "Board.h"

// static defintions
int Board::direct[6][2] = {
                {-1, 0},
                {-1, 1},
                {0,-1},
                {0,1},
                {1, -1},
                {1, 0} // corners
        };

char Board::white = 'W';
char Board::black = 'B';
char Board::empty = '+';

bool Board::inBoard(int x, int y) {
    return (x < size && y < size && x >= 0 && y >= 0);
}

// helper for win(), mutates conditionals (2 element vector) to check borders
void Board::borders(int x, int y, std::vector<bool>& condition, char side){
    if(side == black)
    {
        if(y == 0)
            condition[0] = true;
        if(y == size - 1)
            condition[1] = true;

    }
    else
    {
        if(x == 0)
            condition[0] = true;
        if(x == size - 1)
            condition[1] = true;
    }
}

// "places" a piece on the board, assigns cell block to B or W
bool Board::place(int x, int y, Player p){
    if(inBoard(x,y) && board[x][y] == empty)
    {
        if(p == Player::BLACK)
            board[x][y] = black;
        else
            board[x][y] = white;
        return true;
    }
    return false;
}

// retracts a badMove (or in my case the random suboptimals)
bool Board::badMove(int x, int y){
    if(inBoard(x,y))
    {
        board[x][y] = empty;
        return true;
    }
    return false;
}

// returns all the empty spots on the board, useful for mcts
std::vector<std::pair<int,int>> Board::getEmpty(){
    std::vector<std::pair<int,int>> blankSpots;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            if(board[i][j] == empty)
                blankSpots.push_back(std::make_pair(i,j));
    }
    return blankSpots;
}

// Breadth-first search and checks borders() win conditionals
void Board::bfsSearch(std::vector<std::pair<int,int>>& start, std::vector<bool>& condition){
    if(start.size() != 0)
    {
        int x = start[0].first;
        int y = start[0].second;
        char side = board[x][y];

        std::vector<std::vector<bool>> visited(size, std::vector<bool>(size));
        std::queue<std::pair<int,int>> trace;


        for (auto itr = start.cbegin(); itr != start.cend(); ++itr)
        {
            trace.push(*itr);
            visited[itr->first][itr->second] = true;
        }
        while(!(trace.empty()))
        {
            auto top = trace.front();
            borders(top.first, top.second, condition, side);
            trace.pop();

            for(int i = 0; i < 6; i++)
            {
                int xCursor = top.first + direct[i][0];
                int yCursor = top.second + direct[i][1];
                if(inBoard(xCursor, yCursor) && board[xCursor][yCursor] == side
                   && visited[xCursor][yCursor] == false)
                {
                    visited[xCursor][yCursor] = true;
                    trace.push(std::make_pair(xCursor,yCursor));
                }
            }
        }
    }
}

// BFS last registed move (x,y) returns true if path made
bool Board::win(int x, int y){
    if(inBoard(x,y) && board[x][y] != empty)
    {

        std::vector<bool> condition(2, false); // two opposite ends
        std::vector<std::pair<int,int>> start(1, std::make_pair(x,y));

        bfsSearch(start, condition);
        return condition[0] && condition[1];
    }
    return false;
}

// there logically must be one winner so when win condition met use
// BFS to check if black made a path from left to right, if not
// white is necessarily the winner
Player Board::winner(){
    std::vector<bool> condition(2, false); // tracks side to side win
    std::vector<std::pair<int,int>> start;
    for(int i =0; i<size; i++)
        if(board[i][0] == black)
            start.push_back(std::make_pair(i,0));

    bfsSearch(start, condition);
    return (condition[0] && condition[1]) ? Player::BLACK : Player::WHITE;
}

// printing a board based on coursera example mostly a e s t h e t i c s
void Board::printBoard(){
    if (size <= 0)
        return;

    // start top left
    std::cout << "  0";
    for (int i=1; i<size; i++)
        std::cout << " w " << i; // readability
    std::cout << std::endl;

    // print the first line
    std::cout << "0 " << board[0][0];
    for (int i=1; i<size; i++)
        std::cout << "---" << board[0][i];
    std::cout << std::endl;

    std::string indent = "";
    for (int i=1; i<size; i++)
    {
        indent += ' ';
        std::cout << indent << "b " << line << std::endl;
        if (i < 10)
        {
            indent += ' ';
            std::cout << indent << i << ' ' << board[i][0];
        }
        else
        {
            std::cout << indent << i << ' ' << board[i][0];
            indent += ' ';
        }

        for (int j=1; j<size; j++)
            std::cout << "---" << board[i][j];
        std::cout << std::endl;
    }
    std::cout << "_________________________________________________________" << std::endl;
}
