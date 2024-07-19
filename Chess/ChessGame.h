#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
//1
class ChessGame
{
public:
    ChessGame();
    static void printBoard();

    static bool isSquareEmpty(int row, int col);
    static std::vector<std::vector<std::shared_ptr<class ChessPiece>>> board;
    static bool inBound(int row, int col);

    static void displayValidMove(ChessPiece& piece);
    static std::unordered_map<int, ChessPiece*> getPieceMap();
    static void deleteFromPieceMap(int id);

    static bool checkIfInCheck(ChessPiece& pieceJustMoved);
    
private:
    
    void initializeBoard();

    //Every piece on the board get a corresponding id
    //Retrieve the piece by ID use this map
    //White has an odd ID and black has even ID
    static std::unordered_map<int, ChessPiece*> pieceMap;
};
