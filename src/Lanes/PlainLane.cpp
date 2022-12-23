#include "PlainLane.h"

PlainLane::PlainLane() {}

PlainLane::PlainLane(Objects::ID type, int direction) {
    this->type = type;
}

PlainLane::~PlainLane() {}

void PlainLane::update(float dt) {
    for (auto &object : objects) {
        object->update(dt);
    }
}

void PlainLane::draw() {
    for (auto &object : objects) {
        object->draw();
    }
}