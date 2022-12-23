#pragma once

#include "../Lane.hpp"

class JungleLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    JungleLane(TextureHolder *textures);
    ~JungleLane();
    void update(float dt);
    void draw();
};