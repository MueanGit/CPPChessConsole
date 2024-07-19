#include <iostream>
#include <memory>

#include "Bishop.h"
#include "ChessGame.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

using namespace std;


int main(int argc, char* argv[])
{
    using namespace std;

    ChessGame game;

    ChessGame::board[5][4] = make_unique<Bishop>(0,88,make_pair(5,4));
    ChessGame::board[3][5] = make_unique<Knight>(1,77,make_pair(3,5));
    auto test = ChessGame::board[5][4];
    ChessGame::printBoard();
    
    ChessGame::displayValidMove(*test);
    test->printValidPos();

    int buffer;
    cout << "Type the number of the position you want to move to:\n";
    cin >> buffer;
    
    test->move(test->inputToPos[buffer]);
    ChessGame::displayValidMove(*test);
    test->printValidPos();

    // Wait for user input to prevent the console from closing
    std::cout << "Press Enter to close the console...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any previous input
    std::cin.get(); // Wait for Enter key
    
    return 0;
}
