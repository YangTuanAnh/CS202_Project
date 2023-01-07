#pragma once

#include <raylib.h>

#include "Player.hpp"
#include "Global.h"

class CustomCamera : public Camera2D {
private:
    Player *player;
    // non-isometric position
    Vector2 pos;
    float velocity = -10.0f;
public:
    CustomCamera(Player *player);
    void getCamera();
    void update(float dt);
};