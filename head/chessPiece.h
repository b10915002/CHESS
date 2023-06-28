#pragma once
#include "position.h"
#include <vector>

class ChessPiece
{
private:
public:
    ChessPiece();
    ~ChessPiece();
    bool firstMove;
    int team;
    bool isEmptyChess;
    bool isEmpty();
    virtual std::vector<Position> getLegalMoveList() { return std::vector<Position>(1, {0, 0}); }; //need override
};
