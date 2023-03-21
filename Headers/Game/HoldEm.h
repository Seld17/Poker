
#pragma once
#include <Game/IPokerGame.h>

#include <Model/Table.h>

namespace Poker
{
namespace Model
{
class Player;
} // namespace Model

namespace Game
{
class HoldEm final : public IPokerGame
{
    public:
    /// Constructor
    HoldEm(std::vector<std::string> playerOder, std::map<std::string, std::unique_ptr<Model::Player>> players);

    //using IPokerGame::operator=();

    /// Destructor
    virtual ~HoldEm() = default;

    void PlayRound() override;

    void BettingRound() override;

    private:
    Model::Table mTable;
};
} // namespace Game
} // namespace Poker