#pragma once

#include "Global.h"
#include "Object.h"
#include "PlayerState.h"
#include <raylib.h>
#include <raygui.h>
#include <map>
#include <functional>
#include <memory>
#include <iostream>
const int WIDTH = 1200, HEIGHT = 600;

class Player {
public:
    float mX, mY;
    PlayerState::Ptr mState;
    int point;
    Texture2D *chicken;
    std::map<PlayerStates::ID, std::function<PlayerState::Ptr()>> mFactories;
public:
    Player();
    Player(float, float, int);
    void init(Texture2D*);
    template <typename T>
    void registerState(PlayerStates::ID stateID) {
        std::cerr << "Registering state " << stateID << std::endl;
        mFactories[stateID] = [this] () {
            return PlayerState::Ptr(new T(*this));
        };
    }
    PlayerState::Ptr createState(PlayerStates::ID stateID);
    float getX();
    float getY();
    int getPoint();
    void setX(float);
    void setY(float);
    void setPoint(int);
    void setState(PlayerStates::ID);
    bool isDead();
    void movement();
    void draw();
    void update(float);
    bool collision(Object *);
    ~Player();
};