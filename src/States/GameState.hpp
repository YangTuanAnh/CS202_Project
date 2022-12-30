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
    Map* map;
    Player* player;
    Texture2D* mBackgroundTexture;
    CustomCamera* camera;
public:
    GameState(StateStack* stack, Context context);
    ~GameState();
    void draw();
    bool update(float dt);
    void loadGame(std::istream);
    void saveGame(std::ostream);
    void registerLanes();
};