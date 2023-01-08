#include "SettingsState.h"

SettingsState::SettingsState(StateStack* stack, Context context) : State(stack, context) {
    mOptions.push_back("Volume");
    mOptions.push_back("Return to Main menu");
    mVolume = context.music->getVolume()*100;
    mBackgroundTexture = &context.textures->get(Textures::MenuBackground);
}

void SettingsState::draw() {
    // ClearBackground(RAYWHITE);
    // int len = mOptions.size();
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    DrawRectangleRounded({30, 30, SCREEN_WIDTH-30*2, SCREEN_WIDTH-30*2}, 30, 4, {255, 255, 255, 255/10*9}); 

    DrawRectangleRec({recButton[1].x+5, recButton[1].y+5, recButton[1].width, recButton[1].height}, {0, 0, 0, 255/2});

    if (CheckCollisionPointRec(GetMousePosition(), recButton[1]))
        DrawRectangleRec(recButton[1], LIGHTGRAY);
    else 
        DrawRectangleRec(recButton[1], RAYWHITE);

    DrawRectangleLinesEx(recButton[1], 1, {0, 0, 0, 255/4});

    DrawText(mOptions[1].c_str(), 600-MeasureText(mOptions[1].c_str(), 20)/2, recButton[1].y+15, 20, BLACK);

    
    GuiSpinner(recButton[0], "volume", &mVolume, 0, 100, true);
    DrawText(mOptions[0].c_str(), 600-MeasureText(mOptions[0].c_str(), 20)/2, recButton[0].y+15-50, 20, BLACK);
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