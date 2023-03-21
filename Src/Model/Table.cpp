#include <Model/Table.h>

#include <Model/Deck.h>

namespace Poker::Model
{
Table::Table(std::vector<std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck)
    : mPlayers(std::move(players))
    , mDeck(std::move(deck))
{
}

void Table::DealPlayerHand() 
{
    // todo learn and implement blind changes and changes to player order
    for(const auto& player : mPlayers)
    {
        const auto card1 = mDeck->PickTopCard();
        const auto card2 = mDeck->PickTopCard();
        player->AddCards({card1, card2});
    }
}

void Table::BurnCard()
{
    const auto burnCard = mDeck->PickTopCard();
}
} // namespace Poker::Model