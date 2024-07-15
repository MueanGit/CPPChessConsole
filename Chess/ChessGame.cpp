#include "ChessGame.h"

#include <string>

#include "Bishop.h"
#include "ChessPiece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

std::vector<std::vector<std::unique_ptr<ChessPiece>>> ChessGame::board;

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

void ChessGame::printBoard() const
{
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
}

bool ChessGame::bIsSquareEmpty(int row, int col)
{
    if(board[row][col]) return false;
    return true;
}

bool ChessGame::inBound(int row, int col)
{
    return row>=0 && row<8 && col>=0 && col<8;
}

void ChessGame::initializeBoard()
{
    int id = 1;

    // Initialize pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = std::make_unique<Pawn>(false, id, std::make_pair(1,i)); //White
        pieceMap[id++] = board[1][i].get();
        board[6][i] = std::make_unique<Pawn>(true, id, std::make_pair(6,i)); //Black
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
