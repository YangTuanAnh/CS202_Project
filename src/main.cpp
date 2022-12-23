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

    Texture2D texture = LoadTexture("../asset/object/animal_bird_right.png");
    Texture2D texture2 = LoadTexture("../asset/object/animal_dinosaur_right.png");

    Texture2D bgTexture = LoadTexture("../asset/object/grass_1.png");

    Texture2D gridTexture = LoadTexture("../asset/Grid.png");
    Texture2D gridBGTexture = LoadTexture("../asset/object/Grass_600x300_1.png");
    Texture2D gridBGTexture2 = LoadTexture("../asset/object/Grass_600x300_2.png");
    Texture2D gridBGTexture3 = LoadTexture("../asset/object/Road_600x300_1.png");
    Texture2D gridBGTexture4 = LoadTexture("../asset/object/Road_600x300_2.png");

    // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
    // ImageFlipHorizontal(&inverseDirect);
    // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
    // Vector2 pos = { 40.0f, 40.0f };
    Vector2 posBg = { 0.0f, 0.0f };
    // Vector2 posBg_cont = { 80.0f, 0.0f };
    Vector2 pos = { 0.0f - texture.width, 0.0f };
    Vector2 pos2 = { 0.0f - texture2.width, 40.0f };
    Vector2 isometricPos;

    while (!WindowShouldClose()) {
        // // Color* pixels = LoadImageColors(inverseDirect);
        // // UpdateTexture(inverseTexture, pixels);
        // // UnloadImageColors(pixels);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw background
        // for (float x{ 0.0f }; x < 40.0f; x += 40.0f)
        //     for (float y{ 0.0f }; y < HEIGHT; y += 40.0f) {
        //         isometricPos = convertCar2IsoVector({ posBg.x + x, posBg.y + y });
        //         isometricPos.x -= 40.0f;
        //         DrawTextureV(bgTexture, isometricPos, WHITE);

        //         // isometricPos = convertCar2IsoVector({ posBg_cont.x + x, posBg_cont.y + y });
        //         // isometricPos.x -= 40.0f;
        //         // DrawTextureV(bgTexture, isometricPos, WHITE);
        // }

        //Draw grid
        // for (float x{ 0.0f }; x < 600.0f; x += 40.0f) {
        //     for (float y{ 0.0f }; y < HEIGHT; y += 40.0f) {
        //         isometricPos = convertCar2IsoVector({ posBg.x + x, posBg.y + y});
        //         isometricPos.x -= gridTexture.width/2;
        //         DrawTextureV(gridTexture, isometricPos, WHITE);
        //     }
        // }
        
        //Draw grass
        for (float y{ 0.0f }; y < 600.0f; y += 160.0f) {
            isometricPos = convertCar2IsoVector({ 0.0f, 0.0f + y });
            isometricPos.x -= 40.0f;
            DrawTextureV(gridBGTexture, isometricPos, WHITE);
        }
        for (float y{ 40.0f }; y < 600.0f; y += 160.0f) {
            isometricPos = convertCar2IsoVector({ 0.0f, 0.0f + y });
            isometricPos.x -= 40.0f;
            DrawTextureV(gridBGTexture2, isometricPos, WHITE);
        }
        for (float y{ 80.0f }; y < 600.0f; y += 160.0f) {
            isometricPos = convertCar2IsoVector({ 0.0f, 0.0f + y });
            isometricPos.x -= 40.0f;
            DrawTextureV(gridBGTexture3, isometricPos, WHITE);
        }
        for (float y{ 120.0f }; y < 600.0f; y += 160.0f) {
            isometricPos = convertCar2IsoVector({ 0.0f, 0.0f + y });
            isometricPos.x -= 40.0f;
            DrawTextureV(gridBGTexture4, isometricPos, WHITE);
        }

        // Draw object bird and dinosaur
        isometricPos = convertCar2IsoVector(pos);
        // DrawTexture(inverseTexture, WIDTH/2 - texture.width/2, HEIGHT/2 - texture.height/2, WHITE);
        DrawTextureV(texture, isometricPos, WHITE);
        isometricPos = convertCar2IsoVector(pos2);
        DrawTextureV(texture2, isometricPos, WHITE);

        Vector2 pos_dinosaur = pos2;
        unsigned char x = 255;
        for (int i{ 0 }; i < 28; ++i) {
            pos_dinosaur.x -= 20.0f;
            isometricPos = convertCar2IsoVector(pos_dinosaur);
            DrawTextureV(texture2, isometricPos, { 255, 255, 255, x});
            x -= 255 / 28;
        }
        // DrawRectangleLines(pos.x, pos.y, texture.width, texture.height, RED);
        if (pos.x >= WIDTH || pos.y >= HEIGHT) {
            pos = { 0.0f - texture.width, 0.0f };
        } else {
            pos.x += 3.0f;
            // pos.y += 0.5f;
        }
        if (pos2.x >= WIDTH || pos2.y >= HEIGHT) {
            pos2 = { 0.0f - texture2.width, 40.0f };
        } else {
            pos2.x += 5.0f;
            // pos.y += 0.5f;
        }

        EndDrawing();
        
        // Program.run();
    }
    CloseWindow();
    return 0;
}