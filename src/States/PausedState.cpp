#include "PausedState.h"

#include <iostream>

PausedState::PausedState(StateStack* stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::PausedBackground);
    mOptions.push_back("Resume");
    mOptions.push_back("Return to Main menu");
    context.music->setPaused(true);
}

void PausedState::draw() {
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    int len = mOptions.size();
    for (int i=0; i<len; i++)
        DrawText(mOptions[i].c_str(), recButton[i].x + 150-MeasureText(mOptions[i].c_str(), 20)/2, recButton[i].y+15, 20, BLACK);
    for (int i = 0; i < mOptions.size(); i++)
    {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[i]))
            DrawRectangleRec(recButton[i], {0, 0, 0, 255/4});
    }
}

bool PausedState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_TAB)) {
        requestStackPop();
        return updatePrevState;
    }

    if (IsMouseButtonPressed(0)) {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Resume])) {
            requestStackPop();
        }
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Return])) {
            requestStackPop(), requestStackPop();
        }
    }
    return updatePrevState;
}

PausedState::~PausedState() {
    getContext().music->setPaused(false);
}