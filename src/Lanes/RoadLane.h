#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class RoadLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    RoadLane(TextureHolder *textures);
    ~RoadLane();
    void drawThis();
};