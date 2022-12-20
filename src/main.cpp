#include "program.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Crash Course");
    SetTargetFPS(60);
    Program Program;
    while (!WindowShouldClose())
        Program.run();
    CloseWindow();
    return 0;
}