#include "chessPiece.h"
#pragma once
class rook:public ChessPiece
{
private:
public:
    rook(int t);
    ~rook();
    std::vector<Position> getLegalMoveList();
};