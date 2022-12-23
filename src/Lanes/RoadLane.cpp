#include "RoadLane.h"
#include "../Global.h"

RoadLane::RoadLane(TextureHolder *textures) : Lane(textures) {}

RoadLane::~RoadLane() {}

void RoadLane::update(float dt) {
    for (auto &object : objects) {
        object->update(dt);
    }
}

void RoadLane::draw() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);
    for (auto &object : objects) {
        object->draw();
    }
}