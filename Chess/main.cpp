#include <iostream>
#include <memory>

#include "ChessGame.h"
#include "Pawn.h"

using namespace std;


int main(int argc, char* argv[])
{
    using namespace std;

    ChessGame game;

    auto test = ChessGame::board[6][1];

    ChessGame::board[5][2] = make_unique<Pawn>(0,99,make_pair(5,2));
    ChessGame::displayValidMove(*test);
    test->printValidPos();

    int buffer;
    cout << "Type the number of the position you want to move to:\n";
    cin >> buffer;
    
    test->move(test->inputToPos[buffer]);
    ChessGame::displayValidMove(*test);
    test->printValidPos();
    
    return 0;
}
