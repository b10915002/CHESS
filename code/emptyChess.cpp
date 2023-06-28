#include "emptyChess.h"
#include "gameManager.h"

extern gameManager *gamemanager;

emptyChess::emptyChess()
{
    team = 2;
    firstMove = true;
    isEmptyChess = true;
}

emptyChess::~emptyChess()
{
}
std::vector<Position> emptyChess::getLegalMoveList()
{
    std::vector<Position> legalMoves;
    legalMoves.clear();
    return legalMoves;
};