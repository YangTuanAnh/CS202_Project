#pragma once

#include "../State.h"

class PausedState : public State {
private:
    enum OptionNames {
        Resume,
        Return,
    };
    std::vector<std::string> mOptions;
    Texture2D* mBackgroundTexture;
    Rectangle recButton[2] = {{200, 400, 300, 50}, {700, 400, 300, 50}};
public:
    PausedState(StateStack* stack, Context context);
    void draw();
    bool update(float dt);
    // virtual bool handleEvent(Event event);
};