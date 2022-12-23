#include "SettingsState.h"

SettingsState::SettingsState(StateStack* stack, Context context) : State(stack, context) {
    mOptions.push_back("Volume");
    mOptions.push_back("Return to Main menu");
    mVolume = context.music->getVolume()*100;
}

void SettingsState::draw() {
    ClearBackground(RAYWHITE);
    int len = mOptions.size();

    DrawText(mOptions[0].c_str(), 600-MeasureText(mOptions[0].c_str(), 20)/2, recButton[0].y+15-50, 20, BLACK);
    DrawText(mOptions[1].c_str(), 600-MeasureText(mOptions[1].c_str(), 20)/2, recButton[1].y+15, 20, BLACK);

    GuiSpinner(recButton[0], "volume", &mVolume, 0, 100, true);
    if (CheckCollisionPointRec(GetMousePosition(), recButton[1]))
        DrawRectangleRec(recButton[1], {0, 0, 0, 255/4});
}
bool SettingsState::update(float dt) {
    getContext().music->setVolume(mVolume/100.f);
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