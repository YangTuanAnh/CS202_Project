#include "Camera.h"

#include <iostream>

CustomCamera::CustomCamera(Player *player) {
    this->player = player;
    this->pos = player->getPos();
    this->target = convertCar2IsoVector(this->pos);
    this->offset = {SCREEN_WIDTH / 6, SCREEN_HEIGHT * 3/5};
    this->rotation = 0.0f;
    this->zoom = 1.0f;
    std::cerr << "Camera target position: "<< this->target.x << ", " << this->target.y << std::endl;
    std::cerr << "Camera offset: " << this->offset.x << ", " << this->offset.y << std::endl;
}

void CustomCamera::getCamera() {
}

void CustomCamera::update(float dt) {
    // std::cerr << this->target.x << ", " << this->target.y << std::endl;
    if (this->pos.y > player->getY()) {
        this->pos.y = player->getY();
    } else {
        this->pos.y += this->velocity * dt;
    }
    this->target = convertCar2IsoVector(pos);
}