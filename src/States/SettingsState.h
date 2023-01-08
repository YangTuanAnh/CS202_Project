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
    Rectangle recButton[2] = {{400, 200, 400, 50}, {400, 500, 400, 50}};
    int mVolume;
public:
    SettingsState(StateStack* stack, Context context);
    void draw();
    bool update(float dt);
    // virtual bool handleEvent(Event event);
};