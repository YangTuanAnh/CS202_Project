#include "Program.h"
#include "States/GameState.hpp"
#include "States/PausedState.h"
#include "PlayerStates/IdleState.h"
#include "PlayerStates/JumpingState.h"
#include "Player.hpp"
#include "Global.h"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();

    // Load textures
    mTextures->load(Textures::None, "../image/none.png");
    mTextures->load(Textures::GameBackground, "../asset/img/CrossyRoadBg.png", SCREEN_WIDTH, SCREEN_HEIGHT);
    mTextures->load(Textures::Player, "../asset/img/3.png");
    mTextures->load(Textures::PausedBackground, "../asset/img/PausedScreen.png", SCREEN_WIDTH, SCREEN_HEIGHT);

    mPlayer->init(&mTextures->get(Textures::Player));
    mTextures->load(Textures::Car, "../image/vehicle_car.png", 50, 50);
    mTextures->load(Textures::Truck, "../image/vehicle_truck.png");
    mTextures->load(Textures::Bird, "../image/animal_bird.png");
    mTextures->load(Textures::Dinosaur, "../image/animal_dinosaur_2.png");

    mStateStack.pushState(States::Game);
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
}

void Program::run() {
    // std::cerr << "Program run" << std::endl;
    const char msg1[50] = "Game Over!";
    // Font font1 = LoadFont("resources/custom_mecha.png");
    // Vector2 fontPosition1 = { SCREEN_WIDTH/2.0f - MeasureTextEx(font1, msg1, (float)font1.baseSize, -3).x/2,
    //                           SCREEN_HEIGHT/2.0f - font1.baseSize/2.0f - 80.0f };
    Vector2 pos = {this->mPlayer->getX(),this->mPlayer->getY()};
    Rectangle rec = {0.0f,0.0f,39.0f,39.0f};//base on object size
    BeginDrawing();
    mStateStack.update(GetFrameTime());
    mStateStack.draw();
    DrawRectangle(0.0f,0.0f,40.0f,40.0f,RED);
    // if(CheckCollisionPointRec(pos,rec)){
    //     DrawTextEx(font1, msg1, fontPosition1, 100.0f, -3, WHITE);
    // }
    EndDrawing();
}

void Program::registerStates() {
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PausedState>(States::Pause);
    mPlayer->registerState<IdleState>(PlayerStates::Idle);
    mPlayer->registerState<JumpingState>(PlayerStates::Jumping);
}