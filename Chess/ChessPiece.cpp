#include "ChessPiece.h"

#include "ChessGame.h"

ChessPiece::ChessPiece(bool whiteOrBlack, int id, std::pair<int,int> position)
    :white0Black1(whiteOrBlack), id(id), position(position)
{
}

void ChessPiece::move(std::pair<int, int> pos)
{
    updateValidPos();
    if(std::ranges::find(validPos, pos)==validPos.end())
    {
        std::cout << "You cannot move to that position" << std::endl;
        return;
    }
    //if is enemy
    if(ChessGame::board[pos.first][pos.second]&&ChessGame::board[pos.first][pos.second]->white0Black1 != white0Black1)
    {
        capture(*ChessGame::board[pos.first][pos.second]);
    }
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
