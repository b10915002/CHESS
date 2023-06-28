#include "gameManager.h"

gameManager::gameManager()
{
    currentLegalMoves.resize(100);
    currentLegalMoves.clear();
    record.resize(100);
    record.clear();
    GameOver = 0;
    current_player = 0;
    currentSelectedBox = {7, 3};
    players[0] = new HumanPlayer();
    players[1] = new HumanPlayer();
    board = Board();
    stalemate=false;
}

void gameManager::gameInput(Position inputPos)
{

    /*char inputChar[2];
        scanf("%s", &inputChar);
        Position inputPos = notationToPosition(inputChar);*/
    bool moved = false;
    for (Position currentLegalMove : currentLegalMoves)
    {
        if (currentLegalMove.x == inputPos.x && currentLegalMove.y == inputPos.y) //selected move
        {
            vector<vector<ChessPiece *>> tempBoard = board.getCurrentBoard();
            int tempFirstMove = tempBoard[currentSelectedBox.y][currentSelectedBox.x]->firstMove;
            if (isCheckmated(players[current_player]->move(currentSelectedBox, inputPos, true)))
            {
                tempBoard[currentSelectedBox.y][currentSelectedBox.x]->firstMove = tempFirstMove;
                board.setBoard(tempBoard);
                break;
            }
            board.setBoard(players[current_player]->move(currentSelectedBox, inputPos, false));
            record.push_back({currentSelectedBox, inputPos});
            current_player = (current_player + 1) % 2;
            moved = true;
            currentSelectedBox = inputPos;
            if (isGameover())
            {
                GameOver = true;
            }
            break;
        }
    }
    currentLegalMoves.clear();
    if (!moved)
    {
        currentSelectedBox = inputPos;
        if (board.getCurrentBoard()[currentSelectedBox.y][currentSelectedBox.x]->team == current_player)
        {
            currentLegalMoves = board.getCurrentBoard()[currentSelectedBox.y][currentSelectedBox.x]->getLegalMoveList();
        }
    }
}
Position gameManager::notationToPosition(char input[]) //not used
{
    Position result;
    result.x = input[0] - 'a';
    result.y = 7 - (input[1] - '1');
    return result;
}
bool gameManager::isCheckmated(vector<vector<ChessPiece *>> checkedBoard)
{
    Position tempSelectedBox = currentSelectedBox;
    vector<vector<ChessPiece *>> tempBoard = board.getCurrentBoard();
    board.setBoard(checkedBoard);
    int tempTurn = current_player;
    current_player = (current_player + 1) % 2;
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (checkedBoard[y][x]->team != current_player)
            {
                continue;
            }
            currentSelectedBox = {x, y};
            vector<Position> legalMoves = checkedBoard[y][x]->getLegalMoveList();
            for (Position legalMove : legalMoves)
            {
                if ((string) typeid(*checkedBoard[legalMove.y][legalMove.x]).name() == "class king")
                {
                    current_player = tempTurn;
                    currentSelectedBox = tempSelectedBox;
                    board.setBoard(tempBoard);
                    return 1;
                }
            }
        }
    }
    current_player = tempTurn;
    currentSelectedBox = tempSelectedBox;
    board.setBoard(tempBoard);
    return 0;
}
bool gameManager::isGameover()
{
    Position tempSelectedBox = currentSelectedBox;
    vector<vector<ChessPiece *>> tempBoard = board.getCurrentBoard();
    vector<vector<ChessPiece *>> currentBoard = board.getCurrentBoard();
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (currentBoard[y][x]->team != current_player)
            {
                continue;
            }
            currentSelectedBox = {x, y};
            vector<Position> legalMoves = currentBoard[y][x]->getLegalMoveList();
            for (Position legalMove : legalMoves)
            {
                int tempFirstMove = tempBoard[currentSelectedBox.y][currentSelectedBox.x]->firstMove;
                vector<vector<ChessPiece *>> newBoard = players[0]->move(currentSelectedBox, legalMove, true);
                newBoard[legalMove.y][legalMove.x]->firstMove = tempFirstMove;
                if (!isCheckmated(newBoard))
                {
                    board.setBoard(tempBoard);
                    currentSelectedBox = tempSelectedBox;
                    return 0;
                }
            }
        }
    }
    board.setBoard(tempBoard);
    currentSelectedBox = tempSelectedBox;
    if(!isCheckmated(tempBoard)){
        stalemate=true;
    }
    return 1;
}
/*Position gameManager::getKingPosition(int team)
{
    vector<vector<ChessPiece *>> currentBoard = board.getCurrentBoard();
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if ((string)typeid(*currentBoard[y][x]).name()=="class king"&&currentBoard[y][x]->team==team)
            {
                return {y,x};
            }
        }
    }
}*/
