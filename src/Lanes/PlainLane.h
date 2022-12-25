#pragma once

#include "../Lane.hpp"

class PlainLane : public Lane {
private:
    Objects::ID type;
public:
    PlainLane(TextureHolder *textures);
    ~PlainLane();
    void drawThis();
};