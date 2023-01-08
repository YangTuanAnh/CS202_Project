#include "Lane.hpp"

#include <iostream>

Lane::Lane(TextureHolder *textures) : mTextures(textures) {
    mFactories.registerType<Obstacle>(Objects::Obstacle);
    mFactories.registerType<TrafficLamp>(Objects::TrafficLamp);
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
    // std::cerr << "pos1: " << pos1.x << ", " << pos1.y << std::endl;
    addObstacles();
    addTrafficLamp();
    //addObject(  Objects::ID(GetRandomValue(2, OBJECT_COUNT)), 0);
    //addRandomObject();
}

void Lane::drawThis() {
    //DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, BLACK);
}

void Lane::addObject(Objects::ID type) {
    float speed = 0;
    float x;
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
    direction = GetRandomValue(0, 1);
    x = -40.0f;
    if (!direction) {
        direction = -1;
        x = 600.0f;
    }
    auto newObject = mFactories.create(type, x, mY, direction, speed, mTextures);
    attachChild(std::move(newObject));
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
    direction = 1;
    auto newObject = mFactories.create(type, x, mY, direction, speed, mTextures);
    attachChild(std::move(newObject));
}

void Lane::addRandomObject(Objects::ID type, float dt) {
    // int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE -1;
    if (nextSpawnTime > 0.0f) {
        nextSpawnTime -= dt;
        return;
    } 
    nextSpawnTime = (float)GetRandomValue(100, MAX_SPAWN_TIME*100) / 100.0f;
    //auto randObj = Objects::ID(GetRandomValue(2, OBJECT_COUNT));
    // addObject(type, randX);
    addObject(type);
}

void Lane::addObstacles() {
}

void Lane::updateThis(float dt) {
    addRandomObject(this->type, dt);
    removeOutOfView();
    //addObject(  Objects::ID(GetRandomValue(2, OBJECT_COUNT)), 0);
}
float Lane::getY(){return this->mY;}

void Lane::addTrafficLamp() {
}

void Lane::removeOutOfView() {
    auto objects = getChildren();
    
    int len = objects.size();
    for (int i=0; i<len; i++) {
        std::shared_ptr<Object> obj = std::dynamic_pointer_cast<Object>(objects[i]);
        if (obj->getType()==Objects::ID::TrafficLamp || obj->getType()==Objects::ID::Obstacle) 
            continue;
        if (obj->getX() > BLOCK_SIZE*(MAP_WIDTH+10) || obj->getX()< -10*BLOCK_SIZE) {
            cerr<<"Deleting ";
            if(obj.get()->getType()==Objects::Dinosaur)cerr<<"Dino\n";
            if(obj.get()->getType()==Objects::Bird)cerr<<"Bird\n";
            if(obj.get()->getType()==Objects::Truck)cerr<<"Truck\n";
            if(obj.get()->getType()==Objects::Car)cerr<<"Car\n";
            detachChild(*obj);
        }
        break;
    }
}
