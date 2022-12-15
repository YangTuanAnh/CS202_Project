#pragma once

#include <memory>

#include "ResourceIdentifiers.hpp"

class Player; // Forward declaration

class PlayerState {
protected: 
    Player& player;
public:
    const PlayerStates::ID stateID;
    typedef std::unique_ptr<PlayerState> Ptr;
    PlayerState(Player& player, PlayerStates::ID state) : player(player), stateID(state) {}
    virtual void update(float dt) = 0;
};