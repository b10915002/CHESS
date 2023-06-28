#include "player.h"
class HumanPlayer : public Player
{
public:
    HumanPlayer();
    ~HumanPlayer();
    std::vector<std::vector<ChessPiece *>> move(Position,Position,bool) override;
    //void OnPromote(/* parameters */) override;
    // your code
};
