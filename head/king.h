#include "chessPiece.h"
#pragma once
class king:public ChessPiece
{
private:
public:
    king(int t);
    ~king();
    std::vector<Position> getLegalMoveList();
};