#include <Model/Deck.h>

#include <iostream>
#include <random>

namespace
{
constexpr int DECK_SIZE{ 52 };
}

namespace Solitaire::Model
{

Deck::Deck() : mRemainingCards(DECK_SIZE)
{
    mCards.reserve(DECK_SIZE);
    for (auto i = static_cast<int>(Card::Suits::E_CLUBS); i != static_cast<int>(Card::Suits::E_TOTAL); ++i)
    {
        for (auto j = static_cast<int>(Card::Ranks::E_ACE); j != static_cast<int>(Card::Ranks::E_RANKS_TOTAL); ++j)
        {
            const auto suit = static_cast<Card::Suits>(i);
            const auto rank = static_cast<Card::Ranks>(j);
            mCards.emplace_back(std::make_unique<Card>(suit, rank));
        }
    }
    ShuffleDeck();
}

void Deck::ShuffleDeck()
{
    // pseudo random number genreator
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution deck{ 1, static_cast<int>(DECK_SIZE) };

    std::vector<std::shared_ptr<Card>> temp;
    temp.reserve(DECK_SIZE);
    auto remainingCards = DECK_SIZE;

    while (remainingCards > 0)
    {
        /// "random" pick of a card
        const auto selection = deck(mt) % remainingCards;
        temp.emplace_back(std::move(mCards.at(selection)));
        mCards.erase(mCards.begin() + selection);
        --remainingCards;
    }

    mCards = std::move(temp);
}

[[nodiscard]] std::shared_ptr<Card> Deck::PickTopCard()
{
    if (mRemainingCards > 0)
    {
        auto card = mCards.at(mRemainingCards - 1);
        --mRemainingCards;
        return card;
    }
    return nullptr;
}

int Deck::GetDeckSize() const
{
    return DECK_SIZE;
}

int Deck::GetRemaingingDeckSize() const
{
    return mRemainingCards;
}

} // namespace Solitaire::Model
