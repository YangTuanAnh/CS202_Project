#pragma once

#include "../State.h"
#include "../Player.hpp"
#include "../Map.hpp"
#include "../Camera.h"

#include <iostream>
#include <vector>
#include <deque>

class GameState : public State {
private:
    int promptTime;
    bool gameOver = false;
    Map* map;
    Player* player;
    Texture2D* mBackgroundTexture;
    CustomCamera* camera;
public:
    GameState(StateStack* stack, Context context);
    ~GameState();
    void draw();
    bool update(float dt);
    void loadGame();
    void saveGame();
    void resetSaveFile();
    bool checkSaveFile();
    void registerLanes();
};