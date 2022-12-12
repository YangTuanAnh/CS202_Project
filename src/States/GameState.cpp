#include "GameState.h"

#include <iostream>

GameState::GameState(StateStack* stack, Context context) : State(stack, context) {
    // TODO: Load from TextureHolder
    Image image = LoadImage("../asset/img/CrossyRoadBg.png"); // Path relative to executable
    mBackgroundTexture = new Texture2D(LoadTextureFromImage(image));
}

GameState::~GameState() {
    UnloadTexture(*mBackgroundTexture);
    delete mBackgroundTexture;
}

void GameState::draw() {
    BeginDrawing();
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    EndDrawing();
}

bool GameState::update(float dt) {
    bool updatePrevState = false;
    return updatePrevState;
}