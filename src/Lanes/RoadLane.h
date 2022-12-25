#pragma once

#include "../Lane.hpp"

class RoadLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    RoadLane(TextureHolder *textures);
    ~RoadLane();
    void drawThis();
};