//
// Created by Juan Diego Castro Padilla on 6/05/22.
//

#include "../include/Game.h"

// play function to handle subfunctions also lots of robot overlord stuff
void Game::play(){
    std::cout<< "You wish to challenge a computer in Hex? Very well, Let's play!"
        << std::endl << std::endl;
    while(true)
    {
        setup();
        choose();
        char userIn;
        bool counter = false;

        int turn = (computer == Player::BLACK ? 0:1);
        while(!counter)
        {
            turn = !turn;
            if(turn)
                counter = computerTurn();
            else
                counter = playerTurn();
        }

        if(turn == 1)
        {
            std::cout << "I win! Robots > Mankind!!" << std::endl; // feelsbadman
            std::cout << "Want to redeem yourself? (y/n) ";
            std::cin >> userIn;
        }
        else
        {
            std::cout << "What?!?! How did you win???" << std::endl;
            std::cout << "That was a fluke! Let me try again! (y/n) ";
            std::cin >> userIn;
        }

        if(userIn != 'y' && userIn != 'Y')
            break;
        std::cin.clear();
    }
    std::cout << "Shutting down now, come challenge me again!" << std::endl;
}

// customizable dimensions
// CAREFUL FOR >11 IT GETS SLOW
void Game::setup(){
    std::string border(25, '+');

    int dimensions;
    std::cout << "How big of a board do you want to play on? (5 - 11 recommended): ";
    std::cin >> dimensions;

    if(dimensions > 0)
    {
        std::cin.clear();
        board = Board(dimensions);
    }
    else
    {
        std::cout << "Hey! That's not a positive number! I guess I'll pick 9.\n";
        board = Board(9); // could have while(true) but code expects competency
    }
    std::cout << "Good! The board is set!\n";
    board.printBoard();
}

// no implementation of PIE RULE yet... stay tuned
void Game::choose(){
    char side = 'w';


    std::cout << "Now we need to pick sides. I'll let you pick. (b/w): ";
    std::cin >> side;
    if(side == 'b' || side == 'B')
    {
        player = Player::BLACK;
        computer = Player::WHITE;
    }
    else if(side == 'w' || side == 'W')
    {
        player = Player::WHITE;
        computer = Player::BLACK;
    }
    else
    {
        std::cout << "That's not a valid side...not taking this seriously, huh?\n";
        std::cout << "I guess I'll choose then...I'm player black!" << std::endl << std::endl;
        player = Player::WHITE;
        computer = Player::BLACK;
    }
    std::cin.clear();
}

// turns true if AI won otherwise AI turn handler
bool Game::computerTurn(){
    std::cout << "My turn! I move: ";
    auto move = robotAI.next(board, computer); // calculate optimal move
    board.place(move.first, move.second, computer);
    std::cout << move.first << " " << move.second << std::endl;
    board.printBoard();
    return board.win(move.first, move.second);
}

//returns true if u win otherwise player turn handler
bool Game::playerTurn(){
    int x, y;
    std::cout << "Your turn!" << std::endl;
    while(true)
    {
        std::cout << "Where are you putting your piece? (x y = ) ";
        std::cin >> x >> y;
        if(board.place(x,y,player))
            break;
        std::cout << "You can't do that!" << std::endl;
    }
    board.printBoard();
    return board.win(x,y);
}
