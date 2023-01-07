#include "CarLane.h"

CarLane::CarLane(TextureHolder *textures) : Lane(textures) {}

CarLane::~CarLane() {}

void CarLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIGHTGRAY);

    Texture2D texture = this->mTextures->get(Textures::Road);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void CarLane::updateThis(float dt) {
    addRandomObject(this->type);
}

void CarLane::addObstacles() {}

void CarLane::addTrafficLamp() {
    int randX = GetRandomValue(1, MAP_WIDTH/2)*BLOCK_SIZE -1;
    addObject(Objects::TrafficLamp, randX);
}