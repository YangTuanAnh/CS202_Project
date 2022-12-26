#include "Map.hpp"

#include <cassert>
#include <iostream>

#include "Global.h"

Map::Map(TextureHolder *textures) : mTextures(textures) {}

Map::~Map() {}

Lane::Ptr Map::createLane(Lanes::ID laneID) {
    auto found = mFactories.find(laneID);
    assert(found != mFactories.end());
    return found->second();
}

void Map::init() {
    for (int i = 0; i < 3; i++) {
        addLane(Lanes::Road);
    }
}

void Map::addLane(Lanes::ID laneID) {
    auto newLane = createLane(laneID);
    newLane->init(BLOCK_SIZE * size++);
    attachChild(std::move(newLane));
}

void Map::drawThis() {
    // DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
}

Lanes::ID Map::getRandomLane() {
    return Lanes::ID(GetRandomValue(1, LANE_COUNT));
}