#include "Program.h"
#include "States/GameState.h"
#include "Player.h"

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
}

void Program::run() {
    mStateStack.pushState(States::Game);
    mStateStack.draw();
}

void Program::registerStates() {
    mStateStack.registerState<GameState>(States::ID::Game);
}