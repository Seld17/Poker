
#pragma once

#include <Model/Card.h>
#include <Model/Hand.h>

namespace Poker::Model
{
class Player
{
    public:
    /// Constructor
    explicit Player(unsigned int cash);

    /// Default copy constructor
    Player(const Player&) = default;

    /// Default move constructor
    Player(Player&&) = default;

    /// Default copy assignment operator
    Player& operator=(const Player&) = default;

    /// Default move assignment operator
    Player& operator=(Player&&) = default;

    /// Destructor
    virtual ~Player() = default;

    bool Bet(unsigned int bet);
    void Fold();

    void AddCards(std::vector<std::shared_ptr<Card>> cards);

    protected:
    /// Players betting money, avoiding decimals for simplicity
    unsigned int mCash;

    /// Players current hand
    Hand mHand;
};
} // namespace Poker::Model