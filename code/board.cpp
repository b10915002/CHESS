#include "Board.h"

Board::Board()
{
    board.resize(8);
    for (int i = 0; i < 8; i++)
    {
        board[i].resize(8);
    }
    //emptyChess=0,pawn=1,knight=2,rook=3,bishop=4,queen=5,king=6,negative=blackTeam,positive=whiteTeam
    vector<vector<int>> initBoard{{-3, -2, -4, -5, -6, -4, -2, -3},
                                  {-1, -1, -1, -1, -1, -1, -1, -1},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {1, 1, 1, 1, 1, 1, 1, 1},
                                  {3, 2, 4, 5, 6, 4, 2, 3}};
//    vector<vector<int>> initBoard{{0,0,0,0,0,0,0,0},
//                                  {0,0,0,0,0,6,0,-6},
//                                  {0,0,0,0,0,0,0,0},
//                                  {0,0,0,0,0,0,0,0},
//                                  {-1,0,0,0,0,0,0,0},
//                                  {1,0,4,0,0,0,0,0},
//                                  {0,0,0,0,0,0,0,0},
//                                  {0,0,0,0,0,0,0,0}};
    vector<vector<ChessPiece *>> newBoard;
    newBoard.resize(8);
    for (int i = 0; i < 8; i++)
    {
        newBoard[i].resize(8);
    }
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            bool isBlackChess = initBoard[y][x] < 0;
            switch (((isBlackChess) ? initBoard[y][x] * -1 : initBoard[y][x]))
            {
            case 0:
                newBoard[y][x] = new emptyChess();
                break;
            case 1:
                newBoard[y][x] = new pawn(isBlackChess);
                break;
            case 2:
                newBoard[y][x] = new knight(isBlackChess);
                break;
            case 3:
                newBoard[y][x] = new rook(isBlackChess);
                break;
            case 4:
                newBoard[y][x] = new bishop(isBlackChess);
                break;
            case 5:
                newBoard[y][x] = new queen(isBlackChess);
                break;
            case 6:
                newBoard[y][x] = new king(isBlackChess);
                break;
            default:
                newBoard[y][x] = new emptyChess();
                break;
            }
            //newBoard[y][x]->firstMove=false;
        }
    }
    setBoard(newBoard);
}

Board::~Board()
{
    //printf("~Board uwu\n");
}
vector<vector<ChessPiece *>> Board::getCurrentBoard()
{
    return board;
}

void Board::setBoard(vector<vector<ChessPiece *>> newBoard)
{
    board = newBoard;
}
