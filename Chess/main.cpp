#include <iostream>
#include <memory>
#include <iostream>
#include <climits>
#include <limits>
#include <fcntl.h>
#include <locale>

#include "Bishop.h"
#include "ChessGame.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Queen.h"

using namespace std;

int getValidatedIntInput()
{
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid integer: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input
            return value;
        }
    }
}

void game()
{
    ChessGame game;
    while(!ChessGame::getIsGameOver())
    {
        select:
            ChessGame::turn();
        int unitToMove=INT_MAX;
        do{
            unitToMove = getValidatedIntInput();
        }while (!ChessGame::selectPiece(unitToMove));
        const auto selected = ChessGame::pieceMap[unitToMove];
        do{
            std::cout << "Type a negative number to select another piece\n";
            ChessGame::displayValidMove(*selected);
            int posToMove = INT_MIN;
            posToMove = getValidatedIntInput();
            if(posToMove<0)
                goto select;
            selected->move(selected->inputToPos[posToMove]);
        }while(!ChessGame::bJustMoved);
    }
    ChessGame::printBoard();
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
