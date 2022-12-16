#pragma once

#include <memory>

// #include "StateStack.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureHolder.h"
#include "Player.hpp"

class StateStack;

class State {
public:
    typedef std::unique_ptr<State> Ptr;
    struct Context {
        Context(TextureHolder* textures, Player* player);

        TextureHolder* textures;
        // FontHolder* fonts;
        Player* player;
    };

private:
    StateStack* mStack;
    Context mContext;

protected:
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