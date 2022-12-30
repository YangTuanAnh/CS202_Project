#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class RoadLane : public Lane {
private:
    float speed;
    Objects::ID type = Objects::ID::Car;
public:
    RoadLane(TextureHolder *textures);
    ~RoadLane();
    void drawThis();
    void updateThis(float dt);
    void addObstacles();
};