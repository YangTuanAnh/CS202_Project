#include "JumpingState.h"
#include "../Player.hpp"

#include <iostream>

const float blockSize = 40.0f;

JumpingState::JumpingState(Player& player) : PlayerState(player, PlayerStates::Jumping) {}

float JumpingState::ease() {
    // 1 - (t - 1)^2
    float t = elapsedTime / jumpTime;
    float d = (1.0f - (t - 1.0f) * (t - 1.0f)) * blockSize;
    return d;
}

void JumpingState::setTarget(Vector2 curPos, Directions::ID direction) {
    this->direction = direction;
    switch (direction) {
    case Directions::Up:
        target = Vector2{curPos.x, curPos.y - blockSize};
        break;
    case Directions::Down:
        target = Vector2{curPos.x, curPos.y + blockSize};
        break;
    case Directions::Left:
        target = Vector2{curPos.x - blockSize, curPos.y};
        break;
    case Directions::Right:
        target = Vector2{curPos.x + blockSize, curPos.y};
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
        player.setY((target.y + blockSize) - ease());
        break;
    case Directions::Down:
        player.setY((target.y - blockSize) + ease());
        break;
    case Directions::Left:
        player.setX((target.x + blockSize) - ease());
        break;
    case Directions::Right:
        player.setX((target.x - blockSize) + ease());
        break;
    default:
        break;
    }
    elapsedTime += dt;
}