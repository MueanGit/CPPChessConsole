#pragma once
#include "ChessPiece.h"

class Rook: public ChessPiece
{
public:
    Rook(){}
    Rook(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(int pos) override;
    
};
