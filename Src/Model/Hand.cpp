#include <Model/Hand.h>

#include <algorithm>

namespace
{
constexpr int HIGH_CARD{ 1 };
constexpr int PAIR{ 2 };
constexpr int TWO_PAIRS{ 3 };
constexpr int TRHEE_OF_A_KIND{ 4 };
constexpr int STRAIGHT{ 5 };
constexpr int FLUSH{ 6 };
constexpr int FULL_HOUSE{ 7 };
constexpr int FOUR_OF_A_KIND{ 8 };
constexpr int STRAIGH_FLUSH{ 9 };

} // namespace

namespace Poker::Model
{
Hand::Hand(std::vector<std::shared_ptr<Card>> cards) : mCards(cards)
{
}

int Hand::GetHandValue(const std::vector<std::shared_ptr<Card>>& communityCards)
{
    // todo compute best hand 5/7 among 5 community cards and 2 hand cards
    // This appears at first glance a computationally expensive operation on 
    // top of requiring the evaluation of permutations (sawp in 0, 1 or 2 pocket cards)
    // More effort should be spent on this to be both correct and efficient

    if(mCards.size() == 0 )
    {
        // hand isn't full
        return 0;
    }
    SortCards();
    if(isStraightFlush())
    {
        return STRAIGH_FLUSH;
    }

    if(isFourOfaKind())
    {
        return FOUR_OF_A_KIND;
    }

    // todo implement other hand values
    return 0;
}

void Hand::AddCards(std::vector<std::shared_ptr<Card>> cards)
{
    const auto currentHandSize = mCards.size();
    const auto numberOfAddedCards = cards.size();
    if(currentHandSize > numberOfAddedCards)
    {
        mCards.swap(cards);
    }

    for(const auto& card : cards)
    {
        mCards.emplace_back(card);
    }
    SortCards();
}

void Hand::DiscardHand() 
{
    mCards.clear(); 
}

void Hand::SortCards()
{
    // todo a custom container that sorts by rank by definition might be better
    std::sort(mCards.begin(), mCards.end(), [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) { return a->GetRank() < b->GetRank(); });
}

bool Hand::isStraightFlush() const
{
    // straight flush
    bool isStraight = true;
    for(auto i = 0; i < mCards.size() - 2; ++i)
    {
        const auto currentRank = mCards.at(i)->GetRank();
        const auto currentSuit = mCards.at(i)->GetSuit();

        const auto nextRank = mCards.at(i + 1)->GetRank();
        const auto nextSuit = mCards.at(i + 1)->GetSuit();

        if(currentSuit != nextSuit || nextRank != currentRank + 1)
        {
            isStraight = false;
            break;
        }
    }
    return isStraight;
} // namespace Poker::Model

bool Hand::isFourOfaKind() const
{
    // Four of a kind
    const auto firstRank = mCards.at(0)->GetRank();
    const auto secondRank = mCards.at(1)->GetRank();
    const auto thirdRank = mCards.at(2)->GetRank();
    bool isFourOfAKind = true;
    if(secondRank == thirdRank)
    {
        const auto forthRank = mCards.at(3)->GetRank();
        if(forthRank != thirdRank)
        {
            isFourOfAKind = false;
        }
        else if(firstRank == secondRank)
        {
            // it is a four of a kind
        }
        else if(mCards.at(4)->GetRank() == thirdRank)
        {
            // it is a four of a kind
        }

        isFourOfAKind = false;
    }
    else
    {
        isFourOfAKind = false;
    }

    return isFourOfAKind;
}
} // namespace Poker::Model
