// #include "State.h"
#include "StateStack.hpp"

State::State(StateStack* stack, Context context) : mStack(stack), mContext(context) {}

State::Context::Context(TextureHolder* textures, Player* player, MusicPlayer* music) : textures(textures), player(player), music(music) {}

State::~State() {
}

State::Context State::getContext() const {
    return mContext;
}

void State::requestStackPush(States::ID stateID) {
    mStack->pushState(stateID);
    WaitTime(50);
}

void State::requestStackPop() {
    mStack->popState();
    WaitTime(50);
}

void State::requestStackClear() {
    mStack->clearStates();
}
