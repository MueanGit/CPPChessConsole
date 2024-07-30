#include "Knight.h"

#include "ChessGame.h"

Knight::Knight(bool whiteOrBlack, int id, std::pair<int,int> position)
:ChessPiece{whiteOrBlack, id, position}
{
    if(whiteOrBlack) symbol = "♞"; // Black
    else symbol = "♘"; // White
}

void Knight::move(std::pair<int, int> posToMove)
{
    ChessPiece::move(posToMove);
}

void Knight::updateValidPos()
{
    ChessPiece::updateValidPos();
    const int row = position.first;
    const int col = position.second;

    // * * O   * * *
    // * * * ->O * * 
    if(canMoveTo(row+1,col+2))
        validPos.push_back({row+1, col+2});
    
    // * * *   O * *
    // * * O ->* * * 
    if(canMoveTo(row-1, col-2))
        validPos.push_back({row-1, col-2});
    
    // O * *   * * *
    // * * * ->* * O 
    if(canMoveTo(row+1, col-2))
        validPos.push_back({row+1, col-2});
    
    // * * *   * * O
    // O * * ->* * * 
    if(canMoveTo(row-1, col+2))
        validPos.push_back({row-1, col+2});
    
    // O *     * *
    // * *  -> * *
    // * *     * O
    if(canMoveTo(row+2, col+1))
        validPos.push_back({row+2, col+1});
    
    // * *     * O
    // * *  -> * *
    // O *     * *
    if(canMoveTo(row-2, col+1))
        validPos.push_back({row-2, col+1});
    
    // * O     * *
    // * *  -> * *
    // * *     O *
    if(canMoveTo(row+2, col-1))
        validPos.push_back({row+2, col-1});
    
    // * *     O *
    // * *  -> * *
    // * O     * *
    if(canMoveTo(row-2, col-1))
        validPos.push_back({row-2, col-1});
}
