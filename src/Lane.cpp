#include "Lane.hpp"

#include <iostream>

Lane::Lane(TextureHolder *textures) : mTextures(textures) {
    mFactories.registerType<Obstacle>(Objects::Obstacle);
    mFactories.registerType<Car>(Objects::Car);
    mFactories.registerType<Truck>(Objects::Truck);
    mFactories.registerType<Bird>(Objects::Bird);
    mFactories.registerType<Dinosaur>(Objects::Dinosaur);
}

Lane::~Lane() {
    detachAllChildren();
}

void Lane::init(float y) {
    this->mY = y;
    pos1 = convertCar2IsoVector({ 0.0f, this->mY });
    pos2 = convertCar2IsoVector({ 600.0f, this->mY});
    pos3 = convertCar2IsoVector({ -600.0f, this->mY});
    pos1.x -= 40.0f;
    pos2.x -= 40.0f;
    pos3.x -= 40.0f;
    std::cerr << "pos1: " << pos1.x << ", " << pos1.y << std::endl;
    addObstacles();
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

void Lane::addRandomObject(Objects::ID type) {
    // int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE -1;
    if (nextSpawnTime--) return;
    nextSpawnTime = GetRandomValue(1, MAX_SPAWN_TIME) * FPS;
    //auto randObj = Objects::ID(GetRandomValue(2, OBJECT_COUNT));
    // addObject(type, randX);
    addObject(type, -40.0f);
}

void Lane::addObstacles() {
}

void Lane::updateThis(float dt) {
    addRandomObject(this->type);
    //addObject(  Objects::ID(GetRandomValue(2, OBJECT_COUNT)), 0);
}