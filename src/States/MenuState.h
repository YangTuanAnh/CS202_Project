#pragma once

#include "../State.h"

#include <iostream>
#include <vector>
#include <raygui.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION

class MenuState : public State
{
private:
    enum OptionNames {
        Play,
        Load,
        Settings,
        Exit,
    };
    std::vector<std::string> mOptions;
    std::size_t mOptionIndex;
    Texture2D *mBackgroundTexture;
    Rectangle recMenu[4] = {{300, 200, 600, 50}, 
                            {300, 270, 600, 50},
                            {300, 340, 600, 50},
                            {300, 410, 600, 50}};

public:
    MenuState(StateStack *stack, Context context);
    ~MenuState();
    void draw();
    bool update(float dt);
};