#pragma once
#include "position.h"
#include "chessPiece.h"
#include <vector>

class Player
{
public:
    Player();
    ~Player();
    virtual std::vector<std::vector<ChessPiece *>> move(Position,Position,bool);
    //virtual void OnPromote() = 0;
};
