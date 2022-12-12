#pragma once
#include "Game.h"
#include <raylib.h>
#include "../include/raygui.h"

//const int WIDTH = 1200, HEIGHT = 600;
class Program
{
private:
    Rectangle rec_top{0, 0, 1200, 100};
    Player * mPlayer;

public:
    Program() {
        mPlayer = new Player(0,0,0);
    }
    ~Program() {}
    void run() {
        mPlayer->UpdatePlayer();
        mPlayer->DrawPlayer();
    }
};