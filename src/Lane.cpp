#include "Lane.h"

Lane::Lane() {}

Lane::~Lane() {}

void Lane::addObject(Object::Ptr object) {
    objects.push_back(object);
}

void Lane::removeObject(Object::Ptr object) {
    objects.remove(object);
}

void Lane::update(float dt) {
    for (auto &object : objects) {
        object->update(dt);
    }
}

void Lane::draw() {
    for (auto &object : objects) {
        object->draw();
    }
}