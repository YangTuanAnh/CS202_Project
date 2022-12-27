#pragma once

#include "../PlayerState.h"

#include <raylib.h>

class JumpingState : public PlayerState {
private:
    Vector2 target;
    float elapsedTime = 0.0f;
    Directions::ID direction;
    const float jumpTime = 0.35f;
public:
    JumpingState(Player& player);
    void setTarget(Vector2, Directions::ID);
    float ease();
    void update(float dt) override;
};