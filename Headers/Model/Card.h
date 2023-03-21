#pragma once

#include <string>

namespace Poker::Model
{
class Card final
{
    public:
    enum class Suits : int
    {
        E_CLUBS = 0,
        E_SPADES,
        E_HEARTS,
        E_DIAMONDS,
        E_TOTAL
    };
    enum class Ranks
    {
        E_ACE = 0,
        E_TWO,
        E_THREE,
        E_FOUR,
        E_FIVE,
        E_SIX,
        E_SEVEN,
        E_EIGHT,
        E_NINE,
        E_TEN,
        E_JACK,
        E_QUEEN,
        E_KING,
        E_RANKS_TOTAL
    };

    /// Constructor
    explicit Card(Suits s, Ranks r);

    /// Default copy constructor
    Card(const Card&) = default;

    /// Default move constructor
    Card(Card&&) = default;

    /// Default copy assignment operator
    Card& operator=(const Card&) = default;

    /// Default move assignment operator
    Card& operator=(Card&&) = default;

    /// Default destructor
    ~Card() = default;

    void PrintSelf() const;

    int GetRank() const;
    int GetSuit() const;

    private:
    /// Converts enum to string for printing @{
    std::string SuitsToString(Suits s) const;
    std::string RankToString(Ranks r) const;
    /// @}

    /// Card type 
    Suits mSuit;
    /// Card Value
    Ranks mRank;
};
} // namespace Poker::Model