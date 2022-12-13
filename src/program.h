#pragma once
#include "Game.h"
#include <raylib.h>
#include <raygui.h>
#include "StateStack.hpp"

//const int WIDTH = 1200, HEIGHT = 600;
class Program
{
private:
    Rectangle rec_top{0, 0, 1200, 100};
    StateStack mStateStack;
    TextureHolder *mTextures;
    Player *mPlayer;
public:
    Program();
    ~Program();
    void registerStates();
    void run();
};