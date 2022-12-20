#pragma once

#include "../Lane.h"

class PlainLane : public Lane {
private:
    Objects::ID type;
public:
    PlainLane();
    PlainLane(Objects::ID type, int direction);
    ~PlainLane();
    void update(float dt);
    void draw();
};