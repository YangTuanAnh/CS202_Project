#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class JungleLane : public Lane {
private:
    float speed;
    Objects::ID type = Objects::Dinosaur;
public:
    JungleLane(TextureHolder *textures);
    ~JungleLane();
    void drawThis();
    void updateThis(float dt);
};