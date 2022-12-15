#include "IdleState.h"
#include "../Player.hpp"

#include <raylib.h>

IdleState::IdleState(Player& player) : PlayerState(player, PlayerStates::Idle) {}

void IdleState::update(float dt) {
    if (IsKeyPressed(KEY_W)) {
        player.setState(PlayerStates::Jumping);
    }
}