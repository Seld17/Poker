
#pragma once

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
    bool Fold();

private:
    /// Players betting money
    unsigned int mCash;
};
} // namespace Poker