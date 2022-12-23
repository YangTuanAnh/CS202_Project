#pragma once

#include <list>
#include <memory>
#include <functional>
#include <map>
#include <cassert>

#include "Object.h"
#include "TextureHolder.h"
#include "ObjectFactory.hpp"

class Lane {
protected:
    float mY;
    std::list<Object::Ptr> objects;
    int direction = 1;
    TextureHolder *mTextures;
    ObjectFactory<Object, float, float, int, float, TextureHolder*> mFactories;
public:
    typedef std::unique_ptr<Lane> Ptr;
    Lane(TextureHolder* mTextures);
    ~Lane();
    void init(float y);
    virtual void update(float dt);
    virtual void draw();
    void drawThis();
    void addObject(Objects::ID type, float x);
};