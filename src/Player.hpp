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

class Player {
public:
    float mX, mY;
    PlayerState::Ptr mState;
    int point;
    Texture2D *chicken;
    TextureHolder *mTextures;
    std::map<PlayerStates::ID, std::function<PlayerState::Ptr()>> mFactories;
public:
    Player();
    Player(float, float, int);
    void init(TextureHolder*);
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
    Vector2 getPos();
    int getPoint();
    void setX(float);
    void setY(float);
    void setPoint(int);
    void setState(PlayerStates::ID);
    bool isDead();
    void draw();
    void update(float);
    bool collision(Object *);
    ~Player();
};