#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class ForestLane : public Lane {
private:
    float speed;
    int random;
    int nextTime = 0;
    Objects::ID type = Objects::Obstacle;
public:
    ForestLane(TextureHolder *textures);
    ~ForestLane();
    void drawThis();
    void updateThis(float dt);
    void addObstacles();
};