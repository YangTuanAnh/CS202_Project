#include "PlainLane.h"

PlainLane::PlainLane(TextureHolder *textures) : Lane(textures) {}

PlainLane::~PlainLane() {}

void PlainLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIME);
    
    Texture2D texture = this->mTextures->get(Textures::Plain);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
    texture = this->mTextures->get(Textures::Obstacle);
    posTree = convertCar2IsoVector({ -40.0f, this->mY });
    posTree.x -= 31.0f;
    posTree.y -= 70.0f;
    DrawTextureV(texture, this->posTree, GRAY);
    posTree = convertCar2IsoVector({ 600.0f, this->mY });
    posTree.x -= 31.0f;
    posTree.y -= 70.0f;
    DrawTextureV(texture, this->posTree, GRAY);
}

void PlainLane::updateThis(float dt) {}
