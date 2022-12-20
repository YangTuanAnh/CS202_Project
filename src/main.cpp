#include "program.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Crash Course");
    InitAudioDevice();
    // Music music = LoadMusicStream("../asset/sfx/MenuTheme.mp3");
    // PlayMusicStream(music);
    SetTargetFPS(60);
    Program Program;
    while (!WindowShouldClose())
        Program.run();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}