#include "JungleLane.h"

JungleLane::JungleLane(TextureHolder *textures) : Lane(textures) {}

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