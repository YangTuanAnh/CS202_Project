#include "JungleLane.h"

JungleLane::JungleLane(float speed, int direction, ObjectTypes::ID type) {
    this->speed = speed;
    this->direction = direction;
    this->type = type;
}

JungleLane::~JungleLane() {}

void JungleLane::update(float dt) {
    for (auto &object : objects) {
        object->update(dt);
    }
}

void JungleLane::draw() {
    for (auto &object : objects) {
        object->draw();
    }
}