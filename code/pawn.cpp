#include "pawn.h"
#include "gameManager.h"

extern gameManager *gamemanager;

pawn::pawn(int t)
{
    team = t;
    firstMove = true;
    isEmptyChess = false;
}

pawn::~pawn()
{
}
std::vector<Position> pawn::getLegalMoveList()
{
    std::vector<Position> legalMoves;
    Position currentPos = gamemanager->currentSelectedBox;
    vector<vector<ChessPiece *>> currentBoard = gamemanager->board.getCurrentBoard();
    if (team == 0)
    {
        if (firstMove == true && currentPos.y - 2 >= 0 && currentPos.y - 1 >= 0)
        {
            if (currentBoard[currentPos.y - 1][currentPos.x]->isEmpty() && currentBoard[currentPos.y - 2][currentPos.x]->isEmpty()) //first up
            {
                legalMoves.push_back({currentPos.x, currentPos.y - 2});
            }
        }
        if (currentPos.y - 1 >= 0)
        {
            if (currentBoard[currentPos.y - 1][currentPos.x]->isEmpty()) //up
            {
                legalMoves.push_back({currentPos.x, currentPos.y - 1});
            }
        }
        if (currentPos.y - 1 >= 0 && currentPos.x - 1 >= 0 && currentBoard[currentPos.y - 1][currentPos.x - 1]->team == 1) //attack up left
        {
            legalMoves.push_back({currentPos.x - 1, currentPos.y - 1});
        }
        if (currentPos.y - 1 >= 0 && currentPos.x + 1 <= 7 && currentBoard[currentPos.y - 1][currentPos.x + 1]->team == 1) //attack up right
        {
            legalMoves.push_back({currentPos.x + 1, currentPos.y - 1});
        }
        if (currentPos.x + 1 <= 7 && (string) typeid(*currentBoard[currentPos.y][currentPos.x + 1]).name() == "class pawn" && !gamemanager->record.empty()) //Passant Capturing right
        {
            if ((gamemanager->record.back().oldPos.y == 1 && gamemanager->record.back().oldPos.x == currentPos.x + 1) && (gamemanager->record.back().newPos.y == gamemanager->record.back().oldPos.y + 2 && gamemanager->record.back().newPos.x == currentPos.x + 1) && currentPos.y == gamemanager->record.back().newPos.y)
            {
                legalMoves.push_back({currentPos.x + 1, currentPos.y - 1});
            }
        }
        if (currentPos.x - 1 >= 0 && (string) typeid(*currentBoard[currentPos.y][currentPos.x - 1]).name() == "class pawn" && !gamemanager->record.empty()) //Passant Capturing left
        {
            if ((gamemanager->record.back().oldPos.y == 1 && gamemanager->record.back().oldPos.x == currentPos.x - 1) && (gamemanager->record.back().newPos.y == gamemanager->record.back().oldPos.y + 2 && gamemanager->record.back().newPos.x == currentPos.x - 1) && currentPos.y == gamemanager->record.back().newPos.y)
            {
                legalMoves.push_back({currentPos.x - 1, currentPos.y - 1});
            }
        }
    }
    else
    {
        if (firstMove == true && currentPos.y + 2 <= 7 && currentPos.y + 1 <= 7)
        {
            if (currentBoard[currentPos.y + 1][currentPos.x]->isEmpty() && currentBoard[currentPos.y + 2][currentPos.x]->isEmpty()) //first down
            {
                legalMoves.push_back({currentPos.x, currentPos.y + 2});
            }
        }
        if (currentPos.y + 1 <= 7)
        {
            if (currentBoard[currentPos.y + 1][currentPos.x]->isEmpty()) //down
            {
                legalMoves.push_back({currentPos.x, currentPos.y + 1});
            }
        }
        if (currentPos.y + 1 <= 7 && currentPos.x - 1 >= 0 && currentBoard[currentPos.y + 1][currentPos.x - 1]->team == 0) //attack down left
        {
            legalMoves.push_back({currentPos.x - 1, currentPos.y + 1});
        }
        if (currentPos.y + 1 <= 7 && currentPos.x + 1 <= 7 && currentBoard[currentPos.y + 1][currentPos.x + 1]->team == 0) //attack down right
        {
            legalMoves.push_back({currentPos.x + 1, currentPos.y + 1});
        }
        if (currentPos.x + 1 <= 7 && (string) typeid(*currentBoard[currentPos.y][currentPos.x + 1]).name() == "class pawn" && !gamemanager->record.empty()) //Passant Capturing right
        {
            if ((gamemanager->record.back().oldPos.y == 6 && gamemanager->record.back().oldPos.x == currentPos.x + 1) && (gamemanager->record.back().newPos.y == gamemanager->record.back().oldPos.y - 2 && gamemanager->record.back().newPos.x == currentPos.x + 1) && currentPos.y == gamemanager->record.back().newPos.y)
            {
                legalMoves.push_back({currentPos.x + 1, currentPos.y + 1});
            }
        }
        if (currentPos.x - 1 >= 0 && (string) typeid(*currentBoard[currentPos.y][currentPos.x - 1]).name() == "class pawn" && !gamemanager->record.empty()) //Passant Capturing left
        {
            if ((gamemanager->record.back().oldPos.y == 6 && gamemanager->record.back().oldPos.x == currentPos.x - 1) && (gamemanager->record.back().newPos.y == gamemanager->record.back().oldPos.y - 2 && gamemanager->record.back().newPos.x == currentPos.x - 1) && currentPos.y == gamemanager->record.back().newPos.y)
            {
                legalMoves.push_back({currentPos.x - 1, currentPos.y + 1});
            }
        }
    }
    return legalMoves;
};