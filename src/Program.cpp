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
    const char msg1[50] = "Game Over!";
    Font font1 = LoadFont("resources/custom_mecha.png");
    Vector2 fontPosition1 = { WIDTH/2.0f - MeasureTextEx(font1, msg1, (float)font1.baseSize, -3).x/2,
                              HEIGHT/2.0f - font1.baseSize/2.0f - 80.0f };
    Vector2 pos = {this->mPlayer->getX(),this->mPlayer->getY()};
    Rectangle rec = {400.0f,400.0f,39.0f,39.0f};//base on object size
    BeginDrawing();
    while(!mPlayer->gameover){}{
        mStateStack.update(GetFrameTime());
        mStateStack.draw();
        DrawRectangle(400.0f,400.0f,40.0f,40.0f,RED);
        if(CheckCollisionPointRec(pos,rec)){
            DrawTextEx(font1, msg1, fontPosition1, 100.0f, -3, WHITE);
            this->mPlayer->gameover = true;
            EndDrawing();
            return;
        }
    }
    EndDrawing();
}

void Program::registerStates() {
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PausedState>(States::Pause);
    mPlayer->registerState<IdleState>(PlayerStates::Idle);
    mPlayer->registerState<JumpingState>(PlayerStates::Jumping);
}