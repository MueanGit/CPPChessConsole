#include <iostream>
#include <memory>

#include "ChessGame.h"
#include "Knight.h"
#include "Pawn.h"

using namespace std;


int main(int argc, char* argv[])
{
    using namespace std;

    ChessGame game;

    ChessGame::board[4][3] = make_unique<Knight>(0,99,make_pair(4,3));
    auto test = ChessGame::board[4][3];

    ChessGame::board[5][2] = make_unique<Pawn>(0,99,make_pair(5,2));
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
