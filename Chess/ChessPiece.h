#pragma once

#include <iostream>
#include <vector>

//Abstract class
class ChessPiece
{
public:
    ChessPiece() = default;
    ChessPiece(bool whiteOrBlack, int id, std::pair<int,int> position);
    virtual ~ChessPiece()=default;
    
    virtual void move(int pos);
    virtual void updateValidPos();
    void capture(std::unique_ptr<ChessPiece> opponent);
    void beCaptured();

    friend std::ostream& operator<<(std::ostream& os, const ChessPiece& piece);

    std::string symbol;
    // 0 = white, 1 = black
    bool white0Black1;
    std::pair<int, int> position;
    int getID(){return id;}
    std::vector<std::pair<int,int>> getValidPos();
    void printValidPos();

private:
    int id;

protected:
    std::vector<std::pair<int,int>> validPos;
    
};
