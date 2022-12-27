#include "RoadLane.h"

RoadLane::RoadLane(TextureHolder *textures) : Lane(textures) {}

RoadLane::~RoadLane() {}

void RoadLane::drawThis() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIGHTGRAY);

    Texture2D texture = this->mTextures->get(Textures::Road);
    Vector2 pos = convertCar2IsoVector({ 0.0f, this->mY });
    DrawTextureV(texture, pos, WHITE);
}