#include "JumpingState.h"
#include "../Player.hpp"

#include <iostream>

JumpingState::JumpingState(Player& player) : PlayerState(player, PlayerStates::Jumping) {}

float JumpingState::ease() {
    // 1 - (t - 1)^2
    float t = elapsedTime / jumpTime;
    float v = (2 * t - 2) * 40.0f;
    return v * t;
}

void JumpingState::setTarget(Vector2 curPos, Directions::ID direction) {
    this->direction = direction;
    switch (direction) {
    case Directions::Up:
        target = Vector2{curPos.x, curPos.y - 40.0f};
        break;
    case Directions::Down:
        target = Vector2{curPos.x, curPos.y + 40.0f};
        break;
    case Directions::Left:
        target = Vector2{curPos.x - 40.0f, curPos.y};
        break;
    case Directions::Right:
        target = Vector2{curPos.x + 40.0f, curPos.y};
        break;
    default:
        break;
    }
    std::cerr << "Jumping to " << target.x << ", " << target.y << std::endl;
}

void JumpingState::update(float dt) {
    if (elapsedTime >= jumpTime) {
        player.setX(target.x);
        player.setY(target.y);
        player.setState(PlayerStates::Idle);
        return;
    }
    switch (direction) {
    case Directions::Up:
        player.setY((target.y + 40.0f) + ease());
        break;
    case Directions::Down:
        player.setY((target.y - 40.0f) - ease());
        break;
    case Directions::Left:
        player.setX((target.x + 40.0f) + ease());
        break;
    case Directions::Right:
        player.setX((target.x - 40.0f) - ease());
        break;
    default:
        break;
    }
    elapsedTime += dt;
}