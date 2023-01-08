#include "ForestLane.h"

ForestLane::ForestLane(TextureHolder *textures) : Lane(textures, Lanes::Forest, Objects::Obstacle) {
}

ForestLane::~ForestLane() {}

void ForestLane::drawThis() {
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

void ForestLane::updateThis(float dt) {
    // addRandomObject(this->type);
}

void ForestLane::addObstacles() {
    //mTextures->load(Textures::Obstacle, "../asset/tree2.png");
    int randCnt = GetRandomValue(MAP_WIDTH/4, MAP_WIDTH/2);
    vector<int> posX;
    for (int i=-MAP_WIDTH; i<0; i++) posX.push_back(i*BLOCK_SIZE);
    for (int i=MAP_WIDTH; i<MAP_WIDTH*2; i++) posX.push_back(i*BLOCK_SIZE);
    for (int i=0; i<randCnt; i++) {
        int randX = GetRandomValue(0, MAP_WIDTH-1)*BLOCK_SIZE;
        posX.push_back(randX);
    }
    int len = posX.size();
    for (int i=0; i<len-1; i++)
        for (int j=i+1; j<len; j++)
            if (posX[i]<posX[j])
                swap(posX[i], posX[j]);
                
    for (auto pos : posX)
        addObject(Objects::Obstacle, pos);
}