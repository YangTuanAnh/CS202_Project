#include "RoadLane.h"

RoadLane::RoadLane(float speed, int direction, Objects::ID type) {
    this->speed = speed;
    this->direction = direction;
    this->type = type;
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