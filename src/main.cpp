#include "program.h"
#include "Object.h"
#include "Global.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Crash Course");
    Image icon = LoadImage("../asset/player/chicken_down.png");
    SetWindowIcon(icon);
    InitAudioDevice();
    SetTargetFPS(FPS);
    Program Program;
    while (!WindowShouldClose())
        Program.run();
    CloseAudioDevice();
    CloseWindow();
    UnloadImage(icon);
    return 0;
}