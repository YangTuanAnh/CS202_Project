#include "Map.hpp"

#include <cassert>

Map::Map() {}

Map::~Map() {}

Lane::Ptr Map::createLane(Lanes::ID laneID) {
    auto found = mFactories.find(laneID);
    assert(found != mFactories.end());
    return found->second();
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

void Map::pushBack(Lane::Ptr lane) {
    map.push_back(lane);
}

void Map::pushFront(Lane::Ptr lane) {
    map.push_front(lane);
}

void Map::popBack() {
    map.pop_back();
}

void Map::popFront() {
    map.pop_front();
}