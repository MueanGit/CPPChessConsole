#pragma once
#include <vector>
#include <memory>
#include <unordered_map>

class ChessGame
{
public:
    ChessGame();
    void printBoard() const;

    static bool bIsSquareEmpty(int row, int col);
    static std::vector<std::vector<std::unique_ptr<class ChessPiece>>> board;
    static bool inBound(int row, int col);
private:
    
    void initializeBoard();

    //Every piece on the board get a corresponding id
    //Retrieve the piece by ID use this map
    //White has an odd ID and black has even ID
    std::unordered_map<int, ChessPiece*> pieceMap;
    std::vector<int> whiteID;
    
};
