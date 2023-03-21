#include <Model/Table.h>

#include <Model/Deck.h>

namespace Poker::Model
{
Table::Table(std::vector<std::string> playerOder, std::map<std::string, std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck)
    : mPot(0)
    , mOrder(playerOder)
    , mPlayers(std::move(players))
    , mDeck(std::move(deck))
{
}

void Table::DealPlayerHand()
{
    // todo learn and implement blind changes and changes to player order
    for(const auto& player : mOrder)
    {
        const auto card1 = mDeck->PickTopCard();
        const auto card2 = mDeck->PickTopCard();
        mPlayers.at(player)->AddCards({ card1, card2 });
    }
}

void Table::BurnCard() 
{
    const auto burnCard = mDeck->PickTopCard(); 
}

void Table::AddCommunityCards(unsigned int numberToFlip)
{
    if(numberToFlip == 0)
    {
        throw("invalid number of cards to flip");
    }

    for(unsigned int i = 0; i < numberToFlip; ++i)
    {
        mCommunityCards.emplace_back(mDeck->PickTopCard());
    }
}

void Table::AddToPot(unsigned int bet) 
{
    mPot += bet; 
}

void Table::DistributePot(const std::string& winner)
{
    mPlayers.at(winner)->WinPot(mPot);
    mPot = 0;
};
} // namespace Poker::Model