#pragma once

#include "../PlayerState.h"

class IdleState : public PlayerState {
public:
    IdleState(Player& player);
    void update(float dt) override;
};