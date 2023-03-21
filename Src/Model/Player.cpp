#include <Model/Player.h>

namespace Poker::Model
{
Player::Player(unsigned int cash) : mCash(cash) {}

bool Player::Bet(unsigned int bet) 
{ 
    if(mCash >= bet)
    {
        mCash -= bet;
        return true;
    }
    return false;
}

bool Player::Fold() 
{
    // todo disacrd "hand"
    return false; 
}



} // namespace Poker::Model