#include <Model/Blind.h>

namespace Poker::Model
{

Blind::Blind(unsigned int cash, unsigned int forcedBet) : Player(cash), mForcedBet(forcedBet) {}

Blind::Blind(const Player& player, unsigned int forcedBet) : Player(player), mForcedBet(forcedBet) {}
} // namespace Poker::Model