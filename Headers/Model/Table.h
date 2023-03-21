
#pragma once

#include <Model/Player.h>

#include <memory>
#include <vector>

namespace Poker::Model
{
class Card;
class Deck;

class Table
{
    public:
    /// Constructor
    Table(std::vector<std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck);

    /// Default copy constructor
    Table(const Table&) = default;

    /// Default move constructor
    Table(Table&&) = default;

    /// Default copy assignment operator
    Table& operator=(const Table&) = default;

    /// Default move assignment operator
    Table& operator=(Table&&) = default;

    /// Destructor
    virtual ~Table() = default;

    void DealPlayerHand();

    void BurnCard();

    private:
    unsigned int mPot;

    std::vector<std::unique_ptr<Player>> mPlayers;

    std::unique_ptr<Deck> mDeck;

    std::vector<std::shared_ptr<Card>> mCommunityCards;
};
} // namespace Poker::Model