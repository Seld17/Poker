
#pragma once

#include <Model/Card.h>

#include <vector>
#include <memory>

namespace Poker::Model
{
class Hand final
{
    public:
    /// Constructor
    Hand() = default;

    /// Default copy constructor
    Hand(const Hand&) = default;

    /// Default move constructor
    Hand(Hand&&) = default;

    /// Default copy assignment operator
    Hand& operator=(const Hand&) = default;

    /// Default move assignment operator
    Hand& operator=(Hand&&) = default;

    /// Destructor
    virtual ~Hand() = default;

    /// Accessor to hand Value, higher is better with a max of 9
    int GetHandValue();

    private:
    bool isStraightFlush() const;
    bool isFourOfaKind() const;

    std::vector<std::shared_ptr<Card>> mCards;
};
} // namespace Poker::Model