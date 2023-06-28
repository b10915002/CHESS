#include "king.h"
#include "gameManager.h"

extern gameManager *gamemanager;

king::king(int t)
{
    team = t;
    firstMove = true;
    isEmptyChess = false;
}

king::~king()
{
}
std::vector<Position> king::getLegalMoveList()
{
    std::vector<Position> legalMoves;
    Position currentPos = gamemanager->currentSelectedBox;
    vector<vector<ChessPiece *>> currentBoard = gamemanager->board.getCurrentBoard();
    vector<Position> checkBoxes = {{1, 1},
                                   {1, 0},
                                   {1, -1},
                                   {0, -1},
                                   {-1, -1},
                                   {-1, 0},
                                   {-1, 1},
                                   {0, 1}};
    for (Position check : checkBoxes)
    {
        if (currentPos.x + check.x < 0 || currentPos.x + check.x > 7 || currentPos.y + check.y < 0 || currentPos.y + check.y > 7)
        {
            continue;
        }
        if (currentBoard[currentPos.y + check.y][currentPos.x + check.x]->team != team)
        {
            legalMoves.push_back({currentPos.x + check.x, currentPos.y + check.y});
        }
    }
    if (firstMove == true) //Castling
    {
        if (team == 0)
        {
            if (currentBoard[7][0]->firstMove == true)//left
            {
                if (currentBoard[currentPos.y][currentPos.x - 1]->isEmpty() && currentBoard[currentPos.y][currentPos.x - 2]->isEmpty())
                {
                    legalMoves.push_back({currentPos.x - 2, currentPos.y});
                }
            }
            if (currentBoard[7][7]->firstMove == true)//right
            {
                if (currentBoard[currentPos.y][currentPos.x + 1]->isEmpty() && currentBoard[currentPos.y][currentPos.x + 2]->isEmpty())
                {
                    legalMoves.push_back({currentPos.x + 2, currentPos.y});
                }
            }
        }
        else
        {
            if (currentBoard[0][0]->firstMove == true)//left
            {
                if (currentBoard[currentPos.y][currentPos.x - 1]->isEmpty() && currentBoard[currentPos.y][currentPos.x - 2]->isEmpty())
                {
                    legalMoves.push_back({currentPos.x - 2, currentPos.y});
                }
            }
            if (currentBoard[0][7]->firstMove == true)//right
            {
                if (currentBoard[currentPos.y][currentPos.x + 1]->isEmpty() && currentBoard[currentPos.y][currentPos.x + 2]->isEmpty())
                {
                    legalMoves.push_back({currentPos.x + 2, currentPos.y});
                }
            }
        }
    }
    return legalMoves;
};