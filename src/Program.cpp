#include "Program.h"
#include "States/GameState.h"
#include "Player.h"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();
    mStateStack.pushState(States::Game);

    // Load textures
    mTextures->load(Textures::GameBackground, "../asset/img/CrossyRoadBg.png");
    mTextures->load(Textures::Player, "../asset/img/3.png");

    mPlayer->init(&mTextures->get(Textures::Player));
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
}

void Program::run() {
    BeginDrawing();
    mStateStack.update(1.0f / 60.0f);
    mStateStack.draw();
    EndDrawing();
}

void Program::registerStates() {
    mStateStack.registerState<GameState>(States::Game);
}