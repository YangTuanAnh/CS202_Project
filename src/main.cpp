#include "program.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "Crash Course");
    SetTargetFPS(60);
    Program Program;
    while (!WindowShouldClose())
        Program.run();
    CloseWindow();
    return 0;
}