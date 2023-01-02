#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class TruckLane : public Lane {
private:
    float speed;
    Objects::ID type = Objects::Truck;
public:
    TruckLane(TextureHolder *textures);
    ~TruckLane();
    void drawThis();
    void updateThis(float dt);
    void addObstacles();
};