#pragma once
#include "States/GameState.hpp"
#include <raylib.h>
#include <raygui.h>
#define RAYGUI_IMPLEMENTATION
#include "StateStack.hpp"

class Program
{
private:
    Rectangle rec_top{0, 0, 1200, 100};
    StateStack mStateStack;
    TextureHolder *mTextures;
    Player *mPlayer;
    MusicPlayer *mMusic;
public:
    Program();
    ~Program();
    void registerStates();
    void run();
};