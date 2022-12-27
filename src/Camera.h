#pragma once

#include <raylib.h>

#include "Player.hpp"
#include "Global.h"

class CustomCamera : public Camera2D {
private:
    Player *player;
public:
    CustomCamera(Player *player);
    void getCamera();
    void update(float dt);
};