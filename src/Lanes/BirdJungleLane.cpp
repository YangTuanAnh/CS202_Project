#include "BirdJungleLane.h"

BirdJungleLane::BirdJungleLane(TextureHolder *textures) : Lane(textures, Lanes::BirdJungle, Objects::Bird) {
}

BirdJungleLane::~BirdJungleLane() {}

void BirdJungleLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);

    Texture2D texture = this->mTextures->get(Textures::Jungle);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void BirdJungleLane::updateThis(float dt) {
    addRandomObject(this->type, dt);
}