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

    // Is always called after a player has isInCheck
    static bool isInCheck(ChessPiece& pieceJustMoved);
    static bool bJustMoved;

    // Game
    static bool selectPiece(int num);
    static void gameOver(bool winner);
    static bool getIsGameOver() {return bIsGameOver;}

    static void turn();

    //Every piece on the board get a corresponding id
    //Retrieve the piece by ID use this map
    //White has an odd ID and black has even ID
    static std::unordered_map<int, ChessPiece*> pieceMap;
    
    static void promote(class Pawn pawn);
    
private:
    
    void initializeBoard();
    static bool bBlackTurn;
    static bool bIsGameOver;
    
    
    
};


