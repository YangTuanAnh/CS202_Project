#include "GameOverState.h"

#include <iostream>

GameOverState::GameOverState(StateStack* stack, Context context) : State(stack, context) {
    //mBackgroundTexture = &context.textures->get(Textures::PausedBackground);
    mOptions.push_back("Resume");
    mOptions.push_back("Return to Main menu");
    context.music->setPaused(true);
}

void GameOverState::draw() {
    //DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    ClearBackground(RAYWHITE);
    DrawTextEx(GetFontDefault(), "GAME OVER", 
                {(1200-MeasureText("GAME OVER", 60))/2.f, 200},
                60, 1, BLACK);
    int len = mOptions.size();
    for (int i = 0; i < len; i++)
        DrawText(mOptions[i].c_str(), recButton[i].x + 150-MeasureText(mOptions[i].c_str(), 20)/2, recButton[i].y+15, 20, BLACK);
    for (int i = 0; i < len; i++) {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[i]))
            DrawRectangleRec(recButton[i], {0, 0, 0, 255/4});
    }
}

bool GameOverState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_N)) {
        requestStackPop();
        return updatePrevState;
    }

    if (IsMouseButtonPressed(0)) {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Resume])) {
            //please reset game function here
            requestStackPop();
        }
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Return])) {
            //please reset game function here
            requestStackPop(), requestStackPop();
        }
    }
    return updatePrevState;
}

GameOverState::~GameOverState() {
    getContext().music->setPaused(false);
}