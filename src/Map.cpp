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
    std::cerr << "Map init" << std::endl;
    for (int i = 0; i < 3; i++) {
        map.push_back(createLane(Lanes::Road));
        auto lane = map.rbegin();
        lane->get()->init(BLOCK_SIZE * i);
        lane->get()->addObject(Objects::Car, 0);
    }
}

void Map::update(float dt) {
    for (auto &lane : map) {
        lane->update(dt);
    }
}

void Map::draw() {
    for (auto &lane : map) {
        lane->draw();
    }
}
