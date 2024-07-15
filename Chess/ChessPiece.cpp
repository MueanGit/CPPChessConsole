#include "ChessPiece.h"

ChessPiece::ChessPiece(bool whiteOrBlack, int id, std::pair<int,int> position)
    :white0Black1(whiteOrBlack), id(id), position(position)
{
}

void ChessPiece::move(int pos)
{
}

void ChessPiece::capture(std::unique_ptr<ChessPiece> opponent)
{
}

void ChessPiece::beCaptured()
{
}

void ChessPiece::printValidPos()
{
    std::cout<<"[";
    for(const auto &pair: validPos)
    {
        std::cout << "["<<pair.first<<","<<pair.second<<"],";
    }
    std::cout<<"]\n";
}

std::ostream& operator<<(std::ostream& os, const ChessPiece& piece)
{
    os << piece.symbol;
    return os;
}
