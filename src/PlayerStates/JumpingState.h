#pragma once

#include "../PlayerState.h"

#include <raylib.h>

class JumpingState : public PlayerState {
private:
    Vector2 target;
    float elapsedTime;
    Directions::ID direction;
    const float jumpTime = 0.5f;
public:
    JumpingState(Player& player);
    float ease(float d);
    void update(float dt) override;
};