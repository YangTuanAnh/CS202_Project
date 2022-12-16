#include "PausedState.h"

#include <iostream>

PausedState::PausedState(StateStack* stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::PausedBackground);
}

void PausedState::draw() {
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
}

bool PausedState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_TAB)) {
        requestStackPop();
        return updatePrevState;
    }
    return updatePrevState;
}