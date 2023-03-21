#pragma once

#include <string>
#include <vector>

namespace Poker::Game
{
class IPokerGame
{
    public:
    /// Default copy constructor
    IPokerGame(const IPokerGame&) = default;

    /// Default move constructor
    IPokerGame(IPokerGame&&) = default;

    /// Default copy assignment operator
    IPokerGame& operator=(const IPokerGame&) = default;

    /// Default move assignment operator
    IPokerGame& operator=(IPokerGame&&) = default;

    /// Destructor
    virtual ~IPokerGame() = default;

    // todo implement more poker variations to determine shared aspects of the game that should be in the interface
    virtual void PlayRound() = 0;

    virtual void BettingRound() = 0;

    protected:
    /// Constructor
    IPokerGame(std::vector<std::string> playerOrder);

    // todo learn and implement blind changes and changes to player order
    // unsure if this should be a model concept (shared across poker variations) or buisness concept (unique to hold em)
    std::vector<std::string> mPlayerOrder;

    std::vector<std::string> mRemainingPlayerOrder;
};
} // namespace Poker::Game
