#pragma once
#include "ChessPiece.h"

class Queen: public ChessPiece
{
public:
    Queen(){};
    Queen(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(int pos) override;
};
