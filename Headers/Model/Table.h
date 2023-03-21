
#pragma once

#include <Model/Player.h>

#include <map>
#include <memory>
#include <utility>
#include <vector>

namespace Poker::Model
{
class Card;
class Deck;

class Table
{
    public:
    /// Constructor
    Table(std::map<std::string, std::unique_ptr<Player>> players, std::unique_ptr<Deck> deck);

    /// Default copy constructor
    Table(const Table&) = default;

    /// Default move constructor
    Table(Table&&) = default;

    /// Default copy assignment operator
    Table& operator=(const Table&) = default;

    /// Default move assignment operator
    Table& operator=(Table&&) = default;

    /// Destructor
    virtual ~Table() = default;

    void DealPlayerHand(const std::string& player, unsigned int numberOfCards);

    void BurnCard();

    /// used for flop, turn and river
    void AddCommunityCards(unsigned int numberToFlip);

    void AddToPot(unsigned int bet);

    void DistributePot(const std::string& winner);

    /// \return winner's name
    std::string ShowDown(const std::vector<std::string>& remainingPlayers);

    /// \return winner's name
    void Fold(const std::string& name);

    private:
    std::string ResolveTieBreaker(const std::pair<std::string, std::string>& tiedPlayers) const;

    unsigned int mPot;

    std::map<std::string, std::unique_ptr<Player>> mPlayers;

    /// container for blinds, dealer, button
    /// [title, name]
    std::map<std::string, std::string> mTokens;

    std::unique_ptr<Deck> mDeck;

    std::vector<std::shared_ptr<Card>> mCommunityCards;
};
} // namespace Poker::Model