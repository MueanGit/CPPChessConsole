#include "Pawn.h"
#include "ChessGame.h"

Pawn::Pawn(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    bFirstMove = true;
    if(whiteOrBlack) symbol = "♟";
    else symbol = "♙";
}

void Pawn::move(std::pair<int, int> posToMove)
{
    ChessPiece::move(posToMove);
    bFirstMove = false;
    if(white0Black1) //Black
    {
        if(position.first==0)
            ChessGame::promote(*this);
    }
    else
    {
        if(position.first==7)
            ChessGame::promote(*this);
    }
}

void Pawn::updateValidPos()
{
    ChessPiece::updateValidPos();
    const int row = position.first;
    const int col = position.second;

    int direction = white0Black1 ? -1 : 1; // Assuming black pawns move upwards (-1) and white pawns move downwards (+1)

    // Move forward one square
    if (ChessGame::inBound(row + direction, col) && ChessGame::isSquareEmpty(row + direction, col))
    {
        validPos.push_back({row + direction, col});
    }

    // Move forward two squares if it's the first move
    if (bFirstMove && ChessGame::inBound(row + 2 * direction, col) && ChessGame::isSquareEmpty(row + 2 * direction, col) && ChessGame::isSquareEmpty(row + direction, col))
    {
        validPos.push_back({row + 2 * direction, col});
    }

    // Capture diagonally to the left
    if (ChessGame::inBound(row + direction, col - 1) && !ChessGame::isSquareEmpty(row + direction, col - 1) && canMoveTo(row+direction, col-1))
    {
        validPos.push_back({row + direction, col - 1});
    }

    // Capture diagonally to the right
    if (ChessGame::inBound(row + direction, col + 1) && !ChessGame::isSquareEmpty(row + direction, col + 1) && canMoveTo(row+direction, col+1))
    {
        validPos.push_back({row + direction, col + 1});
    }
    
}


