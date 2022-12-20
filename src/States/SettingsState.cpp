#include "SettingsState.h"

SettingsState::SettingsState(StateStack* stack, Context context) : State(stack, context) {
    mOptions.push_back("Volume");
    mOptions.push_back("Return to Main menu");
}

void SettingsState::draw() {
    ClearBackground(RAYWHITE);
    int len = mOptions.size();
    for (int i=0; i<len; i++)
        DrawText(mOptions[i].c_str(), 600-MeasureText(mOptions[i].c_str(), 20)/2, recButton[i].y+15, 20, BLACK);
    for (int i = 0; i < len; i++)
        if (CheckCollisionPointRec(GetMousePosition(), recButton[i]))
            DrawRectangleRec(recButton[i], {0, 0, 0, 255/4});
}
bool SettingsState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_ESCAPE)) {
        requestStackPop();
        return updatePrevState;
    }

    if (IsMouseButtonDown(0)) {
        if (CheckCollisionPointRec(GetMousePosition(), recButton[Return])) {
            requestStackPop();
            return updatePrevState;
        }
    }
    return updatePrevState;
}