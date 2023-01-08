#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class PlainLane : public Lane {
private:
    float speed;
    Objects::ID type = Objects::None;
    Vector2 posTree;
public:
    PlainLane(TextureHolder *textures);
    ~PlainLane();
    void drawThis();
    void updateThis(float dt);
    void addObstacles();
};