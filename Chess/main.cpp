#include <iostream>
#include <memory>

#include "Bishop.h"
#include "ChessGame.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Queen.h"

using namespace std;

void game()
{
    ChessGame game;
    while(!ChessGame::getIsGameOver())
    {
        ChessGame::turn();

        int unitToMove=INT_MAX;
        do{
            cin >> unitToMove;
        }while (ChessGame::selectPiece(unitToMove));
        const auto selected = ChessGame::pieceMap[unitToMove];
        do{
            ChessGame::displayValidMove(*selected);
            int posToMove = INT_MIN;
            std::cin >> posToMove;
    
            selected->move(selected->inputToPos[posToMove]);
        }while(!ChessGame::bJustMoved);
    }
}

int main(int argc, char* argv[])
{
    using namespace std;
    
    game();
    
    // Wait for user input to prevent the console from closing
    std::cout << "Press Enter to close the console...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any previous input
    std::cin.get(); // Wait for Enter key
    
    return 0;
}
