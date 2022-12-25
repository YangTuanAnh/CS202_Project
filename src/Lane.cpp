#include "Lane.hpp"
#include "Global.h"

#include <iostream>

Lane::Lane(TextureHolder *textures) : mTextures(textures) {
    mFactories.registerType<Car>(Objects::Car);
    mFactories.registerType<Truck>(Objects::Truck);
}

Lane::~Lane() {}

void Lane::init(float y) {
    this->mY = y;
    addObject(Objects::Car, 0);
}

void Lane::drawThis() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, BLACK);
}

void Lane::addObject(Objects::ID type, float x) {
    float speed = 0;
    switch (type) {
    case Objects::Car:
        speed = CAR_SPEED;
        break;
    case Objects::Truck:
        speed = TRUCK_SPEED;
        break;
    default:
        break;
    }
    auto newObject = mFactories.create(type, x, mY, direction, speed, mTextures);
    attachChild(std::move(newObject));
}