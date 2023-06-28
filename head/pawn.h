#include "chessPiece.h"
#pragma once
class pawn:public ChessPiece
{
private:
public:
    pawn(int t);
    ~pawn();
    std::vector<Position> getLegalMoveList();
};