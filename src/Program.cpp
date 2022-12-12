#include "Program.h"
#include "States/GameState.h"
#include "Player.h"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();
    mStateStack.pushState(States::Game);
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
}

void Program::run() {
    mStateStack.update(1.0f / 60.0f);
    mStateStack.draw();
}

void Program::registerStates() {
    mStateStack.registerState<GameState>(States::Game);
}