#pragma once

#include "../State.h"

class GameState : public State {
public:
    GameState(StateStack* stack, Context context);
    ~GameState();
    virtual void draw();
    virtual bool update(float dt);
    // virtual bool handleEvent(Event event);
private:
    Texture2D* mBackgroundTexture;
};