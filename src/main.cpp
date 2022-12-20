#include "program.h"

Vector2 convertCar2IsoVector(Vector2 Cartesian) {
    Vector2 isometricVector;
    isometricVector.x = Cartesian.x - Cartesian.y + WIDTH/2;
    // if (Cartesian.x > 0)
    //     Cartesian.y += Cartesian.x/2;
    // else if (Cartesian.x == 0)
    //     Cartesian.y /= 2;
    isometricVector.y = (Cartesian.x + Cartesian.y)/2;
    return isometricVector;
};

int main()
{
    InitWindow(WIDTH, HEIGHT, "Crash Course");
    SetTargetFPS(60);
    Program Program;

    Texture2D texture = LoadTexture("../asset/object/vehicle_car_left.png");
    Texture2D bgTexture = LoadTexture("../asset/img/CrossyRoadBg.png");
    Texture2D texture2 = LoadTexture("../asset/object/vehicle_car_right.png");

    // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
    // ImageFlipHorizontal(&inverseDirect);
    // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
    // Vector2 pos = { 40.0f, 40.0f };
    Vector2 pos = { 0.0f, 0.0f };
    Vector2 pos2 = { 40.0f, 40.0f };
    Vector2 isometricPos;

    while (!WindowShouldClose()) {
        // // Color* pixels = LoadImageColors(inverseDirect);
        // // UpdateTexture(inverseTexture, pixels);
        // // UnloadImageColors(pixels);

        BeginDrawing();

        ClearBackground(RAYWHITE);
        isometricPos = convertCar2IsoVector(pos);
        DrawTexture(bgTexture, 0.0f, 0.0f, WHITE);
        // DrawTexture(inverseTexture, WIDTH/2 - texture.width/2, HEIGHT/2 - texture.height/2, WHITE);
        DrawTextureV(texture, isometricPos, WHITE);
        isometricPos = convertCar2IsoVector(pos2);
        DrawTextureV(texture2, isometricPos, WHITE);
        // DrawRectangleLines(pos.x, pos.y, texture.width, texture.height, RED);
        if (pos.x >= WIDTH || pos.y >= HEIGHT) {
            pos = { 0, 0 };
        } else {
            pos.x += 1.0f;
            // pos.y += 0.5f;
        }
        if (pos2.x >= WIDTH || pos2.y >= HEIGHT) {
            pos2 = { 40.0f, 40.0f };
        } else {
            pos2.x += 1.0f;
            // pos.y += 0.5f;
        }

        EndDrawing();
        
        // Program.run();
    }
    CloseWindow();
    return 0;
}