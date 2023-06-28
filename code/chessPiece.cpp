#include "chessPiece.h"
#include "gameManager.h"
extern gameManager *gamemanager;

ChessPiece::ChessPiece()
{
    team = 2;
    isEmptyChess = true;
    firstMove = true;
}

ChessPiece::~ChessPiece()
{
    //?
}
bool ChessPiece::isEmpty()
{
    return isEmptyChess;
}