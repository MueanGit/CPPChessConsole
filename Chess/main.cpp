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


int main(int argc, char* argv[])
{
    using namespace std;

    ChessGame game;

    ChessGame::board[3][1] = make_unique<King>(1,88,make_pair(3,1));
    ChessGame::board[4][3] = make_unique<King>(0,77,make_pair(4,3));
    auto test = ChessGame::board[3][1];
    ChessGame::printBoard();
    
    ChessGame::displayValidMove(*test);
    test->printValidPos();

    while(true)
    {
        int buffer;
        cout << "Type the number of the position you want to move to:\n";
        cin >> buffer;
    
        test->move(test->inputToPos[buffer]);
        ChessGame::displayValidMove(*test);
        test->printValidPos();
    }
    

    // Wait for user input to prevent the console from closing
    std::cout << "Press Enter to close the console...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any previous input
    std::cin.get(); // Wait for Enter key
    
    return 0;
}
