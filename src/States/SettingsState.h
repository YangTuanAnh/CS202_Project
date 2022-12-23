#pragma once

#include "../State.h"

class SettingsState : public State {
private:
    enum SettingsName {
        Volume,
        Return
    };
    std::vector<std::string> mOptions;
    Texture2D* mBackgroundTexture;
    Rectangle recButton[2] = {{300, 200, 600, 50}, {300, 500, 600, 50}};
    int mVolume;
public:
    SettingsState(StateStack* stack, Context context);
    void draw();
    bool update(float dt);
    // virtual bool handleEvent(Event event);
};