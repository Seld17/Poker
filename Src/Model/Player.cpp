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

void Player::Fold()
{
    return mHand.DiscardHand();
}

void Player::AddCards(std::vector<std::shared_ptr<Card>> cards) 
{
    mHand.AddCards(cards); 
}

void Player::WinPot(unsigned int pot) 
{
    mCash += pot; }

unsigned int Player::GetHandValue(const std::vector<std::shared_ptr<Card>>& communityCards) 
{ 
   return mHand.GetHandValue(communityCards); 
}

} // namespace Poker::Model