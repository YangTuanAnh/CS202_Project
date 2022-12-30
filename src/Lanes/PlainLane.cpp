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

void PlainLane::addObstacles() {
    // mTextures->load(Textures::Obstacle, "../asset/object/vehicle_truck_left.png");
    // int randCnt = GetRandomValue(5, 10);
    // for (int i=0; i<randCnt; i++) {
    //     int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE -1;
    //     addObject(Objects::ID::Obstacle, randX);
    // }
}