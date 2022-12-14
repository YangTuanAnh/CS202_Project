#include "Map.hpp"

#include <cassert>
#include <iostream>

#include "Global.h"
#include "utils.hpp"

Map::Map(TextureHolder *textures, Player *player) : mTextures(textures), player(player) {}

Map::~Map() {
    detachAllChildren();
}

Lane::Ptr Map::createLane(Lanes::ID laneID) {
    std::cerr << "Creating lane " << laneID << std::endl;
    auto found = mFactories.find(laneID);
    assert(found != mFactories.end());
    return found->second();
}

void Map::init() {
    for (int i = 0; i < 13; i++) {
        addLane(Lanes::Plain, 1);
    }

    for (int i = 0; i < 37; i++)
        addLane(getRandomLane(), GetRandomValue(0, 1) ? 1 : -1);
}

void Map::addLane(Lanes::ID laneID, int direction) {
    auto newLane = createLane(laneID);
    newLane->init(BLOCK_SIZE * size--, direction, true);
    attachChild(std::move(newLane));
}

void Map::loadLane(Lanes::ID laneID, int direction, float y) {
    auto newLane = createLane(laneID);
    newLane->init(y, direction, false);
    attachChild(std::move(newLane));
}

void Map::removeFirstLane() {
    detachFirstChild();
}

void Map::updateThis(float dt) {
    // std::cerr << player->getY() << " " << mY << std::endl;
    auto lanes = this->getChildren();
    auto checkLane = std::dynamic_pointer_cast<Lane>(lanes[13]).get();
    if (player->getY() < checkLane->getY() - 40) {
        addLane(getRandomLane(), GetRandomValue(0, 1) ? 1 : -1);
        removeFirstLane();
    }
}

bool Map::isOver(){
    auto lanes = this->getChildren();
    int id = abs(player->getY() - std::dynamic_pointer_cast<Lane>(this->mChildren[0])->getY())/40.0f;
    std::vector<SceneNode::Ptr> objects;
    for (int i = id-1; i <= id+1; i++) {
        auto tmp = lanes[i]->getChildren();
        objects.insert(std::end(objects), std::begin(tmp), std::end(tmp));
    }
    for(auto i = 0 ; i < (int)objects.size(); i++){
        std::shared_ptr<Object> obj = std::dynamic_pointer_cast<Object>(objects[i]);
        auto tmp = obj.get();
        Objects::ID type = tmp->getType();
        if(player->collision(tmp)) {
            std::cerr << player->getX() << " " << player->getY() << " :: "<< tmp->getX() << " " << tmp->getY() <<'\n';
            if(type==Objects::Dinosaur) cerr<<"Dino\n";
            if(type==Objects::Bird) cerr<<"Bird\n";
            if(type==Objects::Truck) cerr<<"Truck\n";
            if(type==Objects::Car) cerr<<"Car\n";
            if(type==Objects::Obstacle) cerr<<"Tree\n";
            return true;
        }
    }
    return false;
}

void Map::drawThis() {
    // DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
}
Lanes::ID Map::getRandomLane() {
    int random = GetRandomValue(1, 9);
    if (random >= LANE_COUNT + 1)
        random = 4;
    return Lanes::ID(random);
}

void Map::saveThis(std::ofstream& out) {
    // out << "Map: ";
    out << mChildren.size() << '\n';
}

void Map::load(std::ifstream& in) {
    int size;
    in >> size;
    while (size--) {
        int laneID, objType, direction;
        float y;
        in >> laneID >> objType >> y >> direction;
        loadLane(Lanes::ID(laneID), direction, y);
        auto lane = std::dynamic_pointer_cast<Lane>(mChildren.back());
        lane->load(in);
    }
}