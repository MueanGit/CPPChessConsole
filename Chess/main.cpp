#include <iostream>
#include <memory>

#include "ChessGame.h"
#include "Pawn.h"


int main(int argc, char* argv[])
{
    using namespace std;

    unique_ptr<ChessGame> game(new ChessGame());
    
    
    game->displayValidMove(*game->board[6][1]);
    game->board[6][1]->printValidPos();

    game->displayValidMove(*game->board[6][1]);
    game->board[6][1]->printValidPos();

    /*game->board[3][3] = make_unique<Pawn>(0,99,make_pair(3,3));
    game->displayValidMove(*game->board[6][1]);
    game->board[6][1]->printValidPos();*/

    /*game->board[2][1] = make_unique<Pawn>(1,55,make_pair(2,1));
    game->displayValidMove(*game->board[6][1]);
    game->board[6][1]->printValidPos();*/

    /*game->board[2][2] = make_unique<Pawn>(1,44,make_pair(2,2));
    game->displayValidMove(*game->board[6][1]);
    game->board[6][1]->printValidPos();*/
    
    return 0;
}
