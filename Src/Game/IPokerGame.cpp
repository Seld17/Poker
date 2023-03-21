
#include <Game/IPokerGame.h>

namespace Poker::Game
{
IPokerGame::IPokerGame(std::vector<std::string> playerOrder)
    : mPlayerOrder(std::move(playerOrder))
    , mRemainingPlayerOrder(mPlayerOrder)
{
}
} // namespace Poker::Game