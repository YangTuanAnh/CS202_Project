#include "PlainLane.h"

PlainLane::PlainLane(TextureHolder *textures) : Lane(textures) {}

PlainLane::~PlainLane() {}

void PlainLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIME);
    
    Texture2D texture = this->mTextures->get(Textures::Plain);
    Vector2 pos = convertCar2IsoVector({ 0.0f, this->mY });
    pos.x -= 40.0f;
    DrawTextureV(texture, pos, WHITE);
    pos = convertCar2IsoVector({ 600.0f, this->mY });
    pos.x -= 40.0f;
    DrawTextureV(texture, pos, WHITE);
}

void PlainLane::updateThis(float dt) {
    addRandomObject(this->type);
}