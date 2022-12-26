#include "program.h"
#include "Object.h"
#include "Global.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Crash Course");
    InitAudioDevice();
    // Music music = LoadMusicStream("../asset/sfx/MenuTheme.mp3");
    // PlayMusicStream(music);
    SetTargetFPS(FPS);
    Program Program;
    while (!WindowShouldClose())
        Program.run();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}