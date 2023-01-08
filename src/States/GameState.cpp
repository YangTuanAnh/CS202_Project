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
        promptTime = PROMPT_TIME*FPS;

    player->update(dt);
    map->update(dt);
    camera->update(dt);
    return updatePrevState;
}

void GameState::saveGame(ostream fout) {
    // for (int i = 0; i < map.size(); i++) {
    //     fout << map[i]->getType() << '\n';
    //     fout << map[i]->getX() << '\n';
    //     fout << map[i]->getY() << '\n';
    //     fout << map[i]->getDirection() << '\n';
    // }

    // fout << player->getX() << '\n';
    // fout << player->getY() << '\n';
    // fout << player->getPoint() << '\n';
}

void GameState::loadGame(istream fin) {
    // int a;
    // int x, y, dir, point;
    // while (!fin.eof()) {
    //     fin >> a;
    //     switch (a) {
    //     case 2:
    //         fin >> x >> y >> dir;
    //         map.push_back(new Car(x, y, dir));
    //         break;
    //     case 3:
    //         fin >> x >> y >> dir;
    //         map.push_back(new Truck(x, y, dir));
    //         break;
    //     case 4:
    //         fin >> x >> y >> dir;
    //         map.push_back(new Bird(x, y, dir));
    //         break;
    //     case 5:
    //         fin >> x >> y >> dir;
    //         map.push_back(new Dinosaur(x, y, dir));
    //         break;
    //     case 1:
    //         fin >> x >> y >> dir;
    //         map.push_back(new Obstacle(x, y, dir));
    //         break;
    //     }
    // }
    // fin >> x >> y >> point;
    // Player A(x, y, point);
}