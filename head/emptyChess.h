#include "chessPiece.h"
#pragma once
class emptyChess:public ChessPiece
{
private:
public:
    emptyChess();
    ~emptyChess();
    std::vector<Position> getLegalMoveList();
};