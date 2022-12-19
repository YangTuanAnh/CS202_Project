#pragma once

#include <map>
#include <deque>

#include "Lane.h"
#include "ResourceIdentifiers.hpp"

class Map {
private:
    std::deque<Lane::Ptr> map;
    std::map<Lanes::ID, std::function<Lane::Ptr()>> mFactories;
public:
    Map();
    ~Map();
    template <typename T>
    void registerLane(Lanes::ID laneID) {
        mFactories[laneID] = [this] () {
            return Lane::Ptr(new T(this));
        };
    }
    Lane::Ptr createLane(Lanes::ID laneID);
    void update(float dt);
    void draw();
    void pushBack(Lane::Ptr lane);
    void pushFront(Lane::Ptr lane);
    void popBack();
    void popFront();
};