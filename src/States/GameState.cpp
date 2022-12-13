#include "GameState.h"

#include <iostream>

GameState::GameState(StateStack* stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::GameBackground);
}

GameState::~GameState() {}

void GameState::draw() {
    BeginDrawing();
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    EndDrawing();
}

bool GameState::update(float dt) {
    bool updatePrevState = false;
    return updatePrevState;
}