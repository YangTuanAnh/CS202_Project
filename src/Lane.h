#pragma once

#include <list>
#include <memory>

#include "Object.h"

class Lane {
protected:
    std::list<Object::Ptr> objects;
    int direction = 0;
public:
    typedef std::unique_ptr<Lane> Ptr;
    Lane();
    ~Lane();
    void addObject(Object::Ptr object);
    void removeObject(Object::Ptr object);
    void update(float dt);
    void draw();
};