#include "chessPiece.h"
#pragma once
class knight:public ChessPiece
{
private:
public:
    knight(int t);
    ~knight();
    std::vector<Position> getLegalMoveList();
};