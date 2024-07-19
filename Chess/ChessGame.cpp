#include "ChessGame.h"

#include <string>
#include <unordered_set>

#include "Bishop.h"
#include "ChessPiece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

std::vector<std::vector<std::shared_ptr<ChessPiece>>> ChessGame::board;
std::unordered_map<int, ChessPiece*> ChessGame::pieceMap;

ChessGame::ChessGame()
{
    board.resize(8);
    for(auto &row: board)
    {
        row.resize(8);
        for(auto &elem: row)
            elem = nullptr;
    }
    initializeBoard();
}

void ChessGame::printBoard()
{
    std::string separator(56, '*');
    std::cout << separator << "\n";
    for(const auto &row: board)
    {
        for(const auto &elem: row)
        {
            std::cout << "[";
            if(elem)
            {
                std::string id = std::to_string(elem->getID());
                if(elem->getID()<10) id.insert(0,"0");
                std::cout << *elem << "("<<id<<")";
            }

            else
                std::cout << ".....";
            std::cout << "]";
        }
        std::cout << "\n";
    }
    std::cout << separator << "\n";
}

bool ChessGame::isSquareEmpty(int row, int col)
{
    if(board[row][col]) return false;
    return true;
}

bool ChessGame::inBound(int row, int col)
{
    return row>=0 && row<8 && col>=0 && col<8;
}

void ChessGame::deleteFromPieceMap(int id)
{
    pieceMap.erase(id);
    delete pieceMap[id];
}


void ChessGame::initializeBoard()
{
    int id = 1;

    // Initialize pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = std::make_unique<Pawn>(false, id, std::make_pair(1,i));
        pieceMap[id++] = board[1][i].get();
        board[6][i] = std::make_unique<Pawn>(true, id, std::make_pair(6,i));
        pieceMap[id++] = board[6][i].get();
    }

    // Initialize rooks
    board[0][0] = std::make_unique<Rook>(false, id, std::make_pair(0,0));
    pieceMap[id++] = board[0][0].get();
    board[7][0] = std::make_unique<Rook>(true, id, std::make_pair(7,0));
    pieceMap[id++] = board[7][0].get();
    board[0][7] = std::make_unique<Rook>(false, id, std::make_pair(0,7));
    pieceMap[id++] = board[0][7].get();
    board[7][7] = std::make_unique<Rook>(true, id, std::make_pair(7,7));
    pieceMap[id++] = board[7][7].get();

    // Initialize knights
    board[0][1] = std::make_unique<Knight>(false, id, std::make_pair(0,1));
    pieceMap[id++] = board[0][1].get();
    board[7][1] = std::make_unique<Knight>(true, id, std::make_pair(7,1));
    pieceMap[id++] = board[7][1].get();
    board[0][6] = std::make_unique<Knight>(false, id, std::make_pair(0,6));
    pieceMap[id++] = board[0][6].get();
    board[7][6] = std::make_unique<Knight>(true, id, std::make_pair(7,6));
    pieceMap[id++] = board[7][6].get();

    // Initialize bishops
    board[0][2] = std::make_unique<Bishop>(false, id, std::make_pair(0,2));
    pieceMap[id++] = board[0][2].get();
    board[7][2] = std::make_unique<Bishop>(true, id, std::make_pair(7,2));
    pieceMap[id++] = board[7][2].get();
    board[0][5] = std::make_unique<Bishop>(false, id, std::make_pair(0,5));
    pieceMap[id++] = board[0][5].get();
    board[7][5] = std::make_unique<Bishop>(true, id, std::make_pair(7,5));
    pieceMap[id++] = board[7][5].get();

    // Initialize queens
    board[0][3] = std::make_unique<Queen>(false, id, std::make_pair(0,3));
    pieceMap[id++] = board[0][3].get();
    board[7][3] = std::make_unique<Queen>(true, id, std::make_pair(7,3));
    pieceMap[id++] = board[7][3].get();

    // Initialize kings
    board[0][4] = std::make_unique<King>(false, id, std::make_pair(0,4));
    pieceMap[id++] = board[0][4].get();
    board[7][4] = std::make_unique<King>(true, id, std::make_pair(7,4));
    pieceMap[id++] = board[7][4].get();
}

void ChessGame::displayValidMove(ChessPiece& piece)
{
    auto validMoves = piece.getValidPos();
    // Every valid move of the piece will get a number assigned, which will be store in a map
    // The number will be display on the square
    // The player can then type that number to move to that square
    // Example: "1,1": 2
    //          "1,2": 3
    std::unordered_map<std::string,int> validMovesMap;

    // Lambda for converting for example [1,1] to "1,1"
    auto posToStr = [&](int r, int c) -> std::string
    {
      return std::to_string(r)+","+std::to_string(c);
    };
    
    for(int i=0; i<validMoves.size(); i++)
    {
        std::string key = posToStr(validMoves[i].first, validMoves[i].second);
        validMovesMap[key] = i;
        piece.inputToPos[i] = {validMoves[i].first, validMoves[i].second};
    }
    std::string separator(56, '*');
    std::cout << separator << "\n";
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            std::cout << "[";
            std::string posStr = posToStr(i,j);
            if(board[i][j])
            {
                if(validMovesMap.contains(posStr))
                {
                    //Add 0 if 1 bit
                    std::string num = std::to_string(validMovesMap[posStr]);
                    if(validMovesMap[posStr]<10) num.insert(0,"0");
                    std::cout << *board[i][j] << "<"<<num<<">";
                }
                //Check if the piece is black or white
                else
                {
                    // Only print number of the team in turn
                    if(board[i][j]->white0Black1 == piece.white0Black1)
                    {
                        //Add 0 if 1 bit
                        std::string id = std::to_string(board[i][j]->getID());
                        if(board[i][j]->getID()<10) id.insert(0,"0");
                        std::cout << *board[i][j] << "("<<id<<")";
                    }
                    else
                    {
                        std::cout << ".." << *board[i][j]<<"..";
                    }
                    
                }
            }
            else
                if(validMovesMap.contains(posStr))
                {
                    std::string num = std::to_string(validMovesMap[posStr]);
                    if(validMovesMap[posStr]<10) num.insert(0,"0");
                    std::cout << "!<"<<num<<">";
                }
                else
                    std::cout << ".....";
            std::cout << "]";
        }
        std::cout << "\n";
    }
    std::cout << separator << "\n";
}

std::unordered_map<int, ChessPiece*> ChessGame::getPieceMap()
{
    return pieceMap;
}
