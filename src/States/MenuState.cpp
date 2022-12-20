#include "MenuState.h"
MenuState::MenuState(StateStack *stack, Context context) : State(stack, context) {
    std::string playOption = "Play";
    std::string exitOption = "Exit";
    //playOption.setFont(font);
    //DrawText(playOption.c_str(), recMenu[0].x, recMenu[1].y, 20, BLACK);
    //centerOrigin(playOption);
    //playOption.setPosition(context.window->getView().getSize() / 2.f);
    mOptions.push_back(playOption);
    mOptions.push_back(exitOption);
}

void MenuState::draw() {
    ClearBackground(RAYWHITE);
    int len = mOptions.size();
    for (int i=0; i<len; i++)
        //GuiButton(recMenu[i], mOptions[i].c_str());
        DrawText(mOptions[i].c_str(), 600-MeasureText(mOptions[i].c_str(), 20)/2, recMenu[i].y+15, 20, BLACK);
}
bool MenuState::update(float dt) {
    bool updatePrevState = false;
    // if (IsKeyPressed(KEY_TAB)) {
    //     requestStackPush(States::Pause);
    //     return updatePrevState;
    // }
    // player->update(dt);
    // return updatePrevState;
    for (int i = 0; i < mOptions.size(); i++)
    {
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[i]))
        {
            DrawRectangleRec(recMenu[i], {0, 0, 0, 255/4});
            cerr << mOptions[i] << '\n';
        }
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