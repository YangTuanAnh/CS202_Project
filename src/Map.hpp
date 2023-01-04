#pragma once

#include <map>
#include <deque>

#include "Lane.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureHolder.h"
#include "SceneNode.h"
#include "Player.hpp"

class Map : public SceneNode {
private:
    int size = 0;
    std::map<Lanes::ID, std::function<Lane::Ptr()>> mFactories;
    TextureHolder *mTextures;
    Player *player;
public:
    Map(TextureHolder *textures, Player *player);
    virtual ~Map();
    template <typename T>
    void registerLane(Lanes::ID laneID) {
        mFactories[laneID] = [this] () {
            return Lane::Ptr(new T(this->mTextures));
        };
    }
    Lane::Ptr createLane(Lanes::ID laneID);
    void addLane(Lanes::ID laneID);
    void removeFirstLane();
    void updateThis(float dt);
    void drawThis();
    bool isOver();
    Lanes::ID getRandomLane();
    void init();
};