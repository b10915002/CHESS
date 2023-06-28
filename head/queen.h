#include "chessPiece.h"
#pragma once
class queen:public ChessPiece
{
private:
public:
    queen(int t);
    ~queen();
    std::vector<Position> getLegalMoveList();
};