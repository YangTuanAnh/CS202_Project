#include "GameOverState.h"

#include <iostream>

GameOverState::GameOverState(StateStack* stack, Context context) : State(stack, context) {
    //mBackgroundTexture = &context.textures->get(Textures::PausedBackground);
    mOptions.push_back("Resume");
    mOptions.push_back("Return to Main menu");
    context.music->setPaused(true);
    mBackgroundTexture = &context.textures->get(Textures::Player_hospital);
}

void GameOverState::draw() {
    //DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    DrawRectangleGradientH(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE, RAYWHITE);
    DrawText("GAME OVER", (SCREEN_WIDTH-MeasureText("GAMEOVER", 60))/2, 150, 60, BLACK);
    DrawTexture(*mBackgroundTexture, 800, 250, WHITE);
    // ClearBackground(RAYWHITE);
    // DrawTextEx(GetFontDefault(), "GAME OVER", 
    //             {(1200-MeasureText("GAME OVER", 60))/2.f, 200},
    //             60, 1, BLACK);
    int len = mOptions.size();
    for (int i = 0; i < len; i++)
        DrawText(mOptions[i].c_str(), recButton[i].x + 150-MeasureText(mOptions[i].c_str(), 20)/2, recButton[i].y+15, 20, BLACK);
    for (int i = 0; i < len; i++) {
        DrawRectangleRec({recButton[i].x+5, recButton[i].y+5, recButton[i].width, recButton[i].height}, {0, 0, 0, 255/2});

        if (CheckCollisionPointRec(GetMousePosition(), recButton[i]))
            DrawRectangleRec(recButton[i], LIGHTGRAY);
        else 
            DrawRectangleRec(recButton[i], RAYWHITE);

        DrawRectangleLinesEx(recButton[i], 1, {0, 0, 0, 255/4});
        DrawText(mOptions[i].c_str(), recButton[i].x + 150-MeasureText(mOptions[i].c_str(), 20)/2, recButton[i].y+15, 20, BLACK);
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
            requestStackPop(), requestStackPop();
            requestStackPush(States::Game);
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