#include "JungleLane.h"

JungleLane::JungleLane(TextureHolder *textures) : Lane(textures) {
}

JungleLane::~JungleLane() {}

void JungleLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);

    if (!this->nextTime--) {
        random = GetRandomValue(1, 3);
        nextTime = 3 * FPS;
    }
    Texture2D texture;
    if (random == 1)
        texture = this->mTextures->get(Textures::Jungle_1);
    if (random == 2)
        texture = this->mTextures->get(Textures::Jungle_2);
    if (random == 3)
        texture = this->mTextures->get(Textures::Jungle_3);

    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void JungleLane::updateThis(float dt) {
    addRandomObject(this->type, dt);
}