#include <Model/Table.h>

#include <Model/Deck.h>

#include <utility>

namespace Poker::Model
{
Table::Table(std::map<std::string, std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck)
    : mPot(0)
    , mPlayers(std::move(players))
    , mDeck(std::move(deck))
{
}

void Table::DealPlayerHand(const std::string& player, unsigned int numberOfCards)
{
    
    std::vector<std::shared_ptr<Card>> cards;
    for(auto i = 0; i < numberOfCards; ++i)
    {
        cards.emplace_back(mDeck->PickTopCard());
    }
    mPlayers.at(player)->AddCards(cards);
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

std::string Table::ShowDown(const std::vector<std::string>& remainingPlayers)
{
    std::string winner;
    unsigned int best = 0;
    bool isTieBreaker = false;
    std::pair<std::string, std::string> tie;
    for(const auto& name : remainingPlayers)
    {
        const auto val = mPlayers.at(name)->GetHandValue(mCommunityCards);
        if(val > best)
        {
            winner = name;
            
            isTieBreaker = false;
        }
        else if(val == best)
        {
            isTieBreaker = true;
            tie = { winner, name };
        }
    }
    if(isTieBreaker)
    {
        winner = ResolveTieBreaker(tie);
    }
    return winner;
}

void Table::Fold(const std::string& name) 
{ 
    mPlayers.at(name)->Fold(); 
};

std::string Table::ResolveTieBreaker(const std::pair<std::string, std::string>& tiedPlayers) const 
{
    const auto [playerA, playerB] = tiedPlayers;

    // todo implement kickers in had values and split pot 
    return playerA;
};
} // namespace Poker::Model