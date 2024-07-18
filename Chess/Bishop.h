#pragma once
#include "ChessPiece.h"

class Bishop: public ChessPiece
{
public:
    Bishop(){}
    Bishop(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(std::pair<int, int> posToMove) override;
    
};
