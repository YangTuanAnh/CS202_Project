#include "MenuState.h"
#include "../StateStack.hpp"

MenuState::MenuState(StateStack *stack, Context context) : State(stack, context) {
    mOptions.push_back("Start Game");
    mOptions.push_back("Load Game");
    mOptions.push_back("Settings");
    mOptions.push_back("Exit");
    context.music->play(Audio::MenuTheme);
    mBackgroundTexture = &context.textures->get(Textures::MenuBackground);
}

void MenuState::draw() {
    // ClearBackground(RAYWHITE);
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    DrawRectangleRounded({30, 30, SCREEN_WIDTH-30*2, SCREEN_WIDTH-30*2}, 30, 4, {255, 255, 255, 255/10*9}); 

    
    DrawText("CRASH COURSE", (SCREEN_WIDTH-MeasureText("CRASH COURSE", 60))/2+5, 150+5, 60, BLACK);
    DrawText("CRASH COURSE", (SCREEN_WIDTH-MeasureText("CRASH COURSE", 60))/2, 150, 60, WHITE);

    int len = mOptions.size();
    for (int i=0; i<len; i++) {
        DrawRectangleRec({recMenu[i].x+5, recMenu[i].y+5, recMenu[i].width, recMenu[i].height}, {0, 0, 0, 255/2});

        if (CheckCollisionPointRec(GetMousePosition(), recMenu[i]))
            DrawRectangleRec(recMenu[i], LIGHTGRAY);
        else 
            DrawRectangleRec(recMenu[i], RAYWHITE);

        if (OptionNames(i)==Load) {
            ifstream fin("save.txt");
            if (fin.peek() == std::ifstream::traits_type::eof()) {
                DrawRectangleRec(recMenu[i], LIGHTGRAY);
            }
            fin.close();
        }

        DrawRectangleLinesEx(recMenu[i], 1, {0, 0, 0, 255/4});
        DrawText(mOptions[i].c_str(), 600-MeasureText(mOptions[i].c_str(), 20)/2, recMenu[i].y+15, 20, BLACK);
    }
        
}
bool MenuState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_ESCAPE)) {
        requestStackPop();
        CloseWindow();
        return updatePrevState;
    }

    if (IsMouseButtonPressed(0)) {
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[Play])) {
            requestStackPush(States::Game);
            return updatePrevState;
        }
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[Load])) {
            ifstream fin("save.txt");
            if (fin.peek() != std::ifstream::traits_type::eof()) {
                mStack->setSaveFlag(true);
                requestStackPush(States::Game);
                return updatePrevState;
            }
            fin.close();
        }
        if (CheckCollisionPointRec(GetMousePosition(), recMenu[Settings])) {
            requestStackPush(States::Settings);
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