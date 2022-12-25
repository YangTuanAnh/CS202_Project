#include "PlainLane.h"

PlainLane::PlainLane(TextureHolder *textures) : Lane(textures) {}

PlainLane::~PlainLane() {}

void PlainLane::drawThis() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);
}