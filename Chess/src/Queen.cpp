#include "Queen.h"


Queen::Queen(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    if(whiteOrBlack) symbol = "♛"; // Black
    else symbol = "♕"; // White
}

void Queen::move(std::pair<int, int> posToMove)
{
    ChessPiece::move(posToMove);
}

void Queen::updateValidPos()
{
    ChessPiece::updateValidPos();
    const int row = position.first;
    const int col = position.second;

    int i = 1;

    while(canMoveTo(row+i,col+i))
    {
        validPos.push_back({row+i,col+i});
        if(isEnemy(row+i,col+i)) break;
        i++;
    }
    i=1;
    while(canMoveTo(row-i,col+i))
    {
        validPos.push_back({row-i,col+i});
        if(isEnemy(row-i,col+i)) break;
        i++;
    }
    i=1;
    while(canMoveTo(row-i,col-i))
    {
        validPos.push_back({row-i,col-i});
        if(isEnemy(row-i,col-i)) break;
        i++;
    }
    i=1;
    while(canMoveTo(row+i,col-i))
    {
        validPos.push_back({row+i,col-i});
        if(isEnemy(row+i,col-i)) break;
        i++;
    }
    i = 1;
    while(canMoveTo(row+i,col))
    {
        validPos.push_back({row+i,col});
        if(isEnemy(row+i,col)) break;
        i++;
    }
    i=1;
    while(canMoveTo(row-i,col))
    {
        validPos.push_back({row-i,col});
        if(isEnemy(row-i,col)) break;
        i++;
    }
    i=1;
    while(canMoveTo(row,col+i))
    {
        validPos.push_back({row,col+i});
        if(isEnemy(row,col+i)) break;
        i++;
    }
    i=1;
    while(canMoveTo(row,col-i))
    {
        validPos.push_back({row,col-i});
        if(isEnemy(row,col-i)) break;
        i++;
    }
}
