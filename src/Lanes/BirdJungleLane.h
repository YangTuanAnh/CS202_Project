#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class BirdJungleLane : public Lane {
private:
    float speed;
    int random;
    int nextTime = 0;
    Objects::ID type = Objects::Bird;
public:
    BirdJungleLane(TextureHolder *textures);
    ~BirdJungleLane();
    void drawThis();
    void updateThis(float dt);
};