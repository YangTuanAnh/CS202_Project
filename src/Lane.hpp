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
<<<<<<< Updated upstream
=======
    Objects::ID type;
    Objects::ID obstacle;
>>>>>>> Stashed changes
    float mY;
    int direction = 1;
    int nextSpawnTime = 0;
    TextureHolder *mTextures;
    ObjectFactory<Object, float, float, int, float, TextureHolder*> mFactories;
public:
    typedef std::unique_ptr<Lane> Ptr;
    Lane(TextureHolder* mTextures);
    ~Lane();
    void init(float y);
    virtual void drawThis();
    virtual void updateThis(float dt);
    void addObject(Objects::ID type, float x);
<<<<<<< Updated upstream
=======
    virtual void addRandomObject(Objects::ID);
    virtual void addObstacles(Objects::ID);
>>>>>>> Stashed changes
};