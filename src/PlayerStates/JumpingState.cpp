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
        curPos.y -= blockSize;
        this->player.chicken = &(this->player.mTextures->get(Textures::Player_up));
        // if(curPos.y<0.0f) curPos.y = 0.0f;
        break;
    case Directions::Down:
        curPos.y += blockSize;
        this->player.chicken = &(this->player.mTextures->get(Textures::Player_down));
        if (curPos.y > 0.0f) curPos.y = 0.0f;
        break;
    case Directions::Left:
        curPos.x -= blockSize;
        this->player.chicken = &(this->player.mTextures->get(Textures::Player_left));
        if (curPos.x < 0.0f) curPos.x = 0.0f;
        break;
    case Directions::Right:
        curPos.x += blockSize;
        this->player.chicken = &(this->player.mTextures->get(Textures::Player_right));
        if (curPos.x > 560.0f) curPos.x = 560.0f;
        break;
    default:
        break;
    }
    target = Vector2{curPos.x,curPos.y};
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
        if (player.getY() != 0.0f)
            player.setY((target.y - blockSize) + ease());
        break;
    case Directions::Left:
        if (player.getX() != 0.0f)
            player.setX((target.x + blockSize) - ease());
        break;
    case Directions::Right:
        if (player.getX() != 560.0f)
            player.setX((target.x - blockSize) + ease());
        break;
    default:
        break;
    }
    elapsedTime += dt;
}