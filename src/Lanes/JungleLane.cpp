#include "JungleLane.h"

JungleLane::JungleLane() {}

JungleLane::JungleLane(Objects::ID type, int direction) {
    this->type = type;
    this->direction = direction;
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