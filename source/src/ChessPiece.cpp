#include "ChessPiece.h"
#include "ChessGame.h"

#include <algorithm>

ChessPiece::ChessPiece(bool whiteOrBlack, int id, std::pair<int,int> position)
    :white0Black1(whiteOrBlack), id(id), position(position)
{
}

void ChessPiece::move(std::pair<int, int> posToMove)
{
    updateValidPos();
    ChessGame::bJustMoved = true;
    bool found = false;
    for (const auto& pos : validPos) {
        if (pos == posToMove) {
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "You cannot move to that position" << std::endl;
        return;
    }
    
    //if is enemy
    if(canMoveTo(posToMove.first, posToMove.second) && isEnemy(posToMove.first,posToMove.second))
    {
        capture(*ChessGame::board[posToMove.first][posToMove.second]);
    }
    ChessGame::board[posToMove.first][posToMove.second] = std::move(ChessGame::board[position.first][position.second]);
    ChessGame::board[position.first][position.second] = nullptr;
    position = posToMove;
    ChessGame::isInCheck(*this);
}

void ChessPiece::updateValidPos()
{
    validPos.clear();
}

bool ChessPiece::canMoveTo(int row, int col)
{
    if(!ChessGame::inBound(row,col)) return false;
    if(ChessGame::board[row][col]==nullptr) return true;
    return ChessGame::board[row][col]->white0Black1 != white0Black1;
}

bool ChessPiece::isEnemy(int row, int col)
{
    if(!ChessGame::inBound(row,col)) return false;
    if(ChessGame::board[row][col]==nullptr) return false;
    return ChessGame::board[row][col]->white0Black1 != white0Black1;
}

void ChessPiece::capture(ChessPiece& opponent)
{
    opponent.beCaptured();
}

void ChessPiece::beCaptured()
{
    if(ChessGame::getPieceMap().find(id) != ChessGame::getPieceMap().end())
    {
        ChessGame::deleteFromPieceMap(id);
        ChessGame::board[position.first][position.second].reset();
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
