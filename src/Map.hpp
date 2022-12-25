#pragma once

#include <map>
#include <deque>

#include "Lane.hpp"
#include "ResourceIdentifiers.hpp"
#include "TextureHolder.h"
#include "SceneNode.h"

class Map : public SceneNode {
private:
    int size = 0;
    std::map<Lanes::ID, std::function<Lane::Ptr()>> mFactories;
    TextureHolder *mTextures;
public:
    Map(TextureHolder *textures);
    virtual ~Map();
    template <typename T>
    void registerLane(Lanes::ID laneID) {
        mFactories[laneID] = [this] () {
            return Lane::Ptr(new T(this->mTextures));
        };
    }
    Lane::Ptr createLane(Lanes::ID laneID);
    void addLane(Lanes::ID laneID);
    void drawThis();
    void init();
};