#include "King.h"

King::King(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    bIsKing = true;
    if(whiteOrBlack) symbol = "♚"; // Black
    else symbol = "♔"; // White
}

void King::move(std::pair<int, int> posToMove)
{
    ChessPiece::move(posToMove);
}

void King::updateValidPos()
{
    ChessPiece::updateValidPos();
    int row = position.first;
    int col = position.second;

    if(canMoveTo(row+1,col))
        validPos.push_back({row+1,col});
    if(canMoveTo(row-1,col))
        validPos.push_back({row-1,col});
    if(canMoveTo(row,col+1))
        validPos.push_back({row,col+1});
    if(canMoveTo(row,col-1))
        validPos.push_back({row,col-1});
    if(canMoveTo(row+1,col+1))
        validPos.push_back({row+1,col+1});
    if(canMoveTo(row+1,col-1))
        validPos.push_back({row+1,col-1});
    if(canMoveTo(col-1,row+1))
        validPos.push_back({row-1,col+1});
    if(canMoveTo(row-1,col-1))
        validPos.push_back({row-1,col-1});
}
