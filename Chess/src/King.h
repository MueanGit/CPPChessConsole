#pragma once
#include "ChessPiece.h"

class King: public ChessPiece
{
public:
    King() = default;
    King(bool whiteOrBlack, int id, std::pair<int,int> position);
    void move(std::pair<int, int> posToMove) override;
    void beCaptured() override;

    void updateValidPos() override;

    // TO DO
    // Add castling
};
