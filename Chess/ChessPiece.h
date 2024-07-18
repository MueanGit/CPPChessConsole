#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

class ChessPiece
{
public:
    ChessPiece() = default;
    ChessPiece(bool whiteOrBlack, int id, std::pair<int,int> position);
    virtual ~ChessPiece()=default;
    
    virtual void move(std::pair<int, int> posToMove);
    void capture(ChessPiece& opponent);
    void beCaptured();

    friend std::ostream& operator<<(std::ostream& os, const ChessPiece& piece);

    std::string symbol;
    // 0 = white, 1 = black
    bool white0Black1;
    std::pair<int, int> position;
    int getID(){return id;}
    std::vector<std::pair<int,int>> getValidPos();
    void printValidPos();
    //Will be updated in the displayValidMove function
    std::unordered_map<int, std::pair<int,int>> inputToPos;

private:
    int id;

protected:
    virtual void updateValidPos();
    std::vector<std::pair<int,int>> validPos;
    bool canMoveTo(int row, int col);
    //Dont have inbound check
    bool isEnemy(int row, int col);
    
};
