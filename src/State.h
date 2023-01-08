#pragma once

#include <memory>

// #include "StateStack.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureHolder.h"
#include "Player.hpp"
#include "MusicPlayer.h"

class StateStack;

class State {
public:
    typedef std::unique_ptr<State> Ptr;
    struct Context {
        Context(TextureHolder* textures, Player* player, MusicPlayer* music);
        bool saveFlag = false;
        TextureHolder* textures;
        // FontHolder* fonts;
        Player* player;
        MusicPlayer* music;
    };

private:
    Context mContext;

protected:
    StateStack* mStack;
    Context getContext() const;
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStackClear();

public:
    State(StateStack* stack, Context context);
    virtual ~State();
    virtual void draw() = 0;
    virtual bool update(float dt) = 0;
    // virtual bool handleEvent(Event event) = 0;
};