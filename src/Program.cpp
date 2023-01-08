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
    mTextures->load(Textures::Player_right, "../asset/player/chicken_right.png");
    mTextures->load(Textures::Player_left, "../asset/player/chicken_left.png");
    mTextures->load(Textures::Player_up, "../asset/player/chicken_up.png");
    mTextures->load(Textures::Player_down, "../asset/player/chicken_down.png");
    mPlayer->init(this->mTextures);

    mTextures->load(Textures::Plain, "../asset/lane/Plain_final.png");
    mTextures->load(Textures::Road, "../asset/lane/Road_final.png");
    mTextures->load(Textures::Jungle_1, "../asset/lane/Jungle_final_1.png");
    mTextures->load(Textures::Jungle_2, "../asset/lane/Jungle_final_2.png");
    mTextures->load(Textures::Jungle_3, "../asset/lane/Jungle_final_3.png");

    mTextures->load(Textures::Car_left, "../asset/object/vehicle_car_left.png");
    mTextures->load(Textures::Car_right, "../asset/object/vehicle_car_right.png");
    mTextures->load(Textures::Truck_left, "../asset/object/vehicle_truck_left.png");
    mTextures->load(Textures::Truck_right, "../asset/object/vehicle_truck_right.png");
    mTextures->load(Textures::Bird_left, "../asset/object/animal_bird_left.png");
    mTextures->load(Textures::Bird_right, "../asset/object/animal_bird_right.png");
    mTextures->load(Textures::Dinosaur_left, "../asset/object/animal_dinosaur_left.png");
    mTextures->load(Textures::Dinosaur_right, "../asset/object/animal_dinosaur_right.png");
    mTextures->load(Textures::Obstacle, "../asset/Tree.png");
    mTextures->load(Textures::TrafficLamp_green, "../asset/object/green_light.png");
    mTextures->load(Textures::TrafficLamp_yellow, "../asset/object/yellow_light.png");
    mTextures->load(Textures::TrafficLamp_red, "../asset/object/red_light.png");

    mStateStack.pushState(States::Menu);
}

Program::~Program() {
    delete mPlayer;
    delete mTextures;
    delete mMusic;
}

void Program::run() {
    // std::cerr << "Program run" << std::endl;
    mStateStack.update(GetFrameTime());
    BeginDrawing();
    mStateStack.draw();
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