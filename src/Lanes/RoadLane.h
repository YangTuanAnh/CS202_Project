#pragma once

#include "../Lane.h"

class RoadLane : public Lane {
private:
    float speed;
    int direction = 1;
    ObjectTypes::ID type;
public:
    RoadLane(float speed, int direction);
    ~RoadLane();
    void update(float dt);
    void draw();
};