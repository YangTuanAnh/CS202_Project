#include "Program.h"
#include "States/GameState.h"
#include "States/PausedState.h"
#include "PlayerStates/IdleState.h"
#include "PlayerStates/JumpingState.h"
#include "Player.hpp"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();
    mStateStack.pushState(States::Game);

    // Load textures
    mTextures->load(Textures::GameBackground, "../asset/img/CrossyRoadBg.png", WIDTH, HEIGHT);
    mTextures->load(Textures::Player, "../asset/img/3.png");
    mTextures->load(Textures::PausedBackground, "../asset/img/PausedScreen.png", WIDTH, HEIGHT);

    mPlayer->init(&mTextures->get(Textures::Player));
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
}

void Program::run() {
    BeginDrawing();
    mStateStack.update(GetFrameTime());
    mStateStack.draw();
    EndDrawing();
}

void Program::registerStates() {
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PausedState>(States::Pause);
    mPlayer->registerState<IdleState>(PlayerStates::Idle);
    mPlayer->registerState<JumpingState>(PlayerStates::Jumping);
}