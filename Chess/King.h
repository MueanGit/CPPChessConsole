#pragma once
#include "ChessPiece.h"

class King: public ChessPiece
{
public:
    King(){};
    King(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(std::pair<int, int> posToMove) override;
    
};
