
#pragma once

#include <Model/Table.h>

namespace Poker
{
namespace Model
{
class Player;
} // namespace Model

namespace Game
{
class HoldEm
{
    public:
    /// Constructor
    HoldEm(std::vector<std::string> playerOder, std::map<std::string, std::unique_ptr<Model::Player>> players);

    /// Default copy constructor
    HoldEm(const HoldEm&) = default;

    /// Default move constructor
    HoldEm(HoldEm&&) = default;

    /// Default copy assignment operator
    HoldEm& operator=(const HoldEm&) = default;

    /// Default move assignment operator
    HoldEm& operator=(HoldEm&&) = default;

    /// Destructor
    virtual ~HoldEm() = default;

    void PlayRound();

    private:
    Model::Table mTable;
};
} // namespace Game
} // namespace Poker