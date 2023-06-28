#pragma once
#include <iostream>
#include "chessPiece.h"
#include "pawn.h"
#include "emptyChess.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"

using namespace std;

class Board
{
private:
    vector<vector<ChessPiece*>> board;

public:
    Board();
    ~Board();
    vector<vector<ChessPiece*>> getCurrentBoard();
    void setBoard(vector<vector<ChessPiece*>>);
};