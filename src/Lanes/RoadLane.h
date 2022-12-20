#pragma once

#include "../Lane.h"

class RoadLane : public Lane {
private:
    float speed;
    ObjectTypes::ID type;
public:
    RoadLane(float speed, int direction, ObjectTypes::ID type);
    ~RoadLane();
    void update(float dt);
    void draw();
};