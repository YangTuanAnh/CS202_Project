#include "JumpingState.h"
#include "../Player.hpp"

JumpingState::JumpingState(Player& player) : PlayerState(player, PlayerStates::Jumping) {}

float JumpingState::ease(float d) {
    // 1 - (t - 1)^2
    float t = elapsedTime / jumpTime;
    d += (1 - (t - 1) * (t - 1)) * 40.0f;
    return d;
}

void JumpingState::update(float dt) {
    if (elapsedTime >= jumpTime) {
        player.setX(target.x);
        player.setY(target.y);
        player.setState(PlayerStates::Idle);
        return;
    }
    elapsedTime += dt;
}