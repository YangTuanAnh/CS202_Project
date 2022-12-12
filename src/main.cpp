#include "program.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "CS163_Dictionary");
    SetTargetFPS(60);
    Program Program;
    Texture2D texture = LoadTexture("../image/vehicle_car.png");
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(texture, WIDTH/2 - texture.width/2, HEIGHT/2 - texture.height/2, WHITE);

        DrawText("this IS a texture!", 360, 370, 10, GRAY);

        EndDrawing();
    }
        //Program.run();
    CloseWindow();
    return 0;
}