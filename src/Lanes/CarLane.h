#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class CarLane : public Lane {
private:
    float speed;
    int nextLightState = 0;
    Objects::ID type = Objects::Car;
public:
    CarLane(TextureHolder *textures);
    ~CarLane();
    void drawThis();
    void updateThis(float dt);
    void addObstacles();
    void addTrafficLamp();
};