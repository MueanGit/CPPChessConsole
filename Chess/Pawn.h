#pragma once

#include "ChessPiece.h"

class Pawn: public ChessPiece
{
public:
    Pawn() = default;
    Pawn(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(std::pair<int, int> pos) override;
    void updateValidPos() override;

    
private:
    bool bFirstMove;
};
