#include "GameState.h"

GameState::GameState(StateStack* stack, Context context) : State(stack, context) {
    mBackgroundTexture = LoadTexture("../../asset/img/CrossyRoadBg.jpg");
}

void GameState::draw() {
    BeginDrawing();
    DrawTexture(mBackgroundTexture, 0, 0, WHITE);
    EndDrawing();
}

bool GameState::update(float dt) {
    bool updatePrevState = false;
    return updatePrevState;
}