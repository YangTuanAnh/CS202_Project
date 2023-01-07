#include "ForestLane.h"

ForestLane::ForestLane(TextureHolder *textures) : Lane(textures) {
}

ForestLane::~ForestLane() {}

void ForestLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);

    Texture2D texture = this->mTextures->get(Textures::Jungle);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void ForestLane::updateThis(float dt) {
    // addRandomObject(this->type);
}

void ForestLane::addObstacles() {
    //mTextures->load(Textures::Obstacle, "../asset/tree2.png");
    int randCnt = GetRandomValue(5, 10)/2;
    vector<int> posX;
    for (int i=0; i<randCnt; i++) {
        int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE;
        posX.push_back(randX);
    }
    for (int i=0; i<randCnt-1; i++)
        for (int j=i+1; j<randCnt; j++)
            if (posX[i]<posX[j])
                swap(posX[i], posX[j]);
                
    for (auto pos : posX)
        addObject(Objects::Obstacle, pos);
}