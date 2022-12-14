#pragma once

#include "../State.h"

class PausedState : public State {
private:
    Texture2D* mBackgroundTexture;
public:
    PausedState(StateStack* stack, Context context);
    void draw();
    bool update(float dt);
    // virtual bool handleEvent(Event event);
};