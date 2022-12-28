#include "Program.h"
#include "States/MenuState.h"
#include "States/GameState.hpp"
#include "States/PausedState.h"
#include "States/SettingsState.h"
#include "States/GameOverState.h"
#include "PlayerStates/IdleState.h"
#include "PlayerStates/JumpingState.h"
#include "Player.hpp"
#include "Global.h"

#include <iostream>

Program::Program() : mStateStack(State::Context(mTextures = new TextureHolder(), mPlayer = new Player(), mMusic = new MusicPlayer())) {
    registerStates();

    // Load textures
    mTextures->load(Textures::None, "../image/none.png");
    mTextures->load(Textures::GameBackground, "../asset/img/CrossyRoadBg.png", SCREEN_WIDTH, SCREEN_HEIGHT);
    // mTextures->load(Textures::Player_down, "../asset/img/3.png");
    mTextures->load(Textures::PausedBackground, "../asset/img/PausedScreen.png", SCREEN_WIDTH, SCREEN_HEIGHT);

    mStateStack.pushState(States::Game);
    mTextures->load(Textures::Player_right, "../asset/player/chicken_right.png");
    mTextures->load(Textures::Player_left, "../asset/player/chicken_left.png");
    mTextures->load(Textures::Player_up, "../asset/player/chicken_up.png");
    mTextures->load(Textures::Player_down, "../asset/player/chicken_down.png");
    mPlayer->init(this->mTextures);

    mTextures->load(Textures::Plain, "../asset/object/road_600x300_1.png");
    mTextures->load(Textures::Road, "../asset/object/road_600x300_2.png");
    mTextures->load(Textures::Jungle, "../asset/object/grass_600x300_1.png");

    mTextures->load(Textures::Car_left, "../asset/object/vehicle_car_left.png");
    mTextures->load(Textures::Car_right, "../asset/object/vehicle_car_right.png");
    mTextures->load(Textures::Truck_left, "../asset/object/vehicle_truck_left.png");
    mTextures->load(Textures::Truck_right, "../asset/object/vehicle_truck_right.png");
    mTextures->load(Textures::Bird_left, "../asset/object/animal_bird_left.png");
    mTextures->load(Textures::Bird_right, "../asset/object/animal_bird_right.png");
    mTextures->load(Textures::Dinosaur_left, "../asset/object/animal_dinosaur_left.png");
    mTextures->load(Textures::Dinosaur_right, "../asset/object/animal_dinosaur_right.png");

    mStateStack.pushState(States::Menu);
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
    delete mMusic;
}

void Program::run() {
    // std::cerr << "Program run" << std::endl;
    const char msg1[50] = "Game Over!";
    // Font font1 = LoadFont("resources/custom_mecha.png");
    // Vector2 fontPosition1 = { SCREEN_WIDTH/2.0f - MeasureTextEx(font1, msg1, (float)font1.baseSize, -3).x/2,
    //                           SCREEN_HEIGHT/2.0f - font1.baseSize/2.0f - 80.0f };
    Vector2 pos = {this->mPlayer->getX(),this->mPlayer->getY()};
    Rectangle rec = {400.0f,400.0f,39.0f,39.0f};//base on object size
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
    mStateStack.registerState<GameOverState>(States::GameOver);
    mStateStack.registerState<SettingsState>(States::Settings);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PausedState>(States::Pause);
    mPlayer->registerState<IdleState>(PlayerStates::Idle);
    mPlayer->registerState<JumpingState>(PlayerStates::Jumping);
}