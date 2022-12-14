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
#include "../StateStack.hpp"

#include <iostream>

GameState::GameState(StateStack *stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::GameBackground);
    player = context.player;
    camera = new CustomCamera(player);
    map = new Map(context.textures, player);
    registerLanes();
    if(mStack->getSaveFlag() && checkSaveFile()) {
        loadGame();
    } else {
        player->reset();
        camera->reset();
        map->init();
    }
    context.music->play(Audio::GameTheme);
    promptTime = 0;
    mStack->setSaveFlag(false);
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
    if (!gameOver)
        saveGame();
    else
        resetSaveFile();
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
    DrawText("Tab - pause game", 20, 100, 20, SKYBLUE);
    DrawText("L - save game", 20, 130, 20, SKYBLUE);

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
    if(map->isOver() || checkOutOfBounds()){
        this->gameOver = true;
        requestStackPush(States::GameOver);
        return updatePrevState;
    }
    if (IsKeyPressed(KEY_TAB) && player->isIdle()) {
        requestStackPush(States::Pause);
        return updatePrevState;
    }

    if (IsKeyPressed(KEY_L)) 
        promptTime = PROMPT_TIME*FPS;

    player->update(dt);
    map->update(dt);
    camera->update(dt);
    return updatePrevState;
}

bool GameState::checkOutOfBounds() {
    std::cerr << player->getY() << ' ' << camera->target.y << '\n';
    float offset = -160 - camera->target.y;
    return player->getY() + offset > camera->target.y;
}

void GameState::saveGame() {
    std::ofstream fout("save.txt");
    player->save(fout);
    camera->save(fout);
    map->save(fout);
    fout.close();
}

void GameState::loadGame() {
    std::cerr << "Loading game..." << std::endl;
    std::ifstream fin("save.txt");
    player->load(fin);
    camera->load(fin);
    map->load(fin);
    fin.close();
}

void GameState::resetSaveFile() {
    std::ofstream fout("save.txt");
    fout.close();
}

bool GameState::checkSaveFile() {
    std::ifstream fin("save.txt");
    bool ret = fin.is_open();
    fin.seekg(0, std::ios::end);
    ret &= fin.tellg() > 0;
    fin.close();
    return ret;
}