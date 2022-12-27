#include "Lane.hpp"

#include <iostream>

Lane::Lane(TextureHolder *textures) : mTextures(textures) {
    mFactories.registerType<Car>(Objects::Car);
    mFactories.registerType<Truck>(Objects::Truck);
    mFactories.registerType<Bird>(Objects::Bird);
    mFactories.registerType<Dinosaur>(Objects::Dinosaur);
}

Lane::~Lane() {}

void Lane::init(float y) {
    this->mY = y;
    //addObject(  Objects::ID(GetRandomValue(2, OBJECT_COUNT)), 0);
    //addRandomObject();
}

void Lane::drawThis() {
    //DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, BLACK);
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
    case Objects::Bird:
        speed = BIRD_SPEED;
        break;
    case Objects::Dinosaur:
        speed = DINOSAUR_SPEED;
        break;
    default:
        break;
    }
    auto newObject = mFactories.create(type, x, mY, direction, speed, mTextures);
    attachChild(std::move(newObject));
}

void Lane::addRandomObject() {
    if (nextSpawnTime--) return;
    nextSpawnTime = GetRandomValue(1, MAX_SPAWN_TIME) * FPS;
    int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE -1;
    auto randObj = Objects::ID(GetRandomValue(2, OBJECT_COUNT));
    addObject(randObj, randX);
}

void Lane::updateThis(float dt) {
    addRandomObject();
    //addObject(  Objects::ID(GetRandomValue(2, OBJECT_COUNT)), 0);
}