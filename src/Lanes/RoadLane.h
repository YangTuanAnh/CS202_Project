#pragma once

#include "../Lane.h"

class RoadLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    RoadLane(float speed, int direction, Objects::ID type);
    ~RoadLane();
    void update(float dt);
    void draw();
};