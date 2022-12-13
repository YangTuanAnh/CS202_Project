#pragma once

#include "Global.h"
#include "Object.h"
#include <raylib.h>
#include <raygui.h>
const int WIDTH = 1200, HEIGHT = 600;

static bool gameOver = false;
static bool pause = false;
class Player {
public:
    float mX, mY;
    bool mState;
    int point;
    Texture2D *chicken;

public:
    Player() {}
    Player(float, float, int);
    void init(Texture2D*);
    float getmX();
    float getmY();
    int getPoint();
    void setX(float);
    void setY(float);
    void setPoint(int);
    void movement();
    void draw();
    void update();
    bool isDead();
    bool collision(Object *);
    ~Player();
};