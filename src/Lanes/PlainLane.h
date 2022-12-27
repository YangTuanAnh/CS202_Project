#pragma once

#include "../Lane.hpp"
// #include "../Global.h"

class PlainLane : public Lane {
private:
    Objects::ID type;
public:
    PlainLane(TextureHolder *textures);
    ~PlainLane();
    void drawThis();
};