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

ChessGame::ChessGame()
{
    bIsGameOver = false;
    bBlackTurn = true;
    bJustMoved = false;
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

bool ChessGame::isInCheck(ChessPiece& pieceJustMove)
{
    bBlackTurn = !bBlackTurn;
    for(const auto &pos: pieceJustMove.getValidPos())
    {
        if(!inBound(pos.first,pos.second)) return false;
        if(board[pos.first][pos.second]&&board[pos.first][pos.second]->getIsKing())//Problem
        {
            std::cout << "Checkmate!" << std::endl;
            return true;
        }
    }
    return false;
}

bool ChessGame::selectPiece(int num)
{
    if(pieceMap.find(num) == pieceMap.end())
    {
        std::cout << "That unit does not exist!"<<std::endl;
        return false;
    }
    if(bBlackTurn && num%2 != 0)
    {
        std::cout << "Please select your own piece(black)\n";
        return false;
    }
    if(!bBlackTurn && num%2 == 0)
    {
        std::cout << "Please select your own piece(white)\n";
        return false;
    }
    return true;
}

void ChessGame::gameOver(bool winner)
{
    bIsGameOver = true;
    std::cout << "!!!!!!!!!! Game over! ";
    if(!winner)
        std::cout << "White has won. ";
    else
        std::cout << "Black has won. ";
    std::cout << "!!!!!!!!!!"<<std::endl;
}

void ChessGame::turn()
{
    bJustMoved = false;
    std::string separator(56, '*');
    std::cout << separator << "\n";

    for(const auto &row: board)
    {
        for(const auto &elem: row)
        {
            std::cout << "[";
            if(elem)
            {
                //Check whose turn, only display the number that can be isInCheck by current player
                if(elem->white0Black1==bBlackTurn)
                {
                    std::string id = std::to_string(elem->getID());
                    if(elem->getID()<10) id.insert(0,"0");
                    std::cout << *elem << "("<<id<<")";
                }
                else
                {
                    std::cout << ".."<<*elem<<"..";
                }
            }
            else
                std::cout << ".....";
            std::cout << "]";
        }
        std::cout << "\n";
    }

    if(bBlackTurn)
    {
        std::cout << "It is now black turn, "
                     "select the number (without 0 in the front) "
                     "of the piece you want to move.\n";
    }
    else
    {
        std::cout << "It is now white turn, "
                     "select the number (without 0 in the front) "
                     "of the piece you want to move.\n";
    }
    
    std::cout << separator << "\n";
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

void ChessGame::promote(Pawn pawn)
{
    int row = pawn.position.first;
    int col = pawn.position.second;

    int id = pawn.getID();

    std::unique_ptr<Queen> newQueen = std::make_unique<Queen>(pawn.white0Black1,id,pawn.position);
    board[row][col] = nullptr;
    board[row][col] = std::move(newQueen);
    deleteFromPieceMap(id);
    pieceMap[id]= board[row][col].get();
}

void ChessGame::displayValidMove(ChessPiece& piece)
{
    auto validMoves = piece.getValidPos();

    if(validMoves.size()==0)
    {
        std::cout <<"!!!!!This piece cannot be moved, select another one\n";
        return; 
    }
        
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
                if(validMovesMap.find(posStr) != validMovesMap.end())
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
                if(validMovesMap.find(posStr) != validMovesMap.end())
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
    std::cout << "Type the number of position in <> you want to move to\n";
    std::cout << separator << "\n";
}

std::unordered_map<int, ChessPiece*> ChessGame::getPieceMap()
{
    return pieceMap;
}
