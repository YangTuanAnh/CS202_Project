#pragma once

#include <list>
#include <memory>
#include <functional>
#include <map>

#include "Object.h"

class Lane {
protected:
    float mY;
    std::list<Object::Ptr> objects;
    int direction = 0;
public:
    typedef std::unique_ptr<Lane> Ptr;
    Lane();
    ~Lane();
    void init(float y);
    void update(float dt);
    void draw();
};