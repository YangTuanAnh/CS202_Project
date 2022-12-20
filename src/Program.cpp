#include "Program.h"
<<<<<<< HEAD
#include "States/MenuState.h"
#include "States/GameState.h"
=======
#include "States/GameState.hpp"
>>>>>>> 9f06b4a67da96c6084bef4dc47dfcfc4f4e52d81
#include "States/PausedState.h"
#include "PlayerStates/IdleState.h"
#include "PlayerStates/JumpingState.h"
#include "Player.hpp"
#include "Global.h"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player())) {
    registerStates();
    mStateStack.pushState(States::Menu);

    // Load textures
    mTextures->load(Textures::GameBackground, "../asset/img/CrossyRoadBg.png", SCREEN_WIDTH, SCREEN_HEIGHT);
    mTextures->load(Textures::Player, "../asset/img/3.png");
    mTextures->load(Textures::PausedBackground, "../asset/img/PausedScreen.png", SCREEN_WIDTH, SCREEN_HEIGHT);

    mPlayer->init(&mTextures->get(Textures::Player));
    mTextures->load(Textures::Car, "../image/vehicle_car.png");
    mTextures->load(Textures::Truck, "../image/vehicle_truck.png");
    mTextures->load(Textures::Bird, "../image/vehicle_bird.png");
    mTextures->load(Textures::Dinosaur, "../image/vehicle_dinosaur.png");
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
}

void Program::run() {
    const char msg1[50] = "Game Over!";
<<<<<<< HEAD
    //Font font1 = LoadFont("resources/custom_mecha.png");
    Font font1 = GetFontDefault();
    Vector2 fontPosition1 = { WIDTH/2.0f - MeasureTextEx(font1, msg1, (float)font1.baseSize, -3).x/2,
                              HEIGHT/2.0f - font1.baseSize/2.0f - 80.0f };
=======
    // Font font1 = LoadFont("resources/custom_mecha.png");
    // Vector2 fontPosition1 = { SCREEN_WIDTH/2.0f - MeasureTextEx(font1, msg1, (float)font1.baseSize, -3).x/2,
    //                           SCREEN_HEIGHT/2.0f - font1.baseSize/2.0f - 80.0f };
>>>>>>> 9f06b4a67da96c6084bef4dc47dfcfc4f4e52d81
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
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PausedState>(States::Pause);
    mPlayer->registerState<IdleState>(PlayerStates::Idle);
    mPlayer->registerState<JumpingState>(PlayerStates::Jumping);
}