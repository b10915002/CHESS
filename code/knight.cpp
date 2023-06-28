#include "knight.h"
#include "gameManager.h"

extern gameManager *gamemanager;

knight::knight(int t)
{
    team = t;
    firstMove = true;
    isEmptyChess = false;
}

knight::~knight()
{
}
std::vector<Position> knight::getLegalMoveList()
{
    std::vector<Position> legalMoves;
    Position currentPos = gamemanager->currentSelectedBox;
    vector<vector<ChessPiece *>> currentBoard = gamemanager->board.getCurrentBoard();
    vector<Position> checkBoxes = {{1, -2},
                                   {2, -1},
                                   {2, 1},
                                   {1, 2},
                                   {-1, 2},
                                   {-2, 1},
                                   {-2, -1},
                                   {-1, -2}};
    for (Position check : checkBoxes)
    {
        if (currentPos.x + check.x < 0 || currentPos.x + check.x > 7 || currentPos.y + check.y < 0 || currentPos.y + check.y > 7)
        {
            continue;
        }
        if (currentBoard[currentPos.y + check.y][currentPos.x + check.x]->team != team)
        {
            legalMoves.push_back({ currentPos.x + check.x,  currentPos.y + check.y});
        }
    }
    return legalMoves;
};