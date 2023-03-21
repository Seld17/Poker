
#pragma once

#include <Model/Player.h>

namespace Poker::Model
{
class Blind final : public Player
{
    public:
    /// Constructor
    Blind(unsigned int cash, unsigned int forcedBet);

    /// Constructor
    Blind(const Player& player, unsigned int forcedBet);

    /// Default copy constructor
    Blind(const Blind&) = default;

    /// Default move constructor
    Blind(Blind&&) = default;

    /// Default copy assignment operator
    Blind& operator=(const Blind&) = default;

    /// Default move assignment operator
    Blind& operator=(Blind&&) = default;

    /// Destructor
    virtual ~Blind() = default;

    private:
    unsigned int mForcedBet;
};
} // namespace Poker::Model