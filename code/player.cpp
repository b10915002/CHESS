#include "player.h"
#include "emptyChess.h"
Player::Player(){
    //
}
Player::~Player(){
    //
}
    std::vector<std::vector<ChessPiece *>> Player::move(Position,Position,bool){
    std::vector<std::vector<ChessPiece *>>  a(8,std::vector<ChessPiece *>(8,new emptyChess()));
    return a;
}
