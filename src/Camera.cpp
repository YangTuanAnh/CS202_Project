#include "Camera.h"

#include <iostream>

CustomCamera::CustomCamera(Player *player) {
    this->player = player;
    this->target = player->getPos();
    this->offset = {SCREEN_WIDTH / 2, SCREEN_HEIGHT * 2/3};
    this->rotation = 0.0f;
    this->zoom = 1.0f;
    std::cerr << this->target.x << ", " << this->target.y << std::endl;
    std::cerr << this->offset.x << ", " << this->offset.y << std::endl;
}

void CustomCamera::getCamera() {
}

void CustomCamera::update(float dt) {
    // std::cerr << this->target.x << ", " << this->target.y << std::endl;
    this->target = Vector2{this->target.x, player->getPos().y};
}