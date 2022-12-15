#include "program.h"
#include "Object.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "CS163_Dictionary");
    SetTargetFPS(60);
    Program Program;
    Texture2D texture = LoadTexture("../image/animal_dinosaur.png");

    Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
    ImageFlipHorizontal(&inverseDirect);
    Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
    Vector2 pos = { 10.0f, 10.0f };

    while (!WindowShouldClose()) {
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        // DrawTexture(inverseTexture, WIDTH/2 - texture.width/2, HEIGHT/2 - texture.height/2, WHITE);
        DrawTextureV(inverseTexture, pos, WHITE);
        pos.x += 2.0f;

        EndDrawing();
    }
        //Program.run();
    CloseWindow();
    return 0;
}