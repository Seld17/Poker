// Poker.cpp : Defines the entry point for the application.
//

#include "Poker.h"

// includes to move
#include <Model/Deck.h>
#include <Model/Player.h>

#include <map>
#include <memory>

int main()
{
    /// texas hold em play through
    /// shuffle cards
    using namespace Poker::Model;
    const auto deck = std::make_unique<Deck>();
    // init players
    std::vector<std::string> playerOder{ "Alice", "Bob", "Tom", "Jim" };
    std::map<std::string, std::unique_ptr<Player>> players;
    for(const auto& player : playerOder)
    {
        players[player] = std::make_unique<Player>(100);
    }

    // struct player order

    // deal 2 cards each

    // pre-flop round (betting round)
    // round table bets, fold, all chips or all players match bet

    // burn card

    // flop
    // 3 community cards face up
    // betting round

    // burn card

    // turn
    // flip one card
    // betting round

    // burn card

    // river
    // flip 1 card
    //

    // showdown

    // winner
}
