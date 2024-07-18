#pragma once
#include "ChessPiece.h"

class Knight: public ChessPiece
{
public:
    Knight(){}
    Knight(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(std::pair<int, int> posToMove) override;
    
};
