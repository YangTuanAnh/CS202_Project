#include "Lane.h"

#include <iostream>

Lane::Lane() {}

Lane::~Lane() {}

void Lane::init(float y) {
    this->mY = y;
}

void Lane::update(float dt) {
    for (auto &object : objects) {
        object->update(dt);
    }
}

void Lane::draw() {
    // DrawRectangle(0, mY, GetScreenWidth(), 100, BLACK);
    for (auto &object : objects) {
        object->draw();
    }
}