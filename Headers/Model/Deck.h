#pragma once

#include "Card.h"

#include <memory>
#include <vector>

namespace Poker::Model
{
class Deck final
{
    public:
    /// Constructor
    explicit Deck();

    /// Default copy constructor
    Deck(const Deck&) = default;

    /// Default move constructor
    Deck(Deck&&) = default;

    /// Default copy assignment operator
    Deck& operator=(const Deck&) = default;

    /// Default move assignment operator
    Deck& operator=(Deck&&) = default;

    /// Default destructor
    ~Deck() = default;

    /// Shuffle a fresh deck
    void ShuffleDeck();

    /// Pick and remove card from deck
    /// \return the next card or nullptr if no more cards
    [[nodiscard]] std::shared_ptr<Card> PickTopCard();

    /// Accessor to card
    /// \return the next card
    [[nodiscard]] int GetDeckSize() const;

    /// Accessor to remaining card count
    /// \return the next card
    [[nodiscard]] int GetRemaingingDeckSize() const;

    private:
    /// Number of cards
    int mRemainingCards;
    /// Container of cards
    std::vector<std::shared_ptr<Card>> mCards;
};
} // namespace Poker::Model