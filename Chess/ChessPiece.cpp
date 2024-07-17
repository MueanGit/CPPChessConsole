#include "ChessPiece.h"

#include "ChessGame.h"

ChessPiece::ChessPiece(bool whiteOrBlack, int id, std::pair<int,int> position)
    :white0Black1(whiteOrBlack), id(id), position(position)
{
}

void ChessPiece::move(int pos)
{
}

void ChessPiece::updateValidPos()
{
    validPos.clear();
}

void ChessPiece::capture(ChessPiece& opponent)
{
    opponent.beCaptured();
}

void ChessPiece::beCaptured()
{
    if(ChessGame::getPieceMap().contains(id))
    {
        ChessGame::deleteFromPieceMap(id);
        ChessGame::board[position.first][position.second].reset(nullptr);
    }
}

std::vector<std::pair<int, int>> ChessPiece::getValidPos()
{
    updateValidPos();
    return validPos;
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
