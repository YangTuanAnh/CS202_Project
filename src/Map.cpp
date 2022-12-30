#include "Map.hpp"

#include <cassert>
#include <iostream>

#include "Global.h"

Map::Map(TextureHolder *textures, Player *player) : mTextures(textures), player(player) {}

Map::~Map() {
    detachAllChildren();
}

Lane::Ptr Map::createLane(Lanes::ID laneID) {
    auto found = mFactories.find(laneID);
    assert(found != mFactories.end());
    return found->second();
}

void Map::init() {
    for (int i = 0; i < 10; i++) {
        addLane(Lanes::Plain);
    }

    for (int i = 0; i < 20; i++)
        addLane(getRandomLane());
}

void Map::addLane(Lanes::ID laneID) {
    auto newLane = createLane(laneID);
    newLane->init(BLOCK_SIZE * size--);
    attachChild(std::move(newLane));
}

void Map::removeFirstLane() {
    detachFirstChild();
}

void Map::updateThis(float dt) {
    // std::cerr << player->getY() << " " << mY << std::endl;
    if (player->getY() < BLOCK_SIZE * (size + 20)) {
        addLane(getRandomLane());
        removeFirstLane();
    }
}

void Map::drawThis() {
    // DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
}

Lanes::ID Map::getRandomLane() {
    return Lanes::ID(GetRandomValue(1, LANE_COUNT));
}