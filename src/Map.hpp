#pragma once

#include <map>
#include <deque>

#include "Lane.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureHolder.h"

class Map {
private:
    std::deque<Lane::Ptr> map;
    std::map<Lanes::ID, std::function<Lane::Ptr()>> mFactories;
    TextureHolder *mTextures;
public:
    Map(TextureHolder *textures);
    ~Map();
    template <typename T>
    void registerLane(Lanes::ID laneID) {
        mFactories[laneID] = [this] () {
            return Lane::Ptr(new T(this->mTextures));
        };
    }
    Lane::Ptr createLane(Lanes::ID laneID);
    void update(float dt);
    void draw();
    void init();
};