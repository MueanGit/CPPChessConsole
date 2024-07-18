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
}

void Pawn::updateValidPos()
{
    ChessPiece::updateValidPos();
    const int row = position.first;
    const int col = position.second;

    int direction = white0Black1 ? -1 : 1; // Assuming black pawns move upwards (-1) and white pawns move downwards (+1)

    // Move forward one square
    if (ChessGame::inBound(row + direction, col) && ChessGame::bIsSquareEmpty(row + direction, col)) {
        validPos.push_back({row + direction, col});
    }

    // Move forward two squares if it's the first move
    if (bFirstMove && ChessGame::inBound(row + 2 * direction, col) && ChessGame::bIsSquareEmpty(row + 2 * direction, col) && ChessGame::bIsSquareEmpty(row + direction, col)) {
        validPos.push_back({row + 2 * direction, col});
    }

    // Capture diagonally to the left
    if (ChessGame::inBound(row + direction, col - 1) && !ChessGame::bIsSquareEmpty(row + direction, col - 1) && ChessGame::board[row + direction][col - 1]->white0Black1 != white0Black1) {
        validPos.push_back({row + direction, col - 1});
    }

    // Capture diagonally to the right
    if (ChessGame::inBound(row + direction, col + 1) && !ChessGame::bIsSquareEmpty(row + direction, col + 1) && ChessGame::board[row + direction][col + 1]->white0Black1 != white0Black1) {
        validPos.push_back({row + direction, col + 1});
    }
    
}


