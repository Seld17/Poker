
#pragma once

#include <Model/Card.h>

#include <vector>
#include <memory>

namespace Poker::Model
{
class Hand final
{
    public:
    /// Default Constructor
    Hand() = default;

    /// Constructor
    explicit Hand(std::vector<std::shared_ptr<Card>> cards);

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

    /// \throw If more than 5 cards end up in hand
    void AddCards(std::vector<std::shared_ptr<Card>> cards);

    private:
    void SortCards();
    bool isStraightFlush() const;
    bool isFourOfaKind() const;

    std::vector<std::shared_ptr<Card>> mCards;
};
} // namespace Poker::Model