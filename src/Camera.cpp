#include "Camera.h"

#include <iostream>

CustomCamera::CustomCamera(Player *player) {
    this->player = player;
    this->pos = player->getPos();
    this->target = convertCar2IsoVector(this->pos);
    this->offset = {SCREEN_WIDTH * 1/3, SCREEN_HEIGHT * 4/7};
    this->rotation = 0.0f;
    this->zoom = 1.0f;
    std::cerr << "Camera target position: "<< this->target.x << ", " << this->target.y << std::endl;
    std::cerr << "Camera offset: " << this->offset.x << ", " << this->offset.y << std::endl;
}

void CustomCamera::reset() {
    this->pos = player->getPos();
    this->target = convertCar2IsoVector(this->pos);
}

void CustomCamera::update(float dt) {
    // std::cerr << this->target.x << ", " << this->target.y << std::endl;
    if (this->pos.y > player->getY()) {
        this->pos.y = player->getY();
    } else {
        this->pos.y += this->velocity * dt;
    }
    this->target = convertCar2IsoVector(this->pos);
}

void CustomCamera::save(std::ofstream& out) {
    // out << "Camera: ";
    out << this->pos.x << ' ' << this->pos.y << '\n';
}

void CustomCamera::load(std::ifstream& in) {
    in >> this->pos.x >> this->pos.y;
    this->target = convertCar2IsoVector(this->pos);
}