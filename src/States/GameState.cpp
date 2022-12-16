#include "GameState.h"
#include "../PlayerStates/IdleState.h"
#include "../PlayerStates/JumpingState.h"

#include <iostream>

GameState::GameState(StateStack *stack, Context context) : State(stack, context) {
    mBackgroundTexture = &context.textures->get(Textures::GameBackground);
    player = context.player;
}

GameState::~GameState() {
    map.clear();
}

void GameState::draw() {
    DrawTexture(*mBackgroundTexture, 0, 0, WHITE);
    player->draw();
}

bool GameState::update(float dt) {
    bool updatePrevState = false;
    if (IsKeyPressed(KEY_TAB)) {
        requestStackPush(States::Pause);
        return updatePrevState;
    }
    player->update(dt);
    return updatePrevState;
}

// Object* GameState::getAnimal(){
//     for(int i=0; i < obstacle.size();i++){
//         if(obstacle[i]->type() == 2||obstacle[i]->type()==3){
//             animal.push_back(*obstacle[i]);
//         }
//     }
// }
// Object* GameState::getVehicle(){
//     for(int i=0; i < obstacle.size();i++){
//         if(obstacle[i]->type() == 1||obstacle[i]->type() == 0){
//             animal.push_back(*obstacle[i]);
//         }
//     }
// }
// Player GameState::getPeople() {
//     return *player;
// }

void GameState::startGame() // setting a 30x30 map
{
    // set position of player
    player->mX = rand() % 30;
    player->mY = 0;
    // set obstacle
    for (int j = 0; j < 30; j++) {
        int s = rand() % 5;
        int pos = rand() % 30;
        if (s == 2) {
            map.push_back(new Car(j, pos, rand() % 2, V_CAR_N, ));
            continue;
        }
        if (s == 3) {
            map.push_back(new Truck(j, pos, rand() % 2, V_TRUCK_N, ));
            continue;
        }
        if (s == 4) {
            map.push_back(new Bird(j, pos, rand() % 2, V_BIRD_N, ));
            continue;
        }
        if (s == 5) {
            map.push_back(new Dinausor(j, pos, rand() % 2, V_DINAUSOR_N, ));
            continue;
        }
        else {
            map.push_back(new Obstacle(j, pos, rand() % 2, V_OBSTACLE, ));
        }
    }
    draw();
    int tmp = player->getPoint();
    while (!player->isDead()) {
        player->movement();
        if (player->getPoint() > tmp) {
            this->random();
            tmp = player->getPoint();
        }
    }
}

void GameState::random() {
    int s = rand() % 4;
    int pos = rand() % 30;
    map.erase(map.begin());
    if (s == 2) {
        map.push_back(new Car(map[map.size() - 1]->getX() + 1, pos, rand() % 2, V_CAR_N, ));
        return;
    }
    if (s == 3) {
        map.push_back(new Truck(map[map.size() - 1]->getX() + 1, pos, rand() % 2, V_TRUCK_N, ));
        return;
    }
    if (s == 4) {
        map.push_back(new Bird(map[map.size() - 1]->getX() + 1, pos, rand() % 2, V_BIRD_N, ));
        return;
    }
    if (s == 5) {
        map.push_back(new Dinausor(map[map.size() - 1]->getX() + 1, pos, rand() % 2, V_DINAUSOR_N, ));
        return;
    }
    else {
        map.push_back(new Obstacle(map[map.size() - 1]->getX() + 1, pos, rand() % 2, V_OBSTACLE, ));
        return;
    }
}

void GameState::resetGame() {
    startGame();
}

void GameState::updatePos() {
    for (int i = 0; i < map.size(); i++) {
        map[i]->move();
    }
}

void GameState::saveGame(ostream fout) {
    for (int i = 0; i < map.size(); i++) {
        fout << map[i]->type() << '\n';
        fout << map[i]->getX() << '\n';
        fout << map[i]->getY() << '\n';
        fout << map[i]->getDirect() << '\n';
    }

    fout << player->getX() << '\n';
    fout << player->getY() << '\n';
    fout << player->getPoint() << '\n';
}

void GameState::loadGame(istream fin) {
    int a;
    int x, y, dir, point;
    while (!fin.eof()) {
        fin >> a;
        switch (a) {
        case 2:
            fin >> x >> y >> dir;
            map.push_back(new Car(x, y, dir, V_CAR_N, ));
            break;
        case 3:
            fin >> x >> y >> dir;
            map.push_back(new Truck(x, y, dir, V_TRUCK_N, ));
            break;
        case 4:
            fin >> x >> y >> dir;
            map.push_back(new Bird(x, y, dir, V_BIRD_N, ));
            break;
        case 5:
            fin >> x >> y >> dir;
            map.push_back(new Dinausor(x, y, dir, V_DINAUSOR_N, ));
            break;
        case 1:
            fin >> x >> y >> dir;
            map.push_back(new Obstacle(x, y, dir, V_OBSTACLE, ));
            break;
        }
    }
    fin >> x >> y >> point;
    Player A(x, y, point);
}