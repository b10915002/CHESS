#include "bishop.h"
#include "gameManager.h"

extern gameManager *gamemanager;

bishop::bishop(int t)
{
    team = t;
    firstMove = true;
    isEmptyChess = false;
}

bishop::~bishop()
{
}
std::vector<Position> bishop::getLegalMoveList()
{
    std::vector<Position> legalMoves;
    Position currentPos = gamemanager->currentSelectedBox;
    vector<vector<ChessPiece *>> currentBoard = gamemanager->board.getCurrentBoard();
    for (int i = 1; i <= 7; i++)//down right
    {
        if (currentPos.y + i > 7 || currentPos.y + i < 0 || currentPos.x + i > 7 || currentPos.x + i < 0){
            break;
        }
        if (currentBoard[currentPos.y + i][currentPos.x + i]->team==team)
        {
            break;
        }
        if (!currentBoard[currentPos.y + i][currentPos.x + i]->isEmpty())
        {
            legalMoves.push_back({currentPos.x + i,currentPos.y + i});
            break;
        }
        legalMoves.push_back({currentPos.x + i,currentPos.y + i});
    }
    for (int i = 1; i <= 7; i++)//down left
    {
        if (currentPos.y + i > 7 || currentPos.y + i < 0 || currentPos.x - i > 7 || currentPos.x - i < 0){
            break;
        }
        if (currentBoard[currentPos.y + i][currentPos.x - i]->team==team)
        {
            break;
        }
        if (!currentBoard[currentPos.y + i][currentPos.x - i]->isEmpty())
        {
            legalMoves.push_back({currentPos.x - i,currentPos.y + i});
            break;
        }
        legalMoves.push_back({currentPos.x - i,currentPos.y + i});
    }
    for (int i = 1; i <= 7; i++)//up right
    {
        if (currentPos.y - i > 7 || currentPos.y - i < 0 || currentPos.x + i > 7 || currentPos.x + i < 0){
            break;
        }
        if (currentBoard[currentPos.y - i][currentPos.x + i]->team==team)
        {
            break;
        }
        if (!currentBoard[currentPos.y - i][currentPos.x + i]->isEmpty())
        {
            legalMoves.push_back({currentPos.x + i,currentPos.y - i});
            break;
        }
        legalMoves.push_back({currentPos.x + i,currentPos.y - i});
    }
    for (int i = 1; i <= 7; i++)//up left
    {
        if (currentPos.y - i > 7 || currentPos.y - i < 0 || currentPos.x - i > 7 || currentPos.x - i < 0){
            break;
        }
        if (currentBoard[currentPos.y - i][currentPos.x - i]->team==team)
        {
            break;
        }
        if (!currentBoard[currentPos.y - i][currentPos.x - i]->isEmpty())
        {
            legalMoves.push_back({currentPos.x - i,currentPos.y - i});
            break;
        }
        legalMoves.push_back({currentPos.x - i,currentPos.y - i});
    }
    return legalMoves;
};