#include "GameState.hpp"
#include "../PlayerStates/IdleState.h"
#include "../PlayerStates/JumpingState.h"
#include "../Object.h"
#include "../Lanes/RoadLane.h"
#include "../Lanes/JungleLane.h"
#include "../Lanes/PlainLane.h"

#include <iostream>

GameState::GameState(StateStack *stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::GameBackground);
    player = context.player;
    map = new Map(context.textures, player);
    registerLanes();
    map->init();
    context.music->play(Audio::GameTheme);
    camera = new CustomCamera(player);
}

void GameState::registerLanes() {
    map->registerLane<RoadLane>(Lanes::Road);
    map->registerLane<JungleLane>(Lanes::Jungle);
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
}

bool GameState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_TAB)) {
        requestStackPush(States::Pause);
        return updatePrevState;
    }
    if (IsKeyPressed(KEY_N)) {
        requestStackPush(States::GameOver);
        return updatePrevState;
    }
    camera->update(dt);
    map->update(dt);
    player->update(dt);
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