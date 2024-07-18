#include "Bishop.h"

Bishop::Bishop(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    if(whiteOrBlack) symbol = "♝"; // Black
    else symbol = "♗"; // White
}

void Bishop::move(std::pair<int, int> posToMove)
{
    ChessPiece::move(posToMove);
}
