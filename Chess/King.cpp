#include "King.h"

King::King(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    if(whiteOrBlack) symbol = "♚"; // Black
    else symbol = "♔"; // White
}

void King::move(std::pair<int, int> pos)
{
    ChessPiece::move(pos);
}
