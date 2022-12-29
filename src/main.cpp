#include "program.h"
#include "Object.h"
#include "Global.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Crash Course");
    InitAudioDevice();
    SetTargetFPS(FPS);
    Program Program;
    while (!WindowShouldClose())
        Program.run();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}