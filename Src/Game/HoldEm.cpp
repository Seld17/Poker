#include <Game/HoldEm.h>

#include <Model/Player.h>
#include <Model/Deck.h>

namespace Poker::Game
{
namespace
{
constexpr unsigned int HOLD_EM_POCKET_CARD_SIZE{ 2 };
constexpr auto FOLD{ "fold" };
constexpr auto CALL{ "call" };
constexpr auto RAISE{ "raise" };
constexpr auto BET{ "bet" };
constexpr auto CHECK{ "CHECK" };

}


HoldEm::HoldEm(std::vector<std::string> playerOder, std::map<std::string, std::unique_ptr<Model::Player>> players)
    : mPlayerOrder(std::move(playerOder))
    , mTable(Model::Table(std::move(players), std::make_unique<Model::Deck>()))
    , mRemainingPlayerOrder(mPlayerOrder)
{
}

void HoldEm::PlayRound() 
{ 
    for(const auto& name : mPlayerOrder)
    {
        mTable.DealPlayerHand(name, HOLD_EM_POCKET_CARD_SIZE);
    }

    BettingRound();

    mTable.BurnCard();

    mTable.AddCommunityCards(3);

    BettingRound();

    mTable.BurnCard();
    mTable.AddCommunityCards(1);

    BettingRound();

    mTable.BurnCard();
    mTable.AddCommunityCards(1);

    // showdown
    const auto winnner = mTable.ShowDown(mRemainingPlayerOrder);
    // assign winner
    // todo pot distribution affected by tie breakers
    mTable.DistributePot(winnner);

}

void HoldEm::BettingRound() 
{
    for(const auto& player : mRemainingPlayerOrder)
    {
        // todo implement user input to decide player action
        std::string action;
        if(action == FOLD)
        {
            mTable.Fold(player);
        }
        // todo implement other actions
        else if(action == CALL)
        {
        }
        else if(action == RAISE)
        {
        }
        else if(action == BET)
        {
        }
        else if(action == CHECK)
        {
        }
        else
        {
            throw("Unknown actions");
        }
    }
}
} // namespace Poker::Game