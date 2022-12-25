#include "RoadLane.h"
#include "../Global.h"

RoadLane::RoadLane(TextureHolder *textures) : Lane(textures) {}

RoadLane::~RoadLane() {}

void RoadLane::drawThis() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, WHITE);
}