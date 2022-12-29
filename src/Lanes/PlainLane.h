#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class PlainLane : public Lane {
private:
    float speed;
    Objects::ID type = Objects::ID::Truck;
public:
    PlainLane(TextureHolder *textures);
    ~PlainLane();
    void drawThis();
    void updateThis(float dt);
};