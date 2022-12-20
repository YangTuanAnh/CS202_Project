#pragma once

#include "../Lane.h"

class JungleLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    JungleLane();
    JungleLane(Objects::ID type, int direction);
    ~JungleLane();
    void update(float dt);
    void draw();
};