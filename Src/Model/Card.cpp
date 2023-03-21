#include <Model/Card.h>

#include <iostream>

namespace Solitaire::Model
{
Card::Card(Suits s, Ranks r) : mSuit(s), mRank(r) {}

void Card::PrintSelf() const
{
    std::cout << "Card is " << RankToString(mRank) << " of " << SuitsToString(mSuit) << std::endl;
}

std::string Card::SuitsToString(Suits s) const
{
    switch(s)
    {
    case Suits::E_CLUBS:
        return "Clubs";
        break;
    case Suits::E_SPADES:
        return "Spades";
        break;
    case Suits::E_HEARTS:
        return "Hearts";
        break;
    case Suits::E_DIAMONDS:
        return "Diamonds";
        break;
    case Suits::E_TOTAL:
        return "Invalid Suit";
        break;
    default:
        return "Unkown Suit";
        break;
    }
}

std::string Card::RankToString(Ranks r) const
{
    switch(r)
    {
    case Ranks::E_ACE:
        return "Ace";
        break;
    case Ranks::E_TWO:
        return "Two";
        break;
    case Ranks::E_THREE:
        return "Three";
        break;
    case Ranks::E_FOUR:
        return "Four";
        break;
    case Ranks::E_FIVE:
        return "Five";
        break;
    case Ranks::E_SIX:
        return "Six";
        break;
    case Ranks::E_SEVEN:
        return "Seven";
        break;
    case Ranks::E_EIGHT:
        return "Eight";
        break;
    case Ranks::E_NINE:
        return "Nine";
        break;
    case Ranks::E_TEN:
        return "Ten";
        break;
    case Ranks::E_JACK:
        return "Jack";
        break;
    case Ranks::E_QUEEN:
        return "Queen";
        break;
    case Ranks::E_KING:
        return "King";
        break;
    case Ranks::E_RANKS_TOTAL:
        return "Invalid Rank";
        break;
    default:
        return "Uknown Rank";
        break;
    }
}

// clang-format off
int Card::GetRank() const 
{ 
    return static_cast<int>(mRank); 
}

int Card::GetSuit() const 
{
    return static_cast<int>(mSuit); 
}

// clang-format on
} // namespace Solitaire::Model