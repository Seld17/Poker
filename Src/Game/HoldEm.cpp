#include <Game/HoldEm.h>

#include <Model/Player.h>
#include <Model/Deck.h>

namespace Poker::Game
{


HoldEm::HoldEm(std::vector<std::string> playerOder, std::map<std::string, std::unique_ptr<Model::Player>> players)
    : mTable(Model::Table(std::move(playerOder), std::move(players), std::make_unique<Model::Deck>()))
{
}

void HoldEm::PlayRound() 
{ 
    mTable.DealPlayerHand();

    // betting round

    mTable.BurnCard();

    mTable.AddCommunityCards(3);

    // betting round

    mTable.BurnCard();
    mTable.AddCommunityCards(1);

    // betting round

    mTable.BurnCard();
    mTable.AddCommunityCards(1);

    // showdown

    // assign winner
    // mTable.DistributePot();

}
} // namespace Poker::Game