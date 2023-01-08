#include "GameState.hpp"
#include "../PlayerStates/IdleState.h"
#include "../PlayerStates/JumpingState.h"
#include "../Object.h"
#include "../Lanes/CarLane.h"
#include "../Lanes/TruckLane.h"
#include "../Lanes/JungleLane.h"
#include "../Lanes/ForestLane.h"
#include "../Lanes/PlainLane.h"
#include "../Lanes/BirdJungleLane.h"

#include <iostream>

GameState::GameState(StateStack *stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::GameBackground);
    player = context.player;
    player->reset();
    map = new Map(context.textures, player);
    registerLanes();
    map->init();
    context.music->play(Audio::GameTheme);
    camera = new CustomCamera(player);
    promptTime = 0;
}

void GameState::registerLanes() {
    map->registerLane<CarLane>(Lanes::Car);
    map->registerLane<TruckLane>(Lanes::Truck);
    map->registerLane<ForestLane>(Lanes::Forest);
    map->registerLane<JungleLane>(Lanes::Jungle);
    map->registerLane<BirdJungleLane>(Lanes::BirdJungle);
    map->registerLane<PlainLane>(Lanes::Plain);
}

GameState::~GameState() {
    saveGame();
    delete map;
    delete camera;
}

void GameState::draw() {
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    BeginMode2D(*camera);
    map->draw();
    player->draw();
    EndMode2D();
    DrawText(TextFormat("Score: %04i", this->player->getPoint()), 20, 20, 30, SKYBLUE);
    DrawText(TextFormat("Max score: %04i", this->player->getMaxPoint()), 20, 60, 30, SKYBLUE);
    DrawText("Tab - pause game", 20, 90, 20, SKYBLUE);
    DrawText("L - save game", 20, 120, 20, SKYBLUE);

    if (promptTime) {
        saveGame();
        string saveGame = "Saved game!";
        DrawText(saveGame.c_str(), 
                SCREEN_WIDTH - MeasureText(saveGame.c_str(), 20) - 20,
                SCREEN_HEIGHT - 20 - 20, 20, WHITE);
        promptTime--;
    }
}

bool GameState::update(float dt) {
    bool updatePrevState = false;
    if(map->isOver()){
        requestStackPush(States::GameOver);
        return updatePrevState;
    }
    if (IsKeyPressed(KEY_TAB) && player->isIdle()) {
        requestStackPush(States::Pause);
        return updatePrevState;
    }
    if (IsKeyPressed(KEY_L)) 
        promptTime = PROMPT_TIME*dt;
    player->update(dt);
    map->update(dt);
    camera->update(dt);
    return updatePrevState;
}

void GameState::saveGame() {
    std::ofstream fout("save.txt");
    player->save(fout);
    camera->save(fout);
    map->save(fout);
    fout.close();
}

void GameState::loadGame() {
    
}