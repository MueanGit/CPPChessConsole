#include <iostream>
#include <memory>

#include "ChessGame.h"
#include "Pawn.h"


int main(int argc, char* argv[])
{
    using namespace std;

    unique_ptr<ChessGame> game(new ChessGame());
    game->printBoard();
    cout << *game->board[1][1]<<" \n";
    
    game->board[1][1]->updateValidPos();
    game->board[1][1]->printValidPos();

    game->board[3][1] = make_unique<Pawn>(0,99,make_pair(3,1));
    game->printBoard();
    game->board[1][1]->updateValidPos();
    game->board[1][1]->printValidPos();

    game->board[2][1] = make_unique<Pawn>(1,55,make_pair(2,1));
    game->printBoard();
    game->board[1][1]->updateValidPos();
    game->board[1][1]->printValidPos();

    game->board[2][2] = make_unique<Pawn>(0,44,make_pair(2,2));
    game->printBoard();
    game->board[1][1]->updateValidPos();
    game->board[1][1]->printValidPos();
    
    return 0;
}
