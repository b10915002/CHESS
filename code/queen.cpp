#include "queen.h"
#include "gameManager.h"

extern gameManager *gamemanager;

queen::queen(int t)
{
    team = t;
    firstMove = true;
    isEmptyChess = false;
}

queen::~queen()
{
}
std::vector<Position> queen::getLegalMoveList()
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
    for (int i = 1; i <= 7; i++) //right
    {
        if (currentPos.x + i > 7)
        {
            break;
        }
        if (currentBoard[currentPos.y][currentPos.x + i]->team == team)
        {
            break;
        }
        if (!currentBoard[currentPos.y][currentPos.x + i]->isEmpty())
        {
            legalMoves.push_back({ currentPos.x + i,  currentPos.y});
            break;
        }
        legalMoves.push_back({ currentPos.x + i,  currentPos.y});
    }
    for (int i = 1; i <= 7; i++) //left
    {
        if ( currentPos.x - i < 0)
        {
            break;
        }
        if (currentBoard[currentPos.y][currentPos.x - i]->team == team)
        {
            break;
        }
        if (!currentBoard[currentPos.y][currentPos.x - i]->isEmpty())
        {
            legalMoves.push_back({ currentPos.x - i,  currentPos.y});
            break;
        }
        legalMoves.push_back({ currentPos.x - i,  currentPos.y});
    }
    for (int i = 1; i <= 7; i++) //up
    {
        if ( currentPos.y - i < 0)
        {
            break;
        }
        if (currentBoard[currentPos.y - i][currentPos.x]->team == team)
        {
            break;
        }
        if (!currentBoard[currentPos.y - i][currentPos.x]->isEmpty())
        {
            legalMoves.push_back({ currentPos.x,  currentPos.y - i});
            break;
        }
        legalMoves.push_back({ currentPos.x,  currentPos.y - i});
    }
    for (int i = 1; i <= 7; i++) //down
    {
        if (currentPos.y + i > 7 )
        {
            break;
        }
        if (currentBoard[currentPos.y + i][currentPos.x]->team == team)
        {
            break;
        }
        if (!currentBoard[currentPos.y + i][currentPos.x]->isEmpty())
        {
            legalMoves.push_back({ currentPos.x,  currentPos.y + i});
            break;
        }
        legalMoves.push_back({ currentPos.x,  currentPos.y + i});
    }
    return legalMoves;
};