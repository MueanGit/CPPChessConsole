#pragma once
#include "ChessPiece.h"

class Pawn: public ChessPiece
{
public:
    Pawn(){};
    Pawn(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(int pos) override;
    void updateValidPos() override;

    
private:
    bool bFirstMove;
};
