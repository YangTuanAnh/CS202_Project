#include "Lane.h"
#include "Global.h"

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
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, BLACK);
    for (auto &object : objects) {
        object->draw();
    }
}