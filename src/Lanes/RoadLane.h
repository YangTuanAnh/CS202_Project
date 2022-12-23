#pragma once

#include "../Lane.h"

class RoadLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    RoadLane();
    RoadLane(Objects::ID type, int direction);
    ~RoadLane();
    void update(float dt);
    void draw();
};