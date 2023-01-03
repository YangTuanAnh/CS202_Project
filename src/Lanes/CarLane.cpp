#include "CarLane.h"

CarLane::CarLane(TextureHolder *textures) : Lane(textures) {}

CarLane::~CarLane() {}

void CarLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIGHTGRAY);

    Texture2D texture = this->mTextures->get(Textures::Road);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, WHITE);
}

void CarLane::updateThis(float dt) {
    addRandomObject(this->type);
}

void CarLane::addObstacles() {}