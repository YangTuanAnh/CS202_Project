#include "JungleLane.h"
#include <queue>

JungleLane::JungleLane(TextureHolder *textures) : Lane(textures) {
}

JungleLane::~JungleLane() {}

void JungleLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);

    Texture2D texture = this->mTextures->get(Textures::Jungle);
    Vector2 pos = convertCar2IsoVector({ 0.0f, this->mY });
    pos.x -= 40.0f;
    DrawTextureV(texture, pos, WHITE);
    pos = convertCar2IsoVector({ 600.0f, this->mY });
    pos.x -= 40.0f;
    DrawTextureV(texture, pos, WHITE);
}

void JungleLane::updateThis(float dt) {
    addRandomObject(this->type);
}

void JungleLane::addObstacles() {
    //mTextures->load(Textures::Obstacle, "../asset/tree2.png");
    int randCnt = GetRandomValue(5, 10);
    std::priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<randCnt; i++) {
        int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE -1;
        pq.push(randX);
    }
    while (!pq.empty()) {
        addObject(Objects::ID::Obstacle, pq.top());
        pq.pop();
    }
}