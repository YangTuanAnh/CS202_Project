#include "RoadLane.h"
#include "../Global.h"

RoadLane::RoadLane() {}

RoadLane::RoadLane(Objects::ID type, int direction) {
    this->direction = direction;
    this->type = type;
    switch (type) {
        case Objects::Car:
            this->speed = CAR_SPEED;
            break;
        case Objects::Truck:
            this->speed = TRUCK_SPEED;
            break;
        default:
            this->speed = CAR_SPEED;
            break;
    }
}

RoadLane::~RoadLane() {}

void RoadLane::update(float dt) {
    for (auto &object : objects) {
        object->update(dt);
    }
}

void RoadLane::draw() {
    for (auto &object : objects) {
        object->draw();
    }
}