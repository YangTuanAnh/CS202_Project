#pragma once

#include <list>
#include <memory>
#include <functional>
#include <map>
#include <cassert>

#include "Object.h"
#include "TextureHolder.h"
#include "ObjectFactory.hpp"

class Lane : public SceneNode {
protected:
    Lanes::ID laneID;
    Objects::ID type;
    float mY;
    // Isometric position
    Vector2 pos1, pos2, pos3;
    int direction;
    float nextSpawnTime = 0;
    TextureHolder *mTextures;
    ObjectFactory<Object, float, float, int, float, TextureHolder*> mFactories;
public:
    typedef std::unique_ptr<Lane> Ptr;
    Lane(TextureHolder* mTextures, Lanes::ID laneID, Objects::ID type);
    ~Lane(); 
    float getY();
    void init(float y, int d, bool flag);
    virtual void drawThis();
    virtual void updateThis(float dt);
    virtual void saveThis(std::ofstream&);
    virtual void load(std::ifstream&);
    void addObject(Objects::ID type);
    void addObject(Objects::ID type, float x);
    virtual void removeOutOfView();
    virtual void addRandomObject(Objects::ID, float dt);
    virtual void addObstacles();
    virtual void addTrafficLamp();
};