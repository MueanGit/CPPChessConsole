#include "Knight.h"

Knight::Knight(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    if(whiteOrBlack) symbol = "♞"; // Black
    else symbol = "♘"; // White
}

void Knight::move(std::pair<int, int> posToMove)
{
    ChessPiece::move(posToMove);
}
