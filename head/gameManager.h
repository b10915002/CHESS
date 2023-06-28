#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
//#include "King.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "position.h"
#include "Record.h"

using namespace std;

class gameManager
{
public:
    gameManager();
    void gameInput(Position);
    Player *players[2];
    int current_player;
    Position currentSelectedBox;
    std::vector<Record> record;
    Board board;
    std::vector<Position> currentLegalMoves;
    Position notationToPosition(char[]);
    bool GameOver;
    //int turn;   //current_player
    bool isCheckmated(vector<vector<ChessPiece *>>);
    bool isGameover();
    bool stalemate;
    //Viewer viewer;
};
