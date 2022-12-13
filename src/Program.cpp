#include "Program.h"
#include "States/GameState.h"
#include "Player.h"
#include "ResourceIdentifiers.hpp"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();
    mStateStack.pushState(States::Game);
    mTextures->load(Textures::Car, "../image/vehicle_car.png");
    mTextures->load(Textures::Trunk, "../image/vehicle_trunk.png");
    mTextures->load(Textures::Bird, "../image/vehicle_bird.png");
    mTextures->load(Textures::Dinasor, "../image/vehicle_dinosaur.png");
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