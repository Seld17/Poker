// Poker.cpp : Defines the entry point for the application.
//

#include "Poker.h"

// includes to move
#include <Model/Blind.h>
#include <Model/Deck.h>
#include <Model/Player.h>

#include <memory>

int main()
{
    /// texas hold em play through
    /// shuffle cards
    using namespace Poker::Model;
    const auto deck = std::make_unique<Deck>();
    // init players
    std::vector<std::unique_ptr<Player>> players;
    players.push_back(std::make_unique<Player>(100));
    players.push_back(std::make_unique<Player>(100));
    players.push_back(std::make_unique<Blind>(100, 10));
    players.push_back(std::make_unique<Blind>(100, 5));

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
}
