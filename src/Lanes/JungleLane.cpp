#include "JungleLane.h"

JungleLane::JungleLane(TextureHolder *textures) : Lane(textures) {}

JungleLane::~JungleLane() {}

void JungleLane::drawThis() {
    DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);

    Texture2D texture = this->mTextures->get(Textures::Jungle);
    Vector2 pos = convertCar2IsoVector({ 0.0f, this->mY });
    DrawTextureV(texture, pos, WHITE);
}