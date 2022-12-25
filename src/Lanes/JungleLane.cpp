#include "JungleLane.h"

JungleLane::JungleLane(TextureHolder *textures) : Lane(textures) {}

JungleLane::~JungleLane() {}

void JungleLane::drawThis() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);
}