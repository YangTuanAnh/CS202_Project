#include "TruckLane.h"

TruckLane::TruckLane(TextureHolder *textures) : Lane(textures) {}

TruckLane::~TruckLane() {}

void TruckLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIGHTGRAY);

    Texture2D texture = this->mTextures->get(Textures::Road);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void TruckLane::updateThis(float dt) {
    addRandomObject(this->type);
}

void TruckLane::addObstacles() {}