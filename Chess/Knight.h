#pragma once
#include "ChessPiece.h"

class Knight: public ChessPiece
{
public:
    Knight(){}
    Knight(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(int pos) override;
    
};
