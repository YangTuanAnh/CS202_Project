#include "PausedState.h"

#include <iostream>

PausedState::PausedState(StateStack* stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::PausedBackground);
    mOptions.push_back("Resume");
    mOptions.push_back("Return to Main menu");
}

void PausedState::draw() {
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    int len = mOptions.size();
    for (int i=0; i<len; i++)
        DrawText(mOptions[i].c_str(), recButton[i].x + 150-MeasureText(mOptions[i].c_str(), 20)/2, recButton[i].y+15, 20, BLACK);
    for (int i = 0; i < mOptions.size(); i++)
    {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[i]))
        {
            DrawRectangleRec(recButton[i], {0, 0, 0, 255/4});
            cerr << mOptions[i] << '\n';
        }
    }
}

bool PausedState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_TAB)) {
        requestStackPop();
        return updatePrevState;
    }

    if (IsMouseButtonDown(0)) {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Resume])) {
            requestStackPop();
            return updatePrevState;
        }
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Return])) {
            requestStackPop();
            requestStackPop();
            return updatePrevState;
        }
    }
    return updatePrevState;
}