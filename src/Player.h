#pragma once

#include "Global.h"
#include "Object.h"
class Player{
public:
    int mX, mY;
    bool mState;
    int point;
public:
    Player() {}
    Player(int,int,int);
    int getmX();
    int getmY();
    int getPoint();
    void setX(int);
    void setY(int);
    void setPoint(int);
    void Up();
    void Down();
    void Left();
    void Right();
    void movement();
    bool isDead();
    bool Collision(Object*);
    ~Player();
};