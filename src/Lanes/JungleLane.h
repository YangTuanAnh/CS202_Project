#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class JungleLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    JungleLane(TextureHolder *textures);
    ~JungleLane();
    void drawThis();
};