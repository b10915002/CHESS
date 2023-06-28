#include "gameManager.h"
#include "pawnpro.h"

extern gameManager *gamemanager;

HumanPlayer::HumanPlayer()
{
}
HumanPlayer::~HumanPlayer()
{
}
vector<vector<ChessPiece *>> HumanPlayer::move(Position oldPos, Position newPos, bool isChecking)
{
    vector<vector<ChessPiece *>> currentBoard = gamemanager->board.getCurrentBoard();
    ChessPiece *movedChess = currentBoard[oldPos.y][oldPos.x];
    if ((string) typeid(*movedChess).name() == "class king" && newPos.y == oldPos.y && (newPos.x + 2 == oldPos.x || newPos.x - 2 == oldPos.x)) //Castling
    {
        currentBoard[newPos.y][newPos.x] = movedChess;
        currentBoard[newPos.y][newPos.x]->firstMove = false;
        currentBoard[oldPos.y][oldPos.x] = new emptyChess();
        ChessPiece *castlingRook;
        if (newPos.x == oldPos.x + 2) //right
        {
            castlingRook = currentBoard[oldPos.y][7];
            currentBoard[newPos.y][newPos.x - 1] = castlingRook;
            castlingRook->firstMove = false;
            currentBoard[newPos.y][7] = new emptyChess();
        }
        if (newPos.x == oldPos.x - 2) //left
        {
            castlingRook = currentBoard[oldPos.y][0];
            currentBoard[newPos.y][newPos.x + 1] = castlingRook;
            castlingRook->firstMove = false;
            currentBoard[newPos.y][0] = new emptyChess();
        }
    }
    else if ((string) typeid(*movedChess).name() == "class pawn" && currentBoard[newPos.y][newPos.x]->isEmpty() && newPos.x != oldPos.x) //Passant Capturing
    {
        currentBoard[newPos.y][newPos.x] = movedChess;
        movedChess->firstMove = false;
        currentBoard[oldPos.y][oldPos.x] = new emptyChess();
        currentBoard[oldPos.y][newPos.x] = new emptyChess();
    }
    else if ((string) typeid(*movedChess).name() == "class pawn" && ((newPos.y == 7 && movedChess->team == 1) || (newPos.y == 0 && movedChess->team == 0)) && isChecking == false)
    {
        pawnpro test;
        test.exec();
        int t = test.chesschoose;
        switch (t)
        {
        case 2:
            currentBoard[newPos.y][newPos.x] = new knight(movedChess->team);
            break;
        case 3:
            currentBoard[newPos.y][newPos.x] = new rook(movedChess->team);
            break;
        case 4:
            currentBoard[newPos.y][newPos.x] = new bishop(movedChess->team);
            break;
        case 5:
            currentBoard[newPos.y][newPos.x] = new queen(movedChess->team);
            break;
        default:
            break;
        }
        currentBoard[newPos.y][newPos.x]->firstMove = false;
        currentBoard[oldPos.y][oldPos.x] = new emptyChess();
    }
    else
    {
        currentBoard[newPos.y][newPos.x] = movedChess;
        currentBoard[newPos.y][newPos.x]->firstMove = false;
        currentBoard[oldPos.y][oldPos.x] = new emptyChess();
    }
    return currentBoard;
}
