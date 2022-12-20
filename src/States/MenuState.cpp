#include "MenuState.h"
MenuState::MenuState(StateStack *stack, Context context) : State(stack, context) {
    mOptions.push_back("Start Game");
    mOptions.push_back("Load Game");
    mOptions.push_back("Settings");
    mOptions.push_back("Exit");
}

void MenuState::draw() {
    ClearBackground(RAYWHITE);
    int len = mOptions.size();
    for (int i=0; i<len; i++)
        DrawText(mOptions[i].c_str(), 600-MeasureText(mOptions[i].c_str(), 20)/2, recMenu[i].y+15, 20, BLACK);
    for (int i = 0; i < len; i++)
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[i]))
            DrawRectangleRec(recMenu[i], {0, 0, 0, 255/4});
}
bool MenuState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_ESCAPE)) {
        requestStackPop();
        CloseWindow();
        return updatePrevState;
    }

    if (IsMouseButtonDown(0)) {
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[Play])) {
            requestStackPush(States::Game);
            return updatePrevState;
        }
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[Exit])) {
            requestStackPop();
            CloseWindow();
            return updatePrevState;
        }
    }
    return updatePrevState;
}

MenuState::~MenuState() {
}