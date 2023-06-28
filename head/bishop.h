#include "chessPiece.h"
#pragma once
class bishop:public ChessPiece
{
private:
public:
    bishop(int t);
    ~bishop();
    std::vector<Position> getLegalMoveList();
};