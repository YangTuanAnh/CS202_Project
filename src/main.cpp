#include "program.h"
#include "Object.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "Crash Course");
    SetTargetFPS(60);
    Program Program;

    Texture2D texture = LoadTexture("../asset/object/animal_dinosaur.png");
    Texture2D bgTexture = LoadTexture("../asset/img/CrossyRoadBg.png");
    
    Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
    ImageFlipHorizontal(&inverseDirect);
    Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
    // Vector2 pos = { 40.0f, 40.0f };
    Vector2 pos = { WIDTH/4, HEIGHT/4 };

    while (!WindowShouldClose()) {
        // // Color* pixels = LoadImageColors(inverseDirect);
        // // UpdateTexture(inverseTexture, pixels);
        // // UnloadImageColors(pixels);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(bgTexture, 0.0f, 0.0f, WHITE);
        // DrawTexture(inverseTexture, WIDTH/2 - texture.width/2, HEIGHT/2 - texture.height/2, WHITE);
        DrawTextureV(inverseTexture, pos, WHITE);
        DrawRectangleLines(pos.x, pos.y, texture.width, texture.height, RED);
        if (pos.x >= WIDTH || pos.y >= HEIGHT) {
            // pos = { 40.0f, 40.0f };
            pos = { WIDTH/4, HEIGHT/4 };
        } else {
            pos.x += 1.0f;
            pos.y += 0.5f;
        }

        EndDrawing();
        
        // Program.run();
    }
    CloseWindow();
    return 0;
}